#include "Tab_Host.h"
#include "ui_Tab_Host.h"

Tab_Host::Tab_Host(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab_Host)
{
    ui->setupUi(this);
}

Tab_Host::~Tab_Host()
{
    delete ui;
}
