TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += includes/

SOURCES += \
    src/AbstractState.cpp \
    src/ExpectArrayValue.cpp \
    src/ExpectColonState.cpp \
    src/ExpectCommaOrEndState.cpp \
    src/ExpectKeyState.cpp \
    src/ExpectValueState.cpp \
    src/qqjson.cpp \
    src/qqjson_array.cpp \
    src/qqjson_boolen.cpp \
    src/qqjson_null.cpp \
    src/qqjson_number.cpp \
    src/qqjson_object.cpp \
    src/QQJsonContext.cpp \
    src/qqjsondocument.cpp \
    src/QQJsonEncoder.cpp \
    src/qqjsonkey.cpp \
    src/qqjsonstring.cpp \
    src/qqjsonx.cpp \
    src/StartState.cpp \
    example/main.cpp

HEADERS += \
    includes/AbstractContext.h \
    includes/AbstractState.h \
    includes/ExpectArrayValue.h \
    includes/ExpectColonState.h \
    includes/ExpectCommaOrEndState.h \
    includes/ExpectKeyState.h \
    includes/ExpectValueState.h \
    includes/qqjson.h \
    includes/qqjson_array.h \
    includes/qqjson_boolen.h \
    includes/qqjson_null.h \
    includes/qqjson_number.h \
    includes/qqjson_object.h \
    includes/QQJsonCommon.h \
    includes/QQJsonContext.h \
    includes/qqjsondocument.h \
    includes/QQJsonEncoder.h \
    includes/qqjsonkey.h \
    includes/qqjsonstring.h \
    includes/qqjsonx.h \
    includes/StartState.h
