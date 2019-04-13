#ifndef CAPTEURS_H
#define CAPTEURS_H
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDialog>
#include <QString>
#include <QMessageBox>

using namespace std;


class capteurs
{
private:
    QString code_C;
    QString type;
    QString emplacement;
    QString taux;
public:
    capteurs();
    capteurs(QString,QString,QString,QString);
    QString getcode(){return code_C;}
    void setcode(QString a){code_C = a;}
    QString gettype(){return type;}
    void settype(QString a){type = a;}
    QString getemplacement(){return emplacement;}
    void setemplacement(QString a){emplacement = a;}
    /*bool getetat(){return etat;}
    void setetat(bool a){etat = a;}*/
    bool ajouterCAPT();
    bool deleteCAPT(QString Code);
    QSqlQueryModel* chercherCAPT(QString Code);
    QSqlQueryModel* AffichageCAPT();
    int NombreCAPT();

};

#endif // CAPTEURS_H
