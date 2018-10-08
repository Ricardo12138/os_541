#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->OKPushButton,&QPushButton::clicked,this,&Dialog::sendData);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sendData(){
    emit newItem(ui->lineEdit->text(),ui->comboBox->currentIndex());
    this->close();
}
