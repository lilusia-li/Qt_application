#ifndef TOUR_H
#define TOUR_H

#include <QObject>

class Tour : public QObject
{
    Q_OBJECT
public:
    explicit Tour(QObject *parent = nullptr);
    Tour(QString location, int ID, QString time, int cost); //Конструктор
    ~Tour();
    //Для получения значений полей:
    QString getLocation () { return tour_location; };
    int getID () { return tour_ID; };
    QString getTime () { return tour_time; };
    int getCost () { return tour_cost; };

private:
    QString tour_location; //Место отдыха
    int tour_ID; //ID тура
    QString tour_time; //Период отдыха
    int tour_cost; //Стоимость путевки
};

#endif // TOUR_H
