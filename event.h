#ifndef EVENT_H
#define EVENT_H

#include <QDate>
#include <QList>
#include <QString>
#include <QStringList>
#include <QTime>
#include "participant.h"
#include "timeslot.h"
class Participant;
class TimeSlot;

class Event
{
private:
    // Core descriptive metadata
    QString m_title;
    QString m_creator;

    // Structural execution boundaries
    QList<QDate> m_selectedDates; // Replaced range fields with an explicit discrete date collection
    QTime m_startTime;
    QTime m_endTime;

    // Aggregated data entity lists
    QList<Participant> m_participants;
    QList<TimeSlot> m_timeSlots;

public:
    explicit Event() = default;

    // --- Setters (Using const references to optimize system performance) ---
    void setTitle(const QString &title);
    void setCreator(const QString &creator);

    // Replaced setDateRange with a discrete date assignment routine
    void setSelectedDates(const QList<QDate> &dates);
    void setTimeRange(const QTime &startTime, const QTime &endTime);

    // --- Getters (Marked const as they are read-only properties) ---
    QString getTitle() const { return m_title; }
    QString getCreator() const { return m_creator; }
    QList<QDate> getSelectedDates() const { return m_selectedDates; }
    QTime getStartTime() const { return m_startTime; }
    QTime getEndTime() const { return m_endTime; }

    // --- Core Business Logic Operations ---
    void addParticipant(const QString &name);
    void addTimeSlot(const QString &time);
    void vote(const QString &user, const QString &time);
    QString getBestTime() const;

    // --- Data Transport Routines ---
    QByteArray toJson() const;
    bool fromJson(const QByteArray &data);
};

#endif // EVENT_H