/****************************************************************************
** Meta object code from reading C++ file 'PrintheadModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SchoolPrinter/Printheads/PrintheadModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PrintheadModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrintheadModel_t {
    QByteArrayData data[23];
    char stringdata[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrintheadModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrintheadModel_t qt_meta_stringdata_PrintheadModel = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 13),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 6),
QT_MOC_LITERAL(4, 37, 3),
QT_MOC_LITERAL(5, 41, 12),
QT_MOC_LITERAL(6, 54, 13),
QT_MOC_LITERAL(7, 68, 15),
QT_MOC_LITERAL(8, 84, 18),
QT_MOC_LITERAL(9, 103, 10),
QT_MOC_LITERAL(10, 114, 9),
QT_MOC_LITERAL(11, 124, 8),
QT_MOC_LITERAL(12, 133, 9),
QT_MOC_LITERAL(13, 143, 11),
QT_MOC_LITERAL(14, 155, 14),
QT_MOC_LITERAL(15, 170, 6),
QT_MOC_LITERAL(16, 177, 5),
QT_MOC_LITERAL(17, 183, 6),
QT_MOC_LITERAL(18, 190, 8),
QT_MOC_LITERAL(19, 199, 11),
QT_MOC_LITERAL(20, 211, 2),
QT_MOC_LITERAL(21, 214, 7),
QT_MOC_LITERAL(22, 222, 5)
    },
    "PrintheadModel\0statusChanged\0\0Status\0"
    "arg\0colorChanged\0healthChanged\0"
    "warrantyChanged\0installDateChanged\0"
    "QDateTime*\0setStatus\0setColor\0setHealth\0"
    "setWarranty\0setInstallDate\0status\0"
    "color\0health\0warranty\0installDate\0OK\0"
    "WARNING\0ERROR"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrintheadModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       5,   94, // properties
       1,  114, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       7,    1,   73,    2, 0x06 /* Public */,
       8,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   79,    2, 0x0a /* Public */,
      11,    1,   82,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      14,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 9,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 9,    4,

 // properties: name, type, flags
      15, 0x80000000 | 3, 0x0049510b,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::Int, 0x00495103,
      18, QMetaType::Bool, 0x00495103,
      19, 0x80000000 | 9, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

 // enums: name, flags, count, data
       3, 0x0,    3,  118,

 // enum data: key, value
      20, uint(PrintheadModel::OK),
      21, uint(PrintheadModel::WARNING),
      22, uint(PrintheadModel::ERROR),

       0        // eod
};

void PrintheadModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrintheadModel *_t = static_cast<PrintheadModel *>(_o);
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< Status(*)>(_a[1]))); break;
        case 1: _t->colorChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->healthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->warrantyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->installDateChanged((*reinterpret_cast< QDateTime*(*)>(_a[1]))); break;
        case 5: _t->setStatus((*reinterpret_cast< Status(*)>(_a[1]))); break;
        case 6: _t->setColor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setHealth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setWarranty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setInstallDate((*reinterpret_cast< QDateTime*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PrintheadModel::*_t)(Status );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintheadModel::statusChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (PrintheadModel::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintheadModel::colorChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (PrintheadModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintheadModel::healthChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (PrintheadModel::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintheadModel::warrantyChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (PrintheadModel::*_t)(QDateTime * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrintheadModel::installDateChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject PrintheadModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PrintheadModel.data,
      qt_meta_data_PrintheadModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *PrintheadModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrintheadModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrintheadModel.stringdata))
        return static_cast<void*>(const_cast< PrintheadModel*>(this));
    return QObject::qt_metacast(_clname);
}

int PrintheadModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Status*>(_v) = status(); break;
        case 1: *reinterpret_cast< QString*>(_v) = color(); break;
        case 2: *reinterpret_cast< int*>(_v) = health(); break;
        case 3: *reinterpret_cast< bool*>(_v) = warranty(); break;
        case 4: *reinterpret_cast< QDateTime**>(_v) = installDate(); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setStatus(*reinterpret_cast< Status*>(_v)); break;
        case 1: setColor(*reinterpret_cast< QString*>(_v)); break;
        case 2: setHealth(*reinterpret_cast< int*>(_v)); break;
        case 3: setWarranty(*reinterpret_cast< bool*>(_v)); break;
        case 4: setInstallDate(*reinterpret_cast< QDateTime**>(_v)); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PrintheadModel::statusChanged(Status _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PrintheadModel::colorChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PrintheadModel::healthChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PrintheadModel::warrantyChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PrintheadModel::installDateChanged(QDateTime * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
