#include "functionallib.h"

#include <iostream>
#include <functional>
#include <typeinfo>

using namespace std;

int IntSum(int i, int j, int k)
{
    return i + j + k;
}

FunctionalLib::FunctionalLib()
{
    TestLib();
}

void FunctionalLib::TestLib()
{
    BindFunc();
}

void FunctionalLib::BindFunc()
{
    using namespace placeholders;

    // bind global function
    auto addten = std::bind(IntSum, _1, _2, 10);
    cout << "FunctionalLib::BindFunc--" << typeid(addten).name() << endl;
    cout << "FunctionalLib::BindFunc--addten(1, 2)= " << addten(1, 2) << endl;

    // bind member function std::bind(func, caller, args...)
    Student stud("kiki");
    auto sayHello = std::bind(&Student::SayHello, stud, _1);
    sayHello("xueqing");

    // std::bind(func, caller, args...)
    auto sayHelloToXiaoxin = std::bind(&Student::SayHello, stud, "xiaoxin");
    sayHelloToXiaoxin();

    // bind static member function
    auto studid = std::bind(&Student::GetID);
    cout << "FunctionalLib::BindFunc--Student id=" << studid() << endl;

    // bind operator function
    auto addhundred = std::bind(&Student::operator (), stud, _1, _2, 100);
    cout << "FunctionalLib::BindFunc--addhundred(1, 2)= " << addhundred(1, 2) << endl;

    // NOTE: cannot use std::bind to bind a overloaded function
}
