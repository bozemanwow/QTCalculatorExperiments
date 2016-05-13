#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetTopValue(double _Value);

    void AddtoTextBox(QString text );
private slots:
    void on_pushButtonMinus_clicked();

    void on_pushButtonPlus_clicked();

    void on_pushButtonDivide_clicked();

    void on_pushButtonTimes_clicked();

    void on_pushButtonSqrt_clicked();
private:
    void SetBeforeValues();


private:
    Ui::MainWindow *ui;
    QString mBeforeTop ;
    QString mBeforeBottom;


};

#endif // MAINWINDOW_H
