#include "session.h"
#include <QRandomGenerator>
#include "mainwindow.h"

Session::Session()
    : m_username("ggd")
{}
void Session::start()
{
    m_eventHandler = new EventHandler(this);
}
void Session::initConnections(MainWindow *window)
{

}
QString Session::getInviteCode()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    const int codeLength = 5;
    QString inviteCode;

    // Optimization: Pre-allocate memory for 5 characters
    inviteCode.reserve(codeLength);

    for (int i = 0; i < codeLength; ++i) {
        // Generate a secure random index
        quint32 index = QRandomGenerator::global()->bounded(
            static_cast<quint32>(possibleCharacters.length()));
        inviteCode.append(possibleCharacters.at(index));
    }

    return inviteCode;
}

void Session::setRole(bool isHost)
{
    m_isHost = isHost;
}