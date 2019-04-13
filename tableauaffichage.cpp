#include "tableauaffichage.h"
#include "ui_tableauaffichage.h"

TableauAffichage::TableauAffichage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableauAffichage)
{
    ui->setupUi(this);
}

TableauAffichage::~TableauAffichage()
{
    delete ui;
}
