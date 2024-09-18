#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

public:
    void isNumEven(int);
    void drawChart(Ui::Graph *);

private:
    Ui::Graph *ui;
    int num;
    bool isEven;
};

#endif // GRAPH_H
