#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle(tr("Simple Calculator"));
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    i2p = new Infix2Postfix ();
    cal = new Calculate ();
    expression = "";
    precision = 0;
    result = "";
    screen_display("Welcome!");
}

MainWindow::~MainWindow() {
    delete i2p;
    delete cal;
}

void MainWindow::screen_display(string str) {
    ui->screen->setText(QString(str.c_str()));
}

void MainWindow::on_num_0_btn_clicked() {
    expression += "0";
    screen_display(expression);
}

void MainWindow::on_num_1_btn_clicked() {
    expression += "1";
    screen_display(expression);
}

void MainWindow::on_num_2_btn_clicked() {
    expression += "2";
    screen_display(expression);
}

void MainWindow::on_num_3_btn_clicked() {
    expression += "3";
    screen_display(expression);
}

void MainWindow::on_num_4_btn_clicked() {
    expression += "4";
    screen_display(expression);
}

void MainWindow::on_num_5_btn_clicked() {
    expression += "5";
    screen_display(expression);
}

void MainWindow::on_num_6_btn_clicked() {
    expression += "6";
    screen_display(expression);
}

void MainWindow::on_num_7_btn_clicked() {
    expression += "7";
    screen_display(expression);
}

void MainWindow::on_num_8_btn_clicked() {
    expression += "8";
    screen_display(expression);
}

void MainWindow::on_num_9_btn_clicked() {
    expression += "9";
    screen_display(expression);
}

void MainWindow::on_op_add_btn_clicked() {
    expression += "+";
    screen_display(expression);
}

void MainWindow::on_op_sub_btn_clicked() {
    expression += "-";
    screen_display(expression);
}

void MainWindow::on_op_mul_btn_clicked() {
    expression += "*";
    screen_display(expression);
}

void MainWindow::on_op_div_btn_clicked() {
    expression += "/";
    screen_display(expression);
}

void MainWindow::on_op_dot_btn_clicked() {
    expression += ".";
    screen_display(expression);
}

void MainWindow::on_op_lbr_btn_clicked() {
    expression += "(";
    screen_display(expression);
}

void MainWindow::on_op_rbr_btn_clicked() {
    expression += ")";
    screen_display(expression);
}

void MainWindow::on_op_equ_btn_clicked() {
    delete cal;
    cal = new Calculate (expression, precision);
    result = cal->get_value();
    if (result == "") result = "Wrong!";
    screen_display(result);
}

void MainWindow::on_op_clear_btn_clicked() {
    expression.clear();
    expression = "";
    screen_display(expression);
}

void MainWindow::on_op_postfix_btn_clicked() {
    delete i2p;
    i2p = new Infix2Postfix (expression);
    result = i2p->to_postfix();
    if (result == "") result = "Wrong!";
    screen_display(result);
}

void MainWindow::on_prec_edit_valueChanged(int prec) {
    precision = prec;
}
