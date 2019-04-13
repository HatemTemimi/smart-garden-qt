#ifndef LAMPES_H
#define LAMPES_H
#include <string>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDialog>
#include <QString>
#include <QMessageBox>


using namespace std;

class lampes
{
private:
    QString code_L;
    QString emplacement;
    QString couleur;
public:
    lampes();
    lampes(QString,QString,QString);
    QString getcode(){return code_L;}
    void setcode(QString a){code_L = a;}
    QString getemplacement(){return  emplacement;}
    void setemplacement(QString a){emplacement = a;}
    QString getcouleur(){return couleur;}
    void setcouleur(QString a){couleur = a;}
    /*bool getetat(){return etat;}
    void setetat(bool a){etat = a;}*/
    QSqlQueryModel* getALLLMP();
    bool AjouterLMP();
    bool deleteLMP(QString Code);
    QSqlQueryModel* chercherLMP(QString ch);
    int NombreLMP();
};


#endif // LAMPES_H
