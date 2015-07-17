#ifndef STATE_H
#define STATE_H

#include "namespace.h"
#include "rfm_interface.h"
#include <vector>
#include <iostream>

using namespace FSM;

//n. of cycles
#define WARMING_DELAY 1500
//milliseconds
#define OVERRIDE_DELAY 5000
#define SHUTDOWN_DELAY_MIN 3000
#define COOLING_PUBLICATION_DELAY 15000


class State {
friend class Machine;
public:
    State(class Machine* m, STATE nID);
    virtual ~State() {}
    virtual void handleEvent(EVENT evt);
    virtual void update();
    virtual void onEntry() {}
    virtual void onExit() {}
    inline STATE  getID() const      {return m_stateID;}
    inline double getShutdownTime()  {return m_shutdown_timer.getElapsedTimeInMilliSec();}
    inline double getOverrideTime()  {return m_override_timer.getElapsedTimeInMilliSec();}
    inline int    getShutdownDelay() {return m_shutdown_delay;}
    const inline  std::string getName() const {return states[m_stateID];}
private:
    STATE m_stateID;
    CGetTime m_override_timer,
             m_shutdown_timer;
    int      m_shutdown_delay;

protected:
	bool     m_new_event;
    Machine* m_machine;
    void updateFailureRadarShutdown();
};


class OffState: public State {
public:
    OffState(Machine *m);
    virtual ~OffState();
private:
    virtual void onEntry();
    virtual void onExit();

    virtual void update();
    virtual void warmup();
    virtual void hold();
    bool m_is_first_time;
};



class WarmupState: public State {
public:
    WarmupState(Machine *m);
    virtual ~WarmupState();

	inline int getWarmingDelay() const {
		return m_warming_delay;
	}

private:
    virtual void onEntry();
    virtual void onExit();

    virtual void update();
    virtual void off();
    virtual void standby();
    virtual void hold();

    int m_warming_delay;
    void warmup();

};



class StandbyState: public State {
public:
    StandbyState(Machine *m);
    virtual ~StandbyState();
private:
    virtual void onEntry();

    virtual void update();
    virtual void off();
    virtual void on();
    virtual void hold();
};


class OnState: public State {
public:
    OnState(Machine *m);
    virtual ~OnState();
private:
    virtual void update();
    virtual void off();
    virtual void standby();
    virtual void hold();
};


class HoldState: public State {
public:
    HoldState(Machine *m);
    virtual ~HoldState();
private:
    virtual void update();
    virtual void back();
    virtual void off();
    virtual void warmup();
    virtual void standby();
    virtual void on();
};


class TotalFailState: public State {
public:
    TotalFailState(Machine *m);
    virtual ~TotalFailState();
private:
    virtual void onExit();

    virtual void update();
    virtual void hold();
};



class Machine {
    friend class OffState;
    friend class WarmupState;
    friend class StandbyState;
    friend class OnState;
    friend class HoldState;
    friend class TotalFailState;
    friend class State;
private:
    RFM_IF        *m_rfm_iface;
    FSM_MARS_IF   *m_mars_iface;

    OffState       m_off;
    WarmupState    m_warmup;
    StandbyState   m_standby;
    OnState        m_on;
    HoldState      m_hold;
    TotalFailState m_total_fail;

    State         *m_state;
    long long int  m_step;
    STATE          m_prevStateID;
    EVENT          m_ios;
    bool           m_quick_warmup;
    bool           m_radar_power_on;
    bool           m_wow;
    bool           m_is_total_fail;
    bool           m_is_radar_shutdown;
    bool           m_is_override;
    bool           m_is_coolant_failure;

    CGetTime       m_cooling_publication_delay;
    bool           m_is_cooling_delay_ended;

    void setCurrent(STATE s);
    void updateMalfunctions();
    void updateAmraam();

public:
    Machine();
    Machine(RFM_IF *sharedArea, FSM_MARS_IF *marsArea);
    virtual ~Machine() {}

    // TODO:
    // - if FSM is instantiated in mode REFLECTIVE_MEMORY, it reads
    // from ReflectiveMemory on its own (events are disabled).
    //  - If it is instantiated in mode EXT_EVENTS, reflective memory read is disabled and
    // reacts on scheduleEvents() only

    // call step() to let FSM evolve
    void step();
    // let the FSM know what's happening out there
    void scheduleEvent(EVENT e);
    // switch to previous state (basically for Hold state)
    void back();

    //test if current state is equal to s,
    //otherwise print an error and exit
    bool shouldBe(STATE s) const;
    void printStatus();
    inline double getCoolingDelayTime() {return m_cooling_publication_delay.getElapsedTimeInMilliSec();}
};


#endif // STATE_H
