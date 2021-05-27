#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
double pi = 3.1415926535;

double f_num_grad;
double f_num_min;
double f_num_sec;
double f_num;

double s_num_grad;
double s_num_min;
double s_num_sec;
double s_num;

bool znak=true;
bool znak2=true;

bool second=false;

bool minuse=false;

int reslult_grad;
int reslult_min;
int reslult_sec;
int reslult;

bool si=false;
bool co=false;
bool tg=false;
bool ctg=false;

bool asi=false;
bool aco=false;
bool atg=false;
bool act=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Button0,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button1,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button2,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button3,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button4,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button5,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button6,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button7,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button8,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->Button9,SIGNAL(clicked()),this,SLOT(numbers()));

    connect(ui->Button_plus_minuse,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->Button_point,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->Button_grad,SIGNAL(clicked()),this,SLOT(grad()));

    connect(ui->Button_min,SIGNAL(clicked()),this,SLOT(minute()));
    connect(ui->Button_sec,SIGNAL(clicked()),this,SLOT(sec()));


    connect(ui->Button_delete,SIGNAL(clicked()),this,SLOT(del()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers()
{
   QPushButton *button = (QPushButton *)sender();

   double num;
   QString new_label;
   num=(ui->Result->text()+button->text()).toDouble();
   new_label=QString::number(num,'g',15);

   ui->Result->setText(new_label);
}

void MainWindow::operations()
{
   QPushButton *button = (QPushButton *)sender();
   double num;
   QString new_label;

  if (button->text()=="+/-")
   {
       num=(ui->Result->text()).toDouble();
       num=num*-1;
       new_label=QString::number(num,'g',15);
       ui->Result->setText(new_label);
   }
  if (button->text()==".")
   {
       num=(ui->Result->text()).toDouble();

       new_label=QString::number(num,'g',15);
       ui->Result->setText(new_label+'.');
   }
}

void MainWindow::grad()
{
    if (second==true)
    {
        if((ui->label->text().contains("+")))
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);


            QString new_label;
            s_num_grad=(ui->Result->text()).toDouble();
            if (s_num_grad<0) znak2=false;
            while (s_num_grad>360) {s_num_grad-=360;}
            while (s_num_grad<-360) {s_num_grad+=360;}
            new_label=QString::number(s_num_grad,'g',15);
            if (znak2==false)
            {
                ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + ("+new_label+"°)");
            }
            else
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + "+new_label+"°");
            ui->Result->setText("");
        }
        if(minuse==true)
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);


            QString new_label;
            s_num_grad=(ui->Result->text()).toDouble();
            if (s_num_grad<0) znak2=false;
            while (s_num_grad>360) {s_num_grad-=360;}
            while (s_num_grad<-360) {s_num_grad+=360;}
            new_label=QString::number(s_num_grad,'g',15);
            if (znak2==false)
            {
                ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - ("+new_label+"°)");
                ui->Result->setText("");
            }
            else
            {
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - "+new_label+"°");
            ui->Result->setText("");
            }
        }
    }
   if(!(ui->label->text().contains("°")))
   {
   QString new_label;
   f_num_grad=(ui->Result->text()).toDouble();
   if (f_num_grad<0) znak=false;
   while (f_num_grad>360) {f_num_grad-=360;}
   while (f_num_grad<-360) {f_num_grad+=360;}
   new_label=QString::number(f_num_grad,'g',15);
   ui->label->setText(new_label+"°");
   ui->Result->setText("");
   }
}
void MainWindow::del()
{
    f_num_grad=0;
    f_num_min=0;
    f_num_sec=0;
    f_num=0;

    s_num_grad=0;
    s_num_min=0;
    s_num_sec=0;
    s_num=0;

    znak=true;
    znak2=true;

    second=false;

    minuse=false;
    si=false;
    co=false;
    tg=false;
    ctg=false;

    asi=false;
    aco=false;
    atg=false;
    act=false;
    ui->label->setText("");
}
void MainWindow::minute()
{
        if (second==true)
        {
            if((ui->label->text().contains("+")))
            {
                QString new_label1;
                QString new_label2;
                QString new_label3;
                new_label1=QString::number(f_num_grad,'g',15);
                new_label2=QString::number(f_num_min,'g',15);
                new_label3=QString::number(f_num_sec,'g',15);



                QString new_label11;
                QString new_label22;
                s_num_min=(ui->Result->text()).toDouble();
                if (s_num_min<0) s_num_min*=-1;
                while (s_num_min>=60)
                {
                    s_num_min-=60;
                    s_num_grad++;
                    if (s_num_grad>360) {s_num_grad-=360;}
                }
                new_label11=QString::number(s_num_grad,'g',15);
                new_label22=QString::number(s_num_min,'g',15);
                if (znak2==false) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + ("+new_label11+"°"+new_label22+"′)");
                else
                ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + "+new_label11+"°"+new_label22+"′");
                ui->Result->setText("");
            }
            if(minuse==true)
            {
                QString new_label1;
                QString new_label2;
                QString new_label3;
                new_label1=QString::number(f_num_grad,'g',15);
                new_label2=QString::number(f_num_min,'g',15);
                new_label3=QString::number(f_num_sec,'g',15);



                QString new_label11;
                QString new_label22;
                s_num_min=(ui->Result->text()).toDouble();
                if (s_num_min<0) s_num_min*=-1;
                while (s_num_min>=60)
                {
                    s_num_min-=60;
                    s_num_grad++;
                    if (s_num_grad>360) {s_num_grad-=360;}
                }
                new_label11=QString::number(s_num_grad,'g',15);
                new_label22=QString::number(s_num_min,'g',15);
                if (znak2==false) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - ("+new_label11+"°"+new_label22+"′)");
                else
                ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - "+new_label11+"°"+new_label22+"′");
                ui->Result->setText("");
            }
        }

    if((ui->label->text().contains("°")))
    if(!(ui->label->text().contains("′")))
    {
        QString new_label1;
        QString new_label2;
        f_num_min=(ui->Result->text()).toDouble();
        if (f_num_min<0) f_num_min*=-1;
        while (f_num_min>=60)
        {
            f_num_min-=60;
            f_num_grad++;
            if (f_num_grad>360) {f_num_grad-=360;}
        }
        new_label1=QString::number(f_num_grad,'g',15);
        new_label2=QString::number(f_num_min,'g',15);
        ui->label->setText(new_label1+"° "+new_label2+"′");
        ui->Result->setText("");
    }
}
void MainWindow::sec()
{
    if (second==true)
    {
        if((ui->label->text().contains("+")))
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);

            QString new_label11;
            QString new_label22;
            QString new_label33;
            s_num_sec=(ui->Result->text()).toDouble();
            if (s_num_sec<0) s_num_sec*=-1;
            while (s_num_sec>=60)
            {
                s_num_sec-=60;
                s_num_min++;
                if (s_num_min>=60) {s_num_min-=60; s_num_grad++; if (s_num_grad>360) {s_num_grad-=360;}}
            }
            new_label11=QString::number(s_num_grad,'g',15);
            new_label22=QString::number(s_num_min,'g',15);
            new_label33=QString::number(s_num_sec,'g',15);
            if (znak2==false) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + ("+new_label11+"°"+new_label22+"′"+new_label33+"′′)");
            else
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + "+new_label11+"°"+new_label22+"′"+new_label33+"′′");
            ui->Result->setText("");
        }
        if(minuse==true)
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);

            QString new_label11;
            QString new_label22;
            QString new_label33;
            s_num_sec=(ui->Result->text()).toDouble();
            if (s_num_sec<0) s_num_sec*=-1;
            while (s_num_sec>=60)
            {
                s_num_sec-=60;
                s_num_min++;
                if (s_num_min>=60) {s_num_min-=60; s_num_grad++; if (s_num_grad>360) {s_num_grad-=360;}}
            }
            new_label11=QString::number(s_num_grad,'g',15);
            new_label22=QString::number(s_num_min,'g',15);
            new_label33=QString::number(s_num_sec,'g',15);
            if (znak2==false) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - ("+new_label11+"°"+new_label22+"′"+new_label33+"′′)");
            else
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - "+new_label11+"°"+new_label22+"′"+new_label33+"′′");
            ui->Result->setText("");
        }

    }
    if((ui->label->text().contains("°")))
    if((ui->label->text().contains("′")))
    if(!(ui->label->text().contains("′′")))
    {
        QString new_label1;
        QString new_label2;
        QString new_label3;
        f_num_sec=(ui->Result->text()).toDouble();
        if (f_num_sec<0) f_num_sec*=-1;
        while (f_num_sec>=60)
        {
            f_num_sec-=60;
            f_num_min++;
            if (f_num_min>=60) {f_num_min-=60; f_num_grad++; if (f_num_grad>360) {f_num_grad-=360;}}
        }
        new_label1=QString::number(f_num_grad,'g',15);
        new_label2=QString::number(f_num_min,'g',15);
        new_label3=QString::number(f_num_sec,'g',15);
        ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′");
        ui->Result->setText("");
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->Result->setText("");
}


void MainWindow::on_Button_plus_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + ");
            second=true;
        }

}

void MainWindow::on_Button_minuse_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - ");
            second=true;
            minuse=true;
        }
}

void MainWindow::on_Button_pro_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" × ");
            second=true;
        }
}

void MainWindow::on_Button_del_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" / ");
            second=true;
        }
}

void MainWindow::on_Button_str_clicked()
{
    QString new_label1;
    QString new_label2;
    QString new_label3;
    new_label1=QString::number(f_num_grad,'g',15);
    new_label2=QString::number(f_num_min,'g',15);
    new_label3=QString::number(f_num_sec,'g',15);


    if((ui->label->text().contains("×")))
    {
        QString new_label;
        s_num=(ui->Result->text()).toDouble();
        new_label=QString::number(s_num,'g',15);
        if (s_num<0) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" × ("+new_label+")");
        else
        ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" × "+new_label);
         ui->Result->setText("");
    }
    if((ui->label->text().contains("/")))
    {
        QString new_label;
        s_num=(ui->Result->text()).toDouble();
        new_label=QString::number(s_num,'g',15);
        if (s_num<0) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" / ("+new_label+")");
        else
        ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" / "+new_label);
         ui->Result->setText("");
    }
    if(!(ui->label->text().contains("×"))and !(ui->label->text().contains("/")))
    {
        QString new_label;
        f_num=(ui->Result->text()).toDouble();
        new_label=QString::number(f_num,'g',15);
        ui->label->setText(new_label);
        ui->Result->setText("");
    }
}

void MainWindow::on_Button_ravno_clicked()
{
    QString new_label1;
    QString new_label2;
    QString new_label3;
    new_label1=QString::number(f_num_grad,'g',15);
    new_label2=QString::number(f_num_min,'g',15);
    new_label3=QString::number(f_num_sec,'g',15);
    QString new_label11;
    QString new_label22;
    QString new_label33;
    new_label11=QString::number(s_num_grad,'g',15);
    new_label22=QString::number(s_num_min,'g',15);
    new_label33=QString::number(s_num_sec,'g',15);
    if (second==true)
    {
        if((ui->label->text().contains("+")))
        {

            if (znak==false)
            {
                f_num_min*=-1;
                f_num_sec*=-1;
            }
            if (znak2==false)
            {
                s_num_min*=-1;
                s_num_sec*=-1;
            }
            f_num=f_num_sec+f_num_min*60+f_num_grad*60*60;
            s_num=s_num_sec+s_num_min*60+s_num_grad*60*60;

            reslult=f_num-s_num;

            reslult_grad=reslult/3600;

            reslult_min=(reslult-reslult_grad*3600)/60;

            reslult_sec=(reslult-reslult_grad*3600-reslult_min*60);


            if (reslult<0)
            {
                reslult_min*=-1;
                reslult_sec*=-1;

            }

            QString new_label111=QString::number(reslult_grad,'g',15);
            QString new_label222=QString::number(reslult_min,'g',15);
            QString new_label333=QString::number(reslult_sec,'g',15);
            if (znak2==false) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + ("+new_label11+"°"+new_label22+"′"+new_label33+"′′)"+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            else
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" + "+new_label11+"°"+new_label22+"′"+new_label33+"′′"+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            ui->Result->setText("");
        }

        if(minuse==true)
        {

            if (znak==false)
            {
                f_num_min*=-1;
                f_num_sec*=-1;
            }
            if (znak2==false)
            {
                s_num_min*=-1;
                s_num_sec*=-1;
            }

            f_num=f_num_sec+f_num_min*60+f_num_grad*60*60;
            s_num=s_num_sec+s_num_min*60+s_num_grad*60*60;

            reslult=f_num-s_num;

            reslult_grad=reslult/3600;

            reslult_min=(reslult-reslult_grad*3600)/60;

            reslult_sec=(reslult-reslult_grad*3600-reslult_min*60);
            if (reslult<0)
            {
                reslult_min*=-1;
                reslult_sec*=-1;

            }

            QString new_label111=QString::number(reslult_grad,'g',15);
            QString new_label222=QString::number(reslult_min,'g',15);
            QString new_label333=QString::number(reslult_sec,'g',15);
            if (znak2==false) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - ("+new_label11+"°"+new_label22+"′"+new_label33+"′′)"+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            else
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" - "+new_label11+"°"+new_label22+"′"+new_label33+"′′"+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            ui->Result->setText("");
        }
        if((ui->label->text().contains("×")))
        {

            if (znak==false)
            {
                f_num_min*=-1;
                f_num_sec*=-1;
            }
            if (znak2==false)
            {
                s_num_min*=-1;
                s_num_sec*=-1;
            }
            f_num=f_num_sec+f_num_min*60+f_num_grad*60*60;
            reslult=f_num*s_num;
            reslult_grad=reslult/3600;

            reslult_min=(reslult-reslult_grad*3600)/60;

            reslult_sec=(reslult-reslult_grad*3600-reslult_min*60);

            if (reslult<0)
            {
                reslult_min*=-1;
                reslult_sec*=-1;

            }

            QString new_label111=QString::number(reslult_grad,'g',15);
            QString new_label222=QString::number(reslult_min,'g',15);
            QString new_label333=QString::number(reslult_sec,'g',15);
            QString new_label;

            new_label=QString::number(s_num,'g',15);

            if (s_num<0) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" × ("+new_label+")"+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            else
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" × "+new_label+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            ui->Result->setText("");
        }
        if((ui->label->text().contains("/")))
        {
            if (znak==false)
            {
                f_num_min*=-1;
                f_num_sec*=-1;
            }
            if (znak2==false)
            {
                s_num_min*=-1;
                s_num_sec*=-1;
            }
            f_num=f_num_sec+f_num_min*60+f_num_grad*60*60;
            reslult=f_num/s_num;
            reslult_grad=reslult/3600;

            reslult_min=(reslult-reslult_grad*3600)/60;

            reslult_sec=(reslult-reslult_grad*3600-reslult_min*60);

            if (reslult<0)
            {
                reslult_min*=-1;
                reslult_sec*=-1;

            }

            QString new_label111=QString::number(reslult_grad,'g',15);
            QString new_label222=QString::number(reslult_min,'g',15);
            QString new_label333=QString::number(reslult_sec,'g',15);
            QString new_label;

            new_label=QString::number(s_num,'g',15);

            if (s_num<0) ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" / ("+new_label+")"+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            else
            ui->label->setText(new_label1+"° "+new_label2+"′ "+new_label3+"′′"+" / "+new_label+"="+new_label111+"°"+new_label222+"′"+new_label333+"′′");
            ui->Result->setText("");
        }

        if(si==true)
        {
            f_num=f_num_grad*(pi/180)+(f_num_min/60)*(pi/180)+((f_num_sec/60)/60)*(pi/180);
            double r=sin(f_num);
            QString new_label=QString::number(r,'g',15);
            ui->label->setText("sin("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)"+"="+new_label);
        }
        if(co==true)
        {
            f_num=f_num_grad*(pi/180)+(f_num_min/60)*(pi/180)+((f_num_sec/60)/60)*(pi/180);
            double r=cos(f_num);
            QString new_label=QString::number(r,'g',15);
            ui->label->setText("cos("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)"+"="+new_label);
        }
        if(tg==true)
        {
            if ((f_num_grad==90 or f_num_grad==-90) and f_num_min==0 and f_num_sec==0) Error();
            else
            {
            f_num=f_num_grad*(pi/180)+(f_num_min/60)*(pi/180)+((f_num_sec/60)/60)*(pi/180);
            double r=tan(f_num);
            QString new_label=QString::number(r,'g',15);
            ui->label->setText("tg("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)"+"="+new_label);
            }
        }
        if(ctg==true)
        {
            if ((f_num_grad==0 or f_num_grad==180 or f_num_grad==360) and f_num_min==0 and f_num_sec==0) Error();
            else
            {
            f_num=f_num_grad*(pi/180)+(f_num_min/60)*(pi/180)+((f_num_sec/60)/60)*(pi/180);
            double r=1/tan(f_num);
            QString new_label=QString::number(r,'g',15);
            ui->label->setText("ctg("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)"+"="+new_label);
            }
        }
        if(asi==true)
        {
            if ((f_num>1) or (f_num<-1)) Error();
            else
            {
            int r=asin(f_num)/pi*180;
            QString new_label=QString::number(r,'g',15);
            QString new_label2=QString::number(f_num,'g',10);
            ui->label->setText("asin("+new_label2+")"+"="+new_label+"°");
            }
        }
        if(aco==true)
        {
            if ((f_num>1) or (f_num<-1)) Error();
            else
            {
            int r=acos(f_num)/pi*180;
            QString new_label=QString::number(r,'g',15);
            QString new_label2=QString::number(f_num,'g',10);
            ui->label->setText("acos("+new_label2+")"+"="+new_label+"°");
            }
        }
        if(atg==true)
        {

            int r=atan(f_num)/pi*180;
            QString new_label=QString::number(r,'g',15);
            QString new_label2=QString::number(f_num,'g',10);
            ui->label->setText("atg("+new_label2+")"+"="+new_label+"°");

        }
        if(act==true)
        {
            int r=atan(1/f_num)/pi*180;
            QString new_label=QString::number(r,'g',15);
            QString new_label2=QString::number(f_num,'g',10);
            ui->label->setText("actg("+new_label2+")"+"="+new_label+"°");
        }
    }


}
void MainWindow::Error()
{
    ui->label->setText("Error");
    f_num_grad=0;
    f_num_min=0;
    f_num_sec=0;
    f_num=0;

    s_num_grad=0;
    s_num_min=0;
    s_num_sec=0;
    s_num=0;

    znak=true;
    znak2=true;

    second=false;

    minuse=false;
    si=false;
    co=false;
    tg=false;
    ctg=false;

    asi=false;
    aco=false;
    atg=false;
    act=false;
}

void MainWindow::on_pushButton_sin_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            si=true;
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText("sin("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)");
        }
}


void MainWindow::on_pushButton_cos_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            co=true;
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText("cos("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)");
        }
}

void MainWindow::on_pushButton_tg_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            tg=true;
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText("tg("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)");
        }
}

void MainWindow::on_pushButton_ctg_clicked()
{
    if((ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            ctg=true;
            QString new_label1;
            QString new_label2;
            QString new_label3;
            new_label1=QString::number(f_num_grad,'g',15);
            new_label2=QString::number(f_num_min,'g',15);
            new_label3=QString::number(f_num_sec,'g',15);
            ui->label->setText("ctg("+new_label1+"° "+new_label2+"′ "+new_label3+"′′)");
        }

}

void MainWindow::on_pushButton_asin_clicked()
{
    if(!(ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            asi=true;

            QString new_label;
            new_label=QString::number(f_num,'g',15);
            ui->label->setText("asin("+new_label+")");
            ui->Result->setText("");
        }
}

void MainWindow::on_pushButton_acos_clicked()
{
    if(!(ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            aco=true;

            QString new_label;
            new_label=QString::number(f_num,'g',15);
            ui->label->setText("acos("+new_label+")");
            ui->Result->setText("");
        }
}

void MainWindow::on_pushButton_atg_clicked()
{
    if(!(ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            atg=true;

            QString new_label;
            new_label=QString::number(f_num,'g',15);
            ui->label->setText("atg("+new_label+")");
            ui->Result->setText("");
        }
}

void MainWindow::on_pushButton_actg_clicked()
{
    if(!(ui->label->text().contains("°")))
        if(!second)
        {
            second=true;
            act=true;

            QString new_label;
            new_label=QString::number(f_num,'g',15);
            ui->label->setText("actg("+new_label+")");
            ui->Result->setText("");
        }
}
