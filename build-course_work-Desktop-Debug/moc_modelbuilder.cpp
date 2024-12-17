/****************************************************************************
** Meta object code from reading C++ file 'modelbuilder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../course_work/modelbuilder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelbuilder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModelBuilder_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelBuilder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelBuilder_t qt_meta_stringdata_ModelBuilder = {
    {
QT_MOC_LITERAL(0, 0, 12) // "ModelBuilder"

    },
    "ModelBuilder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelBuilder[] = {

 // content:
       8,       // revision
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

void ModelBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ModelBuilder::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ModelBuilder.data,
    qt_meta_data_ModelBuilder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModelBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelBuilder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModelBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ModelCubeBuilder_t {
    QByteArrayData data[5];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelCubeBuilder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelCubeBuilder_t qt_meta_stringdata_ModelCubeBuilder = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ModelCubeBuilder"
QT_MOC_LITERAL(1, 17, 23), // "ready_cube_model_signal"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 7), // "Model3D"
QT_MOC_LITERAL(4, 50, 5) // "model"

    },
    "ModelCubeBuilder\0ready_cube_model_signal\0"
    "\0Model3D\0model"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelCubeBuilder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void ModelCubeBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModelCubeBuilder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ready_cube_model_signal((*reinterpret_cast< Model3D(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModelCubeBuilder::*)(Model3D );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelCubeBuilder::ready_cube_model_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModelCubeBuilder::staticMetaObject = { {
    QMetaObject::SuperData::link<ModelBuilder::staticMetaObject>(),
    qt_meta_stringdata_ModelCubeBuilder.data,
    qt_meta_data_ModelCubeBuilder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModelCubeBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelCubeBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelCubeBuilder.stringdata0))
        return static_cast<void*>(this);
    return ModelBuilder::qt_metacast(_clname);
}

int ModelCubeBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelBuilder::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ModelCubeBuilder::ready_cube_model_signal(Model3D _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ModelTorusBuilder_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelTorusBuilder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelTorusBuilder_t qt_meta_stringdata_ModelTorusBuilder = {
    {
QT_MOC_LITERAL(0, 0, 17) // "ModelTorusBuilder"

    },
    "ModelTorusBuilder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelTorusBuilder[] = {

 // content:
       8,       // revision
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

void ModelTorusBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ModelTorusBuilder::staticMetaObject = { {
    QMetaObject::SuperData::link<ModelBuilder::staticMetaObject>(),
    qt_meta_stringdata_ModelTorusBuilder.data,
    qt_meta_data_ModelTorusBuilder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModelTorusBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelTorusBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelTorusBuilder.stringdata0))
        return static_cast<void*>(this);
    return ModelBuilder::qt_metacast(_clname);
}

int ModelTorusBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelBuilder::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ModelCylinderBuilder_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelCylinderBuilder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelCylinderBuilder_t qt_meta_stringdata_ModelCylinderBuilder = {
    {
QT_MOC_LITERAL(0, 0, 20) // "ModelCylinderBuilder"

    },
    "ModelCylinderBuilder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelCylinderBuilder[] = {

 // content:
       8,       // revision
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

void ModelCylinderBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ModelCylinderBuilder::staticMetaObject = { {
    QMetaObject::SuperData::link<ModelBuilder::staticMetaObject>(),
    qt_meta_stringdata_ModelCylinderBuilder.data,
    qt_meta_data_ModelCylinderBuilder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModelCylinderBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelCylinderBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelCylinderBuilder.stringdata0))
        return static_cast<void*>(this);
    return ModelBuilder::qt_metacast(_clname);
}

int ModelCylinderBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelBuilder::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ModelCheckBuilder_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelCheckBuilder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelCheckBuilder_t qt_meta_stringdata_ModelCheckBuilder = {
    {
QT_MOC_LITERAL(0, 0, 17) // "ModelCheckBuilder"

    },
    "ModelCheckBuilder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelCheckBuilder[] = {

 // content:
       8,       // revision
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

void ModelCheckBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ModelCheckBuilder::staticMetaObject = { {
    QMetaObject::SuperData::link<ModelBuilder::staticMetaObject>(),
    qt_meta_stringdata_ModelCheckBuilder.data,
    qt_meta_data_ModelCheckBuilder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModelCheckBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelCheckBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelCheckBuilder.stringdata0))
        return static_cast<void*>(this);
    return ModelBuilder::qt_metacast(_clname);
}

int ModelCheckBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelBuilder::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
