#include "capteurs.h"
#include <QLCDNumber>



using namespace std;


capteurs :: capteurs()
{

    code_C = '0';
    type = '0';
    emplacement = "maison";
    taux='0';

}

capteurs :: capteurs(QString code,QString type,QString emplacement,QString taux)
{
    code_C = code;
    this->type = type;
    this->emplacement = emplacement;
    this->taux=taux;

}

bool capteurs :: ajouterCAPT()
{

    QSqlQuery q;
    q.prepare("INSERT into CAPTEURS(CODE_C, EMPLACEMENT, TYPE,TAUX) VALUES (:code, :emplacement, :type,:taux)");
    q.bindValue(":code", this->code_C);
    q.bindValue(":emplacement", this->emplacement);
    q.bindValue(":type", this->type);
    q.bindValue(":taux", this->taux);
    if (q.exec()){
        qDebug()<<"Capteur Ajoute";
        QMessageBox::information(nullptr, "Ajout effectué", "<strong> Capteur <strong> Ajouté! <strong>");

        return true;
    }
    else{
        qDebug()<<"Erreur : verifier le CODE_C";
        QMessageBox::information(nullptr, "Ajout non effecuté", " Verifiez le : <strong> CODE_C !<strong>");

        return false;
 }
}

bool capteurs :: deleteCAPT(QString code)
{
    int exist = 0;
    QSqlQuery qDelete;
    QSqlQuery qSelect;
    qDelete.prepare("DELETE from CAPTEURS where CODE_C=:code");
    qSelect.prepare("SELECT CODE_C from CAPTEURS where CODE_C = :code");
    qDelete.bindValue(":code",code);
    qSelect.bindValue(":code",code);
    //qDelete.exec();
    if(qSelect.exec())
    {
        while(qSelect.next()==true)
        {
            exist++;
        }
        if (exist == 1)
        {
        qDelete.exec();
        qDebug()<<"Capteurs Supprime";
        QMessageBox::information(nullptr, "Suppression effectué", "<strong> Capteur <strong> Supprimé! <strong>");
        return true;
        }
        else if (exist < 1)
        {
        qDebug()<<"ERREUR : Verifier Code";
        QMessageBox::information(nullptr, "Suppression non effecuté", "<strong> ERREUR: <strong> Verifiez Code !<strong>");
        return false;
        }
    }
    else return false;
}

QSqlQueryModel *capteurs::AffichageCAPT()
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM  CAPTEURS ORDER BY CODE_C");
        return model;
    }
QSqlQueryModel *capteurs :: chercherCAPT(QString ch)
{//qDebug()<<"*****"<<code;
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery;
    //q->prepare("SELECT * from CAPTEURS where CODE_C= ?");
    q->prepare("SELECT * FROM CAPTEURS WHERE CODE_C LIKE '%"+ch+"%'");
    q->addBindValue(ch);
    q->exec();
    model->setQuery(*q);
    return model;


}

/********2algo*******/////////

int capteurs :: NombreCAPT()
{
    QSqlQuery p ;
    //p->prepare("SELECT COUNT (CODE_C) FROM CAPTEURS")
    p.prepare("SELECT COUNT (*) FROM CAPTEURS");
    p.exec();
    /*int count = 0;
    while(p.next() )
    {
    count++;
    }
    qDebug()<<"*****"<<p.exec();
    qDebug()<<"*****"<<count;
    return count;*/
    p.seek(0);
    p.value(0).toInt();
    //qDebug()<<"*****"<<p.value(0).toInt();
    return p.value(0).toInt();


}
