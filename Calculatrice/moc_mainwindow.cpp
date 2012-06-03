/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Jun 3 15:19:19 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      24,   11,   11,   11, 0x0a,
      36,   11,   11,   11, 0x0a,
      48,   11,   11,   11, 0x0a,
      60,   11,   11,   11, 0x0a,
      72,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     108,   11,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     144,   11,   11,   11, 0x0a,
     157,   11,   11,   11, 0x0a,
     169,   11,   11,   11, 0x0a,
     181,   11,   11,   11, 0x0a,
     194,   11,   11,   11, 0x0a,
     208,   11,   11,   11, 0x0a,
     223,   11,   11,   11, 0x0a,
     236,   11,   11,   11, 0x0a,
     247,   11,   11,   11, 0x0a,
     263,   11,   11,   11, 0x0a,
     277,   11,   11,   11, 0x0a,
     290,   11,   11,   11, 0x0a,
     304,   11,   11,   11, 0x0a,
     319,   11,   11,   11, 0x0a,
     331,   11,   11,   11, 0x0a,
     344,   11,   11,   11, 0x0a,
     355,   11,   11,   11, 0x0a,
     367,   11,   11,   11, 0x0a,
     378,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0Num1Press()\0Num2Press()\0"
    "Num3Press()\0Num4Press()\0Num5Press()\0"
    "Num6Press()\0Num7Press()\0Num8Press()\0"
    "Num9Press()\0Num0Press()\0ComaPress()\0"
    "CmplxPress()\0ExprPress()\0PlusPress()\0"
    "MoinsPress()\0EntrerPress()\0MenuComplexe()\0"
    "MenuEntier()\0MenuReel()\0MenuRationnel()\0"
    "MenuClavier()\0MenuDegres()\0MenuRadians()\0"
    "AnnulerPress()\0SwapPress()\0ClearPress()\0"
    "DupPress()\0DropPress()\0SumPress()\0"
    "MeanPress()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->Num1Press(); break;
        case 1: _t->Num2Press(); break;
        case 2: _t->Num3Press(); break;
        case 3: _t->Num4Press(); break;
        case 4: _t->Num5Press(); break;
        case 5: _t->Num6Press(); break;
        case 6: _t->Num7Press(); break;
        case 7: _t->Num8Press(); break;
        case 8: _t->Num9Press(); break;
        case 9: _t->Num0Press(); break;
        case 10: _t->ComaPress(); break;
        case 11: _t->CmplxPress(); break;
        case 12: _t->ExprPress(); break;
        case 13: _t->PlusPress(); break;
        case 14: _t->MoinsPress(); break;
        case 15: _t->EntrerPress(); break;
        case 16: _t->MenuComplexe(); break;
        case 17: _t->MenuEntier(); break;
        case 18: _t->MenuReel(); break;
        case 19: _t->MenuRationnel(); break;
        case 20: _t->MenuClavier(); break;
        case 21: _t->MenuDegres(); break;
        case 22: _t->MenuRadians(); break;
        case 23: _t->AnnulerPress(); break;
        case 24: _t->SwapPress(); break;
        case 25: _t->ClearPress(); break;
        case 26: _t->DupPress(); break;
        case 27: _t->DropPress(); break;
        case 28: _t->SumPress(); break;
        case 29: _t->MeanPress(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
