/*******************************************************************/

/* Original File Name: About.h                                     */

/* Date: 17-03-2018                                                */

/* Developer: Dionysus Benstein                                    */

/* Copyright © 2018 Dionysus Benstein. All rights reserved.        */

/* Description: Окно с информацией о программе                     */

/*******************************************************************/

#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private slots:
    //Слот обработки клика по кнопке "Закрыть"
    void on_closeButton_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
