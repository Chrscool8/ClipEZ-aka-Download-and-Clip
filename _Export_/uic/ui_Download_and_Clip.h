/********************************************************************************
** Form generated from reading UI file 'Download_and_Clip.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_AND_CLIP_H
#define UI_DOWNLOAD_AND_CLIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Download_and_ClipClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QPlainTextEdit *textedit_videoid;
    QPushButton *button_download;
    QPushButton *button_cleardownload;
    QLabel *label_thumb;
    QGroupBox *groupBox_2;
    QPushButton *button_clip;
    QGroupBox *groupBox_5;
    QSpinBox *spinbox_quality;
    QSlider *slider_quality;
    QLabel *label_quality_smallest;
    QLabel *label_7;
    QGroupBox *groupBox_6;
    QPlainTextEdit *textedit_starttime;
    QGroupBox *groupBox_7;
    QPlainTextEdit *textedit_endtime;
    QGroupBox *groupBox_8;
    QPlainTextEdit *textedit_outputname;
    QPushButton *button_showfolder;
    QGroupBox *groupBox_3;
    QTextEdit *textedit_status_box;
    QProgressBar *progressBar;
    QGroupBox *groupBox_4;
    QPushButton *button_downloadytdl;
    QPushButton *button_downloadffmpeg;
    QCheckBox *checkbox_dark;
    QGroupBox *groupBox_9;
    QTableWidget *table_clipinfo;
    QGroupBox *groupBox_10;
    QTreeView *treeview_files;
    QGroupBox *groupBox_11;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Download_and_ClipClass)
    {
        if (Download_and_ClipClass->objectName().isEmpty())
            Download_and_ClipClass->setObjectName(QString::fromUtf8("Download_and_ClipClass"));
        Download_and_ClipClass->setEnabled(true);
        Download_and_ClipClass->resize(1351, 661);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Download_and_ClipClass->sizePolicy().hasHeightForWidth());
        Download_and_ClipClass->setSizePolicy(sizePolicy);
        Download_and_ClipClass->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgba(40, 40, 40, 100%); \n"
"	color: rgb(200, 200, 200);\n"
"	border: 1px solid rgb(70, 70, 70); \n"
"}\n"
"\n"
"QWidget:disabled\n"
"{	\n"
"	background-color: rgba(40, 40, 40, 25%); \n"
"	color: rgba(80, 80, 80, 50%);\n"
"}\n"
"\n"
"QLabel, QGroupBox\n"
"{\n"
"	background-color: rgb(42,42,42);\n"
"	color: rgb(180, 180, 180);\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"border: 0px;\n"
"}\n"
"\n"
"QGroupBox\n"
"{\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
"\n"
"QLabel:disabled, QGroupBox:disabled\n"
"{\n"
"color: rgb(180, 180, 180);\n"
"}\n"
"\n"
"QTextEdit, QPlainTextEdit\n"
"{\n"
"	background-color:  rgb(59,59,59);\n"
"}\n"
"\n"
"QTextEdit:disabled, QPlainTextEdit:disabled\n"
"{\n"
"	background-color:  rgba(59,59,59,25%);\n"
"}\n"
"\n"
"QSlider::groove:horizontal:disabled \n"
"{ \n"
"	background-color: rgb(59,59,59);\n"
"	border: 0px solid #424242; \n"
"	height: 10px; \n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled \n"
"{ \n"
"	background-color:  rgb(59,59,5"
                        "9); \n"
"	border: 2px solid  rgb(59,59,59); \n"
"	width: 16px; \n"
"	height: 20px; \n"
"	line-height: 20px; \n"
"	margin-top: -5px; \n"
"	margin-bottom: -5px; \n"
"	border-radius: 10px; \n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover:disabled \n"
"{ \n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal \n"
"{ \n"
"	background-color: rgb(80, 80, 80);\n"
"	border: 0px solid #424242; \n"
"	height: 10px; \n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{ \n"
"	background-color:  rgb(110, 110, 110);\n"
"	border: 2px solid rgb(110, 110, 110);\n"
"	width: 16px; \n"
"	height: 20px; \n"
"	line-height: 20px; \n"
"	margin-top: -5px; \n"
"	margin-bottom: -5px; \n"
"	border-radius: 10px; \n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover \n"
"{ \n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QHeaderView::section \n"
"{\n"
"    background-color: rgb(110, 110, 110);\n"
"}\n"
"\n"
"QHeaderView::section:horizontal\n"
"{\n"
"}\n"
"\n"
"QHeaderView::section:vertical\n"
"{\n"
"}\n"
"\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(Download_and_ClipClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(20, 90, 511, 311));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 120, 16));
        textedit_videoid = new QPlainTextEdit(groupBox);
        textedit_videoid->setObjectName(QString::fromUtf8("textedit_videoid"));
        textedit_videoid->setEnabled(false);
        textedit_videoid->setGeometry(QRect(25, 40, 451, 31));
        textedit_videoid->setInputMethodHints(Qt::ImhNone);
        button_download = new QPushButton(groupBox);
        button_download->setObjectName(QString::fromUtf8("button_download"));
        button_download->setEnabled(false);
        button_download->setGeometry(QRect(120, 280, 111, 23));
        button_cleardownload = new QPushButton(groupBox);
        button_cleardownload->setObjectName(QString::fromUtf8("button_cleardownload"));
        button_cleardownload->setEnabled(true);
        button_cleardownload->setGeometry(QRect(250, 280, 111, 23));
        label_thumb = new QLabel(groupBox);
        label_thumb->setObjectName(QString::fromUtf8("label_thumb"));
        label_thumb->setGeometry(QRect(80, 90, 320, 180));
        label_thumb->setScaledContents(true);
        label_thumb->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(540, 90, 511, 311));
        button_clip = new QPushButton(groupBox_2);
        button_clip->setObjectName(QString::fromUtf8("button_clip"));
        button_clip->setEnabled(false);
        button_clip->setGeometry(QRect(160, 280, 81, 23));
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 30, 461, 91));
        spinbox_quality = new QSpinBox(groupBox_5);
        spinbox_quality->setObjectName(QString::fromUtf8("spinbox_quality"));
        spinbox_quality->setEnabled(false);
        spinbox_quality->setGeometry(QRect(380, 30, 42, 22));
        spinbox_quality->setMinimum(1);
        spinbox_quality->setMaximum(64);
        spinbox_quality->setValue(15);
        slider_quality = new QSlider(groupBox_5);
        slider_quality->setObjectName(QString::fromUtf8("slider_quality"));
        slider_quality->setEnabled(false);
        slider_quality->setGeometry(QRect(10, 30, 361, 22));
        slider_quality->setLayoutDirection(Qt::RightToLeft);
        slider_quality->setMinimum(1);
        slider_quality->setMaximum(64);
        slider_quality->setValue(15);
        slider_quality->setOrientation(Qt::Horizontal);
        label_quality_smallest = new QLabel(groupBox_5);
        label_quality_smallest->setObjectName(QString::fromUtf8("label_quality_smallest"));
        label_quality_smallest->setGeometry(QRect(10, 60, 47, 13));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(340, 60, 47, 13));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 120, 231, 71));
        textedit_starttime = new QPlainTextEdit(groupBox_6);
        textedit_starttime->setObjectName(QString::fromUtf8("textedit_starttime"));
        textedit_starttime->setEnabled(false);
        textedit_starttime->setGeometry(QRect(10, 20, 201, 31));
        textedit_starttime->setInputMethodHints(Qt::ImhNone);
        textedit_starttime->setLineWrapMode(QPlainTextEdit::NoWrap);
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(250, 120, 231, 71));
        textedit_endtime = new QPlainTextEdit(groupBox_7);
        textedit_endtime->setObjectName(QString::fromUtf8("textedit_endtime"));
        textedit_endtime->setEnabled(false);
        textedit_endtime->setGeometry(QRect(10, 20, 201, 31));
        textedit_endtime->setInputMethodHints(Qt::ImhNone);
        groupBox_8 = new QGroupBox(groupBox_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 190, 461, 71));
        textedit_outputname = new QPlainTextEdit(groupBox_8);
        textedit_outputname->setObjectName(QString::fromUtf8("textedit_outputname"));
        textedit_outputname->setEnabled(false);
        textedit_outputname->setGeometry(QRect(10, 20, 421, 31));
        textedit_outputname->setInputMethodHints(Qt::ImhNone);
        button_showfolder = new QPushButton(groupBox_2);
        button_showfolder->setObjectName(QString::fromUtf8("button_showfolder"));
        button_showfolder->setGeometry(QRect(260, 280, 81, 23));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 410, 1031, 191));
        textedit_status_box = new QTextEdit(groupBox_3);
        textedit_status_box->setObjectName(QString::fromUtf8("textedit_status_box"));
        textedit_status_box->setGeometry(QRect(10, 20, 1011, 131));
        textedit_status_box->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textedit_status_box->setReadOnly(true);
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 160, 1011, 23));
        progressBar->setValue(0);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 20, 1031, 61));
        button_downloadytdl = new QPushButton(groupBox_4);
        button_downloadytdl->setObjectName(QString::fromUtf8("button_downloadytdl"));
        button_downloadytdl->setEnabled(false);
        button_downloadytdl->setGeometry(QRect(300, 20, 181, 23));
        button_downloadffmpeg = new QPushButton(groupBox_4);
        button_downloadffmpeg->setObjectName(QString::fromUtf8("button_downloadffmpeg"));
        button_downloadffmpeg->setEnabled(false);
        button_downloadffmpeg->setGeometry(QRect(550, 20, 181, 23));
        button_downloadffmpeg->setFlat(false);
        checkbox_dark = new QCheckBox(centralWidget);
        checkbox_dark->setObjectName(QString::fromUtf8("checkbox_dark"));
        checkbox_dark->setGeometry(QRect(20, 610, 70, 17));
        checkbox_dark->setChecked(true);
        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(1060, 410, 271, 191));
        table_clipinfo = new QTableWidget(groupBox_9);
        if (table_clipinfo->columnCount() < 1)
            table_clipinfo->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_clipinfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (table_clipinfo->rowCount() < 2)
            table_clipinfo->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_clipinfo->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_clipinfo->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFlags(Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        table_clipinfo->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFlags(Qt::NoItemFlags);
        table_clipinfo->setItem(1, 0, __qtablewidgetitem4);
        table_clipinfo->setObjectName(QString::fromUtf8("table_clipinfo"));
        table_clipinfo->setEnabled(true);
        table_clipinfo->setGeometry(QRect(10, 20, 251, 161));
        sizePolicy.setHeightForWidth(table_clipinfo->sizePolicy().hasHeightForWidth());
        table_clipinfo->setSizePolicy(sizePolicy);
        table_clipinfo->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        table_clipinfo->setSelectionMode(QAbstractItemView::NoSelection);
        table_clipinfo->setShowGrid(true);
        table_clipinfo->setCornerButtonEnabled(false);
        table_clipinfo->horizontalHeader()->setVisible(false);
        table_clipinfo->horizontalHeader()->setHighlightSections(false);
        table_clipinfo->horizontalHeader()->setStretchLastSection(true);
        table_clipinfo->verticalHeader()->setVisible(true);
        table_clipinfo->verticalHeader()->setHighlightSections(false);
        table_clipinfo->verticalHeader()->setStretchLastSection(false);
        groupBox_10 = new QGroupBox(centralWidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(1060, 90, 271, 311));
        treeview_files = new QTreeView(groupBox_10);
        treeview_files->setObjectName(QString::fromUtf8("treeview_files"));
        treeview_files->setGeometry(QRect(10, 20, 251, 281));
        groupBox_11 = new QGroupBox(centralWidget);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(1060, 19, 271, 61));
        Download_and_ClipClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Download_and_ClipClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Download_and_ClipClass->setStatusBar(statusBar);

        retranslateUi(Download_and_ClipClass);

        QMetaObject::connectSlotsByName(Download_and_ClipClass);
    } // setupUi

    void retranslateUi(QMainWindow *Download_and_ClipClass)
    {
        Download_and_ClipClass->setWindowTitle(QCoreApplication::translate("Download_and_ClipClass", "Download and Clip", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Download", nullptr));
        label->setText(QCoreApplication::translate("Download_and_ClipClass", "YouTube Video ID", nullptr));
        textedit_videoid->setPlaceholderText(QString());
        button_download->setText(QCoreApplication::translate("Download_and_ClipClass", "Download", nullptr));
        button_cleardownload->setText(QCoreApplication::translate("Download_and_ClipClass", "Clear Downloaded", nullptr));
        label_thumb->setText(QCoreApplication::translate("Download_and_ClipClass", "TextLabel", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Clip", nullptr));
        button_clip->setText(QCoreApplication::translate("Download_and_ClipClass", "Clip", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Quality", nullptr));
        label_quality_smallest->setText(QCoreApplication::translate("Download_and_ClipClass", "Smallest", nullptr));
        label_7->setText(QCoreApplication::translate("Download_and_ClipClass", "Biggest", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Start Time", nullptr));
#if QT_CONFIG(tooltip)
        textedit_starttime->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        textedit_starttime->setPlainText(QCoreApplication::translate("Download_and_ClipClass", "00:00:00.0", nullptr));
        textedit_starttime->setPlaceholderText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("Download_and_ClipClass", "End Time", nullptr));
        textedit_endtime->setPlainText(QCoreApplication::translate("Download_and_ClipClass", "00:00:05.0", nullptr));
        textedit_endtime->setPlaceholderText(QString());
        groupBox_8->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Output Name", nullptr));
        textedit_outputname->setPlainText(QCoreApplication::translate("Download_and_ClipClass", "export_clip", nullptr));
        textedit_outputname->setPlaceholderText(QString());
        button_showfolder->setText(QCoreApplication::translate("Download_and_ClipClass", "Show Folder", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Info and Status", nullptr));
        textedit_status_box->setHtml(QCoreApplication::translate("Download_and_ClipClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Programs", nullptr));
        button_downloadytdl->setText(QCoreApplication::translate("Download_and_ClipClass", "Download/Update Youtube-dl", nullptr));
        button_downloadffmpeg->setText(QCoreApplication::translate("Download_and_ClipClass", "Download/Update FFmpeg", nullptr));
        checkbox_dark->setText(QCoreApplication::translate("Download_and_ClipClass", "Dark Mode", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Latest Clip Info", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_clipinfo->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Download_and_ClipClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_clipinfo->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Download_and_ClipClass", "Size", nullptr));

        const bool __sortingEnabled = table_clipinfo->isSortingEnabled();
        table_clipinfo->setSortingEnabled(false);
        table_clipinfo->setSortingEnabled(__sortingEnabled);

        groupBox_10->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Working Directory", nullptr));
        groupBox_11->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Download_and_ClipClass: public Ui_Download_and_ClipClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_AND_CLIP_H
