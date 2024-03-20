#include "tour_add_form.h"
#include "ui_tour_add_form.h"
#include <QValidator>
#include <QMessageBox>

Tour_add_form::Tour_add_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tour_add_form)
{
    ui->setupUi(this);
    ui->tour_ID_input->setValidator(new QIntValidator);
    ui->tour_cost_input->setValidator(new QIntValidator);
}

Tour_add_form::~Tour_add_form()
{
    delete ui;
    delete present;
}

void Tour_add_form::on_addition_clicked()
{
    //Получаем значения из формы
    int tourID = ui->tour_ID_input->text().toInt();

    //Проверка на то, есть ли уже тур с таким ID
    const QVector<Tour *>* vec_tour = present->get_tour_array();
    for (auto it = vec_tour->begin(); it != vec_tour->end(); ++it)
    {
        if ((*it)->getID() == tourID)
        {
            QMessageBox::critical(this, "Ошибка!", "Тур с таким ID уже существует");
            return;
        }
    }
    Tour* tour = new Tour(ui->tour_location_input->text(), tourID, ui->tour_time_input->text(),
                          ui->tour_cost_input->text().toInt());
    present->add_tour(tour);
    //в конце
    close();
}

void Tour_add_form::setDatabasePresent(DatabasePresent* pr)
{
    present = pr;
}

