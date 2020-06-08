/********************************************************************************
** Form generated from reading UI file 'Download_and_Clip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_AND_CLIP_H
#define UI_DOWNLOAD_AND_CLIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Download_and_ClipClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QToolBox *import_toolbox;
    QWidget *page_5;
    QGridLayout *gridLayout_2;
    QPushButton *setup_ytdl_button;
    QSpacerItem *verticalSpacer_8;
    QLineEdit *setup_ytdl_lineedit;
    QHBoxLayout *horizontalLayout;
    QPushButton *setup_show_working_dir;
    QSpacerItem *horizontalSpacer;
    QPushButton *setup_show_output_dir;
    QLabel *setup_ytdl_label;
    QSpacerItem *verticalSpacer;
    QWidget *page_4;
    QGridLayout *gridLayout;
    QLabel *download_label;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QTableWidget *focus_table_2;
    QTextEdit *download_status;
    QLineEdit *download_linedit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *download_button;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *download_image;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *download_check_video;
    QCheckBox *download_check_thumb;
    QCheckBox *download_check_description;
    QCheckBox *download_check_probe;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QLabel *local_label;
    QSpacerItem *verticalSpacer_6;
    QPushButton *local_button;
    QTextEdit *local_status;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QLineEdit *local_lineedit;
    QPushButton *pushButton;
    QPushButton *expand_left;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *focus_image;
    QTableWidget *focus_table;
    QTextEdit *setup_status;
    QPushButton *expand_right;
    QToolBox *export_toolbox;
    QWidget *page_8;
    QGridLayout *gridLayout_7;
    QLineEdit *setup_ffprobe_lineedit;
    QLineEdit *setup_ffmpeg_lineedit;
    QPushButton *setup_ffmpeg_button;
    QPushButton *setup_ffprobe_button;
    QLabel *setup_ffprobe_label;
    QLabel *setup_ffmpeg_label;
    QSpacerItem *verticalSpacer_9;
    QWidget *page_6;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *encode_starttime;
    QLabel *label_2;
    QLineEdit *encode_endtime;
    QPushButton *encode_button;
    QLabel *encode_label;
    QGridLayout *gridLayout_3;
    QLabel *label_quality_smallest;
    QLabel *label_7;
    QSpinBox *encode_spinbox;
    QSlider *encode_slider;
    QLineEdit *encode_lineedit_filename;
    QLabel *encode_label_2;
    QLineEdit *encode_lineedit_directory;
    QSpacerItem *verticalSpacer_10;
    QTextEdit *encode_status;
    QSpacerItem *verticalSpacer_11;
    QComboBox *encode_combo;
    QSpacerItem *verticalSpacer_12;

    void setupUi(QMainWindow *Download_and_ClipClass)
    {
        if (Download_and_ClipClass->objectName().isEmpty())
            Download_and_ClipClass->setObjectName(QString::fromUtf8("Download_and_ClipClass"));
        Download_and_ClipClass->setEnabled(true);
        Download_and_ClipClass->resize(1333, 498);
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
"@QScrollBar:"
                        "horizontal {\n"
"height: 0px;\n"
"width: 0px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"height: 0px;\n"
"width: 0px;\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(Download_and_ClipClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        import_toolbox = new QToolBox(centralWidget);
        import_toolbox->setObjectName(QString::fromUtf8("import_toolbox"));
        import_toolbox->setMinimumSize(QSize(450, 450));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 447, 395));
        gridLayout_2 = new QGridLayout(page_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        setup_ytdl_button = new QPushButton(page_5);
        setup_ytdl_button->setObjectName(QString::fromUtf8("setup_ytdl_button"));
        setup_ytdl_button->setMinimumSize(QSize(60, 18));

        gridLayout_2->addWidget(setup_ytdl_button, 0, 3, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_8, 1, 1, 1, 1);

        setup_ytdl_lineedit = new QLineEdit(page_5);
        setup_ytdl_lineedit->setObjectName(QString::fromUtf8("setup_ytdl_lineedit"));

        gridLayout_2->addWidget(setup_ytdl_lineedit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        setup_show_working_dir = new QPushButton(page_5);
        setup_show_working_dir->setObjectName(QString::fromUtf8("setup_show_working_dir"));

        horizontalLayout->addWidget(setup_show_working_dir);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        setup_show_output_dir = new QPushButton(page_5);
        setup_show_output_dir->setObjectName(QString::fromUtf8("setup_show_output_dir"));

        horizontalLayout->addWidget(setup_show_output_dir);


        gridLayout_2->addLayout(horizontalLayout, 3, 1, 1, 1);

        setup_ytdl_label = new QLabel(page_5);
        setup_ytdl_label->setObjectName(QString::fromUtf8("setup_ytdl_label"));

        gridLayout_2->addWidget(setup_ytdl_label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);

        import_toolbox->addItem(page_5, QString::fromUtf8("Setup"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 447, 395));
        gridLayout = new QGridLayout(page_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        download_label = new QLabel(page_4);
        download_label->setObjectName(QString::fromUtf8("download_label"));

        gridLayout->addWidget(download_label, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        focus_table_2 = new QTableWidget(page_4);
        if (focus_table_2->rowCount() < 2)
            focus_table_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        focus_table_2->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        focus_table_2->setVerticalHeaderItem(1, __qtablewidgetitem1);
        focus_table_2->setObjectName(QString::fromUtf8("focus_table_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(focus_table_2->sizePolicy().hasHeightForWidth());
        focus_table_2->setSizePolicy(sizePolicy1);
        focus_table_2->setMinimumSize(QSize(0, 92));
        focus_table_2->setMaximumSize(QSize(16777215, 92));
        focus_table_2->setAlternatingRowColors(true);

        gridLayout->addWidget(focus_table_2, 4, 0, 1, 3);

        download_status = new QTextEdit(page_4);
        download_status->setObjectName(QString::fromUtf8("download_status"));
        download_status->setEnabled(false);
        download_status->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(download_status, 8, 0, 1, 3);

        download_linedit = new QLineEdit(page_4);
        download_linedit->setObjectName(QString::fromUtf8("download_linedit"));

        gridLayout->addWidget(download_linedit, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        download_button = new QPushButton(page_4);
        download_button->setObjectName(QString::fromUtf8("download_button"));
        download_button->setMinimumSize(QSize(60, 18));

        gridLayout->addWidget(download_button, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(page_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(0, 18));
        pushButton_2->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(pushButton_2, 5, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        download_image = new QLabel(page_4);
        download_image->setObjectName(QString::fromUtf8("download_image"));
        sizePolicy.setHeightForWidth(download_image->sizePolicy().hasHeightForWidth());
        download_image->setSizePolicy(sizePolicy);
        download_image->setMinimumSize(QSize(165, 92));
        download_image->setMaximumSize(QSize(165, 92));

        horizontalLayout_4->addWidget(download_image);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        download_check_video = new QCheckBox(page_4);
        download_check_video->setObjectName(QString::fromUtf8("download_check_video"));
        download_check_video->setEnabled(true);
        download_check_video->setMinimumSize(QSize(80, 18));

        verticalLayout_2->addWidget(download_check_video);

        download_check_thumb = new QCheckBox(page_4);
        download_check_thumb->setObjectName(QString::fromUtf8("download_check_thumb"));
        download_check_thumb->setEnabled(true);
        download_check_thumb->setMinimumSize(QSize(80, 18));

        verticalLayout_2->addWidget(download_check_thumb);

        download_check_description = new QCheckBox(page_4);
        download_check_description->setObjectName(QString::fromUtf8("download_check_description"));
        download_check_description->setEnabled(true);
        download_check_description->setMinimumSize(QSize(80, 18));

        verticalLayout_2->addWidget(download_check_description);

        download_check_probe = new QCheckBox(page_4);
        download_check_probe->setObjectName(QString::fromUtf8("download_check_probe"));
        download_check_probe->setEnabled(true);
        download_check_probe->setMinimumSize(QSize(80, 18));

        verticalLayout_2->addWidget(download_check_probe);


        horizontalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 3);

        import_toolbox->addItem(page_4, QString::fromUtf8("Download Video"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 447, 395));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        local_label = new QLabel(page_3);
        local_label->setObjectName(QString::fromUtf8("local_label"));

        gridLayout_4->addWidget(local_label, 1, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 326, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_6, 6, 1, 1, 1);

        local_button = new QPushButton(page_3);
        local_button->setObjectName(QString::fromUtf8("local_button"));
        local_button->setMinimumSize(QSize(60, 18));

        gridLayout_4->addWidget(local_button, 1, 2, 1, 1);

        local_status = new QTextEdit(page_3);
        local_status->setObjectName(QString::fromUtf8("local_status"));
        local_status->setMaximumSize(QSize(16777215, 100));

        gridLayout_4->addWidget(local_status, 3, 0, 1, 3);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_5, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_7, 2, 1, 1, 1);

        local_lineedit = new QLineEdit(page_3);
        local_lineedit->setObjectName(QString::fromUtf8("local_lineedit"));

        gridLayout_4->addWidget(local_lineedit, 1, 1, 1, 1);

        pushButton = new QPushButton(page_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 18));
        pushButton->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(pushButton, 2, 2, 1, 1);

        import_toolbox->addItem(page_3, QString::fromUtf8("Load Local File"));

        horizontalLayout_2->addWidget(import_toolbox);

        expand_left = new QPushButton(centralWidget);
        expand_left->setObjectName(QString::fromUtf8("expand_left"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(expand_left->sizePolicy().hasHeightForWidth());
        expand_left->setSizePolicy(sizePolicy2);
        expand_left->setMinimumSize(QSize(20, 20));
        expand_left->setMaximumSize(QSize(15, 16777215));
        expand_left->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(expand_left);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(350, 0));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 20, -1, -1);
        focus_image = new QLabel(groupBox);
        focus_image->setObjectName(QString::fromUtf8("focus_image"));
        sizePolicy.setHeightForWidth(focus_image->sizePolicy().hasHeightForWidth());
        focus_image->setSizePolicy(sizePolicy);
        focus_image->setMinimumSize(QSize(330, 185));
        focus_image->setMaximumSize(QSize(330, 185));

        verticalLayout->addWidget(focus_image);

        focus_table = new QTableWidget(groupBox);
        if (focus_table->rowCount() < 2)
            focus_table->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        focus_table->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        focus_table->setVerticalHeaderItem(1, __qtablewidgetitem3);
        focus_table->setObjectName(QString::fromUtf8("focus_table"));
        focus_table->setAlternatingRowColors(true);

        verticalLayout->addWidget(focus_table);

        setup_status = new QTextEdit(groupBox);
        setup_status->setObjectName(QString::fromUtf8("setup_status"));
        setup_status->setEnabled(false);
        setup_status->setMaximumSize(QSize(16777215, 60));

        verticalLayout->addWidget(setup_status);


        horizontalLayout_2->addWidget(groupBox);

        expand_right = new QPushButton(centralWidget);
        expand_right->setObjectName(QString::fromUtf8("expand_right"));
        sizePolicy2.setHeightForWidth(expand_right->sizePolicy().hasHeightForWidth());
        expand_right->setSizePolicy(sizePolicy2);
        expand_right->setMinimumSize(QSize(20, 0));
        expand_right->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(expand_right);

        export_toolbox = new QToolBox(centralWidget);
        export_toolbox->setObjectName(QString::fromUtf8("export_toolbox"));
        export_toolbox->setEnabled(true);
        export_toolbox->setMinimumSize(QSize(450, 450));
        export_toolbox->setMaximumSize(QSize(16777215, 16777215));
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        page_8->setGeometry(QRect(0, 0, 446, 422));
        gridLayout_7 = new QGridLayout(page_8);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        setup_ffprobe_lineedit = new QLineEdit(page_8);
        setup_ffprobe_lineedit->setObjectName(QString::fromUtf8("setup_ffprobe_lineedit"));

        gridLayout_7->addWidget(setup_ffprobe_lineedit, 1, 1, 1, 1);

        setup_ffmpeg_lineedit = new QLineEdit(page_8);
        setup_ffmpeg_lineedit->setObjectName(QString::fromUtf8("setup_ffmpeg_lineedit"));

        gridLayout_7->addWidget(setup_ffmpeg_lineedit, 0, 1, 1, 1);

        setup_ffmpeg_button = new QPushButton(page_8);
        setup_ffmpeg_button->setObjectName(QString::fromUtf8("setup_ffmpeg_button"));
        setup_ffmpeg_button->setMinimumSize(QSize(60, 18));

        gridLayout_7->addWidget(setup_ffmpeg_button, 0, 2, 1, 1);

        setup_ffprobe_button = new QPushButton(page_8);
        setup_ffprobe_button->setObjectName(QString::fromUtf8("setup_ffprobe_button"));
        setup_ffprobe_button->setMinimumSize(QSize(60, 18));

        gridLayout_7->addWidget(setup_ffprobe_button, 1, 2, 1, 1);

        setup_ffprobe_label = new QLabel(page_8);
        setup_ffprobe_label->setObjectName(QString::fromUtf8("setup_ffprobe_label"));

        gridLayout_7->addWidget(setup_ffprobe_label, 1, 0, 1, 1);

        setup_ffmpeg_label = new QLabel(page_8);
        setup_ffmpeg_label->setObjectName(QString::fromUtf8("setup_ffmpeg_label"));

        gridLayout_7->addWidget(setup_ffmpeg_label, 0, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_9, 2, 1, 1, 1);

        export_toolbox->addItem(page_8, QString::fromUtf8("Setup"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 446, 422));
        gridLayout_5 = new QGridLayout(page_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(page_6);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        encode_starttime = new QLineEdit(page_6);
        encode_starttime->setObjectName(QString::fromUtf8("encode_starttime"));
        encode_starttime->setEnabled(true);

        horizontalLayout_3->addWidget(encode_starttime);

        label_2 = new QLabel(page_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        encode_endtime = new QLineEdit(page_6);
        encode_endtime->setObjectName(QString::fromUtf8("encode_endtime"));
        encode_endtime->setEnabled(true);

        horizontalLayout_3->addWidget(encode_endtime);


        gridLayout_5->addLayout(horizontalLayout_3, 5, 0, 1, 3);

        encode_button = new QPushButton(page_6);
        encode_button->setObjectName(QString::fromUtf8("encode_button"));
        encode_button->setMinimumSize(QSize(60, 18));

        gridLayout_5->addWidget(encode_button, 0, 2, 1, 1);

        encode_label = new QLabel(page_6);
        encode_label->setObjectName(QString::fromUtf8("encode_label"));

        gridLayout_5->addWidget(encode_label, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_quality_smallest = new QLabel(page_6);
        label_quality_smallest->setObjectName(QString::fromUtf8("label_quality_smallest"));
        label_quality_smallest->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_3->addWidget(label_quality_smallest, 2, 0, 1, 1);

        label_7 = new QLabel(page_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_3->addWidget(label_7, 2, 1, 1, 1);

        encode_spinbox = new QSpinBox(page_6);
        encode_spinbox->setObjectName(QString::fromUtf8("encode_spinbox"));
        encode_spinbox->setEnabled(true);
        encode_spinbox->setMaximumSize(QSize(40, 16777215));
        encode_spinbox->setMinimum(1);
        encode_spinbox->setMaximum(64);
        encode_spinbox->setValue(15);

        gridLayout_3->addWidget(encode_spinbox, 1, 2, 1, 1);

        encode_slider = new QSlider(page_6);
        encode_slider->setObjectName(QString::fromUtf8("encode_slider"));
        encode_slider->setEnabled(true);
        encode_slider->setLayoutDirection(Qt::RightToLeft);
        encode_slider->setMinimum(0);
        encode_slider->setMaximum(51);
        encode_slider->setValue(15);
        encode_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(encode_slider, 1, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout_3, 3, 0, 1, 3);

        encode_lineedit_filename = new QLineEdit(page_6);
        encode_lineedit_filename->setObjectName(QString::fromUtf8("encode_lineedit_filename"));

        gridLayout_5->addWidget(encode_lineedit_filename, 1, 1, 1, 1);

        encode_label_2 = new QLabel(page_6);
        encode_label_2->setObjectName(QString::fromUtf8("encode_label_2"));

        gridLayout_5->addWidget(encode_label_2, 1, 0, 1, 1);

        encode_lineedit_directory = new QLineEdit(page_6);
        encode_lineedit_directory->setObjectName(QString::fromUtf8("encode_lineedit_directory"));

        gridLayout_5->addWidget(encode_lineedit_directory, 0, 1, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_10, 7, 1, 1, 1);

        encode_status = new QTextEdit(page_6);
        encode_status->setObjectName(QString::fromUtf8("encode_status"));
        encode_status->setEnabled(false);
        encode_status->setMaximumSize(QSize(16777215, 100));

        gridLayout_5->addWidget(encode_status, 8, 0, 1, 3);

        verticalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_11, 2, 1, 1, 1);

        encode_combo = new QComboBox(page_6);
        encode_combo->addItem(QString());
        encode_combo->addItem(QString());
        encode_combo->addItem(QString());
        encode_combo->setObjectName(QString::fromUtf8("encode_combo"));

        gridLayout_5->addWidget(encode_combo, 1, 2, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_12, 4, 1, 1, 1);

        export_toolbox->addItem(page_6, QString::fromUtf8("Encode"));

        horizontalLayout_2->addWidget(export_toolbox);

        Download_and_ClipClass->setCentralWidget(centralWidget);

        retranslateUi(Download_and_ClipClass);

        import_toolbox->setCurrentIndex(1);
        export_toolbox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Download_and_ClipClass);
    } // setupUi

    void retranslateUi(QMainWindow *Download_and_ClipClass)
    {
        Download_and_ClipClass->setWindowTitle(QCoreApplication::translate("Download_and_ClipClass", "YesClip", nullptr));
        setup_ytdl_button->setText(QCoreApplication::translate("Download_and_ClipClass", "Browse", nullptr));
        setup_show_working_dir->setText(QCoreApplication::translate("Download_and_ClipClass", "Show Working Dir", nullptr));
        setup_show_output_dir->setText(QCoreApplication::translate("Download_and_ClipClass", "Show Output Dir", nullptr));
        setup_ytdl_label->setText(QCoreApplication::translate("Download_and_ClipClass", "YouTube-DL: ", nullptr));
        import_toolbox->setItemText(import_toolbox->indexOf(page_5), QCoreApplication::translate("Download_and_ClipClass", "Setup", nullptr));
        download_label->setText(QCoreApplication::translate("Download_and_ClipClass", "URL: ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = focus_table_2->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Download_and_ClipClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = focus_table_2->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Download_and_ClipClass", "Size", nullptr));
        download_button->setText(QCoreApplication::translate("Download_and_ClipClass", "Download", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Download_and_ClipClass", "> Focus >", nullptr));
        download_image->setText(QCoreApplication::translate("Download_and_ClipClass", "Image", nullptr));
        download_check_video->setText(QCoreApplication::translate("Download_and_ClipClass", "Video", nullptr));
        download_check_thumb->setText(QCoreApplication::translate("Download_and_ClipClass", "Thumbnail", nullptr));
        download_check_description->setText(QCoreApplication::translate("Download_and_ClipClass", "Description", nullptr));
        download_check_probe->setText(QCoreApplication::translate("Download_and_ClipClass", "Info Probe", nullptr));
        import_toolbox->setItemText(import_toolbox->indexOf(page_4), QCoreApplication::translate("Download_and_ClipClass", "Download Video", nullptr));
        local_label->setText(QCoreApplication::translate("Download_and_ClipClass", "Directory: ", nullptr));
        local_button->setText(QCoreApplication::translate("Download_and_ClipClass", "Browse", nullptr));
        pushButton->setText(QCoreApplication::translate("Download_and_ClipClass", "> Focus >", nullptr));
        import_toolbox->setItemText(import_toolbox->indexOf(page_3), QCoreApplication::translate("Download_and_ClipClass", "Load Local File", nullptr));
        expand_left->setText(QCoreApplication::translate("Download_and_ClipClass", "<", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Download_and_ClipClass", "Focused Media", nullptr));
        focus_image->setText(QCoreApplication::translate("Download_and_ClipClass", "Image", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = focus_table->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Download_and_ClipClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = focus_table->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Download_and_ClipClass", "Size", nullptr));
        expand_right->setText(QCoreApplication::translate("Download_and_ClipClass", ">", nullptr));
        setup_ffprobe_lineedit->setText(QString());
        setup_ffmpeg_button->setText(QCoreApplication::translate("Download_and_ClipClass", "Browse", nullptr));
        setup_ffprobe_button->setText(QCoreApplication::translate("Download_and_ClipClass", "Browse", nullptr));
        setup_ffprobe_label->setText(QCoreApplication::translate("Download_and_ClipClass", "ffprobe: ", nullptr));
        setup_ffmpeg_label->setText(QCoreApplication::translate("Download_and_ClipClass", "FFmpeg: ", nullptr));
        export_toolbox->setItemText(export_toolbox->indexOf(page_8), QCoreApplication::translate("Download_and_ClipClass", "Setup", nullptr));
        label->setText(QCoreApplication::translate("Download_and_ClipClass", "Start Time: ", nullptr));
        encode_starttime->setText(QCoreApplication::translate("Download_and_ClipClass", "00:00:00.0", nullptr));
        label_2->setText(QCoreApplication::translate("Download_and_ClipClass", "End Time: ", nullptr));
        encode_endtime->setText(QCoreApplication::translate("Download_and_ClipClass", "00:00:05.0", nullptr));
        encode_button->setText(QCoreApplication::translate("Download_and_ClipClass", "Browse", nullptr));
        encode_label->setText(QCoreApplication::translate("Download_and_ClipClass", "Directory: ", nullptr));
        label_quality_smallest->setText(QCoreApplication::translate("Download_and_ClipClass", "Smallest", nullptr));
        label_7->setText(QCoreApplication::translate("Download_and_ClipClass", "Biggest", nullptr));
        encode_label_2->setText(QCoreApplication::translate("Download_and_ClipClass", "File: ", nullptr));
        encode_combo->setItemText(0, QCoreApplication::translate("Download_and_ClipClass", "x264", nullptr));
        encode_combo->setItemText(1, QCoreApplication::translate("Download_and_ClipClass", "x265", nullptr));
        encode_combo->setItemText(2, QCoreApplication::translate("Download_and_ClipClass", "gif", nullptr));

        export_toolbox->setItemText(export_toolbox->indexOf(page_6), QCoreApplication::translate("Download_and_ClipClass", "Encode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Download_and_ClipClass: public Ui_Download_and_ClipClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_AND_CLIP_H
