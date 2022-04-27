#ifndef EVENTS_H
#define EVENTS_H

#include <QDialog>

namespace Ui {
class Events;
}

class Events : public QDialog
{
    Q_OBJECT

public:
    explicit Events(QWidget *parent = nullptr);
    ~Events();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Events *ui;
};

#endif // EVENTS_H
