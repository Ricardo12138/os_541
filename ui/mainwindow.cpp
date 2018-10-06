#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QIcon>
#include <QStringLiteral>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto model=new QStandardItemModel;
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("文件名"));
    QStandardItem *item = new QStandardItem(dirIcon,QString("root"));
    model->appendRow(item);
    ui->fileTreeView->setModel(model);
    ui->fileTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->fileTreeView,&QTreeView::customContextMenuRequested,this,MainWindow::treeMenu);
    connect(ui->intePushButton,&QPushButton::clicked,this,MainWindow::inte);
    connect(ui->IOPushButton,&QPushButton::clicked,this,MainWindow::IO);
    connect(ui->IOFinPushButton,&QPushButton::clicked,this,MainWindow::IOFinish);
    connect(ui->newJobPushButton,&QPushButton::clicked,this,MainWindow::newJob);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::treeMenu(const QPoint &pos){
    QMenu menu;

    QModelIndex curIndex = ui->fileTreeView->indexAt(pos);      //当前点击的元素的index
    QModelIndex index = curIndex.sibling(curIndex.row(),0); //该行的第1列元素的index

    menu.addAction(QStringLiteral("新建文件/文件夹"),this,SLOT(newItemDialog(bool)));
    menu.addAction(QStringLiteral("删除"),this,SLOT(removeItem(bool)));
    menu.exec(QCursor::pos());
}

void MainWindow::removeItem(bool i){
    //向文件管理系统请求删除节点
    auto curIndex = ui->fileTreeView->currentIndex();
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->fileTreeView->model());
    QStandardItem *curItem = model->itemFromIndex(curIndex);
    QStandardItem *pItem=curItem->parent();
    pItem->removeRow(curIndex.row());
}

void MainWindow::newItemDialog(bool i){
    Dialog *itemDialog = new Dialog();
    connect(itemDialog,Dialog::newItem,this,MainWindow::newFileItem);
    itemDialog->exec();
}
void MainWindow::newFileItem(QString name,int type){
    auto curIndex = ui->fileTreeView->currentIndex();
    QStandardItem *item=nullptr;
    if(type==0)
        item = new QStandardItem(dirIcon,name);
    else
        item = new QStandardItem(fileIcon,name);

    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->fileTreeView->model());
    QStandardItem *curItem = model->itemFromIndex(curIndex);
    curItem->appendRow(item);
    ui->fileTreeView->expand(curIndex);
}

void MainWindow::inte(){
    //进行中断处理
}

void MainWindow::IO(){

}

void MainWindow::IOFinish(){

}

void MainWindow::newJob(){
    //进程管理后台创建进程，返回进程信息
    int curRow=ui->processTableWidget->rowCount()+1;
    ui->processTableWidget->setRowCount(curRow);
    ui->processTableWidget->item(curRow,1)->setText("ID");
    ui->processTableWidget->item(curRow,2)->setText("state");
    ui->processTableWidget->item(curRow,3)->setText("addr");
    ui->processTableWidget->item(curRow,4)->setText("Inte");
    ui->processTableWidget->item(curRow,5)->setText("IOState");
}

void MainWindow::refreshProc(string id,string state,string add,string inte,string io){
    QString Qid=QString(id.c_str());
    auto Max_row=ui->processTableWidget->rowCount();
    int curIndex=1;
    for(;curIndex<=Max_row;curIndex++){
        QTableWidgetItem *curItem=ui->processTableWidget->item(curIndex,1);
        if(curItem->text()==Qid) break;
    }
    if(curIndex>Max_row){
        curIndex++;
        ui->processTableWidget->setRowCount(curIndex);
    }
    if(state=="T") ui->processTableWidget->removeRow(curIndex);
    else{
        ui->processTableWidget->item(curIndex,2)->setText(state.c_str());
        ui->processTableWidget->item(curIndex,3)->setText(add.c_str());
        ui->processTableWidget->item(curIndex,4)->setText(inte.c_str());
        ui->processTableWidget->item(curIndex,5)->setText(io.c_str());
    }
}

void MainWindow::message(std::string msg){
    ui->stateListWidget->addItem(QString(msg.c_str()));
    ui->stateListWidget->setCurrentRow(ui->stateListWidget->count());
}

void MainWindow::refreshMem(int add){

}
