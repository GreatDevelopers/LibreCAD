/****************************************************************************
** Meta object code from reading C++ file 'qg_snaptoolbar.h'
**
** Created: Tue Jun 18 04:07:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../librecad/src/ui/forms/qg_snaptoolbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_snaptoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QG_SnapToolBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   15,   15,   15, 0x08,
      68,   60,   15,   15, 0x08,
      97,   60,   15,   15, 0x08,
     123,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QG_SnapToolBar[] = {
    "QG_SnapToolBar\0\0snapsChanged(RS_SnapMode)\0"
    "actionTriggered()\0checked\0"
    "slotRestrictOrthogonal(bool)\0"
    "slotRestrictNothing(bool)\0"
    "setSnaps(RS_SnapMode)\0"
};

void QG_SnapToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QG_SnapToolBar *_t = static_cast<QG_SnapToolBar *>(_o);
        switch (_id) {
        case 0: _t->snapsChanged((*reinterpret_cast< RS_SnapMode(*)>(_a[1]))); break;
        case 1: _t->actionTriggered(); break;
        case 2: _t->slotRestrictOrthogonal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slotRestrictNothing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setSnaps((*reinterpret_cast< RS_SnapMode(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QG_SnapToolBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QG_SnapToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_QG_SnapToolBar,
      qt_meta_data_QG_SnapToolBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QG_SnapToolBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QG_SnapToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QG_SnapToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QG_SnapToolBar))
        return static_cast<void*>(const_cast< QG_SnapToolBar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int QG_SnapToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QG_SnapToolBar::snapsChanged(RS_SnapMode _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
