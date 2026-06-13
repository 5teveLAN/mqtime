#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QString>
#include <QStringList>

class Participant
{
private:
    QString m_name;
    QStringList m_availableTimes;

public:
    Participant() = default;

    explicit Participant(const QString &name);

    void vote(const QString &time);

    QString name() const;

    QStringList availableTimes() const;
};

#endif // PARTICIPANT_H