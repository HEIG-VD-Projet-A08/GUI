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
