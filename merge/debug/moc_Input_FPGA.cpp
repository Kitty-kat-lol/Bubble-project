/****************************************************************************
** Meta object code from reading C++ file 'Input_FPGA.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Input_FPGA.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Input_FPGA.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Input_FPGA_t {
    QByteArrayData data[8];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Input_FPGA_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Input_FPGA_t qt_meta_stringdata_Input_FPGA = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Input_FPGA"
QT_MOC_LITERAL(1, 11, 5), // "A_out"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "O_out"
QT_MOC_LITERAL(4, 24, 5), // "I_out"
QT_MOC_LITERAL(5, 30, 5), // "U_out"
QT_MOC_LITERAL(6, 36, 5), // "B_out"
QT_MOC_LITERAL(7, 42, 9) // "call_read"

    },
    "Input_FPGA\0A_out\0\0O_out\0I_out\0U_out\0"
    "B_out\0call_read"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Input_FPGA[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Input_FPGA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Input_FPGA *_t = static_cast<Input_FPGA *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->A_out(); break;
        case 1: _t->O_out(); break;
        case 2: _t->I_out(); break;
        case 3: _t->U_out(); break;
        case 4: _t->B_out(); break;
        case 5: _t->call_read(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Input_FPGA::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Input_FPGA::A_out)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Input_FPGA::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Input_FPGA::O_out)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Input_FPGA::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Input_FPGA::I_out)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Input_FPGA::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Input_FPGA::U_out)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Input_FPGA::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Input_FPGA::B_out)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Input_FPGA::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Input_FPGA.data,
      qt_meta_data_Input_FPGA,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Input_FPGA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Input_FPGA::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Input_FPGA.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Input_FPGA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Input_FPGA::A_out()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Input_FPGA::O_out()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Input_FPGA::I_out()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Input_FPGA::U_out()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Input_FPGA::B_out()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
