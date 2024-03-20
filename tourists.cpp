#include "tourists.h"
#include "ui_tourists.h"
#include "tourist_add_form.h"
#include "tourist_del_form.h"

Tourists::Tourists(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tourists)
{
    ui->setupUi(this);
}

Tourists::~Tourists()
{
    delete ui;
    delete present;
}

void Tourists::on_addTourist_clicked()
{
    Tourist_add_form *add_form = new Tourist_add_form(nullptr);
    add_form->setDatabasePresent(present);
    add_form->show();
}


void Tourists::on_delTourist_clicked()
{
    Tourist_del_form *del_form = new Tourist_del_form(nullptr);
    del_form->setDatabasePresent(present);
    del_form->show();
}

void Tourists::setDatabasePresent(DatabasePresent* pr)
{
    if (present)
    {
        disconnect(present, SIGNAL(notifyTouristTableChange()), this, SLOT(updateTouristTable()));
    }
    present = pr;
    connect(present, SIGNAL(notifyTouristTableChange()), this, SLOT(updateTouristTable()));
}
void Tourists::updateTouristTable()
{
    ui->touristTable->setRowCount(0); //Очистить строки
    const QVector<Tourist *>* vec_tourist = present->get_tourist_array();
    ui->touristTable->setEditTriggers(QTableWidget::NoEditTriggers);

    for (int i = 0; i < vec_tourist->size(); i++)
    {
        ui->touristTable->insertRow(i);
        ui->touristTable->setItem(i, 0, new QTableWidgetItem(QString::number(vec_tourist->at(i)->getID())));
        ui->touristTable->setItem(i, 1, new QTableWidgetItem(vec_tourist->at(i)->getBirthday()));
        ui->touristTable->setItem(i, 2, new QTableWidgetItem(vec_tourist->at(i)->getName()));
    }
}
