#ifndef FSM_H
#define FSM_H
#include "state.h"
#include <QDebug>


class Fsm
{

    State _currentState;
    State UNKNOWN;
    State START;
    State CMD;
    State CRUD;
    State ErrCMD;
    State CRUDCMD;
    State ErrCRUDCMD;

public:
    Fsm();
    void run(QStringList tokens);

    bool IsCommand(QString token);
    bool checkState(State& src, const State& target, bool cond, FsmFn callback){
        if (src == _currentState && cond) {
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
