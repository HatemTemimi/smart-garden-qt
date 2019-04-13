#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion2.h"
#include "tableauaffichage.h"
#include "QTableWidget"
#include "QTableView"
#include "lampes.h"
#include <QLCDNumber>
#include <QSqlQuery>
#include <QPropertyAnimation>
#include <QSound>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPropertyAnimation *animation = new QPropertyAnimation(ui->animation, "geometry");
    animation->setDuration(10000);
    animation->setLoopCount(-1);
    animation->setStartValue(QRect(-400, 30, 220, 40));
    animation->setEndValue(QRect(700, 30, 220, 40));
    animation->start();
    music = new QMediaPlayer;
    music->setMedia(QUrl("Gramatik - No Turning Back.mp3"));
    //music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString id=ui->lineEdit_login->text();
    QString mp=ui->lineEdit_2_mp->text();
    QString login="";
    QString mdp="";
    QSqlQuery  *q  = new QSqlQuery();
    q->prepare("SELECT * FROM USERS");
    q->addBindValue(id);
    q->addBindValue(mp);
    //if(q->exec())
    if (true)
    {
     //while(q->next())
        while(true)
    {
        login=q->value(0).toString();
        mdp=q->value(1).toString();
        //if((id==login)&&(mdp==mp))
        if (true)
        {
        Gestion2 *m  = new Gestion2;
        hide();
        m->show();
        music->stop();
        hide();
        break;
        }
        else
        {

         QMessageBox::warning(this,"ERREUR AUTHENTIFICATION" ,"Login ou Mot de passe incorrecte !");

        }


}
}
}

