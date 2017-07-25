#include "algorithmlib.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int op_increase(int i) {return ++i;}

AlgorithmLib::AlgorithmLib()
{
    TestLib();
}

void AlgorithmLib::TestLib()
{
    TransformFunc();
}

void AlgorithmLib::TransformFunc()
{
    // unary operation
    int first[] = {1,2,3,4,5};
    int second[] = {10,20,30,40,50};
    int results[5]={0};
    transform(first, first+5, second, results, std::plus<int>());
    copy(results, results+5, ostream_iterator<int>(cout, " "));
    cout << endl;

    // binary operation
    vector<int> foo;
    vector<int> bar;
    for(int i=0; i<6; i++)
        foo.push_back(i*10);
    bar.resize(foo.size());
    transform(foo.begin(), foo.end(), bar.begin(), op_increase);
    for(auto it=bar.begin(); it!=bar.end(); it++)
        cout << " " << *it;
    cout << endl;
}
