#ifndef SHAREDPTRTEST_H
#define SHAREDPTRTEST_H

#include <memory>
#include <iostream>

class clReset {
public:
    clReset(int iNum) : m_iNum(iNum) {
        std::cout << "construct clReset num=" << m_iNum << std::endl;
    }
    ~clReset() {
        std::cout << "destruct clReset num=" << m_iNum << std::endl;
    }

private:
    int m_iNum;
};

class SharedPtrTest
{
public:
    SharedPtrTest();

private:
    void TestLib();

    void ResetPtr();
};

#endif // SHAREDPTRTEST_H
