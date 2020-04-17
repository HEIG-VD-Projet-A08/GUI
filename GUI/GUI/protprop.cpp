#include "protprop.h"
#include "./ui_protprop.h"

ProtProp::ProtProp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProtProp)
{
    ui->setupUi(this);

}

ProtProp::~ProtProp()
{
    delete ui;
}


void ProtProp::on_btn_run_clicked()
{
    nbChars = ui->CharMax->text();
    nbWords = ui->nbWords->text();
    nbIter = ui->iterations->text();
    ip = ui->IP->text();

    //start prog with variables above

    //then, get results in a container and show them on the graph
    int sizeX = nbIter.toInt(); //length of X axis, represents the number of iterations
    int sizeY = 100; //length of Y axis, represents success rate
    QVector<double> contX(sizeX), contY(sizeY); //containers for X and Y values



    ui->widget->addGraph();
    ui->widget->graph(0)->setData(contX, contY);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("iterations");
    ui->widget->yAxis->setLabel("success rate");
    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(0, sizeX);
    ui->widget->yAxis->setRange(0, 100);
    ui->widget->replot();

/*
    //////////////////EXEMPLE/////////////////////
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(-1, 1);
    ui->widget->yAxis->setRange(0, 1);
    ui->widget->replot();*/
}

void ProtProp::on_btn_stop_clicked()
{
    //stop prog
}

void ProtProp::on_btn_save_actual_clicked()
{
    //save current graph and results so you can continue the same process later
}

void ProtProp::on_btn_save_res_clicked()
{
    //save results in a file
}

void ProtProp::on_plot_clicked()
{

}

