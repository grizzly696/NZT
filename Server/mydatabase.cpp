#include "mydatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

mydatabase::mydatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database connected successfully";
        createTable();
    }
}

void mydatabase::createTable() {
    QSqlQuery query;
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS users ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "name TEXT NOT NULL,"
                               "email TEXT UNIQUE NOT NULL);";
    if (!query.exec(createTableQuery)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
    }
}

bool mydatabase::addUser(const QString &name, const QString &email) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (name, email) VALUES (:name, :email)");
    query.bindValue(":name", name);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Failed to add user:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<QVariantList> mydatabase::getUsers() {
    QList<QVariantList> users;
    QSqlQuery query("SELECT id, name, email FROM users");
    while (query.next()) {
        QVariantList user;
        user << query.value(0) << query.value(1) << query.value(2);
        users.append(user);
    }
    return users;
}

bool mydatabase::deleteUser(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to delete user:" << query.lastError().text();
        return false;
    }
    return true;
}
