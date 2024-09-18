#include "result.h"
#include "ui_result.h"

#include <math.h>

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}

Result::~Result()
{
    delete ui;
}

void Result::setText() {
    if (isEven) {
        ui->equation->setText("f(x) = " + QString::number(ceil((double) num / 2)) + " * x<span style='vertical-align:super;'>2</span> + log(x)");
    } else {
        ui->equation->setText("f(x) = " + QString::number(ceil((double) num / 2)) + " * x - log(x)");
    }
    ui->equation->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
    ui->equation->setAlignment(Qt::AlignCenter);
    ui->accuracy->setText(QString::number(e));
    ui->accuracy->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
    ui->interval->setText("[" + QString::number(startA) + "; " + QString::number(startB) + "]");
    ui->interval->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
    if (hasMin) {
        ui->minPoint->setText("x<span style='vertical-align:sub;'>min</span> = " + QString::number(x));
        ui->minPoint->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
        ui->minFunc->setText("f(x<span style='vertical-align:sub;'>min</span>) = " + QString::number(min));
        ui->minFunc->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
        ui->steps->setText(QString::number(steps) + " шагов");
        ui->steps->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
    } else {
        ui->minPoint->setText("не найдена");
        ui->minPoint->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
        ui->minFunc->setText("не найден");
        ui->minFunc->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
        ui->steps->setText("—");
        ui->steps->setStyleSheet("QLabel {font-size:10pt; color:#aa0000;}");
    }
}

void Result::setValues(int num, double a, double b, double e) {
    this->num = num;
    this->startA = a;
    this->startB = b;
    this->a = a;
    this->b = b;
    this->e = e;
    Result::isNumEven(this->num);
}

void Result::isNumEven(int num) {
    if (num % 2 == 0) {
        isEven = true;
    } else {
        isEven = false;
    }
    Result::calculations();
}

double Result::funcEven(double x) {
    double c = ceil((double) num / 2);
    return 2 * c * x + 1 / x;
}

double Result::funcOdd(double x) {
    double c = ceil((double) num / 2);
    return c - 1 / x;
}

void Result::calculations() {
    steps = 0;

    if (isEven) {
        if (funcEven(a) * funcEven(b) >= 0) {
            ui->calculationsOut->append("Условие сходимости не выполнено.");
            ui->calculationsOut->append("На данном интервале нет минимума.");
            hasMin = false;
        }
    } else {
        if (funcOdd(a) * funcOdd(b) >= 0) {
            ui->calculationsOut->append("Условие сходимости не выполнено.");
            ui->calculationsOut->append("На данном интервале нет минимума.");
            hasMin = false;
        }
    }

    if (hasMin) {
        while (fabs(b - a) > e) {
            x = (a + b) / 2;
            ui->calculationsOut->append("Шаг " + QString::number(steps + 1) + ". x<span style='vertical-align:sub;'>min</span> = " + QString::number(x));
            if (isEven) {
                if (Result::funcEven(x - e) < Result::funcEven(x + e)) {
                    b = x;
                } else {
                    a = x;
                }
            } else {
                if (Result::funcOdd(x - e) < Result::funcOdd(x + e)) {
                    b = x;
                } else {
                    a = x;
                }
            }
            steps++;
        }

        x = (a + b) / 2;
        if (isEven) {
            min = num * x * x + log(x);
        } else {
            min = num * x - log(x);
        }
    }
}
