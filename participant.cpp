#include "participant.h"

Participant::Participant(const QString &name)
    : m_name(name)
{
}

void Participant::vote(const QString &time)
{
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