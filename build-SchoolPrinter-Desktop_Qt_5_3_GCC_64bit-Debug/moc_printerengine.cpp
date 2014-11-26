/****************************************************************************
** Meta object code from reading C++ file 'printerengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SchoolPrinter/printerengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printerengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrinterEngine_t {
    QByteArrayData data[18];
    char stringdata[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrinterEngine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrinterEngine_t qt_meta_stringdata_PrinterEngine = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 13),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 3),
QT_MOC_LITERAL(4, 33, 19),
QT_MOC_LITERAL(5, 53, 11),
QT_MOC_LITERAL(6, 65, 11),
QT_MOC_LITERAL(7, 77, 12),
QT_MOC_LITERAL(8, 90, 9),
QT_MOC_LITERAL(9, 100, 15),
QT_MOC_LITERAL(10, 116, 7),
QT_MOC_LITERAL(11, 124, 7),
QT_MOC_LITERAL(12, 132, 8),
QT_MOC_LITERAL(13, 141, 6),
QT_MOC_LITERAL(14, 148, 12),
QT_MOC_LITERAL(15, 161, 4),
QT_MOC_LITERAL(16, 166, 4),
QT_MOC_LITERAL(17, 171, 5)
    },
    "PrinterEngine\0statusChanged\0\0arg\0"
    "statusNumberChanged\0timeChanged\0"
    "typeChanged\0imageChanged\0setStatus\0"
    "setStatusNumber\0setTime\0setType\0"
    "setImage\0status\0statusNumber\0time\0"
    "type\0image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrinterEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       5,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,
       7,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   79,    2, 0x0a /* Public */,
       9,    1,   82,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      12,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::Int, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void PrinterEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrinterEngine *_t = static_cast<PrinterEngine *>(_o);
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->statusNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->timeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->typeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->imageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setStatusNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PrinterEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrinterEngine::statusChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (PrinterEngine::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrinterEngine::statusNumberChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (PrinterEngine::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrinterEngine::timeChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (PrinterEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrinterEngine::typeChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (PrinterEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PrinterEngine::imageChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject PrinterEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PrinterEngine.data,
      qt_meta_data_PrinterEngine,  qt_static_metacall, 0, 0}
};


const QMetaObject *PrinterEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrinterEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrinterEngine.stringdata))
        return static_cast<void*>(const_cast< PrinterEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int PrinterEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< QString*>(_v) = status(); break;
        case 1: *reinterpret_cast< int*>(_v) = statusNumber(); break;
        case 2: *reinterpret_cast< int*>(_v) = time(); break;
        case 3: *reinterpret_cast< QString*>(_v) = type(); break;
        case 4: *reinterpret_cast< QString*>(_v) = image(); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setStatus(*reinterpret_cast< QString*>(_v)); break;
        case 1: setStatusNumber(*reinterpret_cast< int*>(_v)); break;
        case 2: setTime(*reinterpret_cast< int*>(_v)); break;
        case 3: setType(*reinterpret_cast< QString*>(_v)); break;
        case 4: setImage(*reinterpret_cast< QString*>(_v)); break;
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
void PrinterEngine::statusChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PrinterEngine::statusNumberChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PrinterEngine::timeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PrinterEngine::typeChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PrinterEngine::imageChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
