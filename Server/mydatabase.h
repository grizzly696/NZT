#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QList>

class mydatabase {
public:
    mydatabase();  // Конструктор

    // Методы работы с базой данных
    bool addUser(const QString &name, const QString &email);  // Добавить пользователя
    QList<QVariantList> getUsers();  // Получить список пользователей
    bool deleteUser(int id);  // Удалить пользователя по id

private:
    QSqlDatabase db;  // База данных
    void createTable();  // Создание таблицы пользователей
};

#endif // MYDATABASE_H
