#include "tickets.h"
#include "ui_tickets.h"
#include "ticket_add_form.h"
#include "ticket_del_form.h"

Tickets::Tickets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tickets)
{
    ui->setupUi(this);
}

Tickets::~Tickets()
{
    delete ui;
    delete present;
}


void Tickets::on_addTicket_clicked()
{
    Ticket_add_form *add_form = new Ticket_add_form(nullptr);
    add_form->setDatabasePresent(present);
    add_form->show();
}


void Tickets::on_delTicket_clicked()
{
    Ticket_del_form *del_form = new Ticket_del_form(nullptr);
    del_form->setDatabasePresent(present);
    del_form->show();
}

void Tickets::setDatabasePresent(DatabasePresent* pr)
{
    if (present)
    {
        disconnect(present, SIGNAL(notifyTicketTableChange()), this, SLOT(updateTicketTable()));
    }
    present = pr;
    connect(present, SIGNAL(notifyTicketTableChange()), this, SLOT(updateTicketTable()));
}

void Tickets::updateTicketTable()
{
    ui->ticketTable->setRowCount(0); //Очистить строки
    const QVector<Ticket *>* vec_ticket = present->get_ticket_array();
    ui->ticketTable->setEditTriggers(QTableWidget::NoEditTriggers);

    for (int i = 0; i < vec_ticket->size(); i++)
    {
        ui->ticketTable->insertRow(i);
        ui->ticketTable->setItem(i, 0, new QTableWidgetItem(QString::number(vec_ticket->at(i)->getTicketID())));
        ui->ticketTable->setItem(i, 1, new QTableWidgetItem(QString::number(vec_ticket->at(i)->getTourID())));
        ui->ticketTable->setItem(i, 2, new QTableWidgetItem(QString::number(vec_ticket->at(i)->getTouristID())));
        ui->ticketTable->setItem(i, 3, new QTableWidgetItem(vec_ticket->at(i)->getDatePurchase()));
    }
}
