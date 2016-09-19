#include "promptdialog.h"
#include "ui_promptdialog.h"

PromptDialog::PromptDialog(QString title, QString labelText, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PromptDialog)
{
    enteredText="";

    ui->setupUi(this);
    setWindowFlags(windowFlags()&(~(Qt::WindowContextHelpButtonHint)));
    setWindowTitle(title);
    ui->label->setText(labelText);
    ui->textBox->setFocus();
    connect(ui->textBox,&QLineEdit::returnPressed,[=](){ui->okBtn->click();});
    connect(ui->okBtn,&QPushButton::clicked,[=](){enteredText=ui->textBox->text(); this->accept();});
    connect(ui->cancelBtn,&QPushButton::clicked,[=](){enteredText=ui->textBox->text(); this->reject();});
}

PromptDialog::~PromptDialog()
{
    delete ui;
}

QString PromptDialog::prompt(QString title, QString labelText, bool *accepted)
{
    PromptDialog *p=new PromptDialog(title,labelText);
    p->exec();
    if(accepted!=0)
        *accepted=(p->result()==QDialog::Accepted);
    QString t=p->enteredText;
    delete p;
    return t;
}
