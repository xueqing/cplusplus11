#ifndef REFERENCETEST_H
#define REFERENCETEST_H

#include <iostream>
#include <string>

class clReference {
public:
    clReference() : m_iNum(-1) {
        std::cout << "construct default clReference num=" << m_iNum << std::endl;
    }
    clReference(int iNum) : m_iNum(iNum) {
        std::cout << "construct clReference num=" << m_iNum << std::endl;
    }
    clReference(int iNum, std::string strLable) : m_iNum(iNum), m_strLable(strLable) {
        std::cout << "construct clReference num=" << m_iNum << std::endl;
    }
    clReference(clReference &cl) : m_iNum(std::move(cl.m_iNum)), m_strLable(std::move(cl.m_strLable)) {
        std::cout << "copy clReference& num=" << m_iNum << std::endl;
    }
    clReference(clReference &&cl) : m_iNum(std::move(cl.m_iNum)), m_strLable(std::move(cl.m_strLable)) {
        std::cout << "copy clReference&& num=" << m_iNum << std::endl;
    }
    ~clReference() {
        std::cout << "destruct clReference num=" << m_iNum << std::endl;
    }

    int Num() { return m_iNum; }
    std::string Label() { return m_strLable; }

private:
    int m_iNum;
    std::string m_strLable;
};

class ReferenceTest
{
public:
    ReferenceTest() { TestLib(); }

private:
    void TestLib();

    void ReferenceStructTest();
};

#endif // REFERENCETEST_H
