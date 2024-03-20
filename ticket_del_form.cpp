#include "ticket_del_form.h"
#include "ui_ticket_del_form.h"
#include <QValidator>
#include <QMessageBox>

Ticket_del_form::Ticket_del_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ticket_del_form)
{
    ui->setupUi(this);
    ui->ticket_ID_input->setValidator(new QIntValidator);

}

Ticket_del_form::~Ticket_del_form()
{
    delete ui;
    delete present;
}

void Ticket_del_form::on_ticket_delete_clicked()
{
    //Получаем значения из формы
    int ticketID = ui->ticket_ID_input->text().toInt();

    //Проверка на то, есть ли билет с таким ID в БД
    const QVector<Ticket *>* vec_ticket = present->get_ticket_array();

    bool flag = false;
    for (auto it = vec_ticket->begin(); it != vec_ticket->end(); ++it)
    {
        if ((*it)->getTicketID() == ticketID)
            flag = true;
    }
    if (!flag)
    {
        QMessageBox::critical(this, "Ошибка!", "Билета с введенным ID не существует");
        close();
        return;
    }

    present->delete_ticket(ticketID);
    close();
}

void Ticket_del_form::setDatabasePresent(DatabasePresent* pr)
{
    present = pr;
}


