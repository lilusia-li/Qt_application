#include "database.h"

Database::Database(QObject *parent)
    : QObject{parent}
{
    Tour *tour = new Tour("Греция", 1, "20.12.2023-27.12.2023", 100000);
    tour_array.push_back(tour);
    Tour *tour1 = new Tour("Испания", 2, "20.01.2024-27.01.2024", 200000);
    tour_array.push_back(tour1);
    Tour *tour2 = new Tour("США", 3, "01.02.2024-08.02.2024", 150000);
    tour_array.push_back(tour2);
    Tour *tour3 = new Tour("Япония", 4, "15.02.2024-23.02.2024", 300000);
    tour_array.push_back(tour3);

    Tourist *tourist = new Tourist(11, "02.10.2002", "Федоров Василий Иванович");
    Tourist *tourist1 = new Tourist(22, "12.01.2000", "Осипов Валерий Владимирович");
    Tourist *tourist2 = new Tourist(33, "01.11.2001", "Архипов Владислав Викторович");
    tourist_array.push_back(tourist);
    tourist_array.push_back(tourist1);
    tourist_array.push_back(tourist2);

    Ticket *ticket = new Ticket(1, 11, "01.12.2023", 111);
    Ticket *ticket1 = new Ticket(2, 22, "01.12.2023", 222);
    Ticket *ticket2 = new Ticket(3, 33, "01.12.2023", 333);
    ticket_array.push_back(ticket);
    ticket_array.push_back(ticket1);
    ticket_array.push_back(ticket2);
}

Database::~Database()
{

}

void Database::add_tour(Tour *tour)
{
    tour_array.push_back(tour);
    emit notifyTourTableChange();
}
void Database::add_tourist(Tourist *tourist)
{
    tourist_array.push_back(tourist);
    emit notifyTouristTableChange();
}
void Database::add_ticket(Ticket *ticket)
{
    ticket_array.push_back(ticket);
    emit notifyTicketTableChange();
}


void Database::delete_tour(int ID)
{
    for (auto it = tour_array.begin(); it != tour_array.end(); ++it)
    {
        if ((*it)->getID() == ID)
        {
            tour_array.erase(it);
            break;
        }
    }
    emit notifyTourTableChange();
}
void Database::delete_tourist(int ID)
{
    for (auto it = tourist_array.begin(); it != tourist_array.end(); ++it)
    {
        if ((*it)->getID() == ID)
        {
            tourist_array.erase(it);
            break;
        }
    }
    emit notifyTouristTableChange();
}
void Database::delete_ticket(int ID)
{
    for (auto it = ticket_array.begin(); it != ticket_array.end(); ++it)
    {
        if ((*it)->getTicketID() == ID)
        {
            ticket_array.erase(it);
            break;
        }
    }
    emit notifyTicketTableChange();
}

DatabasePresent* Database::constructPresent(int i) //Метод для создания указателя на новый объект класса DatabasePresent
{
    DatabasePresent* present = new DatabasePresent(&ticket_array, &tour_array, &tourist_array, this);
    if (i == 1)
        connect(this, SIGNAL(notifyTourTableChange()), present, SLOT(notifyTourTable()));
    if (i == 2)
        connect(this, SIGNAL(notifyTouristTableChange()), present, SLOT(notifyTouristTable()));
    if (i == 3)
        connect(this, SIGNAL(notifyTicketTableChange()), present, SLOT(notifyTicketTable()));
    return present;
}
