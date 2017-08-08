#include "threadpool.h"

#include <stdexcept>
#include <iostream>
#include <chrono>

ThreadPool::ThreadPool(size_t num)
{
    for(size_t i=0; i<num; i++)
    {
        m_workers.emplace_back(
            [this]
            {
                for(;;)
                {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(m_queuemutex);
                        m_condition.wait(lock, [this]{return this->m_stop || !this->m_tasks.empty();});
                        if(m_stop && m_tasks.empty())
                            return;
                        task = std::move(m_tasks.front());
                        m_tasks.pop();
                    }
                    task();
                }
            }
        );
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(m_queuemutex);
        m_stop = true;
    }
    m_condition.notify_all();
    for(std::thread &worker: m_workers)
        worker.join();
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using returntype = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<returntype()> > (
                std::bind(std::forward<F>(f), std::forward<Args>(args)...)
                );

    std::future<returntype> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(m_queuemutex);
        if(m_stop) //do not allow enqueueing after stopping the pool
            throw std::runtime_error("enqueue on stoppped ThreadPool");

        m_tasks.emplace([task](){(*task)(); });
    }
    m_condition.notify_one();
    return res;
}

void ThreadPoolTest::TestThreadPool()
{
    ThreadPool pool(4);

    std::vector<std::future<int> > results;
    for(int i=0; i<8; i++)
    {
        results.emplace_back(
            pool.enqueue([i]{
                std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "world " << i << std::endl;
                return i*i;
            })
        );
    }

    for(auto &&result: results)
    {
        std::cout << result.get() << " ";
    }
    std::cout << std::endl;
}
