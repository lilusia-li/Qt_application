#include "tours.h"
#include "ui_tours.h"
#include "tour_add_form.h"
#include "tour_del_form.h"

Tours::Tours(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tours)
{
    ui->setupUi(this);
    // регистрация слушателей
    //
}

Tours::~Tours()
{
    delete ui;
    delete present;
}

void Tours::updateTourTable()
{
    ui->tourTable->setRowCount(0); //Очистить строки

    const QVector<Tour *>* vec_tour = present->get_tour_array();
    ui->tourTable->setEditTriggers(QTableWidget::NoEditTriggers);

    for (int i = 0; i < vec_tour->size(); i++)
    {
        ui->tourTable->insertRow(i);
        ui->tourTable->setItem(i, 0, new QTableWidgetItem(QString::number(vec_tour->at(i)->getID())));
        ui->tourTable->setItem(i, 1, new QTableWidgetItem(vec_tour->at(i)->getLocation()));
        ui->tourTable->setItem(i, 2, new QTableWidgetItem(vec_tour->at(i)->getTime()));
        ui->tourTable->setItem(i, 3, new QTableWidgetItem(QString::number(vec_tour->at(i)->getCost())));
    }
}


void Tours::on_addTour_clicked()
{
    Tour_add_form *add_form = new Tour_add_form(nullptr);
    add_form->setDatabasePresent(present);
    add_form->show();
}


void Tours::on_delTour_clicked()
{
    Tour_del_form *del_form = new Tour_del_form(nullptr);
    del_form->setDatabasePresent(present);
    del_form->show();
}

void Tours::setDatabasePresent(DatabasePresent* pr)
{
    if (present)
    {
        disconnect(present, SIGNAL(notifyTourTableChange()), this, SLOT(updateTourTable()));
    }
    present = pr;
    connect(present, SIGNAL(notifyTourTableChange()), this, SLOT(updateTourTable()));
}

