#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customspinbox.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startCalculations_clicked()
{
    QString urNum = ui->urNum->text();
    QString intervalA = ui->intervalA->text();
    QString intervalB = ui->intervalB->text();
    QString accuracy = ui->accuracy->text();
    bool isDigit, isDoubleA, isDoubleB, isDouble;
    int num = urNum.toInt(&isDigit, 10);
    double a = intervalA.toDouble(&isDoubleA);
    double b = intervalB.toDouble(&isDoubleB);
    double e = accuracy.toDouble(&isDouble);
    if (!ui->yesRB->isChecked() && !ui->noRB->isChecked() || ui->urNum->displayText().isEmpty()
        || ui->intervalA->displayText().isEmpty() || ui->intervalB->displayText().isEmpty()) {
        QMessageBox::warning(this, "Внимание!", "Вы заполнили не все формы.\r\nЗаполните их и попробуйте еще раз.");
    } else if (isDigit && num > 0 && num < 21 && isDoubleA && isDoubleB && a > 0 && a < 10
               && b > 0 && b <= 10 && a < b) {
        if (ui->yesRB->isChecked()) {
            result = new Result(this);
            graph = new Graph(this);
            result->setValues(num, a, b, e);
            result->setText();
            graph->isNumEven(num);
            result->show();
            graph->show();
        } else {
            result = new Result(this);
            result->setValues(num, a, b, e);
            result->setText();
            result->show();
        }
    } else {
        QMessageBox::critical(this, "Ошибка!", "Вы ввели неверные данные. На обработку принимаются:\r\n\r\n"
        "- для точности целые числа от 1 до 20 включительно;\r\n- для интервала рациональные числа на интервале (0; 10]"
        "\r\n(используйте точку в качестве разделителя).");
    }
}
