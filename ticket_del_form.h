#ifndef TICKET_DEL_FORM_H
#define TICKET_DEL_FORM_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Ticket_del_form;
}

class Ticket_del_form : public QWidget
{
    Q_OBJECT

public:
    explicit Ticket_del_form(QWidget *parent = nullptr);
    ~Ticket_del_form();
    void setDatabasePresent(DatabasePresent*);

private slots:
    void on_ticket_delete_clicked();

private:
    Ui::Ticket_del_form *ui;
    DatabasePresent* present;
};

#endif // TICKET_DEL_FORM_H
