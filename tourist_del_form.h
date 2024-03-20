#ifndef TOURIST_DEL_FORM_H
#define TOURIST_DEL_FORM_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Tourist_del_form;
}

class Tourist_del_form : public QWidget
{
    Q_OBJECT

public:
    explicit Tourist_del_form(QWidget *parent = nullptr);
    ~Tourist_del_form();
    void setDatabasePresent(DatabasePresent*);

private slots:
    void on_tourist_delete_clicked();

private:
    Ui::Tourist_del_form *ui;
    DatabasePresent* present;
};

#endif // TOURIST_DEL_FORM_H
