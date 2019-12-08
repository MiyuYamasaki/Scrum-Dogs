/****************************************************************************
** Meta object code from reading C++ file 'renderarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Practice/renderarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RenderArea_t {
    QByteArrayData data[20];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderArea_t qt_meta_stringdata_RenderArea = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RenderArea"
QT_MOC_LITERAL(1, 11, 8), // "setShape"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "Shape"
QT_MOC_LITERAL(4, 27, 5), // "shape"
QT_MOC_LITERAL(5, 33, 6), // "setPen"
QT_MOC_LITERAL(6, 40, 3), // "pen"
QT_MOC_LITERAL(7, 44, 8), // "setBrush"
QT_MOC_LITERAL(8, 53, 5), // "brush"
QT_MOC_LITERAL(9, 59, 14), // "setAntialiased"
QT_MOC_LITERAL(10, 74, 11), // "antialiased"
QT_MOC_LITERAL(11, 86, 14), // "setTransformed"
QT_MOC_LITERAL(12, 101, 11), // "transformed"
QT_MOC_LITERAL(13, 113, 8), // "addShape"
QT_MOC_LITERAL(14, 122, 11), // "std::string"
QT_MOC_LITERAL(15, 134, 11), // "deleteShape"
QT_MOC_LITERAL(16, 146, 9), // "findShape"
QT_MOC_LITERAL(17, 156, 16), // "gProject::shapes"
QT_MOC_LITERAL(18, 173, 9), // "getIDNums"
QT_MOC_LITERAL(19, 183, 14) // "QList<QString>"

    },
    "RenderArea\0setShape\0\0Shape\0shape\0"
    "setPen\0pen\0setBrush\0brush\0setAntialiased\0"
    "antialiased\0setTransformed\0transformed\0"
    "addShape\0std::string\0deleteShape\0"
    "findShape\0gProject::shapes\0getIDNums\0"
    "QList<QString>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderArea[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      11,    1,   71,    2, 0x0a /* Public */,
      13,   16,   74,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,
      16,    1,  110,    2, 0x0a /* Public */,
      18,    0,  113,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPen,    6,
    QMetaType::Void, QMetaType::QBrush,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14, QMetaType::Int, 0x80000000 | 14, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 14, QMetaType::Int, QMetaType::Int, 0x80000000 | 14, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    0x80000000 | 17, QMetaType::Int,    2,
    0x80000000 | 19,

       0        // eod
};

void RenderArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setShape((*reinterpret_cast< Shape(*)>(_a[1]))); break;
        case 1: _t->setPen((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 2: _t->setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 3: _t->setAntialiased((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setTransformed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->addShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< std::string(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< std::string(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< std::string(*)>(_a[13])),(*reinterpret_cast< std::string(*)>(_a[14])),(*reinterpret_cast< int(*)>(_a[15])),(*reinterpret_cast< int(*)>(_a[16]))); break;
        case 6: _t->deleteShape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: { gProject::shapes _r = _t->findShape((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< gProject::shapes*>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<QString> _r = _t->getIDNums();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RenderArea::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_RenderArea.data,
    qt_meta_data_RenderArea,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RenderArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RenderArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
