#ifndef FUNCTIONALLIB_H
#define FUNCTIONALLIB_H

#include <string.h>
#include <iostream>

class Student
{
public:
    Student(const char *name)
    {
        strcpy(m_name, name);
    }

    void SayHello(const char *name) const
    {
        std::cout << "Student--" << m_name << " say: hello " << name << std::endl;
    }

    static int GetID()
    {
        return 1100;
    }

    int operator()(int i, int j, int k) const
    {
        return i + j + k;
    }

private:
    char m_name[32];
};

class FunctionalLib
{
public:
    FunctionalLib();

private:
    void TestLib();

    void BindFunc();
};

#endif // FUNCTIONALLIB_H
