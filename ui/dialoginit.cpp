#include "dialoginit.h"
#include "ui_dialoginit.h"

DialogInit::DialogInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInit)
{
    ui->setupUi(this);
}

DialogInit::~DialogInit()
{
    delete ui;
}
