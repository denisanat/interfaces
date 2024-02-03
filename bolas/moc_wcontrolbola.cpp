/****************************************************************************
** Meta object code from reading C++ file 'wcontrolbola.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "wcontrolbola.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wcontrolbola.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WControlBola_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WControlBola_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WControlBola_t qt_meta_stringdata_WControlBola = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WControlBola"
QT_MOC_LITERAL(1, 13, 9), // "slotParar"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "slotCambiarNombre"
QT_MOC_LITERAL(4, 42, 11), // "slotEjemplo"
QT_MOC_LITERAL(5, 54, 14) // "slotBotonParar"

    },
    "WControlBola\0slotParar\0\0slotCambiarNombre\0"
    "slotEjemplo\0slotBotonParar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WControlBola[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       4,    0,   38,    2, 0x0a /* Public */,
       5,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WControlBola::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WControlBola *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotParar(); break;
        case 1: _t->slotCambiarNombre((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slotEjemplo(); break;
        case 3: _t->slotBotonParar(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WControlBola::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WControlBola.data,
    qt_meta_data_WControlBola,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WControlBola::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WControlBola::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WControlBola.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::WControlBola"))
        return static_cast< Ui::WControlBola*>(this);
    return QWidget::qt_metacast(_clname);
}

int WControlBola::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
