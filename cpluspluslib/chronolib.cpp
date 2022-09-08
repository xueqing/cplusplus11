#include "chronolib.h"

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <mutex>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/typeof/typeof.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::property_tree;

ChronoLib::ChronoLib()
{
    TestLib();
    WaitSeconds(10);
}

void ChronoLib::TestLib()
{
    ptree *pRoot = new ptree;
    read_xml("/home/kiki/qt-workspace/exercise/cplusplus11/test.xml", *pRoot);

    // get current time
    string curtime;
    GetTimeAsString(curtime, "%FT%T");

    // get request parameters
    string starttime = pRoot->get<string>("Query.StartTime", curtime);
    string endtime = pRoot->get<string>("Query.EndTime", curtime);
    delete pRoot;

    // get seconds_since_epoch for starttime and endtime
    long scount=-1, ecount=-1;
    GetTimeFromString(starttime, scount);
    GetTimeFromString(endtime, ecount);
    cout << "ChronoLib::TestLib--scount=" << scount << ";ecount=" << ecount << endl;

    string tableName;
    system_clock::time_point stimepoint = system_clock::from_time_t(scount);
    double diffsec = std::difftime(ecount, scount);
    if(diffsec > 0)
    {
        int diffday = diffsec / (24 * 3600);
        for(int i=-1; i<=diffday; i++)
        {
            tableName.clear();
            chrono::hours oneday(i*24);
            system_clock::time_point itimepoint = stimepoint + oneday;
            time_t itime = system_clock::to_time_t(itimepoint);
            GetTimeAsString(tableName, "S%G%m%d", itime);

            cout << "ChronoLib::TestLib--table name: " << tableName << endl;
        }
    }

    long timestamp = 1499258297;
    string stimetamsp;
    GetTimeAsString(stimetamsp, "%FT%T", timestamp);
    cout << "ChronoLib::TestLib--stimestamp=" << stimetamsp << endl;
}

bool ChronoLib::GetTimeAsString(string &strtime, string strformat, long timestamp)
{
    if(timestamp == -1)
    {
        timestamp = std::time(nullptr);
    }

    char buffer[30];
    memset(buffer, 0, sizeof(buffer));

    chrono::seconds cseconds(timestamp);
    system_clock::time_point sctimepoint(cseconds);
    time_t ttime = system_clock::to_time_t(sctimepoint);
    std::tm tmres;
    localtime_r(&ttime, &tmres);
    std::strftime(buffer, 30, strformat.data(), &tmres);

    strtime = string(buffer);
    cout << "ChronoLib::GetTimeAsString--strtime=" << strtime << endl;
    return true;
}

bool ChronoLib::GetTimeFromString(string strtime, long &timestamp)
{
    int nyear, nmon, nday, nhou, nmin, nsec;

    sscanf(strtime.data(), "%d-%d-%dT%d:%d:%d", &nyear, &nmon, &nday, &nhou, &nmin, &nsec);
    std::tm stimeinfo;
    stimeinfo.tm_year = nyear-1900;
    stimeinfo.tm_mon = nmon-1;
    stimeinfo.tm_mday = nday;
    stimeinfo.tm_hour = nhou;
    stimeinfo.tm_min = nmin;
    stimeinfo.tm_sec = nsec;

    timestamp = std::mktime(&stimeinfo);
    return true;
}

void ChronoLib::WaitSeconds(int nSec)
{
    cout << "ChronoLib::WaitSeconds--timestamp=" << std::time(nullptr) << endl;
    mutex mut;
    unique_lock<mutex> locker(mut);
    m_cond.wait_for(locker, chrono::seconds(nSec));
    cout << "ChronoLib::WaitSeconds--timestamp=" << std::time(nullptr) << endl;
}
