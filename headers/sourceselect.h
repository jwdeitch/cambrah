#ifndef SOURCESELECT_H
#define SOURCESELECT_H

#include <QWidget>
#include <QCameraInfo>
#include <QList>
#include <QListWidgetItem>

namespace Ui {
class SourceSelect;
}

class SourceSelect : public QWidget
{
    Q_OBJECT

public:
    explicit SourceSelect(QWidget *parent = 0);
    void ScanForDevices();
    ~SourceSelect();

private slots:
    void on_sourceList_itemClicked(QListWidgetItem *item);

private:
    Ui::SourceSelect *ui;
    QList<QCameraInfo> cameras;
};

#endif // SOURCESELECT_H
