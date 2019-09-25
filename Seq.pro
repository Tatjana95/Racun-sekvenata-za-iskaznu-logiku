QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    and.cpp \
    atom.cpp \
    atomic_formula.cpp \
    base_formula.cpp \
    binary_connective.cpp \
    iff.cpp \
    imp.cpp \
    not.cpp \
    or.cpp \
    sequent.cpp \
    unary_connective.cpp \
    constant.cpp \
    valuation.cpp \
    sources.cpp \
    proof.cpp

HEADERS += \
    and.h \
    atom.h \
    atomic_formula.h \
    atom_set.h \
    base_formula.h \
    iff.h \
    binary_connective.h \
    imp.h \
    not.h \
    or.h \
    sequent.h \
    unary_connective.h \
    constant.h \
    valuation.h \
    propositional_logic.h \
    proof.h
