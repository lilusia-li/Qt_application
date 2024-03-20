#ifndef TICKETS_H
#define TICKETS_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Tickets;
}

class Tickets : public QWidget
{
    Q_OBJECT

public:
    explicit Tickets(QWidget *parent = nullptr);
    ~Tickets();
    void setDatabasePresent(DatabasePresent*);
public slots:
    void updateTicketTable();
private slots:

    void on_addTicket_clicked();
    void on_delTicket_clicked();

private:
    Ui::Tickets *ui;
    DatabasePresent* present = nullptr;
};

#endif // TICKETS_H
