#ifndef TOURIST_H
#define TOURIST_H

#include <QObject>

class Tourist : public QObject
{
    Q_OBJECT
public:
    explicit Tourist(QObject *parent = nullptr);
    Tourist(int ID, QString birthday, QString name); //Конструктор
    ~Tourist();
    //Для получения значений полей:
    QString getBirthday () { return tourist_birthday; }
    int getID () { return tourist_ID; }
    QString getName () { return tourist_name; }

private:
    int tourist_ID;
    QString tourist_birthday;
    QString tourist_name;
};

#endif // TOURIST_H
