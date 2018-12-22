TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    input_params.c \
    hex_convertor.c \
    hex_parser.c

HEADERS += \
    input_params.h \
    hex_convertor.h \
    hex_parser.h
