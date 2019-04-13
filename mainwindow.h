#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QLCDNumber>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlQueryModel* affichage();



private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QLCDNumber *m_lcd;
    QString login;
    QString mp;
    QMediaPlayer *music;

};

#endif // MAINWINDOW_H
