#include "widget.h"
#include "ui_widget.h"
#include <qmessagebox.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbmilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);

    if (money >= 100)
        ui->pbcoffee->setEnabled(true);
    else
        ui->pbcoffee->setEnabled(false);

    if (money >= 150)
        ui->pbtea->setEnabled(true);
    else
        ui->pbtea->setEnabled(false);

    if (money >= 200)
        ui->pbmilk->setEnabled(true);
    else
        ui->pbmilk->setEnabled(false);
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


void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);

}


void Widget::on_pbtea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbmilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString returnmoney;

    if (money == 0){
        mb.information(this, "반환되는 동전은", "없다 게이야");
        return;
    }
    int pb500 = money / 500;
    money %= 500;
    int pb100 = money / 100;
    money %= 100;
    int pb50 = money / 50;
    money %= 50;
    int pb10 = money / 10;


    returnmoney = "";
    if (pb500 > 0)
        returnmoney += QString("500원의 갯수는 %1 개").arg(pb500);

    if (pb100 > 0)
        returnmoney += QString("100원의 갯수는 %1 개").arg(pb100);

    if (pb50 > 0)
        returnmoney += QString("50원의 갯수는 %1 개").arg(pb50);

    if (pb10 > 0)
        returnmoney += QString("10원의 갯수는 %1 개").arg(pb10);

    mb.information(this, "반환되는 동전은", returnmoney);

    ui->lcdNumber->display(money);
    changeMoney(0);
}

