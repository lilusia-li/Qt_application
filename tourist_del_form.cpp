#include "tourist_del_form.h"
#include "ui_tourist_del_form.h"
#include <QValidator>
#include <QMessageBox>

Tourist_del_form::Tourist_del_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tourist_del_form)
{
    ui->setupUi(this);
    ui->tourist_ID_input->setValidator(new QIntValidator);

}

Tourist_del_form::~Tourist_del_form()
{
    delete ui;
    delete present;
}

void Tourist_del_form::on_tourist_delete_clicked()
{
    //Получаем значения из формы
    int touristID = ui->tourist_ID_input->text().toInt();

    //Проверка на то, есть ли турист с таким ID в БД
    const QVector<Tourist *>* vec_tourist = present->get_tourist_array();

    bool flag = false;
    for (auto it = vec_tourist->begin(); it != vec_tourist->end(); ++it)
    {
        if ((*it)->getID() == touristID)
            flag = true;
    }
    if (!flag)
    {
        QMessageBox::critical(this, "Ошибка!", "Туриста с введенным ID не существует в БД");
        close();
        return;
    }

    //Проверка на то, есть ли этот турист в купленных билетах
    const QVector<Ticket *>* vec_ticket = present->get_ticket_array();
    flag = false;
    for (auto it = vec_ticket->begin(); it != vec_ticket->end(); ++it)
    {
        if ((*it)->getTouristID() == touristID)
            flag = true;
    }
    if (flag)
    {
        QMessageBox::critical(this, "Ошибка!", "В БД есть купленные билеты для этого туриста.\nМы не можем его удалить");
        close();
        return;
    }

    present->delete_tourist(touristID);
    close();
}

void Tourist_del_form::setDatabasePresent(DatabasePresent* pr)
{
    present = pr;
}
