#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tours.h"
#include "tourists.h"
#include "tickets.h"
#include "databasepresent.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Base(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openTours_clicked()
{
    Tours *tours = new Tours(nullptr);
    tours->setDatabasePresent(Base.constructPresent(1));
    tours->show();
    tours->updateTourTable();
}


void MainWindow::on_openTourists_clicked()
{
    Tourists *tourists = new Tourists(nullptr);
    tourists->setDatabasePresent(Base.constructPresent(2));
    tourists->show();
    tourists->updateTouristTable();
}


void MainWindow::on_openTickets_clicked()
{
    Tickets *tickets = new Tickets(nullptr);
    tickets->setDatabasePresent(Base.constructPresent(3));
    tickets->show();
    tickets->updateTicketTable();
}

