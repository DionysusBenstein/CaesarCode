/*******************************************************************/

/* Original File Name: MainWindow.h                                */

/* Date: 17-03-2018                                                */

/* Developer: Dionysus Benstein                                    */

/* Copyright: Dionysus Benstein LTD                                */

/* Description: Главное окно с основным функционалом программы     */

/*******************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include "About.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Слот обработки клика по кнопке "Скопировать"
    void on_copy_clicked();

    //Слот обработки клика по RadioButton "Зашифровать"
    void on_encrypt_clicked();

    //Слот обработки клика по RadioButton "Расшифровать"
    void on_decrypt_clicked();

    //Слот обработки изменения значения в SpinBox
    void on_keyValue_valueChanged(int arg1);

    //Слот обработки изменения текста в поле input
    void on_input_textChanged(const QString &arg1);

    //Слот обработки изменения состояния пункта "О программе" в меню "Справка
    void on_action_CaesarCode_triggered();

private:
    Ui::MainWindow *ui;
    QClipboard *clipboard; //Объявление переменной управления буфером обмена
    About *aboutWnd; //Объявления окна "О программе"
};

#endif // MAINWINDOW_H
