/*******************************************************************/

/* Original File Name: MainWindow.h                                */

/* Date: 17-03-2018                                                */

/* Developer: Dionysus Benstein                                    */

/* Copyright © 2018 Dionysus Benstein. All rights reserved.        */

/* Description: Главное окно с основным функционалом программы     */

/*******************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define QT_NO_DEBUG //Объявлено, чтобы отключить проверку Q_ASSERT(cond)

#include <QMainWindow>
#include <QClipboard>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "About.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Метод шифрования текста
    QString encrypt(const QString str, const int key) const;

    //Метод дешифрования текста
    QString decrypt(const QString str, const int key) const;

private slots:
    //Слот обработки клика по кнопке "Скопировать"
    void on_copy_clicked();

    //Слот обработки клика по RadioButton "Зашифровать"
    void on_encrypt_clicked();

    //Слот обработки клика по RadioButton "Расшифровать"
    void on_decrypt_clicked();

    //Слот обработки изменения значения в SpinBox
    void on_keyValue_valueChanged();

    //Слот обработки изменения текста в поле input
    void on_input_textChanged();

    //Слот обработки изменения состояния пункта "О программе" в меню "Справка
    void on_action_CaesarCode_triggered();

    //Слот обработки изменения состояния пункта "Выход" в меню "Файл"
    void on_quit_triggered();

    //Слот обработки изменения состояния пункта "Открыть..." в меню "Файл"
    void on_open_triggered();

    //Слот обработки изменения состояния пункта "Сохранить как..." в меню "Файл"
    void on_save_as_triggered();

private:
    Ui::MainWindow *ui;
    QClipboard *clipboard;
    About *aboutWnd;

    //Объявление строк с алфавитом, знаками и цифрами
    QString high_en_alph;
    QString low_en_alph;
    QString high_ru_alph;
    QString low_ru_alph;
    QString signs;
    QString numbers;
};

#endif //MAINWINDOW_H
