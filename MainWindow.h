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
    void on_copy_clicked();

    void on_encrypt_clicked();

    void on_decrypt_clicked();

    void on_keyValue_valueChanged(int arg1);

    void on_input_textChanged(const QString &arg1);

    void on_action_CaesarCode_triggered();

private:
    Ui::MainWindow *ui;
    QClipboard *clipboard;
    About *aboutWnd;
};

#endif // MAINWINDOW_H
