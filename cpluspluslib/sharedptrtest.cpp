#include "sharedptrtest.h"

using namespace std;

SharedPtrTest::SharedPtrTest()
{
    TestLib();
}

void SharedPtrTest::TestLib()
{
    ResetPtr();
}

void SharedPtrTest::ResetPtr()
{
    shared_ptr<clReset> spReset;
    cout << "before spReset.reset(new clReset(1))" << endl;
    spReset.reset(new clReset(1));
    cout << "before spReset.reset(new clReset(2))" << endl;
    spReset.reset(new clReset(2));
    cout << "before spReset.reset()" << endl;
    spReset.reset();
}
