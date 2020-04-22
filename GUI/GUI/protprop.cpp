#include "protprop.h"
#include "./ui_protprop.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include<QRegExpValidator>


ProtProp::ProtProp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProtProp)
{
    // set validators for input
    QRegExpValidator *inputNumberChar = new QRegExpValidator(  QRegExp("(?:[0-9]){3}"));
    QRegExpValidator *inputNumberPort = new QRegExpValidator(  QRegExp("(?:[0-9]){5}"));
    QRegExpValidator *inputIteration = new QRegExpValidator(  QRegExp("[0-9][0-9][0-9][0-9][0-9]"));
    QRegExpValidator *ipValidator = new QRegExpValidator(  QRegExp("(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)"));
    // set possibility for menu with "localisation" as default possibility
    QStringList n;
    n << "Localisation" << "Toxicité" ;

    ui->setupUi(this);
    ui->comboBox->addItems(n);

    // enable validator for each input
    ui->IP->setText("127.0.0.1");
    ui->IP->setValidator(ipValidator);
    ui->CharMax->setValidator(inputNumberChar);
    // TODO : à enlever en cas de test automatique        sleep(10);
    ui->CharMax->setText("100");
    ui->iterations->setValidator(inputIteration);
    // TODO : à enlever en cas de test automatique
    ui->iterations->setText("11");
    ui->nbWords->setValidator(inputIteration);
    // TODO : à enlever en cas de test automatique
    ui->nbWords->setText("10");
    ui->port->setValidator(inputNumberPort);
    ui->port->setText("9000");
}

ProtProp::~ProtProp()
{
    delete ui;
}

/**
 * @brief ProtProp::on_btn_run_clicked gestion du chargement des paramètres lorsqu'on presse sur run
 */
void ProtProp::on_btn_run_clicked()
{

    nbChars = ui->CharMax->text();
    nbWords = ui->nbWords->text();   //max around 20-50
    nbIter = ui->iterations->text(); //max around 1000
    ip = ui->IP->text();
    port = ui->port->text();
	
	// load input//    nbChars = ui->CharMax->text();
   
        caract = ui->comboBox->currentText();

    // test que les arguments soient tous rempli
    if (nbChars == "" || nbWords == "" || nbIter == "" || caract == ""){
        QMessageBox::warning(0, QString("Erreur de saisie"), QString("Les paramètres ont mal été saisi. Le programme n'a pas été exécuté."));
    }else{
        // écriture du fichier XML dans le dossier de l'application
        QDir dir;
        QString path(dir.currentPath());
        QFile file(path + "/option.xml");

        // partie client TCP
        file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("Options");
        xmlWriter.writeTextElement("Nb_words", nbWords);
        xmlWriter.writeTextElement("Nb_char", nbChars);
        xmlWriter.writeTextElement("Nb_iter", nbIter);
        xmlWriter.writeTextElement("caracteristique", caract);
        xmlWriter.writeTextElement("add_ip", ip);
        xmlWriter.writeEndElement();
        // test si une erreur est survenue pendant l'écriture du fichier xml
        if(xmlWriter.hasError()){
            QMessageBox::warning(0, QString("Erreur de saisie"), QString("Problème lors de la génération du fichier de configuration"));
        }else{
            QMessageBox::information(0, QString("Tout roule."), QString("Le programme va être exécuté."));
        }
        file.close();

        test = new ClientTcp(this, ip, port.toInt());
		
        test->sendGreetings();
        test->sendData(file);

//        //while (Socket->readLine() != "Hello Client");
//        //printf("Hello Recu");
    }	
	
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


        /*
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
        */
        //real code/values


        for(int i = 0; i < sizeX; i++)
        {
            double x;
            double y;
            getValuesFromServer(x, y);
            contX.push_back(x);
            contY.push_back(y);

            /*
            QCPItemTracer *tracer = new QCPItemTracer(ui->widget);
               tracer->setGraph(ui->widget->graph(0));
               tracer->setInterpolating(true);
               tracer->setVisible(false);
               for (int i = 0; i < 4; i++){
                  tracer->updatePosition();
               }*/
               QCPGraph* dwPoints = new QCPGraph(ui->widget->xAxis, ui->widget->yAxis);
                  dwPoints->setAdaptiveSampling(false);
                  dwPoints->setLineStyle(QCPGraph::lsNone);
                  dwPoints->setScatterStyle(QCPScatterStyle::ssCircle);
                  dwPoints->setPen(QPen(QBrush(Qt::red), 2));
                  dwPoints->addData(contX, contY);

            ui->widget->graph(0)->setData(contX, contY);
            ui->widget->replot();
        }


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
            textToWriteOSS << "" << contNameProt[i] << ", " << contX[i] << ", " << contY[i] << "\n";
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


    void ProtProp::getValuesFromServer(double &x, double &y)
    {
        //waiting on code from Jéjé to know how to recup the content, ideally I would want the values to be put directly in those containers.
        // TO DO

        QString it;
        QString score;
        ReadXMLFile(it, score);
        QFile file("temp.xml");
        file.remove();

        x = it.toDouble();
        y = score.toDouble();

    }





    //////////////////////XML PARSING EXEMPLE ///////////////////////////////////////




    void ProtProp::ReadXMLFile(QString &it, QString &score)
    {
        QXmlStreamReader Rxml;


        QFile file;

        file.setFileName("/tmp.xml");

        while(!file.open(QFile::ReadOnly | QFile::Text))
        {

        }

        Rxml.setDevice(&file);

        Rxml.readNext();

        while(!Rxml.atEnd())
        {
            if(Rxml.readNext() != QXmlStreamReader::EndDocument)
            {
                if(Rxml.isStartElement())
                {
                    if(Rxml.name() == "result")
                    {
                        Rxml.readNext();
                    }
                    while(!Rxml.atEnd())
                    {
                         if(Rxml.isEndElement())
                         {
                             Rxml.readNext();
                             break;
                         }
                         else if(Rxml.isCharacters())
                         {
                             Rxml.readNext();
                         }
                         else if(Rxml.isStartElement())
                         {
                             /*
                             if(Rxml.name() == "name")
                             {
                                ReadElement();
                             }*/
                             if(Rxml.name() == "it")
                             {
                                it = Rxml.readElementText();   //Get the xml value
                             }
                             else if(Rxml.name() == "score")
                             {
                                score = Rxml.readElementText();   //Get the xml value
                             }
                             Rxml.readNext();
                         }
                         else
                         {
                            Rxml.readNext();
                         }
                    }
                }
            }
        }

        file.close();

        if (Rxml.hasError())
        {
           std::cerr << "Error: Failed to parse file "
                     << qPrintable("temp.xml") << ": "
                     << qPrintable(Rxml.errorString()) << std::endl;
            }
        else if (file.error() != QFile::NoError)
        {
            std::cerr << "Error: Cannot read file " << qPrintable("temp.xml")
                      << ": " << qPrintable(file.errorString())
                      << std::endl;
        }
    }



    //Example for Element
    /*
    QString ProtProp::ReadElement(QXmlStreamReader Rxml)
    {
        while(!Rxml.atEnd())
        {
            if(Rxml.isEndElement())
            {
                Rxml.readNext();
                break;
            }
            else if(Rxml.isStartElement())
            {
                QString element = Rxml.readElementText();   //Get the xml value
                Rxml.readNext();
                return element;
            }
            else if(Rxml.isCharacters())
            {
                Rxml.readNext();
            }
            else
            {
                Rxml.readNext();
            }
        }
    }
    */
