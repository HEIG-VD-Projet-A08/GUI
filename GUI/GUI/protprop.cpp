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


void ProtProp::on_btn_loadDB_clicked()
{

}
