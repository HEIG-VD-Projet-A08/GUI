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
    // set possibility for menu with "localisation" as default possibility
    QStringList n;
    n << "Localisation" << "Toxicité" ;

    ui->setupUi(this);
    ui->menu_list->addItems(n);

    // enable validator for each input
    ui->IP->setText("127.0.0.1");
    ui->CharMax->setValidator(inputNumberChar);
    ui->iterations->setValidator(inputIteration);
    ui->nbWords->setValidator(inputIteration);
}

ProtProp::~ProtProp()
{
    delete ui;
}


void ProtProp::on_btn_run_clicked()
{
    // load input//    nbChars = ui->CharMax->text();
        nbWords = ui->nbWords->text();
        nbChars = ui->CharMax->text();
        nbIter = ui->iterations->text();
        //caract = ui->menu_list->currentText();
        ip = ui->IP->text();


    if (nbChars == "" || nbWords == "" || nbIter == ""){
    }
}

