/****************************************************************************
** Meta object code from reading C++ file 'renderingwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../renderingwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderingwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RenderingWidget_t {
    QByteArrayData data[21];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderingWidget_t qt_meta_stringdata_RenderingWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "RenderingWidget"
QT_MOC_LITERAL(1, 16, 8), // "meshInfo"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "operatorInfo"
QT_MOC_LITERAL(4, 39, 13), // "SetBackground"
QT_MOC_LITERAL(5, 53, 8), // "ReadMesh"
QT_MOC_LITERAL(6, 62, 9), // "WriteMesh"
QT_MOC_LITERAL(7, 72, 11), // "LoadTexture"
QT_MOC_LITERAL(8, 84, 9), // "Subdivide"
QT_MOC_LITERAL(9, 94, 12), // "SetStiffness"
QT_MOC_LITERAL(10, 107, 1), // "t"
QT_MOC_LITERAL(11, 109, 14), // "CheckDrawPoint"
QT_MOC_LITERAL(12, 124, 2), // "bv"
QT_MOC_LITERAL(13, 127, 13), // "CheckDrawEdge"
QT_MOC_LITERAL(14, 141, 13), // "CheckDrawFace"
QT_MOC_LITERAL(15, 155, 10), // "CheckLight"
QT_MOC_LITERAL(16, 166, 16), // "CheckDrawTexture"
QT_MOC_LITERAL(17, 183, 13), // "CheckDrawAxes"
QT_MOC_LITERAL(18, 197, 9), // "CheckLoop"
QT_MOC_LITERAL(19, 207, 7), // "CheckCC"
QT_MOC_LITERAL(20, 215, 7) // "CheckDS"

    },
    "RenderingWidget\0meshInfo\0\0operatorInfo\0"
    "SetBackground\0ReadMesh\0WriteMesh\0"
    "LoadTexture\0Subdivide\0SetStiffness\0t\0"
    "CheckDrawPoint\0bv\0CheckDrawEdge\0"
    "CheckDrawFace\0CheckLight\0CheckDrawTexture\0"
    "CheckDrawAxes\0CheckLoop\0CheckCC\0CheckDS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   99,    2, 0x06 /* Public */,
       3,    1,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  109,    2, 0x0a /* Public */,
       5,    0,  110,    2, 0x0a /* Public */,
       6,    0,  111,    2, 0x0a /* Public */,
       7,    0,  112,    2, 0x0a /* Public */,
       8,    0,  113,    2, 0x0a /* Public */,
       9,    1,  114,    2, 0x0a /* Public */,
      11,    1,  117,    2, 0x0a /* Public */,
      13,    1,  120,    2, 0x0a /* Public */,
      14,    1,  123,    2, 0x0a /* Public */,
      15,    1,  126,    2, 0x0a /* Public */,
      16,    1,  129,    2, 0x0a /* Public */,
      17,    1,  132,    2, 0x0a /* Public */,
      18,    1,  135,    2, 0x0a /* Public */,
      19,    1,  138,    2, 0x0a /* Public */,
      20,    1,  141,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,

       0        // eod
};

void RenderingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RenderingWidget *_t = static_cast<RenderingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->meshInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->operatorInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SetBackground(); break;
        case 3: _t->ReadMesh(); break;
        case 4: _t->WriteMesh(); break;
        case 5: _t->LoadTexture(); break;
        case 6: _t->Subdivide(); break;
        case 7: _t->SetStiffness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->CheckDrawPoint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->CheckDrawEdge((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->CheckDrawFace((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->CheckLight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->CheckDrawTexture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->CheckDrawAxes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->CheckLoop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->CheckCC((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->CheckDS((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RenderingWidget::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderingWidget::meshInfo)) {
                *result = 0;
            }
        }
        {
            typedef void (RenderingWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderingWidget::operatorInfo)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject RenderingWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_RenderingWidget.data,
      qt_meta_data_RenderingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RenderingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RenderingWidget.stringdata0))
        return static_cast<void*>(const_cast< RenderingWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int RenderingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void RenderingWidget::meshInfo(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RenderingWidget::operatorInfo(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
