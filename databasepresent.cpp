#include "databasepresent.h"

DatabasePresent::DatabasePresent(QObject *parent)
    : QObject{parent}
{

}

DatabasePresent::DatabasePresent(QVector<Ticket *> *ticketArray, QVector<Tour *> *tourArray,
                QVector<Tourist *> *touristArray, Database *base)
    : QObject{nullptr}
{
    ticket_array = ticketArray;
    tour_array = tourArray;
    tourist_array = touristArray;
    Base = base;
}
void DatabasePresent::notifyTourTable()
{
    emit notifyTourTableChange(); //уведомляем наблюдателей
}
void DatabasePresent::notifyTouristTable()
{
    emit notifyTouristTableChange(); //уведомляем наблюдателей
}
void DatabasePresent::notifyTicketTable()
{
    emit notifyTicketTableChange(); //уведомляем наблюдателей
}

void DatabasePresent::add_tour(Tour *tour)
{
    Base->add_tour(tour);
}
void DatabasePresent::add_tourist(Tourist *tourist)
{
    Base->add_tourist(tourist);
}
void DatabasePresent::add_ticket(Ticket *ticket)
{
    Base->add_ticket(ticket);
}

void DatabasePresent::delete_tour(int ID)
{
    Base->delete_tour(ID);
}
void DatabasePresent::delete_tourist(int ID)
{
    Base->delete_tourist(ID);
}
void DatabasePresent::delete_ticket(int ID)
{
    Base->delete_ticket(ID);
}

