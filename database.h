#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include "ticket.h"
#include "tour.h"
#include "tourist.h"

class DatabasePresent;

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    ~Database();
    void add_tour(Tour *tour);
    void add_tourist(Tourist *tourist);
    void add_ticket(Ticket *ticket);

    void delete_tour(int ID);
    void delete_tourist(int ID);
    void delete_ticket(int ID);

    DatabasePresent *constructPresent(int i);
    //Метод для создания объекта класса DatabasePresent

signals:
    void notifyTourTableChange();
    void notifyTouristTableChange();
    void notifyTicketTableChange();

private:
    QVector<Ticket *> ticket_array;
    QVector<Tour *> tour_array;
    QVector<Tourist *> tourist_array;
};

#include "databasepresent.h"

#endif // DATABASE_H
