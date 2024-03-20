#include "tourist_add_form.h"
#include "ui_tourist_add_form.h"
#include <QValidator>
#include <QMessageBox>

Tourist_add_form::Tourist_add_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tourist_add_form)
{
    ui->setupUi(this);
    ui->tourist_ID_input->setValidator(new QIntValidator);
}

Tourist_add_form::~Tourist_add_form()
{
    delete ui;
    delete present;
}

void Tourist_add_form::on_addition_clicked()
{
    //Получаем значения из формы
    int touristID = ui->tourist_ID_input->text().toInt();

    //Проверка на то, есть ли уже турист с таким ID
    const QVector<Tourist *>* vec_tourist = present->get_tourist_array();
    for (auto it = vec_tourist->begin(); it != vec_tourist->end(); ++it)
    {
        if ((*it)->getID() == touristID)
        {
            QMessageBox::critical(this, "Ошибка!", "Турист с таким ID уже существует");
            return;
        }
    }
    Tourist* tourist = new Tourist(touristID, ui->tourist_birthday_input->text(), ui->tourist_name_input->text());
    present->add_tourist(tourist);
    //в конце
    close();
}

void Tourist_add_form::setDatabasePresent(DatabasePresent* pr)
{
    present = pr;
}
