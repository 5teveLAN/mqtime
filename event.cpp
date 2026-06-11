#include "event.h"

// --- Setters ---

void Event::setTitle(const QString &title)
{

}

void Event::setCreator(const QString &creator)
{

}

void Event::setSelectedDates(const QList<QDate> &dates)
{

}

void Event::setTimeRange(const QTime &startTime, const QTime &endTime)
{

}

// --- Core Business Logic Operations ---

void Event::addParticipant(const QString &name)
{

}

void Event::addTimeSlot(const QString &time)
{

}

void Event::vote(const QString &user, const QString &time)
{

}

QString Event::getBestTime() const
{
    return QString();
}

// --- Data Transport Routines ---

QByteArray Event::toJson() const
{
    return QByteArray();
}

bool Event::fromJson(const QByteArray &data)
{
    return false;
}