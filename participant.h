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
    // Pass by const reference for efficiency in Qt
    explicit Participant(const QString &name);

    // Member function to record a vote
    void vote(const QString &time);

    // Getters
    QString name() const;
    QStringList availableTimes() const;
};

#endif // PARTICIPANT_H