#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QIcon>
#include <QStringLiteral>
#include <QComboBox>

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
    connect(ui->fileTreeView,&QTreeView::customContextMenuRequested,this,&MainWindow::treeMenu);
    connect(ui->intePushButton,&QPushButton::clicked,this,&MainWindow::inte);
    connect(ui->IOPushButton,&QPushButton::clicked,this,&MainWindow::IO);
    connect(ui->IOFinPushButton,&QPushButton::clicked,this,&MainWindow::IOFinish);
    connect(ui->newJobPushButton,&QPushButton::clicked,this,&MainWindow::newJob);
    connect(ui->strategyComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeStrategy(int)));
    connect(&NewDetectThread,&new_detect_thread::newThread,this,&MainWindow::message);

    NewDetectThread.start();
    ReadyThread->start();
    RunningThread.start();
    WaitingThread.start();
    TerminatedThread.start();

}

MainWindow::~MainWindow()
{
    delete ui;
    ReadyThread->quit();
    delete ReadyThread;
    NewDetectThread.quit();
    RunningThread.quit();
    WaitingThread.quit();
    TerminatedThread.quit();
}

void MainWindow::treeMenu(const QPoint &pos){
    QMenu menu;

    QModelIndex curIndex = ui->fileTreeView->indexAt(pos);      //当前点击的元素的index
    QModelIndex index = curIndex.sibling(curIndex.row(),0); //该行的第1列元素的index
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->fileTreeView->model());
    QStandardItem *curItem = model->itemFromIndex(curIndex);

    //if(curItem->icon()==dirIcon)
    menu.addAction(QStringLiteral("新建文件/文件夹"),this,SLOT(newItemDialog(bool)));
    menu.addAction(QStringLiteral("删除"),this,SLOT(removeItem(bool)));
    menu.exec(QCursor::pos());
}

void MainWindow::removeItem(bool i){
    //向文件管理系统请求删除节点
    auto curIndex = ui->fileTreeView->currentIndex();
    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->fileTreeView->model());
    QStandardItem *curItem = model->itemFromIndex(curIndex);
    string name = curItem->text().toStdString();
    string type="文件";
    //if(curItem->icon()==fileIcon) type="文件";
    //else type="文件夹";

    node *target=(node *)curItem->data().value<void *>();
    /*
     * 调用文件管理删除节点
     * if(删除成功)
     */
    QStandardItem *pItem=curItem->parent();
    pItem->removeRow(curIndex.row());
    //输出系统状态信息
    message("删除"+type+name);
}

void MainWindow::newItemDialog(bool i){
    Dialog *itemDialog = new Dialog();
    connect(itemDialog,&Dialog::newItem,this,&MainWindow::newFileItem);
    itemDialog->exec();
}
void MainWindow::newFileItem(QString name,int type){
    auto curIndex = ui->fileTreeView->currentIndex();
    QStandardItem *item=nullptr;
    string stype;
    if(type==0)
    {
        item = new QStandardItem(dirIcon,name);
        stype="文件夹";
    }
    else
    {
        item = new QStandardItem(fileIcon,name);
        stype="文件";
    }

    QStandardItemModel *model = static_cast<QStandardItemModel*>(ui->fileTreeView->model());
    QStandardItem *curItem = model->itemFromIndex(curIndex);
    curItem->appendRow(item);
    ui->fileTreeView->expand(curIndex);
    string std_name=name.toStdString();
    message("新建"+stype+std_name);
}

void MainWindow::inte(){
    QString id = ui->pidLineEdit->text();
    //进行中断处理
    QString msg="进程"+id+"发生中断";
    message(msg.toStdString());
}

void MainWindow::IO(){
    QString id = ui->pidLineEdit->text();
    //后台IO
    QString pre=QString::fromLocal8Bit("进程");
    QString post=QString::fromLocal8Bit("发生中断");
    QString msg=pre+id+post;
    message(msg.toStdString());
}

void MainWindow::IOFinish(){
    QString id = ui->pidLineEdit->text();
    //后台结束IO
    QString msg="进程"+id+"IO结束";
    message(msg.toStdString());
}

void MainWindow::newJob(){
    int jobType = ui->jobComboBox->currentIndex();
    switch (jobType) {
    case 0:
        produce(job1);
        break;
    case 1:
        produce(job2);
        break;
    case 2:
        produce(job3);
        break;
    case 3:
        produce(job4);
        break;
    case 4:
        produce(job5);
        break;
    default:
        break;
    }
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
        ui->processTableWidget->item(1,curIndex)->setText(state.c_str());
        ui->processTableWidget->item(2,curIndex)->setText(add.c_str());
        ui->processTableWidget->item(3,curIndex)->setText(inte.c_str());
        ui->processTableWidget->item(4,curIndex)->setText(io.c_str());
    }
}

void MainWindow::message(string msg){
    ui->stateListWidget->insertItem(0,msg.c_str());
    //ui->stateListWidget->addItem(msg.c_str());
    ui->stateListWidget->setCurrentRow(ui->stateListWidget->count());
}

void MainWindow::refreshMem(int add){
    ui->memTableWidget->clear();
    useCondition *info = showMem();
    while (info->next) {
        int cur_row=ui->memTableWidget->rowCount();
        ui->memTableWidget->setRowCount(cur_row+1);
        ui->memTableWidget->setItem(1,cur_row,new QTableWidgetItem(to_string(info->size).c_str()));
        ui->memTableWidget->setItem(3,cur_row,new QTableWidgetItem(to_string(info->address).c_str()));
        if(info->state==0)
            ui->memTableWidget->setItem(1,cur_row,new QTableWidgetItem("空闲"));
        else
            ui->memTableWidget->setItem(1,cur_row,new QTableWidgetItem("占用"));

        info=info->next;
    }
}

void MainWindow::changeStrategy(int curIndex){
    //修改策略
    //
}
