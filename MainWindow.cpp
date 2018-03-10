#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->keyValue->setMaximum(32);
    ui->apply->setText("&Зашифровать");
    ui->apply->setDefault(true);
    ui->encrypt->setChecked(true);
    ui->output->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString encrypt(QString str, int key)
{
    QString high_en_alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString low_en_alph = "abcdefghijklmnopqrstuvwxyz";
    QString high_ru_alph = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    QString low_ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString signs = "!\"#$%^&*()+=-_'?.,|/`~№:;@[]{}";
    QString numbers = "0123456789";

    QString output;

    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i] == ' ')
        {
            output += ' ';
        }

        for (int j = 0; j < high_en_alph.length(); ++j)
        {
            if (high_en_alph[j] == str[i])
            {
                if ((j + key) > 25)
                {
                    output += high_en_alph[(j - 26) + key];
                }
                else
                {
                    output += high_en_alph[j + key];
                }
            }
        }

        for (int j = 0; j < low_en_alph.length(); ++j)
        {
            if (low_en_alph[j] == str[i])
            {
                if ((j + key) > 25)
                {
                    output += low_en_alph[(j - 26) + key];
                }
                else
                {
                    output += low_en_alph[j + key];
                }
            }
        }

        for (int j = 0; j < high_ru_alph.length(); ++j)
        {
            if (high_ru_alph[j] == str[i])
            {
                if ((j + key) > 32)
                {
                    output += high_ru_alph[(j - 33) + key];
                }
                else
                {
                    output += high_ru_alph[j + key];
                }
            }
        }

        for (int j = 0; j < low_ru_alph.length(); ++j)
        {
            if (low_ru_alph[j] == str[i])
            {
                if ((j + key) > 32)
                {
                    output += low_ru_alph[(j - 33) + key];
                }
                else
                {
                    output += low_ru_alph[j + key];
                }
            }
        }

        for (int j = 0; j < signs.length(); ++j)
        {
            if (signs[j] == str[i])
            {
                if ((j + key) > 29)
                {
                    output += signs[(j - 30) + key];
                }
                else
                {
                    output += signs[j + key];
                }
            }
        }

        for (int j = 0; j < numbers.length(); ++j)
        {
            if (numbers[j] == str[i])
            {
                if ((j + key) > 9)
                {
                    output += numbers[(j - 10) + key];
                }
                else
                {
                    output += numbers[j + key];
                }
            }
        }
    }
    return output;
}

QString decrypt(QString str, int key)
{
    QString high_en_alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString low_en_alph = "abcdefghijklmnopqrstuvwxyz";
    QString high_ru_alph = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    QString low_ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString signs = "!\"#$%^&*()+=-_'?.,|/`~№:;@[]{}";
    QString numbers = "0123456789";

    QString output;

    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i] == ' ')
        {
            output += ' ';
        }

        for (int j = 0; j < high_en_alph.length(); ++j)
        {
            if (high_en_alph[j] == str[i])
            {
                if ((j - key) < 0)
                {
                    output += high_en_alph[(j + 26) - key];
                }
                else
                {
                    output += high_en_alph[j - key];
                }
            }
        }

        for (int j = 0; j < low_en_alph.length(); ++j)
        {
            if (low_en_alph[j] == str[i])
            {
                if ((j - key) < 0)
                {
                    output += low_en_alph[(j + 26) - key];
                }
                else
                {
                    output += low_en_alph[j - key];
                }
            }
        }

        for (int j = 0; j < high_ru_alph.length(); ++j)
        {
            if (high_ru_alph[j] == str[i])
            {
                if ((j - key) < 0)
                {
                    output += high_ru_alph[(j + 33) - key];
                }
                else
                {
                    output += high_ru_alph[j - key];
                }
            }
        }

        for (int j = 0; j < low_ru_alph.length(); ++j)
        {
            if (low_ru_alph[j] == str[i])
            {
                if ((j - key) < 0)
                {
                    output += low_ru_alph[(j + 33) - key];
                }
                else
                {
                    output += low_ru_alph[j - key];
                }
            }
        }

        for (int j = 0; j < signs.length(); ++j)
        {
            if (signs[j] == str[i])
            {
                if ((j - key) < 0)
                {
                    output += signs[(j + 30) - key];
                }
                else
                {
                    output += signs[j - key];
                }
            }
        }

        for (int j = 0; j < numbers.length(); ++j)
        {
            if (numbers[j] == str[i])
            {
                if ((j + key) < 0)
                {
                    output += numbers[(j + 10) - key];
                }
                else
                {
                    output += numbers[j - key];
                }
            }
        }
    }
    return output;
}


void MainWindow::on_apply_clicked()
{
    if (ui->encrypt->isChecked())
    {
        ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
        ui->statusBar->showMessage("Текст успешно зашифрован");
    }
    else if (ui->decrypt->isChecked())
    {
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

void MainWindow::on_keyValue_valueChanged(int arg1)
{
    if (ui->encrypt->isChecked())
    {
        ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
        ui->statusBar->showMessage("Текст успешно зашифрован");
    }
    else if (ui->decrypt->isChecked())
    {
        ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
        ui->statusBar->showMessage("Текст успешно расшифрован");
    }
}
