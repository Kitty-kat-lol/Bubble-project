/****************************************************************************
** Meta object code from reading C++ file 'Scores.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Scores.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scores.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Scores_t {
    QByteArrayData data[8];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scores_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scores_t qt_meta_stringdata_Scores = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Scores"
QT_MOC_LITERAL(1, 7, 10), // "add_scores"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "stru_scores"
QT_MOC_LITERAL(4, 31, 3), // "act"
QT_MOC_LITERAL(5, 35, 11), // "gets_scores"
QT_MOC_LITERAL(6, 47, 8), // "w_scores"
QT_MOC_LITERAL(7, 56, 13) // "reinit_scores"

    },
    "Scores\0add_scores\0\0stru_scores\0act\0"
    "gets_scores\0w_scores\0reinit_scores"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scores[] = {

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
       1,    1,   34,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Scores::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scores *_t = static_cast<Scores *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_scores((*reinterpret_cast< stru_scores(*)>(_a[1]))); break;
        case 1: _t->gets_scores(); break;
        case 2: _t->w_scores(); break;
        case 3: _t->reinit_scores(); break;
        default: ;
        }
    }
}

const QMetaObject Scores::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Scores.data,
      qt_meta_data_Scores,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Scores::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scores::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Scores.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Scores::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
