#include "../headers/sourceselect.h"
#include "ui_sourceselect.h"
#include <QCameraInfo>
#include <QMessageBox>

SourceSelect::SourceSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SourceSelect)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);
    ScanForDevices();
}

SourceSelect::~SourceSelect()
{
    delete ui;
}

void SourceSelect::ScanForDevices() {
    cameras = QCameraInfo::availableCameras();
    for (int i = 0; i < cameras.size(); i++) {
        QListWidgetItem *newItem = new QListWidgetItem(cameras[i].description());

        QVariant v;
        v.setValue(cameras[i].deviceName());
        newItem->setData(Qt::UserRole, v);
        ui->sourceList->addItem(newItem);
    }
}

void SourceSelect::on_sourceList_itemClicked(QListWidgetItem *item)
{
    for (int i = 0; i < cameras.size(); i++) {
        if (item->data(Qt::UserRole).toString() == cameras[i].deviceName()) {
            QCamera *selectedCamera = new QCamera(cameras[i]);
            selectedCamera->setViewfinder(ui->viewfinder);
            selectedCamera->start();
        }
    }

}

void SourceSelect::on_refreshButton_clicked()
{
    ScanForDevices();
}

void SourceSelect::on_addButton_clicked()
{

}
