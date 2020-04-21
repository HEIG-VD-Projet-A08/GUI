#include "protprop.h"
#include "./ui_protprop.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

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
    nbWords = ui->nbWords->text();   //max around 20-50
    nbIter = ui->iterations->text(); //max around 1000
    ip = ui->IP->text();

    //start prog with variables above
    //have to send some of those informations to the server to run the algo
    //wait for the algo to start sending us results

    //then, get results in a container and show them on the graph
    int sizeX = nbIter.toInt(); //length of X axis, represents the number of iterations
    int sizeY = 100; //length of Y axis, represents success rate


    ui->widget->clearGraphs();
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->addGraph();
    // give the axes some labels:
    ui->widget->xAxis->setLabel("iterations");
    ui->widget->yAxis->setLabel("success rate");
    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(0, sizeX);
    ui->widget->yAxis->setRange(0, sizeY);
    ui->widget->replot();


    //DUMB VALUES
    for(int i = 0; i < sizeX; i++)
    {
        usleep(100);

        //Here we will replace those appends by the values we receive from the server
        contX.append(i);
        contY.append(5+i);

        ui->widget->graph(0)->setData(contX, contY);
        ui->widget->replot();
    }

    //real code/values
    /*
    getValuesFromServer(contXFromServ, contYFromServ);
    for(int i = 0; i < sizeX; i++)
    {
        usleep(100);
        contX.push_back(contXFromServ[i]);
        contY.push_back(contYFromServ[i]);

        ui->widget->graph(0)->setData(contX, contY);
        ui->widget->replot();
    }
*/

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
    //implémenter plus tard, les gens sont pas d'accord sur la fonction du bouton
    //stop prog
}

void ProtProp::on_btn_save_actual_clicked()
{
    //snapshot system, to implement later
    //save current graph and results so you can continue the same process later
}

void ProtProp::on_btn_save_res_clicked()
{
    //save results in a file
    //save in a file (csv) x and y coordinates WITH the name of an individual (get it from the alg, best word in the 10words group of each iteration)
    std::ofstream myFile;
    myFile.open("/home/reds/Desktop/savedResults.csv");

    std::ostringstream textToWriteOSS;
    for(int i = 0; i < nbIter.toInt(); i++)
    {
        textToWriteOSS << "" << contX[i] << ", " << contY[i] << "\n";
    }
    std::string textToWrite = textToWriteOSS.str();

    myFile << textToWrite;
    myFile.close();

}

void ProtProp::on_plot_clicked()
{

    //Resets the view (usefull if we used the drag or the zoom feature)
    ui->widget->xAxis->setRange(0, nbIter.toInt());
    ui->widget->yAxis->setRange(0, 100);
    ui->widget->replot();
}


void getValuesFromServer(QVector<double> contX, QVector<double> contY)
{
    //waiting on code from Jéjé to know how to recup the content, ideally I would want the values to be put directly in those containers.
    // TO DO
}
