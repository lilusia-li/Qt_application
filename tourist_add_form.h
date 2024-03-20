#ifndef TOURIST_ADD_FORM_H
#define TOURIST_ADD_FORM_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Tourist_add_form;
}

class Tourist_add_form : public QWidget
{
    Q_OBJECT

public:
    explicit Tourist_add_form(QWidget *parent = nullptr);
    ~Tourist_add_form();
    void setDatabasePresent(DatabasePresent*);

private slots:
    void on_addition_clicked();

private:
    Ui::Tourist_add_form *ui;
    DatabasePresent* present;
};

#endif // TOURIST_ADD_FORM_H
