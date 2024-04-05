#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"
#include <QtGlobal>
#include "QRandomGenerator"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::sredniaArytmetycznaFun(){

    float buffor = 0;

    for(int i = 0; i < liczby_join.length(); i++){
        buffor += liczby_join[i];
        sredniaArytmetyczna = buffor / liczby_join.length();
    }

    return 0;

}


MainWindow::WygenerujLiczby(){

    QRandomGenerator random;


    for(int i = 0; i < 10; i++){

        int losowaLiczba = random.bounded(0, 100);
        MainWindow::liczby_1.append(losowaLiczba);
        ui->listWidget->addItem(QString::number(liczby_1[i]));
    }

    for(int i = 0; i < 10; i++){
        int losowaLiczba = random.bounded(0, 100);
        MainWindow::liczby_2.append(losowaLiczba);
        ui->listWidget_2->addItem(QString::number(liczby_2[i]));
    }

    for(int i = 0; i < liczby_1.length(); i++){
        liczby_join.append(liczby_1[i]);
    }
    for(int i = 0; i < liczby_2.length(); i++){
        liczby_join.append(liczby_2[i]);
    }


    for(int i = 0; i < liczby_join.length(); i++){
        qDebug() << liczby_join[i];
    }

    return 0;

    sredniaArytmetycznaFun();

}

MainWindow::OdchylenieStandardowe(){

    float buffor = 0;

    for(int i = 0; i < liczby_join.length(); i++){

        buffor += pow(liczby_join[i] - sredniaArytmetyczna , 2) / liczby_join.length();
        wariacja = sqrt(buffor);
    }



   ui->odchylenie->setNum(wariacja);

   return 0;
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_clicked()
{
    WygenerujLiczby();
    OdchylenieStandardowe();
}



