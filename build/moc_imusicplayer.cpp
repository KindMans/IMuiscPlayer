/****************************************************************************
** Meta object code from reading C++ file 'imusicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/imusicplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imusicplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IMusicPlayer_t {
    QByteArrayData data[22];
    char stringdata0[362];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IMusicPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IMusicPlayer_t qt_meta_stringdata_IMusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "IMusicPlayer"
QT_MOC_LITERAL(1, 13, 15), // "on_fast_forward"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "position"
QT_MOC_LITERAL(4, 39, 11), // "on_duration"
QT_MOC_LITERAL(5, 51, 8), // "duration"
QT_MOC_LITERAL(6, 60, 17), // "on_speed_progress"
QT_MOC_LITERAL(7, 78, 5), // "value"
QT_MOC_LITERAL(8, 84, 20), // "on_currentRow_change"
QT_MOC_LITERAL(9, 105, 3), // "row"
QT_MOC_LITERAL(10, 109, 21), // "on_btn_player_clicked"
QT_MOC_LITERAL(11, 131, 20), // "on_btn_pause_clicked"
QT_MOC_LITERAL(12, 152, 15), // "on_seqPlayMusic"
QT_MOC_LITERAL(13, 168, 19), // "on_btn_load_clicked"
QT_MOC_LITERAL(14, 188, 19), // "on_btn_prev_clicked"
QT_MOC_LITERAL(15, 208, 19), // "on_btn_next_clicked"
QT_MOC_LITERAL(16, 228, 27), // "on_listWidget_doubleClicked"
QT_MOC_LITERAL(17, 256, 11), // "QModelIndex"
QT_MOC_LITERAL(18, 268, 5), // "index"
QT_MOC_LITERAL(19, 274, 30), // "on_position_change_sliderMoved"
QT_MOC_LITERAL(20, 305, 28), // "on_volume_change_sliderMoved"
QT_MOC_LITERAL(21, 334, 27) // "on_tabWidget_currentChanged"

    },
    "IMusicPlayer\0on_fast_forward\0\0position\0"
    "on_duration\0duration\0on_speed_progress\0"
    "value\0on_currentRow_change\0row\0"
    "on_btn_player_clicked\0on_btn_pause_clicked\0"
    "on_seqPlayMusic\0on_btn_load_clicked\0"
    "on_btn_prev_clicked\0on_btn_next_clicked\0"
    "on_listWidget_doubleClicked\0QModelIndex\0"
    "index\0on_position_change_sliderMoved\0"
    "on_volume_change_sliderMoved\0"
    "on_tabWidget_currentChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IMusicPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       6,    1,   90,    2, 0x08 /* Private */,
       8,    1,   93,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    1,  102,    2, 0x08 /* Private */,
      19,    1,  105,    2, 0x08 /* Private */,
      20,    1,  108,    2, 0x08 /* Private */,
      21,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void IMusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IMusicPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_fast_forward((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->on_duration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->on_speed_progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_currentRow_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_btn_player_clicked(); break;
        case 5: _t->on_btn_pause_clicked(); break;
        case 6: _t->on_seqPlayMusic(); break;
        case 7: _t->on_btn_load_clicked(); break;
        case 8: _t->on_btn_prev_clicked(); break;
        case 9: _t->on_btn_next_clicked(); break;
        case 10: _t->on_listWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_position_change_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_volume_change_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IMusicPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_IMusicPlayer.data,
    qt_meta_data_IMusicPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IMusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IMusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IMusicPlayer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IMusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
