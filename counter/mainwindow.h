#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QPushButton>
#include <QTextBrowser>
#include <QtGui/QtGui>
#include "infix2postfix.h"
#include "calculate.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    Infix2Postfix* i2p;
    Calculate* cal;
    string expression;
    int precision;
    string result;

    void screen_display(string str);

private slots:
    void on_num_0_btn_clicked();
    void on_num_1_btn_clicked();
    void on_num_2_btn_clicked();
    void on_num_3_btn_clicked();
    void on_num_4_btn_clicked();
    void on_num_5_btn_clicked();
    void on_num_6_btn_clicked();
    void on_num_7_btn_clicked();
    void on_num_8_btn_clicked();
    void on_num_9_btn_clicked();
    void on_op_add_btn_clicked();
    void on_op_sub_btn_clicked();
    void on_op_mul_btn_clicked();
    void on_op_div_btn_clicked();
    void on_op_dot_btn_clicked();
    void on_op_equ_btn_clicked();
    void on_op_lbr_btn_clicked();
    void on_op_rbr_btn_clicked();
    void on_op_clear_btn_clicked();
    void on_op_postfix_btn_clicked();
    void on_prec_edit_valueChanged(int prec);

};

#endif // MAINWINDOW_H
