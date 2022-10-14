#include "referencetest.h"

#include <deque>

using namespace std;

void ReferenceTest::TestLib()
{
    ReferenceStructTest();
}

void ReferenceTest::ReferenceStructTest()
{
    deque<clReference> deqRefer;

    deqRefer.emplace_back(clReference());
    cout << "size=" << deqRefer.size() << endl << endl;
    deqRefer.pop_front();

    deqRefer.emplace_back(1);
    cout << "size=" << deqRefer.size() << endl << endl;

    clReference clRefer2(2);
    deqRefer.push_back(clRefer2);
    cout << "size=" << deqRefer.size() << endl << endl;

    clReference& clRefer3 = clRefer2;
    deqRefer.push_back(clRefer3);
    cout << "size=" << deqRefer.size() << endl << endl;

    clReference clRefer4(4, "Im4");
    deqRefer.push_back(std::move(clRefer4));
    cout << "size=" << deqRefer.size() << endl << endl;
    cout << "clRefer4:" << clRefer4.Num() << ";" << clRefer4.Label() << endl << endl;
    cout << "deqRefer.back():" << deqRefer.back().Num() << ";" << deqRefer.back().Label() << endl << endl;
}
