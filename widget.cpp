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
    while(1){
        if(money <= 90){
            ui->pbCoffee->setEnabled(false);
            ui->pbCola->setEnabled(false);
            ui->pbTea->setEnabled(false);
            break;
        }
        else if(money >= 100 && money <= 140){
            ui->pbCoffee->setEnabled(true);
            break;
        }
        else if(money >= 150 && money <= 200){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            break;
        }
        else if(money > 200){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbCola->setEnabled(true);
            break;
        }
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    QMessageBox msg;
    if(money <= 90){
        msg.information(nullptr, "Not Money", "You don't have Money, Please insert coin!");
    }
    else{
        changeMoney(-100);
        }
}

void Widget::on_pbTea_clicked()
{
    QMessageBox msg;
    if(money <= 140){
        msg.information(nullptr, "Not Money", "You don't have Money, Please insert coin!");
    }
    else{
        changeMoney(-150);
    }
}

void Widget::on_pbCola_clicked()
{
    QMessageBox msg;
    if(money <= 190){
        msg.information(nullptr, "Not Money", "You don't have Money, Please insert coin!");
    }
    else{
        changeMoney(-200);
    }
}
