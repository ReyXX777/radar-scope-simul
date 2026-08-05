/****************************************************************************
** Meta object code from reading C++ file 'RadarModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/model/RadarModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RadarModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RadarModel_t {
    QByteArrayData data[10];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RadarModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RadarModel_t qt_meta_stringdata_RadarModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RadarModel"
QT_MOC_LITERAL(1, 11, 17), // "sweepAngleChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "targetPing"
QT_MOC_LITERAL(4, 41, 8), // "targetId"
QT_MOC_LITERAL(5, 50, 14), // "targetsChanged"
QT_MOC_LITERAL(6, 65, 10), // "sweepAngle"
QT_MOC_LITERAL(7, 76, 7), // "targets"
QT_MOC_LITERAL(8, 84, 24), // "QQmlListProperty<Target>"
QT_MOC_LITERAL(9, 109, 10) // "targetList"

    },
    "RadarModel\0sweepAngleChanged\0\0targetPing\0"
    "targetId\0targetsChanged\0sweepAngle\0"
    "targets\0QQmlListProperty<Target>\0"
    "targetList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RadarModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       5,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::Double, 0x00495103,
       7, 0x80000000 | 8, 0x00095409,
       9, QMetaType::QVariantList, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       2,

       0        // eod
};

void RadarModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RadarModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sweepAngleChanged(); break;
        case 1: _t->targetPing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->targetsChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RadarModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarModel::sweepAngleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RadarModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarModel::targetPing)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RadarModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarModel::targetsChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RadarModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->sweepAngle(); break;
        case 1: *reinterpret_cast< QQmlListProperty<Target>*>(_v) = _t->targets(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->targetList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RadarModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSweepAngle(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject RadarModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RadarModel.data,
    qt_meta_data_RadarModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RadarModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RadarModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RadarModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RadarModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RadarModel::sweepAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RadarModel::targetPing(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RadarModel::targetsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
