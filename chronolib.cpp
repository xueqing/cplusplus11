#include "chronolib.h"

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <chrono>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/typeof/typeof.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::property_tree;

ChronoLib::ChronoLib()
{
    TestLib();
}

void ChronoLib::TestLib()
{
    ptree *pRoot = new ptree;
    read_xml("/home/kiki/qt-workspace/exercise/cplusplus11/test.xml", *pRoot);

    char buf[30];
    memset(buf, 0, sizeof(buf));
    time_t rawtime = std::time(nullptr);
    std::tm *ptimeinfo = std::localtime(&rawtime);
    std::strftime(buf, 30, "%FT%T", ptimeinfo);
    string curtime(buf);
    string starttime = pRoot->get<string>("Query.StartTime", curtime);
    string endtime = pRoot->get<string>("Query.EndTime", curtime);

    int nyear, nmon, nday, nhou, nmin, nsec;

    sscanf(starttime.data(), "%d-%d-%dT%d:%d:%d", &nyear, &nmon, &nday, &nhou, &nmin, &nsec);
    std::tm stimeinfo;
    stimeinfo.tm_year = nyear-1900;
    stimeinfo.tm_mon = nmon-1;
    stimeinfo.tm_mday = nday;
    stimeinfo.tm_hour = nhou;
    stimeinfo.tm_min = nmin;
    stimeinfo.tm_sec = nsec;
    time_t stime = std::mktime(&stimeinfo);
    system_clock::time_point stimepoint = system_clock::from_time_t(stime);
    system_clock::duration sduration = stimepoint.time_since_epoch();
    long scount = sduration.count() * system_clock::period::num / system_clock::period::den; // scount = stime

    sscanf(endtime.data(), "%d-%d-%dT%d:%d:%d", &nyear, &nmon, &nday, &nhou, &nmin, &nsec);
    std::tm etimeinfo;
    etimeinfo.tm_year = nyear-1900;
    etimeinfo.tm_mon = nmon-1;
    etimeinfo.tm_mday = nday;
    etimeinfo.tm_hour = nhou;
    etimeinfo.tm_min = nmin;
    etimeinfo.tm_sec = nsec;
    time_t etime = std::mktime(&etimeinfo);
    system_clock::time_point etimepoint = system_clock::from_time_t(etime);
    system_clock::duration eduration = etimepoint.time_since_epoch();
    long ecount = eduration.count() * system_clock::period::num / system_clock::period::den; // ecount = etime

    cout << "ChronoLib::TestLib--scount=" << scount << ";ecount=" << ecount << endl;

    string tableName;
    double diffsec = std::difftime(etime, stime);
    if(diffsec > 0)
    {
        int diffday = diffsec / (24 * 3600);
        for(int i=-1; i<=diffday; i++)
        {
            tableName.clear();
            memset(buf, 0, sizeof(buf));
            chrono::hours oneday(i*24);
            system_clock::time_point itimepoint = stimepoint + oneday;
            time_t itime = system_clock::to_time_t(itimepoint);
            std::tm *itimeinfo = std::localtime(&itime);
            std::strftime(buf, 30, "S%G%m%d", itimeinfo);
            tableName = string(buf);

            cout << "ChronoLib::TestLib--table name: " << tableName << endl;
        }
    }
    delete pRoot;

    char buffer[30];
    memset(buffer, 0, sizeof(buf));
    long timestamp = 1499258297;
    chrono::seconds vseconds(timestamp);
    system_clock::time_point vtimepoint(vseconds);
    time_t vtime = system_clock::to_time_t(vtimepoint);
    std::tm *vtimeinfo = std::localtime(&vtime);
    std::strftime(buffer, 30, "%FT%T", vtimeinfo);
    cout << "ChronoLib::TestLib--buf: " << buffer << endl;
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
    std::tm *ptm = std::localtime(&ttime);
    std::strftime(buffer, 30, strformat.data(), ptm);

    strtime = string(buffer);
    cout << "BMIUtilities::GetTimeAsString--strtime=" << strtime << endl;
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
