#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include<QString>
#include <QSystemTrayIcon>
#include <QDebug>

class notification
{
        private:
        int num;
        //QSystemTrayIcon *notifyIcon;
        public:
        notification();
        bool notification_ajout(QString);

};

#endif // NOTIFICATION_H
