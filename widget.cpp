#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    //vending machine algorithm
    while(1){
        if(money <= 90){
            ui->pbCoffee->setEnabled(false);
            ui->pbCola->setEnabled(false);
            ui->pbTea->setEnabled(false);
            break;
        }
        else if(money >= 100 && money <= 140){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(false);
            ui->pbCola->setEnabled(false);
            break;
        }
        else if(money >= 150 && money <= 190){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbCola->setEnabled(false);
            break;
        }
        else if(money >= 200){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbCola->setEnabled(true);
            break;
        }
        break;
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10); //+10won
}

void Widget::on_pb50_clicked()
{
    changeMoney(50); //+50won
}

void Widget::on_pb100_clicked()
{
    changeMoney(100); //+100won
}

void Widget::on_pb500_clicked()
{
    changeMoney(500); //+500won
}

void Widget::on_pbCoffee_clicked()
{
    //if you push Coffee button, -100won
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    //if you push Tea button, -150won
    changeMoney(-150);
}

void Widget::on_pbCola_clicked()
{
    //if you push Cola button, -200won
    changeMoney(-200);
}

void Widget::on_pbRefund_clicked()
{
    //Refund algorithm
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    while(1){
        if(money >= 500){
            changeMoney(-500);
            w++;
        }
        else if(money >= 100){
            changeMoney(-100);
            x++;
        }
        else if(money > 40 && money <= 90){
            changeMoney(-50);
            y++;
        }
        else if(money <= 40 && money > 0){
            changeMoney(-10);
            z++;
        }
        else if(money == 0){
            //This MessageBox show refund money
            QMessageBox msg;
            msg.information(nullptr, "Thank you",
                            "500won   " + QString::number(w) + "\n"
                            + "100won   " + QString::number(x) + "\n"
                            + "50won   " + QString::number(y) + "\n"
                            + "10won   " + QString::number(z));
            break;
        }
    }
}
