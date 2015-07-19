#ifndef _CTIMER_H_
#define _CTIMER_H_

#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef SGI_IRIX
#include <iostream.h>
#endif
#ifdef LINUX_RH
#include <iostream>
using namespace std;
#endif
#include <errno.h>

class CTimer
{
public:
    CTimer(void (*f)(int), int S);
    ~CTimer();
    void    setTimer(double Time);
    void    setDelay(long Delay){m_Delay = Delay;}
    int     getTimer(void){return m_timerPeriod;}
    int     getSignal(void){return m_nSignal;}
    void    start();
    void    stop();
    int     getStatus() {return m_Status;}
    double  getTimeStamp();
    void    printInfo();

private:
    timer_t  m_timerId;
    double   m__timerPeriod;
    int      m_nSignal;
    struct   itimerspec m_timer;
    int      m_Status;
    long     m_Delay;
    struct sigevent m_Event;
#ifdef SGI_IRIX
    sigaction_t m_Action;
#endif
#ifdef LINUX_RH
    struct sigaction m_Action;
#endif
    sigset_t m_Empty;
};

#endif
