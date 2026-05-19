#include "timeslot.h"

TimeSlot::TimeSlot(const QString &time)
    : m_time(time)
{
}

void TimeSlot::addVote(const QString &user)
{
    m_voters.append(user);
}

QString TimeSlot::getTime() const
{
    return m_time;
}

QStringList TimeSlot::getVoters() const
{
    return m_voters;
}

int TimeSlot::getVoteCount() const
{
    return m_voters.size();
}