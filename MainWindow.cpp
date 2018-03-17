/*******************************************************************/

/* Original File Name: MainWindow.cpp                              */

/* Date: 17-03-2018                                                */

/* Developer: Dionysus Benstein                                    */

/* Copyright: Dionysus Benstein LTD                                */

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод шифрования текста
QString encrypt(QString str, int key)
{
    //Инициализация строк с алфавитом, знаками и цифрами
    QString high_en_alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString low_en_alph = "abcdefghijklmnopqrstuvwxyz";
    QString high_ru_alph = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    QString low_ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString signs = "!\"#$%^&*()+=-_'?.,|/`~№:;@[]{}";
    QString numbers = "0123456789";

    QString output;

    //Посимвольное прохождение по введённой строке
    for (int i = 0; i < str.length(); ++i)
    {
        //Если в введённой строке встречается пробел, то он остаётся неизменённым
        if(str[i] == ' ')
        {
            output += ' ';
        }

        //Посимвольное прохождение по английскому алфавиту в верхнем регистре
        for (int j = 0; j < high_en_alph.length(); ++j)
        {
            if (high_en_alph[j] == str[i]) //Нахождение совпадений в алфавите
            {
                if ((j + key) > 25) //Проверка на выход за границы массива
                {
                    //Сдвиг индекса в начало алфавита
                    output += high_en_alph[(j - 26) + key];
                }
                else
                {
                    //Сдвиг j-элемента на key позиций вправо
                    output += high_en_alph[j + key];
                }
            }
        }

        //Посимвольное прохождение по английскому алфавиту в нижнем регистре
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

        //Посимвольное прохождение по русскому алфавиту в верхнем регистре
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

        //Посимвольное прохождение по русскому алфавиту в нижнем регистре
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

        //Посимвольное прохождение по строчке со знаками
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

        //Посимвольное прохождение по строчке с цифрами
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
QString decrypt(QString str, int key)
{
    //Инициализация строк с алфавитом, знаками и цифрами
    QString high_en_alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString low_en_alph = "abcdefghijklmnopqrstuvwxyz";
    QString high_ru_alph = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    QString low_ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString signs = "!\"#$%^&*()+=-_'?.,|/`~№:;@[]{}";
    QString numbers = "0123456789";

    QString output;

    //Посимвольное прохождение по введённой строке
    for (int i = 0; i < str.length(); ++i)
    {
        //Если в введённой строке встречается пробел, то он остаётся неизменённым
        if(str[i] == ' ')
        {
            output += ' ';
        }

        //Посимвольное прохождение по английскому алфавиту в верхнем регистре
        for (int j = 0; j < high_en_alph.length(); ++j)
        {
            if (high_en_alph[j] == str[i]) //Нахождение совпадений в алфавите
            {
                if ((j - key) < 0) //Проверка на выход за границы массива
                {
                    //Сдвиг индекса в конец алфавита
                    output += high_en_alph[(j + 26) - key];
                }
                else
                {
                    //Сдвиг j-элемента на key позиций влево
                    output += high_en_alph[j - key];
                }
            }
        }

        //Посимвольное прохождение по английскому алфавиту в нижнем регистре
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

        //Посимвольное прохождение по русскому алфавиту в верхнем регистре
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

        //Посимвольное прохождение по русскому алфавиту в нижнем регистре
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

        //Посимвольное прохождение по строчке со знаками
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

        //Посимвольное прохождение по строчке с цифрами
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
    clipboard = QApplication::clipboard(); //Выделение памяти под буфер обмена
    clipboard->setText(ui->output->text()); //Установка текста из поля output в буфер обмена

    //Если поле input пустое, то сообщение о копировании в StatusBar не выводится
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
    //Если поле input не пустое, там нет пробелов или табуляций
    if (!(ui->input->text().isEmpty() || ui->input->text() == " " || ui->input->text() == "\t"))
    {
        //и если значения ключа не равно 0
        if (ui->keyValue->value() != 0)
        {
            //вызывается функция шифрования
            ui->output->setText(encrypt(ui->input->text(), ui->keyValue->value()));
            //и выводится сообщение в StatusBar
            ui->statusBar->showMessage("Текст успешно зашифрован");
        }
        else
        {
            //Иначе в output присваивается не зашифрованный текст
            ui->output->setText(ui->input->text());
            ui->statusBar->showMessage(""); //и сообщение не выводится
        }
    }
    else
    {
        //Иначе в output присваивается не зашифрованный текст
        ui->output->setText(ui->input->text());
        ui->statusBar->showMessage(""); //и сообщение не выводится
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
    //Проверка на состояние RadioButton "Зашифровать"
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
    //Проверка на состояние RadioButton "Расшифровать"
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
    //Проверка на состояние RadioButton "Зашифровать"
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
    //Проверка на состояние RadioButton "Расшифровать"
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
    aboutWnd = new About; //Выделение памяти под окно "О программе"
    aboutWnd->setModal(true); //Установка в качестве модального окна
    aboutWnd->exec(); //Запуск цикла обработки событий
}
