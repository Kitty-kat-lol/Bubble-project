/****************************************************************************
** Meta object code from reading C++ file 'Player_Custom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Player_Custom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Player_Custom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Player_custom_t {
    QByteArrayData data[12];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_custom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_custom_t qt_meta_stringdata_Player_custom = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Player_custom"
QT_MOC_LITERAL(1, 14, 10), // "move_right"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "move_left"
QT_MOC_LITERAL(4, 36, 9), // "set_lives"
QT_MOC_LITERAL(5, 46, 7), // "nb_vies"
QT_MOC_LITERAL(6, 54, 9), // "add_score"
QT_MOC_LITERAL(7, 64, 5), // "point"
QT_MOC_LITERAL(8, 70, 8), // "set_1vie"
QT_MOC_LITERAL(9, 79, 4), // "etat"
QT_MOC_LITERAL(10, 84, 9), // "set_2vies"
QT_MOC_LITERAL(11, 94, 9) // "set_3vies"

    },
    "Player_custom\0move_right\0\0move_left\0"
    "set_lives\0nb_vies\0add_score\0point\0"
    "set_1vie\0etat\0set_2vies\0set_3vies"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player_custom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void Player_custom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Player_custom *_t = static_cast<Player_custom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->move_right(); break;
        case 1: _t->move_left(); break;
        case 2: _t->set_lives((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->add_score((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->set_1vie((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->set_2vies((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->set_3vies((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Player_custom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Player_custom.data,
      qt_meta_data_Player_custom,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Player_custom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player_custom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Player_custom.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Player_custom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
