QT += widgets multimedia multimediawidgets

HEADERS       = mainwindow.h \
                mdichild.h \
                camera.h \
                imagesettings.h \
                videosettings.h

SOURCES       = main.cpp \
                mainwindow.cpp \
                mdichild.cpp \
                camera.cpp \
                imagesettings.cpp \
                videosettings.cpp

FORMS += \
    camera.ui \
    videosettings.ui \
    imagesettings.ui

RESOURCES     = mdi.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/mdi
INSTALLS += target
