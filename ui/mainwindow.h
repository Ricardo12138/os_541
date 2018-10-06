#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <string>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
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

private:
    Ui::MainWindow *ui;
    QIcon fileIcon=QIcon(QStringLiteral(":/pic/file.png"));
    QIcon dirIcon=QIcon(QStringLiteral(":/pic/dir.png"));

};

#endif // MAINWINDOW_H
