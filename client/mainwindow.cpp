//
// Created by linux on 5/22/17.
//

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "mainwindow.h"
#include "dbus_interface.h"

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent) {

    this->resize(300, 200);

    QLabel *label = new QLabel(this);
    label->setGeometry(10, 60, 300, 20);

    qDebug() << QCoreApplication::applicationPid();
    com::polkit::qt::example::dbus *dbus = new com::polkit::qt::example::dbus(
            "com.polkit.qt.example.dbus", "/", QDBusConnection::systemBus(), this);

    label->setText(dbus->echo(getpid()));
}
