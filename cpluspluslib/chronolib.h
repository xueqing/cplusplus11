#ifndef CHRONOLIB_H
#define CHRONOLIB_H

#include <string>

class ChronoLib
{
public:
    ChronoLib();

private:
    void TestLib();

    bool GetTimeAsString(std::string &strtime, std::string strformat, long timestamp = -1);
    bool GetTimeFromString(std::string strtime, long &timestamp);

};

#endif // CHRONOLIB_H
