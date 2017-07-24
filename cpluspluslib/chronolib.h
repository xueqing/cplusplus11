#ifndef CHRONOLIB_H
#define CHRONOLIB_H

#include <string>
#include <mutex>
#include <condition_variable>

class ChronoLib
{
public:
    ChronoLib();

private:
    std::mutex m_mutexCond;
    std::condition_variable m_cond;

    void TestLib();

    /**
     * @brief GetTimeAsString   transform timestamp into strtime according to strformat
     * @param strtime           formatted string
     * @param strformat         format, referring to format of 'std::strftime()'
     * @param timestamp         given time
     * @return
     */
    bool GetTimeAsString(std::string &strtime, std::string strformat, long timestamp = -1);

    /**
     * @brief GetTimeFromString transform strtime into timestamp according to strformat
     * @param strtime           given string of time, "yyyy-mm-ddThh:mm:ss"
     * @param timestamp         requested time
     * @return
     */
    bool GetTimeFromString(std::string strtime, long &timestamp);

    /**
     * @brief WaitSeconds       sleep for given time
     * @param nSec              given time
     */
    void WaitSeconds(int nSec); //Timer
};

#endif // CHRONOLIB_H
