#include "sourceselect.h"
#include "ui_sourceselect.h"

SourceSelect::SourceSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SourceSelect)
{
    ui->setupUi(this);
}

SourceSelect::~SourceSelect()
{
    delete ui;
}
