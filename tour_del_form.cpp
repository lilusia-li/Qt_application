#include "tour_del_form.h"
#include "ui_tour_del_form.h"
#include <QValidator>
#include <QMessageBox>

Tour_del_form::Tour_del_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tour_del_form)
{
    ui->setupUi(this);
    ui->tour_ID_input->setValidator(new QIntValidator);

}

Tour_del_form::~Tour_del_form()
{
    delete ui;
    delete present;
}


void Tour_del_form::on_tour_delete_clicked()
{
    //Получаем значения из формы
    int tourID = ui->tour_ID_input->text().toInt();

    //Проверка на то, есть ли тур с таким ID в БД
    const QVector<Tour *>* vec_tour = present->get_tour_array();

    bool flag = false;
    for (auto it = vec_tour->begin(); it != vec_tour->end(); ++it)
    {
        if ((*it)->getID() == tourID)
            flag = true;
    }
    if (!flag)
    {
        QMessageBox::critical(this, "Ошибка!", "Тура с введенным ID не существует");
        close();
        return;
    }

    //Проверка на то, есть ли этот тур в купленных билетах
    const QVector<Ticket *>* vec_ticket = present->get_ticket_array();
    flag = false;
    for (auto it = vec_ticket->begin(); it != vec_ticket->end(); ++it)
    {
        if ((*it)->getTourID() == tourID)
            flag = true;
    }
    if (flag)
    {
        QMessageBox::critical(this, "Ошибка!", "В БД есть купленные билеты на этот тур.\nМы не можем его удалить");
        close();
        return;
    }

    present->delete_tour(tourID);
    close();
}

void Tour_del_form::setDatabasePresent(DatabasePresent* pr)
{
    present = pr;
}
