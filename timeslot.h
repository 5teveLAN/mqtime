#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <QString>
#include <QStringList>

class TimeSlot
{
private:
    QString m_time;
    QStringList m_voters;

public:
    TimeSlot() = default;

    explicit TimeSlot(const QString &time);
    void addVote(const QString &user);

    // Getter
    QString getTime() const;
    QStringList getVoters() const;
    int getVoteCount() const;
};

#endif // TIMESLOT_H