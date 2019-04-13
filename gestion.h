#ifndef GESTION_H
#define GESTION_H

#include "capteurs.h"
#include "lampes.h"
#include <vector>



class jardin
{
private:
    long id;
    bool etat;
public:
    long getid(){return id;}
    void setid(long a){id = a;}
    bool getetat(){return etat;}
    void setetat(bool a){etat = a;}


};




#endif // GESTION_H
