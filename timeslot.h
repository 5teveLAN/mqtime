#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <QString>
#include <QStringList>

class TimeSlot
{
private:
    QString m_time;
    int m_score;
    QStringList m_voters; // Replaced vector<string> with QStringList

public:
    // Explicit default constructor
    TimeSlot() = default;

    // Custom initialization constructor
    TimeSlot(const QString &time)
        : m_time(time)
        , m_score(0)
    {}

    // Public Methods
    void addVote(const QString &user);

    // Marked const because it only evaluates data without changing the state
    int getScore() const;

    // Getter for the specific time string
    QString getTime() const { return m_time; }
};

#endif // TIMESLOT_H