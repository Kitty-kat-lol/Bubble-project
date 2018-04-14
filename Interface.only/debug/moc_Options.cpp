/****************************************************************************
** Meta object code from reading C++ file 'Options.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Options.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Options.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogOut_t {
    QByteArrayData data[13];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogOut_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogOut_t qt_meta_stringdata_LogOut = {
    {
QT_MOC_LITERAL(0, 0, 6), // "LogOut"
QT_MOC_LITERAL(1, 7, 13), // "Print_Vitesse"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "vitesse"
QT_MOC_LITERAL(4, 30, 13), // "Print_Chances"
QT_MOC_LITERAL(5, 44, 7), // "chances"
QT_MOC_LITERAL(6, 52, 15), // "Print_Debug_CMD"
QT_MOC_LITERAL(7, 68, 5), // "state"
QT_MOC_LITERAL(8, 74, 16), // "Print_Debug_FPGA"
QT_MOC_LITERAL(9, 91, 17), // "Print_Debug_Fille"
QT_MOC_LITERAL(10, 109, 13), // "Print_une_vie"
QT_MOC_LITERAL(11, 123, 15), // "Print_deux_vies"
QT_MOC_LITERAL(12, 139, 16) // "Print_trois_vies"

    },
    "LogOut\0Print_Vitesse\0\0vitesse\0"
    "Print_Chances\0chances\0Print_Debug_CMD\0"
    "state\0Print_Debug_FPGA\0Print_Debug_Fille\0"
    "Print_une_vie\0Print_deux_vies\0"
    "Print_trois_vies"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogOut[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       8,    1,   63,    2, 0x0a /* Public */,
       9,    1,   66,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LogOut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogOut *_t = static_cast<LogOut *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Print_Vitesse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Print_Chances((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Print_Debug_CMD((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Print_Debug_FPGA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->Print_Debug_Fille((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->Print_une_vie(); break;
        case 6: _t->Print_deux_vies(); break;
        case 7: _t->Print_trois_vies(); break;
        default: ;
        }
    }
}

const QMetaObject LogOut::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_LogOut.data,
      qt_meta_data_LogOut,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LogOut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogOut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogOut.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int LogOut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
struct qt_meta_stringdata_Options_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Options_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Options_t qt_meta_stringdata_Options = {
    {
QT_MOC_LITERAL(0, 0, 7) // "Options"

    },
    "Options"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Options[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Options::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Options::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Options.data,
      qt_meta_data_Options,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Options::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Options::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Options.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Options::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
