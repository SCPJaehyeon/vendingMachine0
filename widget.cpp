#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>
#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
    if(money >= 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(true);
    }else if(money >= 150){
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }else if(money >= 100){
        ui->pbCoffee->setEnabled(true);
    }
    if(money < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }else if(money < 150){
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }else if(money < 200){
        ui->pbCoke->setEnabled(false);
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
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}
QString Message(int money){
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    while(money!=0){
        if(money >= 500){
            money = money - 500;
            cnt1 += 1;
        }else if (money >= 100){
            money = money - 100;
            cnt2 += 1;
        }else if (money >= 50){
            money = money - 50;
            cnt3 += 1;
        }else if (money >= 10){
            money = money - 10;
            cnt4 += 1;
        }

    }
    char msg[200];
    sprintf(msg, "500won : %d \n 100won : %d \n 50won : %d \n 10won : %d \n", cnt1, cnt2, cnt3, cnt4);
    return msg;
}
void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    QString res = Message(money);
    msg.information(nullptr,"Reset", res);
    money = 0;
    ui->lcdNumber->display(money);
}
