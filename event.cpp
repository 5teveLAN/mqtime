#include "event.h"
#include "participant.h"
#include "timeslot.h"

void Event::setTitle(const QString &title)
{
    m_title = title;
}

void Event::setCreator(const QString &creator)
{
    m_creator = creator;
}

void Event::setSelectedDates(const QList<QDate> &dates)
{
    m_selectedDates = dates;
}

void Event::setTimeRange(const QTime &startTime,const QTime &endTime)
{
    m_startTime = startTime;
    m_endTime = endTime;
}

void Event::addParticipant(const QString &name)
{
    Participant participant(name);
    m_participants.append(participant);
}

void Event::addTimeSlot(const QString &time)
{
    TimeSlot slot(time);
    m_timeSlots.append(slot);
}

void Event::vote(const QString &user,const QString &time)
{
    for (Participant &participant : m_participants)
    {
        if (participant.name() == user)
        {
            participant.vote(time);
        }
    }
    for (TimeSlot &slot : m_timeSlots)
    {
        if (slot.getTime() == time)
        {
            slot.addVote(user);
        }
    }
}

QString Event::getBestTime() const
{
    int bestScore = -1;
    QString bestTime;

    for (const TimeSlot &slot : m_timeSlots)
    {
        if (slot.getVoteCount() > bestScore)
        {
            bestScore = slot.getVoteCount();
            bestTime = slot.getTime();
        }
    }

    return bestTime;
}
QString Event::getTitle() const
{
    return m_title;
}

QString Event::getCreator() const
{
    return m_creator;
}

QList<QDate> Event::getSelectedDates() const
{
    return m_selectedDates;
}

QTime Event::getStartTime() const
{
    return m_startTime;
}

QTime Event::getEndTime() const
{
    return m_endTime;
}

QList<Participant> Event::getParticipants() const
{
    return m_participants;
}

QList<TimeSlot> Event::getTimeSlots() const
{
    return m_timeSlots;
}
