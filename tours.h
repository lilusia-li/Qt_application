#ifndef TOURS_H
#define TOURS_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Tours;
}

class Tours : public QWidget
{
    Q_OBJECT

public:
    explicit Tours(QWidget *parent = nullptr);
    ~Tours();
    void setDatabasePresent(DatabasePresent*);

public slots:
    void updateTourTable();

private slots:

    void on_addTour_clicked();
    void on_delTour_clicked();

private:
    Ui::Tours* ui;
    DatabasePresent* present = nullptr;
};

#endif // TOURS_H
