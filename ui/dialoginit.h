#ifndef DIALOGINIT_H
#define DIALOGINIT_H

#include <QDialog>

namespace Ui {
class DialogInit;
}

class DialogInit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInit(QWidget *parent = 0);
    ~DialogInit();

private:
    Ui::DialogInit *ui;
};

#endif // DIALOGINIT_H
