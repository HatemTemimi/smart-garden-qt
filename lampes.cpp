#include "lampes.h"
#include <string>


using namespace std;


lampes :: lampes ()
{
    code_L = "1";
    emplacement = "maison";
    couleur = "1";
}

lampes :: lampes (QString code,QString emp,QString coul)
{
    this->code_L = code;
    this->couleur = emp;
    this->emplacement = coul;
}

QSqlQueryModel *lampes::getALLLMP()
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM  LAMPES ORDER BY CODE_L");
        return model;
    }

bool lampes :: AjouterLMP()
{

    QSqlQuery q;
    q.prepare("INSERT into LAMPES(CODE_L, COULEUR, EMPLACEMENT) VALUES (:code, :couleur, :emplacement)");
    q.bindValue(":code", this->code_L);
    q.bindValue(":couleur", this->couleur);
    q.bindValue(":emplacement", this->emplacement);
    if (q.exec()){
        qDebug()<<"Lampe Ajouté";
        QMessageBox::information(nullptr, "Ajout effectué", "<strong> Lampe <strong> Ajoutée! <strong>");

        return true;
    }
    else{
        qDebug()<<"Lampe non Ajouté";
        QMessageBox::information(nullptr, "Ajout non effecuté", "<strong> Verifiez <strong> CODE_L !<strong>");

        return false;
 }
}

bool lampes :: deleteLMP(QString code)
{
    int exist = 0;
    QSqlQuery qDelete;
    QSqlQuery qSelect;
    qDelete.prepare("DELETE from LAMPES where CODE_L=:code");
    qSelect.prepare("SELECT CODE_L from LAMPES where CODE_L = :code");
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
        qDebug()<<"Lampe Supprime";
        QMessageBox::information(nullptr, "Suppression effectué", "<strong> Lampe <strong> Supprimé! <strong>");
        return true;
        }
        else if (exist < 1)
        {
        qDebug()<<"ERREUR:Verifier Code";
        QMessageBox::information(nullptr, "Suppression non effecuté", "<strong> ERREUR: <strong> Verifiez Code<strong>");
        return false;
        }
    }
    else return false;
}

QSqlQueryModel *lampes :: chercherLMP(QString ch)
{//qDebug()<<"*****"<<code;
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery;
    //q->prepare("SELECT * from CAPTEURS where CODE_C= ?");
    q->prepare("SELECT * FROM LAMPES WHERE CODE_L LIKE '%"+ch+"%'");
    q->addBindValue(ch);
    q->exec();
    model->setQuery(*q);
    return model;
}

int lampes :: NombreLMP()
{
    QSqlQuery p ;
    //p->prepare("SELECT COUNT (CODE_C) FROM CAPTEURS")
    p.prepare("SELECT COUNT (*) FROM LAMPES");
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
