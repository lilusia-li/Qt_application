#ifndef TOUR_ADD_FORM_H
#define TOUR_ADD_FORM_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Tour_add_form;
}

class Tour_add_form : public QWidget
{
    Q_OBJECT

public:
    explicit Tour_add_form(QWidget *parent = nullptr);
    ~Tour_add_form();
    void setDatabasePresent(DatabasePresent*);

private slots:
    void on_addition_clicked();

private:
    Ui::Tour_add_form *ui;
    DatabasePresent* present;
};

#endif // TOUR_ADD_FORM_H
