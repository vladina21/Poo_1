#ifndef EXPOZITII_SI_EVENIMENTE_H
#define EXPOZITII_SI_EVENIMENTE_H

#include <QDialog>

namespace Ui {
class Expozitii_si_evenimente;
}

class Expozitii_si_evenimente : public QDialog
{
    Q_OBJECT

public:
    explicit Expozitii_si_evenimente(QWidget *parent = nullptr);
    ~Expozitii_si_evenimente();

private:
    Ui::Expozitii_si_evenimente *ui;
};

#endif // EXPOZITII_SI_EVENIMENTE_H
