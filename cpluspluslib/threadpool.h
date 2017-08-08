#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>

class ThreadPool
{
public:
    ThreadPool(size_t num);
    // add new work item to the pool
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
        -> std::future<typename std::result_of<F(Args...)>::type>;
    // join all threads
    ~ThreadPool();

private:
    std::vector<std::thread> m_workers; // keep track of threads to join them
    std::queue<std::function<void()> > m_tasks; // task queue

    std::mutex m_queuemutex;
    std::condition_variable m_condition;
    bool m_stop = false;
};

class ThreadPoolTest
{
public:
    ThreadPoolTest(){TestThreadPool();}
    ~ThreadPoolTest(){}

private:
    void TestThreadPool();
};

#endif // THREADPOOL_H
