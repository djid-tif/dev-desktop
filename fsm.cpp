#include "fsm.h"

Fsm::Fsm()
{
    UNKNOWN.setStateName("UNKNOWN");
    START.setStateName("START");
    CMD.setStateName("CMD");
    ErrCMD.setStateName("ErrCMD");
    CRUDCMD.setStateName("CRUDCMD");
    ErrCRUDCMD.setStateName("ErrCRUDCMD");
}

void Fsm::run(QStringList tokens)
{

    checkState(UNKNOWN, START, 1, [](){
        qDebug("fsm Started");
    });
    qDebug() << "tokens : " << tokens.size();
    for (int i = 0; i < tokens.size(); i++)  {
        QString currentToken = tokens[i];

        checkState(START, CMD, IsCommand(currentToken), [](){
            qDebug() << "CMD STATE";
        });
    }
}

bool Fsm::IsCommand(QString token) {
    QStringList commands = {"SEARCH", "INDEXER", "CRUD"};
    return commands.contains(token);
}
