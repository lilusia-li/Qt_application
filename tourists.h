#ifndef TOURISTS_H
#define TOURISTS_H

#include <QWidget>
#include "databasepresent.h"

namespace Ui {
class Tourists;
}

class Tourists : public QWidget
{
    Q_OBJECT

public:
    explicit Tourists(QWidget *parent = nullptr);
    ~Tourists();
    void setDatabasePresent(DatabasePresent*);

public slots:
    void updateTouristTable();

private slots:

    void on_addTourist_clicked();
    void on_delTourist_clicked();

private:
    Ui::Tourists *ui;
    DatabasePresent* present = nullptr;
};

#endif // TOURISTS_H
