#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void numbers();//Ввод чисел

    void operations();

    void grad();
    void minute();
    void sec();

    void del();
    void on_pushButton_clicked();
    void on_Button_plus_clicked();
    void on_Button_minuse_clicked();
    void on_Button_pro_clicked();
    void on_Button_del_clicked();
    void on_Button_str_clicked();


    void on_Button_ravno_clicked();



    void Error();
    void on_pushButton_sin_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_tg_clicked();
    void on_pushButton_ctg_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_atg_clicked();
    void on_pushButton_actg_clicked();
};
#endif // MAINWINDOW_H
