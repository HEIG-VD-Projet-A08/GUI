/****************************************************************************
** Meta object code from reading C++ file 'protprop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../GUI/protprop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protprop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtProp_t {
    QByteArrayData data[22];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProtProp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProtProp_t qt_meta_stringdata_ProtProp = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ProtProp"
QT_MOC_LITERAL(1, 9, 18), // "on_btn_run_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "on_btn_stop_clicked"
QT_MOC_LITERAL(4, 49, 26), // "on_btn_save_actual_clicked"
QT_MOC_LITERAL(5, 76, 23), // "on_btn_save_res_clicked"
QT_MOC_LITERAL(6, 100, 16), // "showPointToolTip"
QT_MOC_LITERAL(7, 117, 12), // "QMouseEvent*"
QT_MOC_LITERAL(8, 130, 5), // "event"
QT_MOC_LITERAL(9, 136, 11), // "ReadXMLFile"
QT_MOC_LITERAL(10, 148, 8), // "QString&"
QT_MOC_LITERAL(11, 157, 2), // "it"
QT_MOC_LITERAL(12, 160, 5), // "score"
QT_MOC_LITERAL(13, 166, 8), // "newValue"
QT_MOC_LITERAL(14, 175, 17), // "QVector<QString>&"
QT_MOC_LITERAL(15, 193, 4), // "word"
QT_MOC_LITERAL(16, 198, 19), // "getValuesFromServer"
QT_MOC_LITERAL(17, 218, 7), // "double&"
QT_MOC_LITERAL(18, 226, 1), // "x"
QT_MOC_LITERAL(19, 228, 2), // "y1"
QT_MOC_LITERAL(20, 231, 2), // "y2"
QT_MOC_LITERAL(21, 234, 12) // "updateGraphe"

    },
    "ProtProp\0on_btn_run_clicked\0\0"
    "on_btn_stop_clicked\0on_btn_save_actual_clicked\0"
    "on_btn_save_res_clicked\0showPointToolTip\0"
    "QMouseEvent*\0event\0ReadXMLFile\0QString&\0"
    "it\0score\0newValue\0QVector<QString>&\0"
    "word\0getValuesFromServer\0double&\0x\0"
    "y1\0y2\0updateGraphe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtProp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       9,    4,   61,    2, 0x08 /* Private */,
      16,    4,   70,    2, 0x08 /* Private */,
      21,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 14,   11,   12,   13,   15,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17, 0x80000000 | 17, 0x80000000 | 14,   18,   19,   20,   15,
    QMetaType::Void,

       0        // eod
};

void ProtProp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProtProp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_run_clicked(); break;
        case 1: _t->on_btn_stop_clicked(); break;
        case 2: _t->on_btn_save_actual_clicked(); break;
        case 3: _t->on_btn_save_res_clicked(); break;
        case 4: _t->showPointToolTip((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->ReadXMLFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QVector<QString>(*)>(_a[4]))); break;
        case 6: _t->getValuesFromServer((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QVector<QString>(*)>(_a[4]))); break;
        case 7: _t->updateGraphe(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProtProp::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ProtProp.data,
    qt_meta_data_ProtProp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProtProp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtProp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtProp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ProtProp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
