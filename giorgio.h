#ifndef GIORGIO_H
#define GIORGIO_H

#include <QDialog>

namespace Ui {
class Giorgio;
}

class Giorgio : public QDialog
{
    Q_OBJECT

public:
    explicit Giorgio(QWidget *parent = nullptr);
    ~Giorgio();

private:
    Ui::Giorgio *ui;
};

#endif // GIORGIO_H
