#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include "eventhandler.h"
class MainWindow;
class EventHandler; // for initConnections(MainWindow *window)
class Session : public QObject
{
    Q_OBJECT
private:
    QString m_username;
    EventHandler *m_eventHandler;
    QString m_inviteCode;
    MainWindow *m_mainWindow;
    bool m_isHost;
    void setRole(bool isHost);

    void initConnections();

public:
    Session(MainWindow *window);
    QString getCurrentUser();
signals:
    // Page 1
    void roleSetupSuccessed(bool isHost);

public slots:
    // Page 1
    void onRoleSelected(QString username, bool isHost);

};

#endif // SESSION_H
