#ifndef TICKET_ADD_FORM_H
#define TICKET_ADD_FORM_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Ticket_add_form;
}

class Ticket_add_form : public QWidget
{
    Q_OBJECT

public:
    explicit Ticket_add_form(QWidget *parent = nullptr);
    ~Ticket_add_form();
    void setDatabasePresent(DatabasePresent*);

private slots:
    void on_addition_clicked();

private:
    Ui::Ticket_add_form *ui;
    DatabasePresent* present;
};

#endif // TICKET_ADD_FORM_H
