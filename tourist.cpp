#include "tourist.h"

Tourist::Tourist(QObject *parent)
    : QObject{parent}
{

}

Tourist::Tourist(int ID, QString birthday, QString name)
{
    tourist_ID = ID;
    tourist_birthday = birthday;
    tourist_name = name;
}

Tourist::~Tourist() {}
