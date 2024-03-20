#include "ticket.h"

Ticket::Ticket(QObject *parent)
    : QObject{parent}
{

}

Ticket::Ticket(int tourID, int touristID, QString datePurchase, int ticketID)
{
    ticket_ID = ticketID;
    tour_ID = tourID;
    tourist_ID = touristID;
    date_purchase = datePurchase;
}

Ticket::~Ticket() {}
