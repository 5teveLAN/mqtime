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
class Participant;
class TimeSlot;

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

    // 參與者與時間格
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
    QString getTitle() const
    {
        return m_title;
    }

    QString getCreator() const
    {
        return m_creator;
    }

    QList<QDate> getSelectedDates() const
    {
        return m_selectedDates;
    }

    QTime getStartTime() const
    {
        return m_startTime;
    }

    QTime getEndTime() const
    {
        return m_endTime;
    }

    // Participant
    void addParticipant(const QString &name);

    // TimeSlot
    void addTimeSlot(const QString &time);

    // 一般投票
    void vote(const QString &user,const QString &time);

    // 自動建立時段
    void createSchedule(int selectDays,int timeRange);

    // UI 格子投票
    void voteAvailableTimes(const QString &user,const QList<int> &select);

    // 找最佳時間
    QString getBestTime() const;

    // JSON
    QByteArray toJson() const;

    bool fromJson(const QByteArray &data);
};

#endif // EVENT_H