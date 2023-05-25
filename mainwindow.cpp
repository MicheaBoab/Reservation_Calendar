#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    time_label = new QLabel(this);
    // link the label with time_label
    time_label = ui->time_label;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::labelUpdate);
    timer->start(60000);

    ui->lineEdit_Duration->setValidator(new QIntValidator(0, 120, this));
    ui->lineEdit_PersonCount->setValidator(new QIntValidator(0, 9, this));
    ui->lineEdit_Phone->setValidator(new QIntValidator(1111, 9999, this));

    labelUpdate();
}

// time count down
void MainWindow::labelUpdate(){
    QDateTime current_time = QDateTime::currentDateTime();

    if(time_label){
        time_label->setText(current_time.toString("yyyy-MM-dd hh:mm"));
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_addAppointment_clicked(){

    Person new_customer;

    new_customer.name = ui->lineEdit_Name->text();
    new_customer.person_count = ui->lineEdit_PersonCount->text();
    new_customer.start_time = ui->lineEdit_StartTime->text();
    new_customer.duration = ui->lineEdit_Duration->text();
    new_customer.comment = ui->label_Comment->text();

    if(ui->radioButton_Male->isChecked()){
        new_customer.sex = "男";
    }
    else{
        new_customer.sex = "女";
    }

    customer.append(new_customer);

    int row = ui->tableWidget_futureAppointment->rowCount();
    //int column = ui->tableWidget_futureAppointment->columnCount();

    ui->tableWidget_futureAppointment->setRowCount(row + 1);
    //ui->tableWidget_futureAppointment->setColumnCount(++column);
    ui->tableWidget_futureAppointment->setItem(row, 0, new QTableWidgetItem(new_customer.start_time));
    ui->tableWidget_futureAppointment->setItem(row, 1, new QTableWidgetItem(new_customer.duration));
    ui->tableWidget_futureAppointment->setItem(row, 2, new QTableWidgetItem(new_customer.person_count));
    ui->tableWidget_futureAppointment->setItem(row, 3, new QTableWidgetItem(new_customer.sex));

    ui->tableWidget_futureAppointment->show();
}

