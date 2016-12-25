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
    Triangle.cpp \
    CoordinateAxes.cpp \
    FunctionPlot.cpp \
    Circle.cpp

HEADERS += \
    Point.h \
    ScreenBuffer.h \
    Canvas.h \
    Shapes.h \
    Paintable.h \
    Shape.h \
    Rectangle.h \
    Triangle.h \
    CoordinateAxes.h \
    FunctionPlot.h \
    Factory.h \
    Variant.h \
    VariantMap.h \
    Persistent.h \
    Circle.h
