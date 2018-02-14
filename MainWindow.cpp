#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QClipboard>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->keyValue->setMaximum(25);
    ui->apply->setDefault(true);
    ui->apply->setText("&Зашифровать");
    ui->encrypt->setChecked(true);
    ui->output->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString encrypt(QString str, int key)
{
    for (int i = 0; i < str.length(); i++)
    {
        int sym = 0;

        if (str[i].toLatin1() > 64 && str[i].toLatin1() < 91 && (sym = str[i].toLatin1() + key) > 90)
        {
            str[i] = QChar(sym - 90 + 64);
        }
        else if(str[i].toLatin1() > 96 && str[i].toLatin1() < 123 && (sym = str[i].toLatin1() + key) > 122)
        {
            str[i] = QChar(sym - 122 + 96);
        }
        else
        {
            str[i] = QChar(str[i].toLatin1() + key);
        }
    }
    return str;
}

QString decrypt(QString str, int key)
{
    for (int i = 0; i < str.length(); i++)
    {
        int sym = 0;

        if(str[i].toLatin1() > 64 && str[i].toLatin1() < 91 && (sym = str[i].toLatin1() - key) < 65)
        {
            str[i] = QChar(sym - 64 + 90);
        }
        else if(str[i].toLatin1() > 96 && str[i].toLatin1() < 123 && (sym = str[i].toLatin1() - key) < 97)
        {
            str[i] = QChar(sym - 96 + 122);
        }
        else
        {
            str[i] = QChar(str[i].toLatin1() - key);
        }
    }
    return str;
}

void MainWindow::on_apply_clicked()
{

    if (ui->encrypt->isChecked())
    {

//        int key = ui->keyValue->value();
//        QString str = ui->input->text();
//        QString res = str;

//        for(int i = 0; i < res.length(); i++)
//        {
//            res[i] = res[i].toLatin1() + key;
//        }

        ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
        ui->statusBar->showMessage("Текст успешно зашифрован");
    }
    else if (ui->decrypt->isChecked())
    {

//        int key = ui->keyValue->value();
//        QString str = ui->input->text();
//        QString res = str;

//        for(int i = 0; i < res.length(); i++)
//        {
//            res[i] = res[i].toLatin1() - key;
//        }

        ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
        ui->statusBar->showMessage("Текст успешно расшифрован");
    }
}

void MainWindow::on_encrypt_clicked()
{
    ui->apply->setText("&Зашифровать");
}

void MainWindow::on_decrypt_clicked()
{
    ui->apply->setText("&Расшифровать");
}

void MainWindow::on_copy_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->output->text());
}
