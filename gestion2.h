#ifndef GESTION2_H
#define GESTION2_H

#include <QWidget>
#include <QSound>
#include <QMediaPlayer>
#include "arduino.h"
#include <QTime>
#include <QThread>
#include "notification.h"

namespace Ui {
class Gestion2;
}

class Gestion2 : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion2(QWidget *parent = nullptr);
    ~Gestion2();
    bool tester();

private:
    Ui::Gestion2 *ui;
    QMediaPlayer *click;
    QTimer *timer;
    /****************************************/
    QByteArray data; // variable contenant les données reçues
    Arduino A;// objet temporaire
    notification n;
    QSystemTrayIcon *notify;


private slots:
    void on_Bouton_Ajouter_3_clicked();
    void on_Refresh_3_clicked();
    void on_BoutonRechercheL_3_clicked();
    void on_BoutonSupprimerLMP_3_clicked();
    void on_BoutonAjouter_L_3_clicked();
    void on_BoutonAfficherLMP_3_clicked();
    void on_BoutonRecherche_3_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_Type_3_textChanged(const QString &arg1);
 /**********************************************/


    void on_pushButton_clicked();
    void on_BoutonOn_clicked();
    void on_BoutonOFF_clicked();
    void on_BoutonPlus_clicked();
    void on_BoutonMoin_clicked();
    void updateLCD();
};

#endif // GESTION2_H
