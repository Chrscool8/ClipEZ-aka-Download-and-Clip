/****************************************************************************
** Meta object code from reading C++ file 'Download_and_Clip.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Download_and_Clip.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Download_and_Clip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Download_and_Clip_t {
    QByteArrayData data[23];
    char stringdata0[362];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Download_and_Clip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Download_and_Clip_t qt_meta_stringdata_Download_and_Clip = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Download_and_Clip"
QT_MOC_LITERAL(1, 18, 17), // "download_exe_ytdl"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "execute_ytdl_download"
QT_MOC_LITERAL(4, 59, 11), // "expand_left"
QT_MOC_LITERAL(5, 71, 12), // "expand_right"
QT_MOC_LITERAL(6, 84, 21), // "execute_ffmpeg_encode"
QT_MOC_LITERAL(7, 106, 15), // "darkmode_toggle"
QT_MOC_LITERAL(8, 122, 5), // "state"
QT_MOC_LITERAL(9, 128, 14), // "clear_download"
QT_MOC_LITERAL(10, 143, 16), // "typing_clip_name"
QT_MOC_LITERAL(11, 160, 19), // "show_folder_working"
QT_MOC_LITERAL(12, 180, 18), // "show_folder_output"
QT_MOC_LITERAL(13, 199, 23), // "choose_output_directory"
QT_MOC_LITERAL(14, 223, 18), // "choose_local_video"
QT_MOC_LITERAL(15, 242, 15), // "browse_for_ytdl"
QT_MOC_LITERAL(16, 258, 17), // "browse_for_ffmpeg"
QT_MOC_LITERAL(17, 276, 18), // "browse_for_ffprobe"
QT_MOC_LITERAL(18, 295, 18), // "processStateChange"
QT_MOC_LITERAL(19, 314, 11), // "std::string"
QT_MOC_LITERAL(20, 326, 22), // "QProcess::ProcessState"
QT_MOC_LITERAL(21, 349, 8), // "newState"
QT_MOC_LITERAL(22, 358, 3) // "tag"

    },
    "Download_and_Clip\0download_exe_ytdl\0"
    "\0execute_ytdl_download\0expand_left\0"
    "expand_right\0execute_ffmpeg_encode\0"
    "darkmode_toggle\0state\0clear_download\0"
    "typing_clip_name\0show_folder_working\0"
    "show_folder_output\0choose_output_directory\0"
    "choose_local_video\0browse_for_ytdl\0"
    "browse_for_ffmpeg\0browse_for_ffprobe\0"
    "processStateChange\0std::string\0"
    "QProcess::ProcessState\0newState\0tag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Download_and_Clip[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    1,   99,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    3,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 20, 0x80000000 | 19,    2,   21,   22,

       0        // eod
};

void Download_and_Clip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Download_and_Clip *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->download_exe_ytdl(); break;
        case 1: _t->execute_ytdl_download(); break;
        case 2: _t->expand_left(); break;
        case 3: _t->expand_right(); break;
        case 4: _t->execute_ffmpeg_encode(); break;
        case 5: _t->darkmode_toggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->clear_download(); break;
        case 7: _t->typing_clip_name(); break;
        case 8: _t->show_folder_working(); break;
        case 9: _t->show_folder_output(); break;
        case 10: _t->choose_output_directory(); break;
        case 11: _t->choose_local_video(); break;
        case 12: _t->browse_for_ytdl(); break;
        case 13: _t->browse_for_ffmpeg(); break;
        case 14: _t->browse_for_ffprobe(); break;
        case 15: _t->processStateChange((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< QProcess::ProcessState(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Download_and_Clip::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Download_and_Clip.data,
    qt_meta_data_Download_and_Clip,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Download_and_Clip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Download_and_Clip::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Download_and_Clip.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Download_and_Clip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
