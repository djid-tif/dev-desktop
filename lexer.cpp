#include "lexer.h"
#include "qregularexpression.h"


Lexer::Lexer(Fsm *fsm):fsm(fsm)
{

}

QString Lexer::prompt() const
{
    return m_prompt;
}

void Lexer::setPrompt(const QString &newPrompt)
{
    m_prompt = newPrompt;
    m_tokens = stringToList(m_prompt);
}

void Lexer::compute()
{
    fsm->run(m_tokens);
}

/**
 * @brief stringToList
 * @abstract split a string as list with double quotes (") handling
 * @param line
 * @return QStringList
 */

QStringList Lexer::stringToList(const QString str)
{
//    qDebug() << __FUNCTION__ << str;
//    QStringList list;


//    static QRegularExpression rx("\"([^\"]*)\"");
//    QRegularExpressionMatchIterator matchIterator = rx.globalMatch(str);
//    qDebug() << __FUNCTION__ << "test 2";

//    while (matchIterator.hasNext()) {
//        qDebug() << __FUNCTION__ << "test 3";
//        QRegularExpressionMatch match = matchIterator.next();
//        QString word = match.captured(1);
//        list.append(word);
//    }

    return str.split(" ");;

}
