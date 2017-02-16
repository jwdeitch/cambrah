QT += widgets multimedia multimediawidgets

#INCLUDEPATH += /usr/local/Cellar/opencv/2.4.13.2/include/
#LIBS += `pkg-config opencv --libs`

QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
PKGCONFIG += opencv

HEADERS       = headers/mainwindow.h \
                headers/mdichild.h \
                headers/camera.h \
                headers/imagesettings.h \
                headers/videosettings.h \
                headers/sourceselect.h

SOURCES       = source/main.cpp \
                source/mainwindow.cpp \
                source/mdichild.cpp \
                source/camera.cpp \
                source/imagesettings.cpp \
                source/videosettings.cpp \
                source/sourceselect.cpp

FORMS += \
    ui/camera.ui \
    ui/videosettings.ui \
    ui/imagesettings.ui \
    ui/sourceselect.ui

RESOURCES     = mdi.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/mdi
INSTALLS += target
