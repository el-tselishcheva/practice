#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();

public:
    void setText();
    void setValues(int, double, double, double);
    void isNumEven(int);
    double funcEven(double);
    double funcOdd(double);
    void calculations();

private:
    Ui::Result *ui;
    int num, steps;
    double a, b, e, x, min, startA, startB;
    bool isEven, hasMin = true;
};

#endif // RESULT_H
