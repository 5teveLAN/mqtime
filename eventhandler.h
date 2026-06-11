#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include "event.h"

class Event;
class EventHandler : public QObject
{
    Q_OBJECT
private:
    Event *m_event;
    QString m_inviteCode;
    QString generateInviteCode();
    Event *joinEvent(QString inviteCode);

public:
    explicit EventHandler(QObject *parent = nullptr);

signals:
    // Page 2 (Host)
    void eventCreationSuccessed(QString inviteCode, Event *event);

    // Page 2 (Guest)
    void eventJoinSuccessed(Event *event);
    void eventJoinFailed();

    // Page 3
    void eventMatrixUpdated();

public slots:
    // Page 2 (Host)
    void onCreateEventSubmitted(QString eventName, QStringList dates, QTime startTime, QTime endTime);

    // Page 2 (Guest)
    void onJoinEventSubmitted(QString inviteCode);

    // Page 3
    void onTimeSelectionChanged(QStringList timeSlots);
};
#endif // EVENTHANDLER_H
