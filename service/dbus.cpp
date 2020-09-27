//
// Created by linux on 5/22/17.
//

#include "dbus.h"
#include "PolicyKitHelper.h"
#include <QDebug>
#include <QtCore/QFile>
#include <unistd.h>

dbus::dbus(QObject *parent) :
    QObject(parent){

}

QString dbus::echo(qint64 PID) {
    if(PolicyKitHelper::instance()->checkAuthorization("com.polkit.qt.example.echo", PID)){
        return tr("Hello DBus");
    }else{
        return tr("无权限");
    }

}


