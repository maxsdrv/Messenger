/****************************************************************************
** Meta object code from reading C++ file 'send.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Classes/send.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'send.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Send_t {
    const uint offsetsAndSize[32];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Send_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Send_t qt_meta_stringdata_Send = {
    {
QT_MOC_LITERAL(0, 4), // "Send"
QT_MOC_LITERAL(5, 10), // "stopSignal"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 11), // "sendMessage"
QT_MOC_LITERAL(29, 3), // "msg"
QT_MOC_LITERAL(33, 14), // "runningChanged"
QT_MOC_LITERAL(48, 6), // "runing"
QT_MOC_LITERAL(55, 14), // "messageChanged"
QT_MOC_LITERAL(70, 15), // "message2Changed"
QT_MOC_LITERAL(86, 3), // "run"
QT_MOC_LITERAL(90, 10), // "setRunning"
QT_MOC_LITERAL(101, 10), // "newRunning"
QT_MOC_LITERAL(112, 10), // "setMessage"
QT_MOC_LITERAL(123, 10), // "newMessage"
QT_MOC_LITERAL(134, 11), // "setMessage2"
QT_MOC_LITERAL(146, 11) // "newMessage2"

    },
    "Send\0stopSignal\0\0sendMessage\0msg\0"
    "runningChanged\0runing\0messageChanged\0"
    "message2Changed\0run\0setRunning\0"
    "newRunning\0setMessage\0newMessage\0"
    "setMessage2\0newMessage2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Send[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    0 /* Public */,
       3,    1,   69,    2, 0x06,    1 /* Public */,
       5,    1,   72,    2, 0x06,    3 /* Public */,
       7,    0,   75,    2, 0x06,    5 /* Public */,
       8,    0,   76,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   77,    2, 0x0a,    7 /* Public */,
      10,    1,   78,    2, 0x0a,    8 /* Public */,
      12,    1,   81,    2, 0x0a,   10 /* Public */,
      14,    1,   84,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void Send::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Send *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stopSignal(); break;
        case 1: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->messageChanged(); break;
        case 4: _t->message2Changed(); break;
        case 5: _t->run(); break;
        case 6: _t->setRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setMessage2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Send::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Send::stopSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Send::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Send::sendMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Send::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Send::runningChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Send::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Send::messageChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Send::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Send::message2Changed)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Send::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Send.offsetsAndSize,
    qt_meta_data_Send,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Send_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Send::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Send::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Send.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Send::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Send::stopSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Send::sendMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Send::runningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Send::messageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Send::message2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
