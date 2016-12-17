TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
# CONFIG -= qt
CONFIG += qt
QT += core
CONFIG += c++11

SOURCES += main.cpp \
    ScreenBuffer.cpp \
    Shapes.cpp \
    Rectangle.cpp \
    Ellipse.cpp \
    Triangle.cpp \
    CoordinateAxes.cpp \
    FunctionPlot.cpp \
    Line.cpp \



HEADERS += \
    Point.h \
    ScreenBuffer.h \
    Canvas.h \
    Shapes.h \
    Paintable.h \
    Shape.h \
    Rectangle.h \
    Ellipse.h \
    Triangle.h \
    CoordinateAxes.h \
    FunctionPlot.h \
    Factory.h \
    line.h \
    Persistent.h \
    Variant.h \
    VariantMap.h


