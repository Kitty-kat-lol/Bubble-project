/****************************************************************************
** Meta object code from reading C++ file 'Play.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Play.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Play.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bubble_Trouble_t {
    QByteArrayData data[7];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bubble_Trouble_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bubble_Trouble_t qt_meta_stringdata_Bubble_Trouble = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Bubble_Trouble"
QT_MOC_LITERAL(1, 15, 15), // "gamepad_control"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "Death"
QT_MOC_LITERAL(4, 38, 11), // "bulle_event"
QT_MOC_LITERAL(5, 50, 15), // "set_bulle_speed"
QT_MOC_LITERAL(6, 66, 8) // "pourcent"

    },
    "Bubble_Trouble\0gamepad_control\0\0Death\0"
    "bulle_event\0set_bulle_speed\0pourcent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bubble_Trouble[] = {

 // content:
       7,       // revision
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
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void Bubble_Trouble::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Bubble_Trouble *_t = static_cast<Bubble_Trouble *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gamepad_control(); break;
        case 1: _t->Death(); break;
        case 2: _t->bulle_event(); break;
        case 3: _t->set_bulle_speed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Bubble_Trouble::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Bubble_Trouble.data,
      qt_meta_data_Bubble_Trouble,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Bubble_Trouble::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bubble_Trouble::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bubble_Trouble.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QObject"))
        return static_cast< QObject*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Bubble_Trouble::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Play_t {
    QByteArrayData data[4];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Play_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Play_t qt_meta_stringdata_Play = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Play"
QT_MOC_LITERAL(1, 5, 9), // "Quit_play"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10) // "Start_play"

    },
    "Play\0Quit_play\0\0Start_play"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Play[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Play::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Play *_t = static_cast<Play *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Quit_play(); break;
        case 1: _t->Start_play(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Play::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Play.data,
      qt_meta_data_Play,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Play::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Play::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Play.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Play::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
