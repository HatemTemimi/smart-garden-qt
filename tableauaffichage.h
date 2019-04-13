#ifndef TABLEAUAFFICHAGE_H
#define TABLEAUAFFICHAGE_H

#include <QWidget>

namespace Ui {
class TableauAffichage;
}

class TableauAffichage : public QWidget
{
    Q_OBJECT

public:
    explicit TableauAffichage(QWidget *parent = nullptr);
    ~TableauAffichage();

private:
    Ui::TableauAffichage *ui;
};

#endif // TABLEAUAFFICHAGE_H
