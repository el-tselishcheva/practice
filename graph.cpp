#include "graph.h"
#include "ui_graph.h"

#include <math.h>

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
}

Graph::~Graph()
{
    delete ui;
}

void Graph::isNumEven(int num) {
    this->num = num;
    if (num % 2 == 0) {
        isEven = true;
    } else {
        isEven = false;
    }
    Graph::drawChart(ui);
}

void Graph::drawChart(Ui::Graph *ui) {
    QSplineSeries *line = new QSplineSeries();

    double c = ceil((double) num / 2);
    double y;
    for(double x = 0; x <= 1; x += 0.1) {
        if (isEven) {
            y = c * x * x + log(x);
        } else {
            y = c * x - log(x);
        }
        line->append(x, y);
    }

    QChart *chart = new QChart();
    ui->chart->setChart(chart);

    if (isEven) {
        chart->setTitle("График функции f(x) = " + QString::number(ceil((double) num / 2)) + " * x<span style='vertical-align:super;'>2</span> + log(x)");
    } else {
        chart->setTitle("График функции f(x) = " + QString::number(ceil((double) num / 2)) + " * x - log(x)");
    }

    chart->legend()->hide();
    chart->addSeries(line);

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).back()->setRange(0, 1);

    if (isEven) {
        chart->axes(Qt::Vertical).back()->setRange(-1, 8);
    } else {
        chart->axes(Qt::Vertical).back()->setRange(0, 8);
    }

    chart->axes(Qt::Horizontal).back()->setTitleText("x");
    chart->axes(Qt::Vertical).back()->setTitleText("y");
}
