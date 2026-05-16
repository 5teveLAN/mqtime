#ifndef EVENT_H
#define EVENT_H

#include <QList>
#include <QString>
#include <QStringList>

// Forward declarations to keep compilation fast
// (Assuming Participant and TimeSlot are defined in their own headers)
class Participant;
class TimeSlot;

class Event
{
private:
    QString m_title;
    QString m_creator;
    QList<Participant> m_participants;
    QList<TimeSlot> m_timeSlots;

public:
    // Explicit constructor
    Event() = default;

    // Public Methods
    // Using 'const QString &' avoids expensive deep-copying of string memory blocks
    void addParticipant(const QString &name);
    void addTimeSlot(const QString &time);
    void vote(const QString &user, const QString &time);
    void fromJson(const QByteArray &data);

    // Marked 'const' because it only reads the state to calculate the best time
    QString getBestTime() const;
};

#endif // EVENT_H