#ifndef DATABASEPRESENT_H
#define DATABASEPRESENT_H

#include <QObject>
#include "database.h"

class DatabasePresent : public QObject
{
    Q_OBJECT
public:
    explicit DatabasePresent(QObject *parent = nullptr);
    DatabasePresent(QVector<Ticket *> *ticketArray, QVector<Tour *> *tourArray,
                    QVector<Tourist *> *touristArray, Database *base);

    void add_tour(Tour *tour);
    void add_tourist(Tourist *tourist);
    void add_ticket(Ticket *ticket);

    void delete_tour(int ID);
    void delete_tourist(int ID);
    void delete_ticket(int ID);

    const QVector<Ticket *>* get_ticket_array() { return ticket_array; }
    const QVector<Tour *>* get_tour_array() { return tour_array; }
    const QVector<Tourist *>* get_tourist_array() { return tourist_array; }

public slots:
    void notifyTourTable();
    void notifyTouristTable();
    void notifyTicketTable();

signals:
    void notifyTourTableChange(); //уведомляем наблюдателей
    void notifyTouristTableChange(); //уведомляем наблюдателей
    void notifyTicketTableChange(); //уведомляем наблюдателей

private:
    const QVector<Ticket *>* ticket_array;
    const QVector<Tour *>* tour_array;
    const QVector<Tourist *>* tourist_array;
    Database *Base; //Указатель на базу данных
};

#endif // DATABASEPRESENT_H
