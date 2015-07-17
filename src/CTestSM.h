#ifndef TEST_H
#define TEST_H
#include "namespace.h"
#include "CStateMachine.h"
#include <queue>

class TestEvent {
    int m_event; //int instead of EVENT to allow for invalid values
    int m_leap;
    STATE m_state; //expected state of fsm after execution of this event
public:
    TestEvent(int event, STATE state) : m_event(event), m_leap(1), m_state(state) {}
    TestEvent(int cycle_leap, int event, STATE state) {m_event = event; m_leap = (cycle_leap > 1 ? cycle_leap : 1); m_state = state; }
    int getLeap() { return m_leap; }
    int getEvent() { return m_event; }
    STATE getState() { return m_state; }
};

class TestMachine {
private:
    Machine *fsm;
    std::queue< TestEvent > q;
    int m_loop;
    int m_leap;
    int m_event_n;
    STATE m_expected_state;
    void reset();
    bool start();
public:
    TestMachine();
    void testEvents();
    void slowWarmup();
    void interleavedHold();
    void quickWarmup();
    void quickWarmup2();
    void mySequence();
    void mixed();

};





/*
    In una FIFO vengono impilati elementi <evento, n>.
    evento è un intero, che può corrispondere a EVENT (ma non deve necessariamente)
    n indica il numero di cicli da aspettare prima di eseguire l'evento
    Se n viene omesso si intende eseguire l'evento nel ciclo corrente

    Esempio:

    push( RADAR_POWER_ON        )       --> nel primo ciclo
    push( QUICK_WARMUP_TRUE     )       --> dopo 1 ciclo dal precedente
    push( (IOS_PAUSE,        2) )    --> dopo 2 cicli dal precedente
    push( (764,              3) )    --> dopo 3 cicli dal precedente (FSM deve dare eccezione per valore non valido!)

    bool t = true;
    while (FIFO non vuota and (t==true)) {
        loop++;
        pop();
        --> abbiamo <evento, n>
        if (n)
            n--;
        if (n == 0) {
            schedula evento
            //fsm.scheduleEvent(QUICK_WARMUP_FALSE);
            evolvi la macchina a stati
            fsm.step();
            controlla che lo stato sia quello previsto
            t = machine->shouldBe(STATE_XXX);
        }
    }
    */


#endif // TEST_H
