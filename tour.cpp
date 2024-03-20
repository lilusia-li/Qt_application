#include "tour.h"

Tour::Tour(QObject *parent)
    : QObject{parent}
{

}

Tour::Tour(QString location, int ID, QString time, int cost)
{
    tour_location = location;
    tour_ID = ID;
    tour_time = time;
    tour_cost = cost;
}

Tour::~Tour() {}
