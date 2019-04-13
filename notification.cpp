#include"notification.h"
#include <QDebug>

notification::notification()
{
      num=0;
}

bool notification::notification_ajout(QString number)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon();


    notifyIcon->setIcon(QIcon("dollar.bmp"));
    //notifyIcon->showMessage("Reclamation","le capteur d'humidité num "+number+" a dépasser le taux",QSystemTrayIcon::Warning,300000);
    notifyIcon->showMessage("Alerte","capteur numero "+number+" a depassé le taux ",QSystemTrayIcon::Information,15000);

    notifyIcon->setToolTip(QString("Humidité au capteur num "+number+" Inférieure au taux"));
    qDebug()<<"notif :" <<notifyIcon->isSystemTrayAvailable();
    notifyIcon->setVisible(true);
    notifyIcon->show();
    num++;
    return true;
}
