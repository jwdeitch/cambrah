#ifndef SOURCESELECT_H
#define SOURCESELECT_H

#include <QWidget>

namespace Ui {
class SourceSelect;
}

class SourceSelect : public QWidget
{
    Q_OBJECT

public:
    explicit SourceSelect(QWidget *parent = 0);
    ~SourceSelect();

private:
    Ui::SourceSelect *ui;
};

#endif // SOURCESELECT_H
