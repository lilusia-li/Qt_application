#ifndef TOUR_DEL_FORM_H
#define TOUR_DEL_FORM_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Tour_del_form;
}

class Tour_del_form : public QWidget
{
    Q_OBJECT

public:
    explicit Tour_del_form(QWidget *parent = nullptr);
    ~Tour_del_form();
    void setDatabasePresent(DatabasePresent*);

private slots:

    void on_tour_delete_clicked();

private:
    Ui::Tour_del_form *ui;
    DatabasePresent* present;
};

#endif // TOUR_DEL_FORM_H
