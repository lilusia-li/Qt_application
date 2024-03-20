#ifndef TICKET_H
#define TICKET_H

#include <QObject>

class Ticket : public QObject
{
    Q_OBJECT
public:
    explicit Ticket(QObject *parent = nullptr);
    Ticket(int tourID, int touristID, QString datePurchase, int ticketID); //Конструктор
    ~Ticket();
    //Для получения значений полей:
    QString getDatePurchase () { return date_purchase; };
    int getTouristID () { return tourist_ID; };
    int getTourID () { return tour_ID; };
    int getTicketID () { return ticket_ID; };

private:
    int ticket_ID; //ID билета
    int tour_ID; //ID тура
    int tourist_ID; //ID туриста
    QString date_purchase; //Дата покупки
};

#endif // TICKET_H
