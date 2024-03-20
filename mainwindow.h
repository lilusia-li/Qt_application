#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_openTours_clicked();
    void on_openTourists_clicked();
    void on_openTickets_clicked();

private:
    Ui::MainWindow *ui;
    Database Base; //оригинал базы данных
};
#endif // MAINWINDOW_H
