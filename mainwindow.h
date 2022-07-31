#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double_t Rezult=0, arg[2]={0,0};
    qint16 index=0, oper=0;
    QString argument[5];
    bool num_clicked=false, rezult_clicked=false;


private slots:
    void print_symbol(int arg1);

    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_rezult_clicked();

    void on_pushButton_CE_clicked();
    void refresh_lines();

    void on_pushButton_minus_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
