#ifndef STATE_H
#define STATE_H
#include <QString>
#include <QDebug>
typedef void (*FsmFn)();

class State{
    static int _currentIndex;
    int _id = 0;
    QString _stateName = "";


public:

    State(QString stateName = "UNKNOWN"): _stateName(stateName){

        _id = _currentIndex;
        _currentIndex++;
    }

    bool operator == ( const State& st1) {
       return st1._stateName == _stateName;
    }


    QString stateName() const;
    void setStateName(const QString &newStateName);
    int id() const;
    void setId(int newId);
};

#endif // STATE_H
