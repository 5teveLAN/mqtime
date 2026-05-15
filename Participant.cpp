#include "Participant.h"

// Using the member initialization list with m_ prefix
Participant::Participant(const QString &name)
    : m_name(name)
{}

void Participant::vote(const QString &time)
{
    // QStringList (and QList) uses append() or << operator
    m_availableTimes.append(time);
}

QString Participant::name() const
{
    return m_name;
}

QStringList Participant::availableTimes() const
{
    return m_availableTimes;
}