#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    QList<QPushButton *> *buttons = new QList<QPushButton *>();
    buttons->append(ui->pushButton_0);
    buttons->append(ui->pushButton_1);
    buttons->append(ui->pushButton_2);
    buttons->append(ui->pushButton_3);
    buttons->append(ui->pushButton_4);
    buttons->append(ui->pushButton_5);
    buttons->append(ui->pushButton_6);
    buttons->append(ui->pushButton_7);
    buttons->append(ui->pushButton_8);
    buttons->append(ui->pushButton_9);
}
void MainWindow::print_symbol(int arg1)
{
    QString text2;
    num_clicked=true;
    if (!rezult_clicked)
    {
        argument[index]+=text2.setNum(arg1);
        argument[2]+=text2.setNum(arg1);
    }
    else
    {
        argument[index]=text2.setNum(arg1);
        argument[2]=text2.setNum(arg1);
    }
    argument[3]=argument[2];
    arg[index]=argument[index].toDouble();
    refresh_lines();
}

void MainWindow::on_pushButton_0_clicked()
{
    print_symbol(0);
}


void MainWindow::on_pushButton_1_clicked()
{
    print_symbol(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    print_symbol(2);
}


void MainWindow::on_pushButton_3_clicked()
{
    print_symbol(3);
}


void MainWindow::on_pushButton_4_clicked()
{
    print_symbol(4);
}


void MainWindow::on_pushButton_5_clicked()
{
    print_symbol(5);
}


void MainWindow::on_pushButton_6_clicked()
{
    print_symbol(6);
}


void MainWindow::on_pushButton_7_clicked()
{
    print_symbol(7);
}


void MainWindow::on_pushButton_8_clicked()
{
    print_symbol(8);
}


void MainWindow::on_pushButton_9_clicked()
{
    print_symbol(9);
}

void MainWindow::refresh_lines()
 {
     ui->lineEdit->setText(argument[index]);
     ui->textEdit->setText(argument[2]);
     rezult_clicked=false;
 }
void MainWindow::on_pushButton_plus_clicked()
{
    if (num_clicked)
    {
        argument[2]+="+";
    }

    num_clicked=false;

    if(!index /*&& !oper*/)
    {
        arg[0]=argument[0].toDouble();
        index=1;
    }
    else /*if (!oper)*/
    {
//        arg[index]=text1.toDouble();
        arg[1]=argument[1].toDouble();
        arg[0]+=arg[1];
        argument[0].setNum(arg[0]);
        argument[1].clear();
        arg[1]=0;
    }

    oper=1;//+
    ui->lineEdit->setText(argument[0]);
    ui->textEdit->setText(argument[2]);
}


void MainWindow::on_pushButton_C_clicked()
{
    num_clicked=false;
    ui->lineEdit->clear();
    arg[0]=arg[1]=0;
    argument[0].clear();
    argument[1].clear();
    argument[2].clear();
    argument[3].clear();
    oper=index=0;
    Rezult=0;
    ui->textEdit->clear();
}


void MainWindow::on_pushButton_rezult_clicked()
{
    if (!rezult_clicked)
    {
        QString text1;
        switch (oper)
        {
            case 0://+
            {
                break;
            }
            case 1://+
            {
                Rezult=arg[0]+arg[1];
                break;
            }
            case 2://-
            {
                Rezult=arg[0]-arg[1];
                break;
            }
            case 3://*
            {
                Rezult=arg[0]*arg[1];
                break;
            }
            case 4:// /
            {
                Rezult=arg[0]/arg[1];
                break;
            }
        }
        ui->lineEdit->setText(text1.setNum(Rezult));
        argument[0].setNum(Rezult);
        arg[0]=Rezult;
        if (num_clicked)
        {
            argument[2]+="="+text1;
            argument[3]=argument[2];
        }
        else
        {
            argument[2]=argument[3]+"="+text1;
        }
        num_clicked=false;

        ui->textEdit->setText(argument[2]);
        arg[1]=0;
        argument[1].clear();
        oper=0;
        Rezult=0;
        index=1;
        rezult_clicked=true;
    }

}


void MainWindow::on_pushButton_CE_clicked()
{
    num_clicked=false;
    ui->lineEdit->clear();
    arg[1]=0;
    argument[1].clear();
    argument[2]=argument[3];
    ui->textEdit->setText(argument[2]);
}


void MainWindow::on_pushButton_minus_clicked()
{


    argument[2]+="-";
    if(!index /*&& !oper*/)
    {
        arg[0]=argument[0].toDouble();
        index=1;
    }
    else /*if (!oper)*/
    {
        if (num_clicked)
        {
            arg[1]=argument[1].toDouble();
            arg[0]-=arg[1];
            argument[0].setNum(arg[0]);
            argument[1].clear();
//            arg[1]=0;
        }
        else
        {
          arg[0]=arg[1];
        }

    }
    oper=2;//-
    ui->lineEdit->setText(argument[0]);
    ui->textEdit->setText(argument[2]);
    argument[3]=argument[2];
     num_clicked=false;
}



void MainWindow::on_pushButton_incr_clicked()
{
    argument[2]+="*";
    if(!index /*&& !oper*/)
    {
        arg[0]=argument[0].toDouble();
        index=1;
    }
    else /*if (!oper)*/
    {
        if (num_clicked)
        {
            arg[1]=argument[1].toDouble();
            arg[0]=arg[0]*arg[1];
            argument[0].setNum(arg[0]);
            argument[1].clear();
//            arg[1]=0;
        }
        else
        {
          arg[0]=arg[1];
        }
    }

    oper=3;//+
    ui->lineEdit->setText(argument[0]);
    ui->textEdit->setText(argument[2]);
    argument[3]=argument[2];
    num_clicked=false;

}


void MainWindow::on_pushButton_decr_clicked()
{
    argument[2]+="/";
    if(!index /*&& !oper*/)
    {
        arg[0]=argument[0].toDouble();
        index=1;
    }
    else /*if (!oper)*/
    {
        if (num_clicked)
        {
            arg[1]=argument[1].toDouble();
            arg[0]=arg[0]/arg[1];
            argument[0].setNum(arg[0]);
            argument[1].clear();
//            arg[1]=1;
        }
        else
        {
          arg[0]=arg[1];
        }
    }

    oper=3;//+
    ui->lineEdit->setText(argument[0]);
    ui->textEdit->setText(argument[2]);
    argument[3]=argument[2];
    num_clicked=false;

}


void MainWindow::on_pushButton_del_clicked()
{
    if (num_clicked)
    {
        argument[1].resize(argument[1].size() - 1);
        argument[0].resize(argument[0].size() - 1);
        argument[2].resize(argument[2].size() - 1);
        ui->lineEdit->setText(argument[0]);
        ui->textEdit->setText(argument[2]);
        arg[1]=argument[1].toDouble();
    }

}



void MainWindow::keyPressEvent(QKeyEvent *e)
{
//    if (e->key() == Qt::Key_0)
//    {
//        on_pushButton_0_clicked();
//    }
    switch (e->key())
    {
    case Qt::Key_0:
    {
        on_pushButton_0_clicked();
        break;
    }
    case Qt::Key_1:
    {
        on_pushButton_1_clicked();
        break;
    }
    case Qt::Key_2:
    {
        on_pushButton_2_clicked();
        break;
    }
    case Qt::Key_3:
    {
        on_pushButton_3_clicked();
        break;
    }
    case Qt::Key_4:
    {
        on_pushButton_4_clicked();
        break;
    }
    case Qt::Key_5:
    {
        on_pushButton_5_clicked();
        break;
    }
    case Qt::Key_6:
    {
        on_pushButton_6_clicked();
        break;
    }
    case Qt::Key_7:
    {
        on_pushButton_7_clicked();
        break;
    }
    case Qt::Key_8:
    {
        on_pushButton_8_clicked();
        break;
    }
    case Qt::Key_9:
    {
        on_pushButton_9_clicked();
        break;
    }
    case Qt::Key_Backspace:
    {
        on_pushButton_del_clicked();
        break;
    }
    case Qt::Key_Plus:
    {
        on_pushButton_plus_clicked();
        break;
    }
    case Qt::Key_Minus:
    {
        on_pushButton_minus_clicked();
        break;
    }
    case Qt::Key_Slash:
    {
        on_pushButton_decr_clicked();
        break;
    }
    case Qt::Key_Enter:
    {
        on_pushButton_rezult_clicked();
        break;
    }
    }
}

