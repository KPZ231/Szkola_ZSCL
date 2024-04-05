#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<int> liczby_1 = QList<int>();
    QList<int> liczby_2 = QList<int>();
    QList<int> liczby_join = QList<int>();
    float wariacja = 0.0f;
    float sredniaArytmetyczna = 0.0f;
    WygenerujLiczby();
    OdchylenieStandardowe();
    sredniaArytmetycznaFun();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
