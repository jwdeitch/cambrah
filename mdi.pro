QT += widgets multimedia multimediawidgets

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
