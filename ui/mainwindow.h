#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <string>
#include <QThread>
#include "../os_541/file.h"
#include "../os_541/file_mangement.h"
#include "../os_541/global.h"
#include "../os_541/memory.h"
#include "../os_541/new.h"
#include "../os_541/run.h"
#include "../os_541/Operation.h"
#include "../os_541/PCB.h"
#include "../os_541/Process.h"
#include "../os_541/ready.h"
#include "../os_541/running.h"
#include "../os_541/scheduleAlgorithm.h"
#include "../os_541/targetver.h"
#include "../os_541/TC_ThreadQueue.h"
#include "../os_541/terminated.h"
#include "../os_541/waiting.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    new_detect_thread NewDetectThread;
    readyThread * ReadyThread=new readyThread("FCFS");
    runningThread RunningThread;
    waitingThread WaitingThread;
    terminatedThread TerminatedThread;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void treeMenu(const QPoint &pos);
    void newFileItem(QString,int);
    void newItemDialog(bool);
    void inte();
    void IO();
    void IOFinish();
    void newJob();
    void refreshProc(string id,string state,string add,string inte,string io);
    void message(std::string msg);
    void refreshMem(int add);
    void removeItem(bool);
    void changeStrategy(int);

private:
    Ui::MainWindow *ui;
    QIcon fileIcon=QIcon(QStringLiteral(":/pic/file.png"));
    QIcon dirIcon=QIcon(QStringLiteral(":/pic/dir.png"));

};

#endif // MAINWINDOW_H
