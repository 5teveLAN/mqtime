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

public:
    explicit EventHandler(QObject *parent = nullptr);

signals:
private slots:
    //a function receives QByteArray from MqttHandler, and update m_event
    void updateEvent(const QByteArray &data);
};
#endif // EVENTHANDLER_H
