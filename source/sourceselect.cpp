#include "../headers/sourceselect.h"
#include "ui_sourceselect.h"
#include <QCameraInfo>
#include <QMessageBox>

//using namespace cv;

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

//Mat differenceFrame( Mat prev_frame, Mat curr_frame )
//{
//    Mat image = prev_frame.clone();
//    printf("frame rows %d Cols %d\n" , image.rows, image.cols);

//    for (int rows = 0; rows < image.rows; rows++)
//    {
//        for (int cols = 0; cols < image.cols; cols++)
//        {

//            image.at<cv::Vec3b>(rows,cols)[0] = abs(prev_frame.at<cv::Vec3b>(rows,cols)[0] -
//                                              curr_frame.at<cv::Vec3b>(rows,cols)[0]);
//            image.at<cv::Vec3b>(rows,cols)[1] = abs(prev_frame.at<cv::Vec3b>(rows,cols)[1] -
//                                              curr_frame.at<cv::Vec3b>(rows,cols)[1]);
//            image.at<cv::Vec3b>(rows,cols)[2] = abs(prev_frame.at<cv::Vec3b>(rows,cols)[2] -
//                                              curr_frame.at<cv::Vec3b>(rows,cols)[2]);
//        }
//    }
//    return image;
//}
