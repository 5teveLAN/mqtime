#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include "eventhandler.h"
#include "mqtthandler.h"
class MainWindow; // for initConnections(MainWindow *window)
class Session : public QObject
{
    Q_OBJECT
private:
    QString m_username;
    MqttHandler *m_mqttHandler;
    EventHandler *m_EventHandler;
    QString m_inviteCode;
    bool m_isHost;
    void setRole(bool isHost);

public:
    Session();
    void start();
    void initConnections(MainWindow *window);
    QString getInviteCode();
private slots:
};

#endif // SESSION_H
