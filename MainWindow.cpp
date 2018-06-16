/*******************************************************************/

/* Original File Name: MainWindow.cpp                              */

/* Date: 17-03-2018                                                */

/* Developer: Dionysus Benstein                                    */

/* Copyright © 2018 Dionysus Benstein. All rights reserved.        */

/* Description: Главное окно с основным функционалом программы     */

/*******************************************************************/

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Установка значений по умолчанию
    ui->keyValue->setMaximum(32);
    ui->encrypt->setChecked(true);
    ui->output->setReadOnly(true);
    MainWindow::setWindowTitle("CaesarCode v1.5.10");

    high_en_alph  =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    low_en_alph   =  "abcdefghijklmnopqrstuvwxyz";
    high_ru_alph  =  "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    low_ru_alph   =  "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    signs         =  "!\"#$%^&*()+=-_'?.,|/`~№:;@[]{}";
    numbers       =  "0123456789";
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод шифрования текста
QString MainWindow::encrypt(const QString str, const int key) const
{
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

//Метод дешифрования текста
QString MainWindow::decrypt(const QString str, const int key) const
{
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

//Слот обработки клика по кнопке "Скопировать"
void MainWindow::on_copy_clicked()
{
    clipboard = QApplication::clipboard();
    clipboard->setText(ui->output->text());

    if (ui->input->text().isEmpty())
    {
        ui->statusBar->showMessage("");
    }
    else
    {
        ui->statusBar->showMessage("Скопировано в буфер обмена");
    }
}

//Слот обработки клика по RadioButton "Зашифровать"
void MainWindow::on_encrypt_clicked()
{
    if (!(ui->input->text().isEmpty() || ui->input->text() == " " || ui->input->text() == "\t"))
    {
        if (ui->keyValue->value() != 0)
        {
            ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
            ui->statusBar->showMessage("Текст успешно зашифрован");
        }
        else
        {
            ui->output->setText(ui->input->text());
            ui->statusBar->showMessage("");
        }
    }
    else
    {
        ui->output->setText(ui->input->text());
        ui->statusBar->showMessage("");
    }
}

//Слот обработки клика по RadioButton "Расшифровать"
void MainWindow::on_decrypt_clicked()
{
    if (!(ui->input->text().isEmpty() || ui->input->text() == " " || ui->input->text() == "\t"))
    {
        if (ui->keyValue->value() != 0)
        {
            ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
            ui->statusBar->showMessage("Текст успешно расшифрован");
        }
        else
        {
            ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
            ui->statusBar->showMessage("");
        }
    }
    else
    {
        ui->output->setText(ui->input->text());
        ui->statusBar->showMessage("");
    }
}

//Слот обработки изменения значения в SpinBox
void MainWindow::on_keyValue_valueChanged(int arg1)
{
    if (ui->encrypt->isChecked())
    {
        if (!(ui->input->text().isEmpty() || ui->input->text() == " " || ui->input->text() == "\t"))
        {
            if (ui->keyValue->value() != 0)
            {
                ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("Текст успешно зашифрован");
            }
            else
            {
                ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("");
            }
        }
        else
        {
            ui->output->setText(ui->input->text());
            ui->statusBar->showMessage("");
        }
    }
    else if (ui->decrypt->isChecked())
    {
        if (!(ui->input->text().isEmpty() || ui->input->text() == " " || ui->input->text() == "\t"))
        {
            if (ui->keyValue->value() != 0)
            {
                ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("Текст успешно расшифрован");
            }
            else
            {
                ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("");
            }
        }
        else
        {
            ui->output->setText(ui->input->text());
            ui->statusBar->showMessage("");
        }
    }
}

//Слот обработки изменения текста в поле input
void MainWindow::on_input_textChanged(const QString &arg1)
{
    if (ui->encrypt->isChecked())
    {
        if (!(ui->input->text().isEmpty() || ui->input->text() == " " || ui->input->text() == "\t"))
        {
            if (ui->keyValue->value() != 0)
            {
                ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("Текст успешно зашифрован");
            }
            else
            {
                ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("");
            }
        }
        else
        {
            ui->output->setText(ui->input->text());
            ui->statusBar->showMessage("");
        }
    }
    else if (ui->decrypt->isChecked())
    {
        if (!(ui->input->text().isEmpty() || ui->input->text() == " " || ui->input->text() == "\t"))
        {
            if (ui->keyValue->value() != 0)
            {
                ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("Текст успешно расшифрован");
            }
            else
            {
                ui->output->setText(decrypt(ui->input->text(), ui->keyValue->value()));
                ui->statusBar->showMessage("");
            }
        }
        else
        {
            ui->output->setText(ui->input->text());
            ui->statusBar->showMessage("");
        }
    }
}

//Слот обработки изменения состояния пункта "О программе" в меню "Справка
void MainWindow::on_action_CaesarCode_triggered()
{
    aboutWnd = new About;
    aboutWnd->setModal(true); //Установка в качестве модального окна
    aboutWnd->exec(); //Запуск цикла обработки событий
}

//Слот обработки изменения состояния пункта "Выход" в меню "Файл"
void MainWindow::on_quit_triggered()
{
    this->close();
}

//Слот обработки изменения состояния пункта "Открыть..." в меню "Файл"
void MainWindow::on_open_triggered()
{
    //Создаётся диалоговое окно для открытия файла
    QString fileName = QFileDialog::getOpenFileName(this, "Открытие", "C:\\", "Текстовые документы (*.txt)");

    //Проверка на успешное создание диалогового окна для открытия файла
    if (!fileName.isEmpty())
    {
        QFile file(fileName); //Открывется полученный файл

        //----------------------------------------------------------------------------//
        //Проверка на ошибки                                                          //
        //Для возможности записи или чтения необходимо открыть файл с указанием флага //
        //чтения QIODevice::ReadOnly или записи QIODevice::WriteOnly.                 //
        if (!file.open(QIODevice::ReadOnly))                                          //
        {                                                                             //
            //Если возники ошибки, то вызывается сообщение об ошибке                  //
            QMessageBox::critical(this, "Ошибка", "Невозможно открыть файл");         //
        }                                                                             //
        //----------------------------------------------------------------------------//

        QTextStream in(&file);
        ui->input->setText(in.readAll());
        file.close();
    }
}

//Слот обработки изменения состояния пункта "Сохранить как..." в меню "Файл"
void MainWindow::on_save_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранение", "C:\\", "Текстовые документы (*.txt)");

    if(!fileName.isEmpty())
    {
        QFile file(fileName);

        //Проверка на ошибки
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, "Ошибка", "Невозможно открыть файл");
        }

        //Запись в файл
        QTextStream out(&file);
        out << ui->output->text();

        //----------------------------------------------------------------------------//
        //Данные сразу не записываются в файл на накопителе, они записываются         //
        //в буфер в оперативной памяти. После закрытия файла данные из буфера         //
        //записываются в файл на носителе. Это сделано для того, чтобы не нагружать   //
        //жесткий диск или любой другой тип накопителя, на котором находится файл.    //
        //Информацию из буфера в файл можно записать принудительно без закрытия файла,//
        //вызвав метод QFile::flush()                                                 //
        file.flush();                                                                 //
        //----------------------------------------------------------------------------//

        file.close();
    }
}
