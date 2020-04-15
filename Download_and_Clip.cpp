#include "Download_and_Clip.h"
#include "qwidget.h"
#include "curl/curl.h"
#include <fstream>
#include "zlib.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>

#include <atlbase.h>
#include <atlconv.h>
#include <iostream>

#include <filesystem>  
namespace fs = std::filesystem;
fs::path working_dir("working_directory/");

std::string status = "";
void Download_and_Clip::update_status(std::string str)
{
	status += str;
	status += "\n";

	ui.textedit_status_box->setPlainText(QString::fromStdString(status));
}

static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
	return written;

}

int Download_and_Clip::download_file(std::string _url, std::string _file) {
	CURL* curl;
	FILE* fp;

	curl = curl_easy_init();
	if (curl)
	{
		fp = fopen(_file.c_str(), "wb");
		curl_easy_setopt(curl, CURLOPT_URL, _url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
		update_status("Started downloading from: ");
		update_status(_url);
		//CURLcode res = 
		curl_easy_perform(curl);
		update_status("Done.");
		curl_easy_cleanup(curl);
		fclose(fp);
	}
	return 0;
}

void Download_and_Clip::check_for_ytdl()
{
	if (fs::exists(fs::path("youtube-dl.exe")))
	{
		update_status("youtube-dl.exe found.");
		ui.textedit_videoid->setEnabled(true);
		ui.button_download->setEnabled(true);
		//ui.button_downloadytdl->setEnabled(true);
		ui.button_downloadytdl->setText("Update Youtube-DL");
	}
	else
	{
		update_status("youtube-dl.exe not found.");
		ui.textedit_videoid->setEnabled(false);
		ui.button_download->setEnabled(false);
		//ui.button_downloadytdl->setEnabled(true);
		ui.button_downloadytdl->setText("Download Youtube-DL");
	}
}

void Download_and_Clip::check_for_ffmpeg()
{
	if (fs::exists(fs::path("ffmpeg.exe")))
	{
		update_status("ffmpeg.exe found.");
		ui.button_downloadffmpeg->setEnabled(false);
		ui.button_downloadffmpeg->setText("Update ffmpeg");
		ui.textedit_starttime->setEnabled(false);
		ui.textedit_endtime->setEnabled(false);
		ui.textedit_starttime->setEnabled(true);
		ui.textedit_endtime->setEnabled(true);
		ui.slider_quality->setEnabled(true);
		ui.spinbox_quality->setEnabled(true);
		ui.textedit_outputname->setEnabled(true);
		ui.button_clip->setEnabled(true);
	}
	else
	{
		update_status("ffmpeg.exe not found.");
		ui.button_downloadffmpeg->setEnabled(false);
		ui.button_downloadffmpeg->setText("Download ffmpeg");
		ui.slider_quality->setEnabled(false);
		ui.spinbox_quality->setEnabled(false);
		ui.textedit_outputname->setEnabled(false);
		ui.button_clip->setEnabled(false);
	}
}

QProcess* process_ytdl;
QProcess* process_ffmpeg;

void Download_and_Clip::download_ytdl()
{
	ui.button_downloadytdl->setEnabled(false);
	download_file("https://yt-dl.org/latest/youtube-dl.exe", "youtube-dl.exe");
	check_for_ytdl();
}

void Download_and_Clip::download_ffmpeg()
{
	ui.button_downloadytdl->setEnabled(false);
	download_file("https://ffmpeg.zeranoe.com/builds/win64/static/ffmpeg-20200403-52523b6-win64-static.zip", "ffmpeg.zip");
	check_for_ffmpeg();
}

void Download_and_Clip::run_ytdl()
{
	update_status("Run YT-DL");
	remove("downloaded_video.*");
	std::string program = "youtube-dl.exe";
	QStringList args = { ui.textedit_videoid->toPlainText(), "-o", "working_directory/downloaded_video", "--write-thumbnail", "-f", "bestvideo+bestaudio/best" };
	//mTranscodingProcess = new QProcess;
	process_ytdl->setProgram(program.c_str());
	process_ytdl->setStandardErrorFile("stderr.txt");
	process_ytdl->setStandardOutputFile("stdout.txt");
	process_ytdl->setArguments(args);
	process_ytdl->start();

	ui.button_download->setEnabled(false);

	//myProcess->start(program.c_str());
	//mTranscodingProcess->start(program, args, om);

}

void Download_and_Clip::processStarted_ytdl()
{
	update_status("Process Started.");
}

void Download_and_Clip::readyReadStandardOutput_ytdl()
{
	update_status("Output.");
}

void Download_and_Clip::downloadFinished_ytdl()
{
	update_status("Done.");
	ui.button_download->setEnabled(true);

	QPixmap image("working_directory/downloaded_video.jpg");
	ui.label_thumb->setPixmap(image);

	check_for_ffmpeg();
}


void Download_and_Clip::run_ffmpeg()
{
	if (ui.textedit_outputname->toPlainText().length() > 0)
		remove((((std::string)ui.textedit_outputname->toPlainText().toStdString()) + ".mp4").c_str());

	update_status("Run FFMPEG");
	std::string program = "cmd.exe";
	QStringList args;
	args << "/C";
	args << R"(trim.bat)";
	args << ui.textedit_starttime->toPlainText();
	args << ui.textedit_endtime->toPlainText();
	args << std::to_string(ui.slider_quality->value()).c_str();
	args << ui.textedit_outputname->toPlainText();
	process_ffmpeg->setProgram(program.c_str());
	process_ffmpeg->setStandardErrorFile("stderr.txt");
	process_ffmpeg->setStandardOutputFile("stdout.txt");
	process_ffmpeg->setArguments(args);
	process_ffmpeg->start();

	ui.button_download->setEnabled(false);
	ui.button_clip->setEnabled(false);
}

void Download_and_Clip::processStarted_ffmpeg()
{
	update_status("Process Started.");
}

void Download_and_Clip::readyReadStandardOutput_ffmpeg()
{
	update_status("Output.");
}
void Download_and_Clip::encodingFinished_ffmpeg()
{
	update_status("Done.");
	ui.button_download->setEnabled(true);
	ui.button_clip->setEnabled(true);
	update_status("Your clip was saved to: ");
	std::string s = ui.textedit_outputname->toPlainText().toStdString();
	update_status(s);
}

void Download_and_Clip::darkmode_toggle(bool state)
{
	darkmode(state);
}

void Download_and_Clip::clear_download()
{
	update_status("Clear");
	fs::remove_all(working_dir);
}

void Download_and_Clip::darkmode(bool on)
{

	//update_status(std::to_string(state));
	if (on)
	{
		QPalette palette;
		palette.setColor(QPalette::Window, QColor(53, 53, 53));
		palette.setColor(QPalette::WindowText, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::WindowText,
			QColor(127, 127, 127));
		palette.setColor(QPalette::Base, QColor(42, 42, 42));
		palette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
		palette.setColor(QPalette::ToolTipBase, Qt::white);
		palette.setColor(QPalette::ToolTipText, QColor(53, 53, 53));
		palette.setColor(QPalette::Text, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
		palette.setColor(QPalette::Dark, QColor(35, 35, 35));
		palette.setColor(QPalette::Shadow, QColor(20, 20, 20));
		palette.setColor(QPalette::Button, QColor(53, 53, 53));
		palette.setColor(QPalette::ButtonText, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::ButtonText,
			QColor(127, 127, 127));
		palette.setColor(QPalette::BrightText, Qt::red);
		palette.setColor(QPalette::Link, QColor(42, 130, 218));
		palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
		palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
		palette.setColor(QPalette::HighlightedText, Qt::white);
		palette.setColor(QPalette::Disabled, QPalette::HighlightedText,
			QColor(127, 127, 127));
		this->setPalette(palette);

		std::string ss =
			"QToolTip{"
			"  color:#ffffff;"
			"  background-color:palette(base);"
			"  border:1px solid palette(highlight);"
			"  border-radius:4px;"
			"}"
			"QStatusBar{"
			"  background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  color:palette(mid);"
			"}"
			"QMenuBar{"
			"  background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border-bottom:2px solid rgba(25,25,25,75);"
			"}"
			"QMenuBar::item{"
			"  spacing:2px;"
			"  padding:3px 4px;"
			"  background:transparent;"
			"}"
			"QMenuBar::item:selected{"
			"  background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(106,106,106,255),stop:1 rgba(106,106,106,75));"
			"  border-left:1px solid rgba(106,106,106,127);"
			"  border-right:1px solid rgba(106,106,106,127);"
			"}"
			"QMenuBar::item:pressed{"
			"  background-color:palette(highlight);"
			"  border-left:1px solid rgba(25,25,25,127);"
			"  border-right:1px solid rgba(25,25,25,127);"
			"}"
			"QMenu{"
			"  background-color:palette(window);"
			"  border:1px solid palette(shadow);"
			"}"
			"QMenu::item{"
			"  padding:3px 25px 3px 25px;"
			"  border:1px solid transparent;"
			"}"
			"QMenu::item:disabled{"
			"  background-color:rgba(35,35,35,127);"
			"  color:palette(disabled);"
			"}"
			"QMenu::item:selected{"
			"  border-color:rgba(147,191,236,127);"
			"  background:palette(highlight);"
			"}"
			"QMenu::icon:checked{"
			"  background-color:qlineargradient(x1:0,y1:1,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border:1px solid palette(highlight);"
			"  border-radius:2px;"
			"}"
			"QMenu::separator{"
			"  height:1px;"
			"  background:palette(alternate-base);"
			"  margin-left:5px;"
			"  margin-right:5px;"
			"}"
			"QMenu::indicator{"
			"  width:18px;"
			"  height:18px;"
			"}"
			"QMenu::indicator:non-exclusive:checked{"
			"  image:url(:/darkstyle/icon_checkbox_checked.png);"
			"  padding-left:2px;"
			"}"
			"QMenu::indicator:non-exclusive:unchecked{"
			"  image:url(:/darkstyle/icon_checkbox_unchecked.png);"
			"  padding-left:2px;"
			"}"
			"QMenu::indicator:exclusive:checked{"
			"  image:url(:/darkstyle/icon_radiobutton_checked.png);"
			"  padding-left:2px;"
			"}"
			"QMenu::indicator:exclusive:unchecked{"
			"  image:url(:/darkstyle/icon_radiobutton_unchecked.png);"
			"  padding-left:2px;"
			"}"
			"QToolBar::top{"
			"  background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border-bottom:3px solid qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"}"
			"QToolBar::bottom{"
			"  background-color:qlineargradient(x1:0,y1:1,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border-top:3px solid qlineargradient(x1:0,y1:1,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"}"
			"QToolBar::left{"
			"  background-color:qlineargradient(x1:0,y1:0,x2:1,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border-right:3px solid qlineargradient(x1:0,y1:0,x2:1,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"}"
			"QToolBar::right{"
			"  background-color:qlineargradient(x1:1,y1:0,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border-left:3px solid qlineargradient(x1:1,y1:0,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"}"
			"QMainWindow::separator{"
			"  width:6px;"
			"  height:5px;"
			"  padding:2px;"
			"}"
			"QSplitter::handle:horizontal{"
			"  width:10px;"
			"}"
			"QSplitter::handle:vertical{"
			"  height:10px;"
			"}"
			"QMainWindow::separator:hover,QSplitter::handle:hover{"
			"  background:palette(highlight);"
			"}"
			"QDockWidget::title{"
			"  padding:4px;"
			"  background-color:qlineargradient(x1:0,y1:1,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border:1px solid rgba(25,25,25,75);"
			"  border-bottom:2px solid rgba(25,25,25,75);"
			"}"
			"QDockWidget{"
			"  titlebar-close-icon:url(:/darkstyle/icon_close.png);"
			"  titlebar-normal-icon:url(:/darkstyle/icon_restore.png);"
			"}"
			"QDockWidget::close-button,QDockWidget::float-button{"
			"  subcontrol-position:top right;"
			"  subcontrol-origin:margin;"
			"  position:absolute;"
			"  top:3px;"
			"  bottom:0px;"
			"  width:20px;"
			"  height:20px;"
			"}"
			"QDockWidget::close-button{"
			"  right:3px;"
			"}"
			"QDockWidget::float-button{"
			"  right:25px;"
			"}"
			"QGroupBox{"
			"  background-color:rgba(66,66,66,50%);"
			"  margin-top:27px;"
			"  border:1px solid rgba(25,25,25,127);"
			"  border-radius:4px;"
			"}"
			"QGroupBox::title{"
			"  subcontrol-origin:margin;"
			"  subcontrol-position:left top;"
			"  padding:4px 6px;"
			"  margin-left:3px;"
			"  background-color:qlineargradient(x1:0,y1:1,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border:1px solid rgba(25,25,25,75);"
			"  border-bottom:2px solid rgb(127,127,127);"
			"  border-top-left-radius:4px;"
			"  border-top-right-radius:4px;"
			"}"
			"QTabWidget::pane{"
			"  background-color:rgba(66,66,66,50%);"
			"  border-top:1px solid rgba(25,25,25,50%);"
			"}"
			"QTabWidget::tab-bar{"
			"  left:3px;"
			"  top:1px;"
			"}"
			"QTabBar{"
			"  background-color:transparent;"
			"  qproperty-drawBase:0;"
			"  border-bottom:1px solid rgba(25,25,25,50%);"
			"}"
			"QTabBar::tab{"
			"  padding:4px 6px;"
			"  background-color:qlineargradient(x1:0,y1:1,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border:1px solid rgba(25,25,25,75);"
			"  border-top-left-radius:4px;"
			"  border-top-right-radius:4px;"
			"}"
			"QTabBar::tab:selected,QTabBar::tab:hover{"
			"  background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(53,53,53,127),stop:1 rgba(66,66,66,50%));"
			"  border-bottom-color:rgba(66,66,66,75%);"
			"}"
			"QTabBar::tab:selected{"
			"  border-bottom:2px solid palette(highlight);"
			"}"
			"QTabBar::tab::selected:disabled{"
			"  border-bottom:2px solid rgb(127,127,127);"
			"}"
			"QTabBar::tab:!selected{"
			"  margin-top:2px;"
			"}"
			"QCheckBox::indicator{"
			"  width:18px;"
			"  height:18px;"
			"}"
			"QCheckBox::indicator:checked,QTreeView::indicator:checked,QTableView::indicator:checked,QGroupBox::indicator:checked{"
			"  image:url(:/darkstyle/icon_checkbox_checked.png);"
			"}"
			"QCheckBox::indicator:checked:pressed,QTreeView::indicator:checked:pressed,QTableView::indicator:checked:pressed,QGroupBox::indicator:checked:pressed{"
			"  image:url(:/darkstyle/icon_checkbox_checked_pressed.png);"
			"}"
			"QCheckBox::indicator:checked:disabled,QTreeView::indicator:checked:disabled,QTableView::indicator:checked:disabled,QGroupBox::indicator:checked:disabled{"
			"  image:url(:/darkstyle/icon_checkbox_checked_disabled.png);"
			"}"
			"QCheckBox::indicator:unchecked,QTreeView::indicator:unchecked,QTableView::indicator:unchecked,QGroupBox::indicator:unchecked{"
			"  image:url(:/darkstyle/icon_checkbox_unchecked.png);"
			"}"
			"QCheckBox::indicator:unchecked:pressed,QTreeView::indicator:unchecked:pressed,QTableView::indicator:unchecked:pressed,QGroupBox::indicator:unchecked:pressed{"
			"  image:url(:/darkstyle/icon_checkbox_unchecked_pressed.png);"
			"}"
			"QCheckBox::indicator:unchecked:disabled,QTreeView::indicator:unchecked:disabled,QTableView::indicator:unchecked:disabled,QGroupBox::indicator:unchecked:disabled{"
			"  image:url(:/darkstyle/icon_checkbox_unchecked_disabled.png);"
			"}"
			"QCheckBox::indicator:indeterminate,QTreeView::indicator:indeterminate,QTableView::indicator:indeterminate,QGroupBox::indicator:indeterminate{"
			"  image:url(:/darkstyle/icon_checkbox_indeterminate.png);"
			"}"
			"QCheckBox::indicator:indeterminate:pressed,QTreeView::indicator:indeterminate:pressed,QTableView::indicator:indeterminate:pressed,QGroupBox::indicator:indeterminate:pressed{"
			"  image:url(:/darkstyle/icon_checkbox_indeterminate_pressed.png);"
			"}"
			"QCheckBox::indicator:indeterminate:disabled,QTreeView::indicator:indeterminate:disabled,QTableView::indicator:indeterminate:disabled,QGroupBox::indicator:indeterminate:disabled{"
			"  image:url(:/darkstyle/icon_checkbox_indeterminate_disabled.png);"
			"}"
			"QRadioButton::indicator{"
			"  width:18px;"
			"  height:18px;"
			"}"
			"QRadioButton::indicator:checked{"
			"  image:url(:/darkstyle/icon_radiobutton_checked.png);"
			"}"
			"QRadioButton::indicator:checked:pressed{"
			"  image:url(:/darkstyle/icon_radiobutton_checked_pressed.png);"
			"}"
			"QRadioButton::indicator:checked:disabled{"
			"  image:url(:/darkstyle/icon_radiobutton_checked_disabled.png);"
			"}"
			"QRadioButton::indicator:unchecked{"
			"  image:url(:/darkstyle/icon_radiobutton_unchecked.png);"
			"}"
			"QRadioButton::indicator:unchecked:pressed{"
			"  image:url(:/darkstyle/icon_radiobutton_unchecked_pressed.png);"
			"}"
			"QRadioButton::indicator:unchecked:disabled{"
			"  image:url(:/darkstyle/icon_radiobutton_unchecked_disabled.png);"
			"}"
			"QTreeView, QTableView{"
			"  alternate-background-color:palette(window);"
			"  background:palette(base);"
			"}"
			"QTreeView QHeaderView::section, QTableView QHeaderView::section{"
			"  background-color:qlineargradient(x1:0,y1:1,x2:0,y2:0,stop:0 rgba(25,25,25,127),stop:1 rgba(53,53,53,75));"
			"  border-style:none;"
			"  border-bottom:1px solid palette(dark);"
			"  padding-left:5px;"
			"  padding-right:5px;"
			"}"
			"QTreeView::item:selected:disabled, QTableView::item:selected:disabled{"
			"  background:rgb(80,80,80);"
			"}"
			"QTreeView::branch{"
			"  background-color:palette(base);"
			"}"
			"QTreeView::branch:has-siblings:!adjoins-item{"
			"  border-image:url(:/darkstyle/icon_vline.png) 0;"
			"}"
			"QTreeView::branch:has-siblings:adjoins-item{"
			"  border-image:url(:/darkstyle/icon_branch_more.png) 0;"
			"}"
			"QTreeView::branch:!has-children:!has-siblings:adjoins-item{"
			"  border-image:url(:/darkstyle/icon_branch_end.png) 0;"
			"}"
			"QTreeView::branch:has-children:!has-siblings:closed,"
			"QTreeView::branch:closed:has-children:has-siblings{"
			"  border-image:none;"
			"  image:url(:/darkstyle/icon_branch_closed.png);"
			"}"
			"QTreeView::branch:open:has-children:!has-siblings,"
			"QTreeView::branch:open:has-children:has-siblings{"
			"  border-image:none;"
			"  image:url(:/darkstyle/icon_branch_open.png);"
			"}"
			"QScrollBar:vertical{"
			"  background:palette(base);"
			"  border-top-right-radius:2px;"
			"  border-bottom-right-radius:2px;"
			"  width:16px;"
			"  margin:0px;"
			"}"
			"QScrollBar::handle:vertical{"
			"  background-color:palette(alternate-base);"
			"  border-radius:2px;"
			"  min-height:20px;"
			"  margin:2px 4px 2px 4px;"
			"}"
			"QScrollBar::handle:vertical:hover{"
			"  background-color:palette(highlight);"
			"}"
			"QScrollBar::add-line:vertical{"
			"  background:none;"
			"  height:0px;"
			"  subcontrol-position:right;"
			"  subcontrol-origin:margin;"
			"}"
			"QScrollBar::sub-line:vertical{"
			"  background:none;"
			"  height:0px;"
			"  subcontrol-position:left;"
			"  subcontrol-origin:margin;"
			"}"
			"QScrollBar:horizontal{"
			"  background:palette(base);"
			"  height:16px;"
			"  margin:0px;"
			"}"
			"QScrollBar::handle:horizontal{"
			"  background-color:palette(alternate-base);"
			"  border-radius:2px;"
			"  min-width:20px;"
			"  margin:4px 2px 4px 2px;"
			"}"
			"QScrollBar::handle:horizontal:hover{"
			"  background-color:palette(highlight);"
			"}"
			"QScrollBar::add-line:horizontal{"
			"  background:none;"
			"  width:0px;"
			"  subcontrol-position:bottom;"
			"  subcontrol-origin:margin;"
			"}"
			"QScrollBar::sub-line:horizontal{"
			"  background:none;"
			"  width:0px;"
			"  subcontrol-position:top;"
			"  subcontrol-origin:margin;"
			"}"
			"QSlider::handle:horizontal{"
			"  border-radius:4px;"
			"  border:1px solid rgba(25,25,25,255);"
			"  background-color:palette(alternate-base);"
			"  min-height:20px;"
			"  margin:0 -4px;"
			"}"
			"QSlider::handle:horizontal:hover{"
			"  background:palette(highlight);"
			"}"
			"QSlider::add-page:horizontal{"
			"  background:palette(base);"
			"}"
			"QSlider::sub-page:horizontal{"
			"  background:palette(highlight);"
			"}"
			"QSlider::sub-page:horizontal:disabled{"
			"  background:rgb(80,80,80);"
			"}"

		/*////////////////////////////////////////////////*/
		/*"	* {"
		"		background: #191919;"
		"		color: #DDDDDD;"
		"		border: 1px solid #5A5A5A;"
		"		}"
		""
		"		QWidget::item:selected{"
		"			background: #3D7848;"
		"		}"
		""
		"			QCheckBox, QRadioButton{"
		"				border: none;"
		"		}"
		""
		"			QRadioButton::indicator, QCheckBox::indicator{"
		"				width: 13px;"
		"				height: 13px;"
		"		}"
		""
		"			QRadioButton::indicator::unchecked, QCheckBox::indicator::unchecked{"
		"				border: 1px solid #5A5A5A;"
		"				background: none;"
		"		}"
		""
		"			QRadioButton::indicator:unchecked:hover, QCheckBox::indicator : unchecked : hover{"
		"				border: 1px solid #DDDDDD;"
		"		}"
		""
		"			QRadioButton::indicator::checked, QCheckBox::indicator::checked{"
		"				border: 1px solid #5A5A5A;"
		"				background: #5A5A5A;"
		"		}"
		""
		"			QRadioButton::indicator:checked:hover, QCheckBox::indicator : checked : hover{"
		"				border: 1px solid #DDDDDD;"
		"				background: #DDDDDD;"
		"		}"
		""
		"			QGroupBox{"
		"				margin - top: 6px;"
		"		}"
		""
		"			QGroupBox::title{"
		"				top: -7px;"
		"				left: 7px;"
		"		}"
		""
		"			QScrollBar{"
		"				border: 1px solid #5A5A5A;"
		"				background: #191919;"
		"		}"
		""
		"		QScrollBar:horizontal{"
		"			height: 15px;"
		"			margin: 0px 0px 0px 32px;"
		"		}"
		""
		"		QScrollBar:vertical{"
		"			width: 15px;"
		"			margin: 32px 0px 0px 0px;"
		"		}"
		""
		"			QScrollBar::handle{"
		"				background: #353535;"
		"				border: 1px solid #5A5A5A;"
		"		}"
		""
		"			QScrollBar::handle:horizontal{"
		"				border - width: 0px 1px 0px 1px;"
		"		}"
		""
		"			QScrollBar::handle : vertical{"
		"				border - width: 1px 0px 1px 0px;"
		"		}"
		""
		"			QScrollBar::handle : horizontal{"
		"				min - width: 20px;"
		"		}"
		""
		"			QScrollBar::handle : vertical{"
		"				min - height: 20px;"
		"		}"
		""
		"			QScrollBar::add - line, QScrollBar::sub - line{"
		"				background:#353535;"
		"				border: 1px solid #5A5A5A;"
		"				subcontrol - origin: margin;"
		"		}"
		""
		"			QScrollBar::add - line{"
		"				position: absolute;"
		"		}"
		""
		"			QScrollBar::add - line:horizontal{"
		"				width: 15px;"
		"				subcontrol - position: left;"
		"				left: 15px;"
		"		}"
		""
		"			QScrollBar::add - line:vertical{"
		"				height: 15px;"
		"				subcontrol - position: top;"
		"				top: 15px;"
		"		}"
		""
		"			QScrollBar::sub - line:horizontal{"
		"				width: 15px;"
		"				subcontrol - position: top left;"
		"		}"
		""
		"			QScrollBar::sub - line : vertical{"
		"				height: 15px;"
		"				subcontrol - position: top;"
		"		}"
		""
		"		QScrollBar:left - arrow, QScrollBar::right - arrow, QScrollBar::up - arrow, QScrollBar::down - arrow{"
		"			border: 1px solid #5A5A5A;"
		"			width: 3px;"
		"			height: 3px;"
		"		}"
		""
		"			QScrollBar::add - page, QScrollBar::sub - page{"
		"				background: none;"
		"		}"
		""
		"		QAbstractButton:hover{"
		"			background: #353535;"
		"		}"
		""
		"		QAbstractButton:pressed{"
		"			background: #5A5A5A;"
		"		}"
		""
		"			QAbstractItemView{"
		"				show - decoration - selected: 1;"
		"				selection - background - color: #3D7848;"
		"				selection - color: #DDDDDD;"
		"				alternate - background - color: #353535;"
		"		}"
		""
		"			QHeaderView{"
		"				border: 1px solid #5A5A5A;"
		"		}"
		""
		"			QHeaderView::section{"
		"				background: #191919;"
		"				border: 1px solid #5A5A5A;"
		"				padding: 4px;"
		"		}"
		""
		"			QHeaderView::section:selected, QHeaderView::section::checked{"
		"				background: #353535;"
		"		}"
		""
		"			QTableView{"
		"				gridline - color: #5A5A5A;"
		"		}"
		""
		"			QTabBar{"
		"				margin - left: 2px;"
		"		}"
		""
		"			QTabBar::tab{"
		"				border - radius: 0px;"
		"				padding: 4px;"
		"				margin: 4px;"
		"		}"
		""
		"			QTabBar::tab:selected{"
		"				background: #353535;"
		"		}"
		""
		"			QComboBox::down - arrow{"
		"				border: 1px solid #5A5A5A;"
		"				background: #353535;"
		"		}"
		""
		"			QComboBox::drop - down{"
		"				border: 1px solid #5A5A5A;"
		"				background: #353535;"
		"		}"
		""
		"			QComboBox::down - arrow{"
		"				width: 3px;"
		"				height: 3px;"
		"				border: 1px solid #5A5A5A;"
		"		}"
		""
		"			QAbstractSpinBox{"
		"				padding - right: 15px;"
		"		}"
		""
		"			QAbstractSpinBox::up - button, QAbstractSpinBox::down - button{"
		"				border: 1px solid #5A5A5A;"
		"				background: #353535;"
		"				subcontrol - origin: border;"
		"		}"
		""
		"			QAbstractSpinBox::up - arrow, QAbstractSpinBox::down - arrow{"
		"				width: 3px;"
		"				height: 3px;"
		"				border: 1px solid #5A5A5A;"
		"		}"
		""
		"			QSlider{"
		"				border: none;"
		"		}"
		""
		"			QSlider::groove:horizontal{"
		"				height: 5px;"
		"				margin: 4px 0px 4px 0px;"
		"		}"
		""
		"			QSlider::groove : vertical{"
		"				width: 5px;"
		"				margin: 0px 4px 0px 4px;"
		"		}"
		""
		"			QSlider::handle{"
		"				border: 1px solid #5A5A5A;"
		"				background: #353535;"
		"		}"
		""
		"			QSlider::handle:horizontal{"
		"				width: 15px;"
		"				margin: -4px 0px - 4px 0px;"
		"		}"
		""
		"			QSlider::handle : vertical{"
		"				height: 15px;"
		"				margin: 0px - 4px 0px - 4px;"
		"		}"
		""
		"			QSlider::add - page : vertical, QSlider::sub - page : horizontal{"
		"				background: #3D7848;"
		"		}"
		""
		"			QSlider::sub - page : vertical, QSlider::add - page : horizontal{"
		"				background: #353535;"
		"		}"
		""
		"			QLabel{"
		"				border: none;"
		"		}"
		""
		"			QProgressBar{"
		"				text - align: center;"
		"		}"
		""
		"			QProgressBar::chunk{"
		"				width: 1px;"
		"				background - color: #3D7848;"
		"		}"
		""
		"			QMenu::separator{"
		"				background: #353535;"
		"		}";*/
;
		QString qs = QString::fromStdString(ss);
		this->setStyleSheet(qs);

	}
	else
		this->setStyleSheet("");
}

void Download_and_Clip::typing_clip_name()
{
	std::string s = ui.textedit_outputname->toPlainText().toStdString();
	//std::replace(s.begin(), s.end(), ' ', '_');
	ui.textedit_outputname->setPlainText(s.c_str());
}

//Init
Download_and_Clip::Download_and_Clip(QWidget* parent) :QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.button_downloadytdl, SIGNAL(clicked()), this, SLOT(download_ytdl()));
	connect(ui.button_downloadffmpeg, SIGNAL(clicked()), this, SLOT(download_ffmpeg()));
	connect(ui.button_download, SIGNAL(clicked()), this, SLOT(run_ytdl()));
	connect(ui.button_clip, SIGNAL(clicked()), this, SLOT(run_ffmpeg()));
	connect(ui.button_cleardownload, SIGNAL(clicked()), this, SLOT(clear_download()));

	connect(ui.slider_quality, SIGNAL(valueChanged(int)), ui.spinbox_quality, SLOT(setValue(int)));
	connect(ui.spinbox_quality, SIGNAL(valueChanged(int)), ui.slider_quality, SLOT(setValue(int)));

	connect(ui.checkbox_dark, SIGNAL(clicked(bool)), this, SLOT(darkmode_toggle(bool)));

	connect(ui.textedit_outputname, SIGNAL(textChanged()), this, SLOT(typing_clip_name()));

	check_for_ytdl();

	process_ytdl = new QProcess(this);
	process_ffmpeg = new QProcess(this);

	connect(process_ytdl, SIGNAL(started()), this, SLOT(processStarted_ytdl()));
	connect(process_ytdl, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput_ytdl()));
	connect(process_ytdl, SIGNAL(finished(int)), this, SLOT(downloadFinished_ytdl()));

	connect(process_ffmpeg, SIGNAL(started()), this, SLOT(processStarted_ffmpeg()));
	connect(process_ffmpeg, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput_ffmpeg()));
	connect(process_ffmpeg, SIGNAL(finished(int)), this, SLOT(encodingFinished_ffmpeg()));


	//this->setStyle(new DarkStyle);

	//darkmode(true);

	if (!(fs::exists(working_dir)))
	{
		fs::create_directory(working_dir);
	}

	ui.label_thumb->setText("");



}