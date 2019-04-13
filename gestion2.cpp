#include "gestion2.h"
#include "ui_gestion2.h"
#include "capteurs.h"
#include "tableauaffichage.h"
#include "QTableWidget"
#include "QTableView"
#include "lampes.h"
#include"notification.h"
#include <QLCDNumber>
#include "arduino.h"
#include <QTimer>




Gestion2::Gestion2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion2)
{
    ui->setupUi(this);
    capteurs* c = new capteurs;
    lampes* l = new lampes;
    click = new QMediaPlayer;
    click->setMedia(QUrl("C:/click.wav"));
    ui->lcdNumber_5->display(c->NombreCAPT());
    ui->lcdNumber_6->display(l->NombreLMP());
    tester();
    //qDebug()<<"test : "<<tester();
    n.notification_ajout("a");
    ui->taux->hide();
    ui->label_16->hide();



    /**********************/
    int ret=A.connect_arduino(); // lancer la connexion à arduino

    switch(ret)

    {

    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
    break;

    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
    break;

    case(-1):qDebug() << "arduino is not available";
        }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).

    ui->Readhumidite->display("-----");
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    timer->start();

}

Gestion2::~Gestion2()
{
    delete ui;
}

bool Gestion2::tester()
{
    notification n;
    QSqlQuery  *q  = new QSqlQuery();
    q->prepare("SELECT * FROM CAPTEURS");
    QString taux="";
    QString num;
    if(q->exec())
        {
         while(q->next())
        {
            taux=q->value(3).toString();
            num=q->value(0).toString();
            if(taux<50)
            {

              n.notification_ajout(num);
            //qDebug()<<"y : "<<buul;
            }
        }
        }
      return false;
}

void Gestion2::on_Bouton_Ajouter_3_clicked()
{
    QMediaPlayer *music = new QMediaPlayer;
    music->setMedia(QUrl("click.wav"));
    music->play();
    QString code = ui->Code_C_3->text();
    QString type = ui->Type_3->text();
    QString emp = ui->Emplacement_3->text();
    QString taux = ui->taux->text();
    capteurs *c = new capteurs(code,emp,type,taux);
    c->ajouterCAPT();
    tester();
}

void Gestion2::on_Refresh_3_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    capteurs *c = new capteurs;
    //m_lcd->display(c->NombreCAPT());
    ui->lcdNumber_5->display(c->NombreCAPT());
    click = new QMediaPlayer;
    ui->Readhumidite->display(A.read_HT_arduino());
    tester();
}

void Gestion2::on_BoutonRechercheL_3_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    QString codeL = ui->RechercheLMP_3->text();
    QTableView *T = new QTableView;
    lampes *c=new lampes();
    T->setModel(c->chercherLMP(codeL));
    T->show();
}

void Gestion2::on_BoutonSupprimerLMP_3_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    lampes *p=new lampes();
    p->deleteLMP(ui->RechercheLMP_3->text());
}

void Gestion2::on_BoutonAjouter_L_3_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    QString code = ui->Code_L_3->text();
    QString couleur = ui->Couleur_L_3->text();
    QString emplacement = ui->Emplacement_L_3->text();

    lampes *c = new lampes(code,couleur,emplacement);
    c->AjouterLMP();
}

void Gestion2::on_BoutonAfficherLMP_3_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    QTableView *T = new QTableView;
    lampes *p=new lampes();
    T->setModel(p->getALLLMP());
    T->show();
    T->setMinimumSize(320,400);
}

void Gestion2::on_BoutonRecherche_3_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    QString codeR = ui->rechercherligne_3->text();
    QTableView *T = new QTableView;
    capteurs *c=new capteurs();
    T->setModel(c->chercherCAPT(codeR));
    T->setMinimumSize(320,400);
    T->show();
}

void Gestion2::on_pushButton_8_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    QTableView *T = new QTableView;
    capteurs *p=new capteurs();
    T->setModel(p->AffichageCAPT());
    T->palette();
    T->show();
    T->setMinimumSize(320,400);
}

void Gestion2::on_pushButton_7_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    capteurs *p=new capteurs();
    p->deleteCAPT(ui->rechercherligne_3->text());
}

void Gestion2::on_pushButton_9_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    lampes* l = new lampes;
    ui->lcdNumber_6->display(l->NombreLMP());
    A.read_HT_arduino();
}

void Gestion2::on_Type_3_textChanged(const QString &arg1)
{
    QString type = ui->Type_3->text();
    QString taux ;
    if((type == "humidite")||(type == "HUMIDITE")||(type=="humidité"))
    {
        ui->taux->show();
        ui->label_16->show();
        taux = ui->taux->text();
    }
    else
    {
        ui->taux->hide();
        ui->label_16->hide();

    }
}

void Gestion2::updateLCD()
{
    capteurs *c = new capteurs;
    ui->lcdNumber_5->display(c->NombreCAPT());
    lampes* l = new lampes;
    ui->lcdNumber_6->display(l->NombreLMP());
    QString L = A.read_HT_arduino();
    //qDebug()<<L;
    if ((L!="10")&&(L!=""))
    {
        ui->Readhumidite->display(L);
    }

}

void Gestion2::on_BoutonOn_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    A.write_to_arduino("1");
}

void Gestion2::on_BoutonOFF_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    A.write_to_arduino("0");
}

void Gestion2::on_BoutonPlus_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    A.write_to_arduino("3");
}

void Gestion2::on_BoutonMoin_clicked()
{
    QMediaPlayer *clk = new QMediaPlayer;
    clk->setMedia(QUrl("click.wav"));
    clk->play();
    A.write_to_arduino("2");
}
