#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags((windowFlags()&(~(Qt::WindowMinimizeButtonHint))));
    setFixedSize(size());
    loremIpsum="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    connect(ui->promptBtn,&QPushButton::clicked,[=](){
        PromptDialog *dialog=new PromptDialog("Enter some text",loremIpsum,this);
        connect(dialog,&PromptDialog::accepted,this,&MainWindow::promptDialogAccepted);
        dialog->show();
    });
    connect(ui->promptBtn2,&QPushButton::clicked,[=](){
        PromptDialog *dialog=new PromptDialog("Enter some text","This prompt dialog only has one line of text.",this);
        connect(dialog,&PromptDialog::accepted,this,&MainWindow::promptDialogAccepted);
        dialog->show();
    });
    connect(ui->staticPromptBtn,&QPushButton::clicked,[=](){
        bool accepted;
        QString result=PromptDialog::prompt("Enter some text",loremIpsum,&accepted);
        if(!accepted)
            return;
        QMessageBox::information(this,"PromptDialog result","You entered:\n"+result);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::promptDialogAccepted()
{
    // This must be a slot in order for us to be able to capture "sender()"
    PromptDialog *p=(PromptDialog*)sender();
    QMessageBox::information(this,"PromptDialog result","You entered:\n"+p->enteredText);
}
