#include "About.h"
#include "ui_About.h"

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);
    ui->linkLabel->setOpenExternalLinks(true);
    this->setFixedSize(456, 269);

}

About::~About()
{
    delete ui;
}

void About::on_closeButton_clicked()
{
    this->close();
}
