#include "protprop.h"
#include "./ui_protprop.h"

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
    ui->menu_list->addItems(n);

    // enable validator for each input
    ui->IP->setText("127.0.0.1");
    ui->CharMax->setValidator(inputNumberChar);
    ui->iterations->setValidator(inputIteration);
    ui->nbWords->setValidator(inputIteration);

    ui->setupUi(this);
}

ProtProp::~ProtProp()
{
    delete ui;
}


void ProtProp::on_btn_run_clicked()
{
    // load input
    nbChars = ui->CharMax->text();
    nbWords = ui->nbWords->text();
    nbIter = ui->iterations->text();
    caract = ui->menu_list->currentText();
    ip = ui->IP->text();

    if (nbChars == "" || nbWords == "" || nbIter == ""){
    }
}

void ProtProp::on_btn_stop_clicked()
{

}

void ProtProp::on_btn_save_actual_clicked()
{

}

void ProtProp::on_btn_save_res_clicked()
{

}

void ProtProp::on_plot_clicked()
{

}

