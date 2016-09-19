#ifndef PROMPTDIALOG_H
#define PROMPTDIALOG_H

#include <QDialog>

namespace Ui {
class PromptDialog;
}

class PromptDialog : public QDialog
{
    Q_OBJECT

public:
    QString enteredText;

    explicit PromptDialog(QString title, QString labelText, QWidget *parent = 0);
    ~PromptDialog();

    static QString prompt(QString title, QString labelText, bool *accepted = 0);

private:
    Ui::PromptDialog *ui;
};

#endif // PROMPTDIALOG_H
