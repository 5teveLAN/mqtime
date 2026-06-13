#ifndef EVENT_H
#define EVENT_H

#include <QByteArray>
#include <QDate>
#include <QList>
#include <QString>
#include <QStringList>
#include <QTime>

#include "participant.h"
#include "timeslot.h"

class Event
{
private:
    // 活動基本資訊
    QString m_title;
    QString m_creator;

    // 日期與時間範圍
    QList<QDate> m_selectedDates;
    QTime m_startTime;
    QTime m_endTime;

    // 參與者與時段
    QList<Participant> m_participants;
    QList<TimeSlot> m_timeSlots;

public:
    Event() = default;

    // Setter
    void setTitle(const QString &title);
    void setCreator(const QString &creator);
    void setSelectedDates(const QList<QDate> &dates);
    void setTimeRange(const QTime &startTime,const QTime &endTime);

    // Getter
    QString getTitle() const;
    QString getCreator() const;
    QList<QDate> getSelectedDates() const;
    QTime getStartTime() const;
    QTime getEndTime() const;

    // Participant
    void addParticipant(const QString &name);

    QList<Participant> getParticipants() const;

    // TimeSlot
    void addTimeSlot(const QString &time);

    QList<TimeSlot> getTimeSlots() const;

    // 投票
    void vote(const QString &user,const QString &time);

    // 根據日期與時間範圍建立時段
    void createSchedule(int intervalMinutes);

    void voteAvailableTimes(const QString &user,const QList<int> &selectedIndexes);

    // 找出最佳時段
    QStringList getBestTimes() const;

    QByteArray toJson() const;
    bool fromJson(const QByteArray &data);
};

#endif // EVENT_H