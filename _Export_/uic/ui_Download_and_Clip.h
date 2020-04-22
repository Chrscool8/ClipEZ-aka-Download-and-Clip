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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Download_and_ClipClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QPushButton *button_clip;
    QGroupBox *groupBox_5;
    QSpinBox *spinbox_quality;
    QSlider *slider_quality;
    QLabel *label_quality_smallest;
    QLabel *label_7;
    QGroupBox *groupBox_6;
    QLineEdit *lineedit_starttime;
    QGroupBox *groupBox_7;
    QLineEdit *lineedit_endtime;
    QGroupBox *groupBox_8;
    QGroupBox *groupBox_13;
    QLineEdit *lineedit_directory;
    QPushButton *button_choose_directory;
    QGroupBox *groupBox_14;
    QLineEdit *lineedit_outputname;
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
    QPushButton *button_showworking;
    QPushButton *button_showoutput;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QPlainTextEdit *textedit_videoid;
    QPushButton *button_download;
    QPushButton *button_cleardownload;
    QLabel *label_thumb_download;
    QLabel *label_download_title;
    QWidget *tab_2;
    QGroupBox *groupBox_12;
    QLabel *label_thumb_local;
    QPushButton *pushButton;
    QLabel *label_local_name;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Download_and_ClipClass)
    {
        if (Download_and_ClipClass->objectName().isEmpty())
            Download_and_ClipClass->setObjectName(QString::fromUtf8("Download_and_ClipClass"));
        Download_and_ClipClass->setEnabled(true);
        Download_and_ClipClass->resize(1371, 709);
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
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(550, 90, 511, 361));
        button_clip = new QPushButton(groupBox_2);
        button_clip->setObjectName(QString::fromUtf8("button_clip"));
        button_clip->setEnabled(false);
        button_clip->setGeometry(QRect(210, 330, 81, 23));
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
        groupBox_6->setGeometry(QRect(20, 120, 231, 51));
        lineedit_starttime = new QLineEdit(groupBox_6);
        lineedit_starttime->setObjectName(QString::fromUtf8("lineedit_starttime"));
        lineedit_starttime->setEnabled(false);
        lineedit_starttime->setGeometry(QRect(20, 20, 191, 20));
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(250, 120, 231, 51));
        lineedit_endtime = new QLineEdit(groupBox_7);
        lineedit_endtime->setObjectName(QString::fromUtf8("lineedit_endtime"));
        lineedit_endtime->setEnabled(false);
        lineedit_endtime->setGeometry(QRect(20, 20, 191, 20));
        groupBox_8 = new QGroupBox(groupBox_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 170, 461, 151));
        groupBox_13 = new QGroupBox(groupBox_8);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(20, 30, 421, 51));
        lineedit_directory = new QLineEdit(groupBox_13);
        lineedit_directory->setObjectName(QString::fromUtf8("lineedit_directory"));
        lineedit_directory->setEnabled(true);
        lineedit_directory->setGeometry(QRect(10, 20, 321, 20));
        lineedit_directory->setReadOnly(true);
        button_choose_directory = new QPushButton(groupBox_13);
        button_choose_directory->setObjectName(QString::fromUtf8("button_choose_directory"));
        button_choose_directory->setGeometry(QRect(330, 20, 71, 20));
        groupBox_14 = new QGroupBox(groupBox_8);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(20, 80, 421, 51));
        lineedit_outputname = new QLineEdit(groupBox_14);
        lineedit_outputname->setObjectName(QString::fromUtf8("lineedit_outputname"));
        lineedit_outputname->setEnabled(false);
        lineedit_outputname->setGeometry(QRect(10, 20, 391, 21));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 460, 1031, 191));
        textedit_status_box = new QTextEdit(groupBox_3);
        textedit_status_box->setObjectName(QString::fromUtf8("textedit_status_box"));
        textedit_status_box->setGeometry(QRect(10, 20, 1011, 131));
        textedit_status_box->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textedit_status_box->setReadOnly(true);
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 160, 1011, 23));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 20, 1031, 61));
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
        checkbox_dark->setGeometry(QRect(30, 660, 70, 17));
        checkbox_dark->setChecked(true);
        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(1070, 460, 271, 191));
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
        groupBox_10->setGeometry(QRect(1070, 90, 271, 361));
        treeview_files = new QTreeView(groupBox_10);
        treeview_files->setObjectName(QString::fromUtf8("treeview_files"));
        treeview_files->setGeometry(QRect(10, 20, 251, 331));
        groupBox_11 = new QGroupBox(centralWidget);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(1070, 19, 271, 61));
        button_showworking = new QPushButton(groupBox_11);
        button_showworking->setObjectName(QString::fromUtf8("button_showworking"));
        button_showworking->setGeometry(QRect(30, 20, 101, 23));
        button_showoutput = new QPushButton(groupBox_11);
        button_showoutput->setObjectName(QString::fromUtf8("button_showoutput"));
        button_showoutput->setGeometry(QRect(140, 20, 101, 23));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(14, 90, 527, 361));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(-10, -10, 521, 381));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 120, 16));
        textedit_videoid = new QPlainTextEdit(groupBox);
        textedit_videoid->setObjectName(QString::fromUtf8("textedit_videoid"));
        textedit_videoid->setEnabled(false);
        textedit_videoid->setGeometry(QRect(25, 40, 461, 31));
        textedit_videoid->setInputMethodHints(Qt::ImhNone);
        button_download = new QPushButton(groupBox);
        button_download->setObjectName(QString::fromUtf8("button_download"));
        button_download->setEnabled(false);
        button_download->setGeometry(QRect(370, 170, 111, 23));
        button_cleardownload = new QPushButton(groupBox);
        button_cleardownload->setObjectName(QString::fromUtf8("button_cleardownload"));
        button_cleardownload->setEnabled(true);
        button_cleardownload->setGeometry(QRect(370, 210, 111, 23));
        label_thumb_download = new QLabel(groupBox);
        label_thumb_download->setObjectName(QString::fromUtf8("label_thumb_download"));
        label_thumb_download->setGeometry(QRect(30, 120, 291, 161));
        label_thumb_download->setFrameShape(QFrame::NoFrame);
        label_thumb_download->setScaledContents(true);
        label_thumb_download->setAlignment(Qt::AlignCenter);
        label_download_title = new QLabel(groupBox);
        label_download_title->setObjectName(QString::fromUtf8("label_download_title"));
        label_download_title->setGeometry(QRect(30, 90, 291, 20));
        label_download_title->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_12 = new QGroupBox(tab_2);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(-10, -10, 531, 331));
        label_thumb_local = new QLabel(groupBox_12);
        label_thumb_local->setObjectName(QString::fromUtf8("label_thumb_local"));
        label_thumb_local->setGeometry(QRect(120, 110, 291, 141));
        label_thumb_local->setFrameShape(QFrame::NoFrame);
        label_thumb_local->setScaledContents(true);
        label_thumb_local->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox_12);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(230, 50, 75, 23));
        label_local_name = new QLabel(groupBox_12);
        label_local_name->setObjectName(QString::fromUtf8("label_local_name"));
        label_local_name->setGeometry(QRect(240, 280, 47, 13));
        tabWidget->addTab(tab_2, QString());
        Download_and_ClipClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Download_and_ClipClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Download_and_ClipClass->setStatusBar(statusBar);

        retranslateUi(Download_and_ClipClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Download_and_ClipClass);
    } // setupUi

    void retranslateUi(QMainWindow *Download_and_ClipClass)
    {
        Download_and_ClipClass->setWindowTitle(QCoreApplication::translate("Download_and_ClipClass", "YesClip", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Clip", nullptr));
        button_clip->setText(QCoreApplication::translate("Download_and_ClipClass", "Clip", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Quality", nullptr));
        label_quality_smallest->setText(QCoreApplication::translate("Download_and_ClipClass", "Smallest", nullptr));
        label_7->setText(QCoreApplication::translate("Download_and_ClipClass", "Biggest", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Start Time", nullptr));
        lineedit_starttime->setText(QCoreApplication::translate("Download_and_ClipClass", "00:00:00.0", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("Download_and_ClipClass", "End Time", nullptr));
        lineedit_endtime->setText(QCoreApplication::translate("Download_and_ClipClass", "00:00:05.0", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Output", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Directory", nullptr));
        lineedit_directory->setText(QCoreApplication::translate("Download_and_ClipClass", "C:/temp/", nullptr));
        button_choose_directory->setText(QCoreApplication::translate("Download_and_ClipClass", "Choose", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("Download_and_ClipClass", "File Name", nullptr));
        lineedit_outputname->setText(QCoreApplication::translate("Download_and_ClipClass", "export_clip", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Info and Status", nullptr));
        textedit_status_box->setHtml(QCoreApplication::translate("Download_and_ClipClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        progressBar->setFormat(QCoreApplication::translate("Download_and_ClipClass", "%p% ", nullptr));
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
        groupBox_11->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Explorer", nullptr));
        button_showworking->setText(QCoreApplication::translate("Download_and_ClipClass", "Working Dir", nullptr));
        button_showoutput->setText(QCoreApplication::translate("Download_and_ClipClass", "Output Dir", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Download_and_ClipClass", "YouTube Video ID", nullptr));
        textedit_videoid->setPlaceholderText(QString());
        button_download->setText(QCoreApplication::translate("Download_and_ClipClass", "Download", nullptr));
        button_cleardownload->setText(QCoreApplication::translate("Download_and_ClipClass", "Clear Downloaded", nullptr));
        label_thumb_download->setText(QCoreApplication::translate("Download_and_ClipClass", "[Thumbnail]", nullptr));
        label_download_title->setText(QCoreApplication::translate("Download_and_ClipClass", "Video Title", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Download_and_ClipClass", "Download", nullptr));
        groupBox_12->setTitle(QString());
        label_thumb_local->setText(QCoreApplication::translate("Download_and_ClipClass", "[Thumbnail]", nullptr));
        pushButton->setText(QCoreApplication::translate("Download_and_ClipClass", "Choose File", nullptr));
        label_local_name->setText(QCoreApplication::translate("Download_and_ClipClass", "File Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Download_and_ClipClass", "Local File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Download_and_ClipClass: public Ui_Download_and_ClipClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_AND_CLIP_H
