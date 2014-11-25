/****************************************************************************
** Meta object code from reading C++ file 'databaseengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../databaseEngine/databaseengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databaseengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Users_t {
    QByteArrayData data[1];
    char stringdata[6];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Users_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Users_t qt_meta_stringdata_Users = {
    {
QT_MOC_LITERAL(0, 0, 5)
    },
    "Users"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Users[] = {

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

void Users::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Users::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Users.data,
      qt_meta_data_Users,  qt_static_metacall, 0, 0}
};


const QMetaObject *Users::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Users::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Users.stringdata))
        return static_cast<void*>(const_cast< Users*>(this));
    return QObject::qt_metacast(_clname);
}

int Users::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_Printheads_t {
    QByteArrayData data[1];
    char stringdata[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Printheads_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Printheads_t qt_meta_stringdata_Printheads = {
    {
QT_MOC_LITERAL(0, 0, 10)
    },
    "Printheads"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Printheads[] = {

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

void Printheads::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Printheads::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Printheads.data,
      qt_meta_data_Printheads,  qt_static_metacall, 0, 0}
};


const QMetaObject *Printheads::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Printheads::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Printheads.stringdata))
        return static_cast<void*>(const_cast< Printheads*>(this));
    return QObject::qt_metacast(_clname);
}

int Printheads::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_DatabaseEngine_t {
    QByteArrayData data[6];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseEngine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseEngine_t qt_meta_stringdata_DatabaseEngine = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 11),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 18),
QT_MOC_LITERAL(4, 47, 17),
QT_MOC_LITERAL(5, 65, 16)
    },
    "DatabaseEngine\0userChanged\0\0"
    "accessLevelChanged\0userAccessChanged\0"
    "printheadChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DatabaseEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseEngine *_t = static_cast<DatabaseEngine *>(_o);
        switch (_id) {
        case 0: _t->userChanged(); break;
        case 1: _t->accessLevelChanged(); break;
        case 2: _t->userAccessChanged(); break;
        case 3: _t->printheadChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DatabaseEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatabaseEngine::userChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (DatabaseEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatabaseEngine::accessLevelChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (DatabaseEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatabaseEngine::userAccessChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (DatabaseEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatabaseEngine::printheadChanged)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DatabaseEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DatabaseEngine.data,
      qt_meta_data_DatabaseEngine,  qt_static_metacall, 0, 0}
};


const QMetaObject *DatabaseEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseEngine.stringdata))
        return static_cast<void*>(const_cast< DatabaseEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int DatabaseEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DatabaseEngine::userChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DatabaseEngine::accessLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void DatabaseEngine::userAccessChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void DatabaseEngine::printheadChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
