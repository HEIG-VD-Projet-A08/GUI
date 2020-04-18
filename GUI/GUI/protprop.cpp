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
        QMessageBox::warning(0, QString("Error de saisie"), QString("Les paramètres ont mal été saisi. Le programme n'a pas été exécuté."));
    }else{
        QMessageBox::information(0, QString("Tout roule."), QString("Le programme va être exécuté."));


        QString path("/home/jerome/HEIG/Labo/PRO/GUI/");
        QDir dir;
        // création du directory si besoin
        if (!dir.exists(path))
            dir.mkpath(path);

        QFile file(path + "option.xml");

        file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("Options");
        xmlWriter.writeTextElement("Nb_words", nbWords);
        xmlWriter.writeTextElement("Nb_char", nbChars);
        xmlWriter.writeTextElement("Nb_iter", nbIter);
        xmlWriter.writeTextElement("caracteristique", caract);
        xmlWriter.writeEndElement();
        file.close();
    }
}

