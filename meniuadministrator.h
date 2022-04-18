#ifndef MENIUADMINISTRATOR_H
#define MENIUADMINISTRATOR_H

#include <QDialog>

namespace Ui {
class meniuadministrator;
}

class meniuadministrator : public QDialog
{
    Q_OBJECT

public:
    explicit meniuadministrator(QWidget *parent = nullptr);
    ~meniuadministrator();

private:
    Ui::meniuadministrator *ui;
};

#endif // MENIUADMINISTRATOR_H
