#include "ticket_add_form.h"
#include "ui_ticket_add_form.h"
#include <QValidator>
#include <QMessageBox>

Ticket_add_form::Ticket_add_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ticket_add_form)
{
    ui->setupUi(this);
    ui->tour_ID_input->setValidator(new QIntValidator);
    ui->tourist_ID_input->setValidator(new QIntValidator);
    ui->ticket_ID_input->setValidator(new QIntValidator);
}

Ticket_add_form::~Ticket_add_form()
{
    delete ui;
    delete present;
}

void Ticket_add_form::on_addition_clicked()
{
    //Получаем значения из формы
    int tourID = ui->tour_ID_input->text().toInt();
    int touristID = ui->tourist_ID_input->text().toInt();
    int ticketID = ui->ticket_ID_input->text().toInt();

    //Проверка на то, есть ли уже билет с таким ID
    const QVector<Ticket *>* vec_ticket = present->get_ticket_array();
    for (auto it = vec_ticket->begin(); it != vec_ticket->end(); ++it)
    {
        if ((*it)->getTicketID() == ticketID)
        {
            QMessageBox::critical(this, "Ошибка!", "Билет с таким ID уже существует");
            return;
        }
    }

    bool flag_tour = false;
    const QVector<Tour *>* vec_tour = present->get_tour_array();
    for (auto it = vec_tour->begin(); it != vec_tour->end(); ++it)
    {
        if ((*it)->getID() == tourID)
            flag_tour = true;
    }

    bool flag_tourist = false;
    const QVector<Tourist *>* vec_tourist = present->get_tourist_array();
    for (auto it = vec_tourist->begin(); it != vec_tourist->end(); ++it)
    {
        if ((*it)->getID() == touristID)
            flag_tourist = true;
    }

    if (flag_tour && flag_tourist) //Значит и данный тур и данный турист существуют в базе, и мы можем создать билет
    {
        Ticket* ticket = new Ticket(tourID, touristID, ui->date_purchase_input->text(), ticketID);
        present->add_ticket(ticket);
    }
    else
    {
        QMessageBox::critical(this, "Ошибка!", "ID тура или ID туриста отсутствует в базе");
        return;
    }

    //в конце
    close();
}

void Ticket_add_form::setDatabasePresent(DatabasePresent* pr)
{
    present = pr;
}

