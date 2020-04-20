#include "protprop.h"
#include "./ui_protprop.h"
#include<QRegExpValidator>

ProtProp::ProtProp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProtProp)
{
    // set validators for input
    QRegExpValidator *inputNumberChar = new QRegExpValidator(  QRegExp("[0-9][0-9][0-9]"));
    QRegExpValidator *inputIteration = new QRegExpValidator(  QRegExp("[0-9][0-9][0-9][0-9][0-9]"));
    QRegExpValidator *ipValidator = new QRegExpValidator(  QRegExp("(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)"));
    // set possibility for menu with "localisation" as default possibility
    QStringList n;
    n << "Localisation" << "Toxicité" ;

    ui->setupUi(this);
    ui->menu_list->addItems(n);

    // enable validator for each input
    ui->IP->setText("127.0.0.1");
    ui->IP->setValidator(ipValidator);
    ui->CharMax->setValidator(inputNumberChar);
    ui->iterations->setValidator(inputIteration);
    ui->nbWords->setValidator(inputIteration);
    qDebug() << "App path : " << qApp->applicationDirPath();
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
    // load input//    nbChars = ui->CharMax->text();
        nbWords = ui->nbWords->text();
        nbChars = ui->CharMax->text();
        nbIter = ui->iterations->text();
        ip = ui->IP->text();
        caract = ui->menu_list->currentText();

    // test que les arguments soient tous rempli
    if (nbChars == "" || nbWords == "" || nbIter == "" || caract == ""){
        QMessageBox::warning(0, QString("Erreur de saisie"), QString("Les paramètres ont mal été saisi. Le programme n'a pas été exécuté."));
    }else{
        // écriture du fichier XML dans le dossier de l'application
        QDir dir;
        QString path(dir.currentPath());
        QFile file(path + "/option.xml");

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


        QTcpSocket *_pSocket;

        _pSocket = new QTcpSocket( this );
        file.open(QIODevice::ReadOnly);
        QByteArray mydata=file.readAll();

        _pSocket->connectToHost(ip, 9000);
        if( _pSocket->waitForConnected() ) {
            _pSocket->write( mydata );
        }
        file.close();
        _pSocket->disconnectFromHost();
    }
}

