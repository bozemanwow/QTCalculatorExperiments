#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <qmessagebox.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonMinus_clicked()
{
     SetBeforeValues();
     SetTopValue(ui->doubleTopValue->value() - ui->doubleBottomValue->value());
     AddtoTextBox(mBeforeTop+ " - "+mBeforeBottom  + " = " +ui->doubleTopValue->text() );
}

void MainWindow::on_pushButtonPlus_clicked()
{
      SetBeforeValues();
      SetTopValue(ui->doubleTopValue->value() + ui->doubleBottomValue->value());
      AddtoTextBox(mBeforeTop+ " + "+mBeforeBottom  + " = " +ui->doubleTopValue->text() );
}

void MainWindow::on_pushButtonDivide_clicked()
{
    if(ui->doubleBottomValue->value() != 0){
          SetBeforeValues();
          SetTopValue(ui->doubleTopValue->value() /ui->doubleBottomValue->value());
          AddtoTextBox(mBeforeTop+ " / "+mBeforeBottom  + " = " +ui->doubleTopValue->text() );
    }
   else
        QMessageBox::information(this,"Error","Can't divide by zero.");
}

void MainWindow::on_pushButtonTimes_clicked()
{

    SetBeforeValues();
    SetTopValue(ui->doubleTopValue->value() *ui->doubleBottomValue->value());
    AddtoTextBox(mBeforeTop+ " * "+mBeforeBottom  + " = " +ui->doubleTopValue->text() );
}

void MainWindow::on_pushButtonSqrt_clicked()
{




    if(ui->doubleTopValue->value() < 0)
    {
         QMessageBox::information(this,"Error","Can't SQRT less than zero.");

    }
    else
    {
        SetBeforeValues();
        SetTopValue(qSqrt( ui->doubleTopValue->value()));
        AddtoTextBox(" SQRT ( "+mBeforeTop+ ") = " +ui->doubleTopValue->text() );
    }



}

void  MainWindow::SetTopValue(double _Value)
{
     ui->doubleTopValue->setValue( _Value);
}

void MainWindow::AddtoTextBox(QString text )
{
    ui->plainTextEdit->appendPlainText( QString("Log: "+text));
}

void MainWindow::SetBeforeValues()
{
    mBeforeTop = ui->doubleTopValue->text();
    mBeforeBottom =ui->doubleBottomValue->text();
}

