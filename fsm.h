#ifndef FSM_H
#define FSM_H
#include "state.h"
#include <QDebug>


class Fsm
{

    State _currentState;

public:
    Fsm();
    virtual void run()=0;


    bool checkState(State& src, const State& target, bool cond, FsmFn callback){
        qDebug() << __FUNCTION__ << _currentState.stateName() << _currentState.id();
        if (src == _currentState && cond) {
            qDebug() << _currentState.stateName();
            _currentState = target;
            if (callback != nullptr) {
                callback();
            }
            return true;
        }
        return false;
    }
};

#endif // FSM_H
