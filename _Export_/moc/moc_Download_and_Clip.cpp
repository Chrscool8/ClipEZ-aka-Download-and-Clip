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
    QByteArrayData data[16];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Download_and_Clip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Download_and_Clip_t qt_meta_stringdata_Download_and_Clip = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Download_and_Clip"
QT_MOC_LITERAL(1, 18, 13), // "download_ytdl"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "run_ytdl"
QT_MOC_LITERAL(4, 42, 19), // "processStarted_ytdl"
QT_MOC_LITERAL(5, 62, 28), // "readyReadStandardOutput_ytdl"
QT_MOC_LITERAL(6, 91, 21), // "downloadFinished_ytdl"
QT_MOC_LITERAL(7, 113, 10), // "run_ffmpeg"
QT_MOC_LITERAL(8, 124, 21), // "processStarted_ffmpeg"
QT_MOC_LITERAL(9, 146, 30), // "readyReadStandardOutput_ffmpeg"
QT_MOC_LITERAL(10, 177, 23), // "encodingFinished_ffmpeg"
QT_MOC_LITERAL(11, 201, 15), // "darkmode_toggle"
QT_MOC_LITERAL(12, 217, 5), // "state"
QT_MOC_LITERAL(13, 223, 14), // "clear_download"
QT_MOC_LITERAL(14, 238, 16), // "typing_clip_name"
QT_MOC_LITERAL(15, 255, 11) // "show_folder"

    },
    "Download_and_Clip\0download_ytdl\0\0"
    "run_ytdl\0processStarted_ytdl\0"
    "readyReadStandardOutput_ytdl\0"
    "downloadFinished_ytdl\0run_ffmpeg\0"
    "processStarted_ffmpeg\0"
    "readyReadStandardOutput_ffmpeg\0"
    "encodingFinished_ffmpeg\0darkmode_toggle\0"
    "state\0clear_download\0typing_clip_name\0"
    "show_folder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Download_and_Clip[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Download_and_Clip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Download_and_Clip *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->download_ytdl(); break;
        case 1: _t->run_ytdl(); break;
        case 2: _t->processStarted_ytdl(); break;
        case 3: _t->readyReadStandardOutput_ytdl(); break;
        case 4: _t->downloadFinished_ytdl(); break;
        case 5: _t->run_ffmpeg(); break;
        case 6: _t->processStarted_ffmpeg(); break;
        case 7: _t->readyReadStandardOutput_ffmpeg(); break;
        case 8: _t->encodingFinished_ffmpeg(); break;
        case 9: _t->darkmode_toggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->clear_download(); break;
        case 11: _t->typing_clip_name(); break;
        case 12: _t->show_folder(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
