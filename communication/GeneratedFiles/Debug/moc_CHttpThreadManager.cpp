/****************************************************************************
** Meta object code from reading C++ file 'CHttpThreadManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CHttpThreadManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CHttpThreadManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CHttpThreadManager_t {
    QByteArrayData data[8];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHttpThreadManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHttpThreadManager_t qt_meta_stringdata_CHttpThreadManager = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CHttpThreadManager"
QT_MOC_LITERAL(1, 19, 15), // "GetDataCallback"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "nCmd"
QT_MOC_LITERAL(4, 41, 9), // "nWidgetId"
QT_MOC_LITERAL(5, 51, 11), // "strFuncName"
QT_MOC_LITERAL(6, 63, 7), // "strData"
QT_MOC_LITERAL(7, 71, 17) // "slot_threadFinish"

    },
    "CHttpThreadManager\0GetDataCallback\0\0"
    "nCmd\0nWidgetId\0strFuncName\0strData\0"
    "slot_threadFinish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHttpThreadManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CHttpThreadManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CHttpThreadManager *_t = static_cast<CHttpThreadManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetDataCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->slot_threadFinish(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CHttpThreadManager::*_t)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CHttpThreadManager::GetDataCallback)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CHttpThreadManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CHttpThreadManager.data,
      qt_meta_data_CHttpThreadManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CHttpThreadManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHttpThreadManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpThreadManager.stringdata0))
        return static_cast<void*>(const_cast< CHttpThreadManager*>(this));
    return QObject::qt_metacast(_clname);
}

int CHttpThreadManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CHttpThreadManager::GetDataCallback(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
