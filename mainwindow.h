#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QDateTime>
#include <QtWidgets>
#include <QCalendarWidget>
#include <Customer.h>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void labelUpdate();

    void on_addAppointment_clicked();

private:
    QList<Person> customer;
    QTimer *timer;
    QLabel *time_label;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
