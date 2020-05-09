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

#include <algorithm>
#include <string>

#include <filesystem>  
namespace fs = std::filesystem;

std::string status = "";
QString dark_stylesheet;

std::string downloaded_video;
std::string downloaded_thumb;
std::string downloaded_info;

std::string local_video;
std::string local_thumb;

std::string working_directory = (QDir::currentPath().toStdString() + "/working_directory/");

std::vector<QProcess*> QProcesses;

void Download_and_Clip::load_downloaded_thumbnail()
{
	downloaded_thumb = "";

	for (auto& p : fs::directory_iterator(working_directory))
	{
		std::string file = p.path().string();
		if (file.find("downloaded_thumb") != std::string::npos)
		{
			if (!file.empty())
			{
				QPixmap image(file.c_str());
				ui.label_thumb_download->setPixmap(image);
				downloaded_thumb = file;
			}
		}
	}
}


void Download_and_Clip::load_local_thumbnail()
{
	local_thumb = "";

	for (auto& p : fs::directory_iterator(working_directory))
	{
		std::string file = p.path().string();
		if (file.find("local_thumb") != std::string::npos)
		{
			if (!file.empty())
			{
				QPixmap image(file.c_str());
				ui.label_thumb_local->setPixmap(image);
				local_thumb = file;
			}
		}
	}
}

void Download_and_Clip::load_video_info()
{
	downloaded_info = "";

	for (auto& p : fs::directory_iterator(working_directory))
	{
		std::string file = p.path().string();
		if (file.find("downloaded_info") != std::string::npos)
		{
			if (!file.empty())
			{
				QFile inFile(file.c_str());
				inFile.open(QIODevice::ReadOnly);
				QByteArray data = inFile.readAll();
				inFile.close();
				QJsonParseError errorPtr;
				QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
				if (doc.isNull()) {
					update_status("Parse failed");
				}
				QJsonObject rootObj = doc.object();
				ui.label_download_title->setText(rootObj.value("title").toString());
				ui.lineedit_videoid->setText(rootObj.value("webpage_url").toString());
				downloaded_info = file;
				check_for_ffmpeg();
			}
		}
	}
}

void Download_and_Clip::load_video()
{
	downloaded_video = "";

	for (auto& p : fs::directory_iterator(working_directory))
	{
		std::string file = p.path().string();

		if (file.find("downloaded_video") != std::string::npos)
		{
			downloaded_video = file;
		}
	}
	ui.button_download->setEnabled(true);
	check_for_ffmpeg();
	ui.progressBar->setValue(100);
}

void Download_and_Clip::processStateChange(std::string program, QProcess::ProcessState newState, std::string tag)
{
	switch (newState)
	{
	case QProcess::Starting:
	{
		update_status(tag + " Starting");
	}
	break;
	case QProcess::Running:
	{
		update_status(tag + " Running");
	}
	break;
	case QProcess::NotRunning:
	{
		update_status(tag + " Done");

		if (tag == "download video thumbnail")
		{
			load_downloaded_thumbnail();
		}
		else if (tag == "download video")
		{
			load_video();
		}
		else if (tag == "encode")
		{
			ui.button_download->setEnabled(true);
			ui.button_clip->setEnabled(true);

			std::string s = ui.lineedit_outputname->text().toStdString() + get_ext();

			ui.progressBar->setValue(100);

			if (fs::exists(ui.lineedit_directory->text().toStdString() + s))
			{
				update_status("Your clip was saved to: ");
				update_status(working_directory + s);

				QLocale locale = this->locale();
				QString valueText = locale.formattedDataSize(fs::file_size((ui.lineedit_directory->text().toStdString() + s).c_str()));
				update_status(valueText.toStdString());

				ui.table_clipinfo->setItem(0, 0, new QTableWidgetItem(s.c_str()));
				ui.table_clipinfo->setItem(0, 1, new QTableWidgetItem(valueText));
			}
			else
			{
				update_status("Uh oh!!! Your clip might not have worked??");
			}
		}
		else if (tag == "download video info")
		{
			load_video_info();
		}
		else if (tag == "local thumb")
		{
			load_local_thumbnail();
		}
	}
	break;
	};
}

void Download_and_Clip::start_new_process(std::string program, QStringList args, std::string tag)
{
	QProcess* info = new QProcess(this);
	QProcesses.push_back(info);
	info->setProgram(program.c_str());
	info->setStandardErrorFile("stderr.txt");
	info->setStandardOutputFile("stdout.txt");
	info->setArguments(args);

	connect(info, &QProcess::stateChanged, [=](QProcess::ProcessState newState)
	{
		processStateChange(program, newState, tag);
	});

	info->start();
}

void Download_and_Clip::check_for_downloaded_files()
{
	load_downloaded_thumbnail();
	load_video_info();
	load_video();
}

void Download_and_Clip::update_status(std::string str)
{
	ui.textedit_status_box->append(str.c_str());
	QTextCursor c = ui.textedit_status_box->textCursor();
	c.movePosition(QTextCursor::End);
	ui.textedit_status_box->setTextCursor(c);
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
		ui.lineedit_videoid->setEnabled(true);
		ui.button_download->setEnabled(true);
		//ui.button_downloadytdl->setEnabled(true);
		ui.button_downloadytdl->setText("Update Youtube-DL");
	}
	else
	{
		update_status("youtube-dl.exe not found.");
		ui.lineedit_videoid->setEnabled(false);
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
		ui.lineedit_starttime->setEnabled(true);
		ui.lineedit_endtime->setEnabled(true);
		ui.slider_quality->setEnabled(true);
		ui.spinbox_quality->setEnabled(true);
		ui.lineedit_outputname->setEnabled(true);
		ui.button_clip->setEnabled(true);
	}
	else
	{
		update_status("ffmpeg.exe not found.");
		ui.button_downloadffmpeg->setEnabled(false);
		ui.button_downloadffmpeg->setText("Download ffmpeg");
		ui.slider_quality->setEnabled(false);
		ui.spinbox_quality->setEnabled(false);
		ui.lineedit_outputname->setEnabled(false);
		ui.button_clip->setEnabled(false);
	}
}

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
	remove(downloaded_info.c_str());
	remove(downloaded_video.c_str());
	remove(downloaded_thumb.c_str());

	QStringList args = { ui.lineedit_videoid->text(), "-o", (working_directory + "downloaded_info").c_str(), "--skip-download", "--no-playlist", "--write-info-json" };
	start_new_process("youtube-dl.exe", args, "download video info");

	QStringList args2 = { ui.lineedit_videoid->text(), "-o", (working_directory + "downloaded_thumb").c_str(), "--write-thumbnail", "--skip-download", "--no-playlist" };
	start_new_process("youtube-dl.exe", args2, "download video thumbnail");

	QStringList args3 = { ui.lineedit_videoid->text(), "-o", (working_directory + "downloaded_video").c_str(), "-f", "bestvideo+bestaudio/best", "--no-playlist" };
	start_new_process("youtube-dl.exe", args3, "download video");

	ui.button_download->setEnabled(false);
	ui.progressBar->setValue(0);
}

std::string Download_and_Clip::get_ext()
{
	std::string type = ui.combo_encoder->currentText().toStdString();
	std::string extension = "";
	if (type.compare("x264") == 0 || type.compare("x265") == 0)
		extension = ".mp4";
	else if (type.compare("gif") == 0)
		extension = ".gif";
	else
	{
		extension = ".error";
		update_status("Unknown format??");
	}
	return extension;
}

void Download_and_Clip::run_ffmpeg()
{
	if (ui.lineedit_outputname->text().length() > 0)
	{
		std::string outfile = (ui.lineedit_directory->text() + ui.lineedit_outputname->text()).toStdString();
		outfile += get_ext();

		update_status(outfile);

		bool ripcord = false;

		if (fs::exists(outfile))
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, "File Exists!", (outfile + "\nWant to overwrite?").c_str(), QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes) {

			}
			else {
				ripcord = true;
			}
		}

		if (!ripcord)
		{
			remove(outfile.c_str());

			std::string source_video;
			if (ui.tabs_source->currentIndex() == 0)
				source_video = downloaded_video;
			else
				source_video = local_video;

			std::string type = ui.combo_encoder->currentText().toStdString();

			if (type.compare("x264") == 0 || type.compare("x265") == 0)
			{
				QStringList args = { "-i", source_video.c_str(), "-c:v", ("lib" + ui.combo_encoder->currentText().toStdString()).c_str(), "-crf", std::to_string(ui.slider_quality->value()).c_str(), "-preset", "ultrafast", "-c:a", "aac", "-strict", "experimental",
					"-b:a", "192k", "-ss", ui.lineedit_starttime->text(), "-to", ui.lineedit_endtime->text(), "-ac", "2", outfile.c_str() };
				start_new_process("ffmpeg.exe", args, "encode");
			}
			else if (type.compare("gif") == 0)
			{
				QStringList args = { "-i", source_video.c_str(), "-crf", std::to_string(ui.slider_quality->value()).c_str(), "-preset", "ultrafast", "-c:a", "aac", "-strict", "experimental",
					"-b:a", "192k", "-ss", ui.lineedit_starttime->text(), "-to", ui.lineedit_endtime->text(), "-ac", "2", (outfile).c_str() };
				start_new_process("ffmpeg.exe", args, "encode");
			}
			else
				update_status("Unknown type???");

			ui.button_download->setEnabled(false);
			ui.button_clip->setEnabled(false);
			ui.progressBar->setValue(0);
		}
	}
	else
		update_status("Clip Name Too Short");
}

void Download_and_Clip::darkmode_toggle(bool state)
{
	darkmode(state);
}

void Download_and_Clip::clear_download()
{
	update_status("Clear");
	remove(downloaded_thumb.c_str());
	remove(downloaded_video.c_str());
	remove(downloaded_info.c_str());

	ui.button_downloadffmpeg->setEnabled(false);
	ui.button_downloadffmpeg->setText("Download ffmpeg");
	ui.slider_quality->setEnabled(false);
	ui.spinbox_quality->setEnabled(false);
	ui.lineedit_outputname->setEnabled(false);
	ui.button_clip->setEnabled(false);
}

void Download_and_Clip::darkmode(bool on)
{
	if (on)
		this->setStyleSheet(dark_stylesheet);
	else
		this->setStyleSheet("");
}

const std::string forbiddenChars = "\\/:?\"<>|,.!*";
static char ClearForbidden(char toCheck)
{
	if (forbiddenChars.find(toCheck) != std::string::npos)
	{
		return '_';
	}

	return toCheck;
}

void Download_and_Clip::typing_clip_name()
{
	QString qstr = ui.lineedit_outputname->text();

	std::string str = qstr.toStdString();
	std::transform(str.begin(), str.end(), str.begin(), ClearForbidden);
	qstr = str.c_str();
	ui.lineedit_outputname->setText(qstr);
}

static char fix_slashes(char toCheck)
{
	const std::string forbiddenChars = "/";
	if (forbiddenChars.find(toCheck) != std::string::npos)
	{
		return '\\';
	}

	return toCheck;
}

void Download_and_Clip::show_folder_working()
{
	std::string str = working_directory;
	std::transform(str.begin(), str.end(), str.begin(), fix_slashes);
	system(("explorer \"" + str + "\"").c_str());
}

void Download_and_Clip::show_folder_output()
{
	std::string str = ui.lineedit_directory->text().toStdString();
	std::transform(str.begin(), str.end(), str.begin(), fix_slashes);
	system(("explorer \"" + str + "\"").c_str());
}

void Download_and_Clip::choose_output_directory()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), ui.lineedit_directory->text(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	std::string str;

	if (dir.isEmpty())
		str = working_directory;
	else
		str = dir.toStdString() + "/";



	while (str.find("//") != std::string::npos)
	{
		str.replace(str.begin(), str.end(), "//", "/");
	}

	ui.lineedit_directory->setText(str.c_str());

	remove("config.txt");
	std::ofstream out;
	out.open("config.txt");
	out << str;
	out.close();
}

void Download_and_Clip::choose_local_video()
{
	std::string s = ("Video File (*.*)");
	QString ex = s.c_str();
	QString dir = QFileDialog::getOpenFileName(this, tr("Open File"), ui.lineedit_directory->text(), ex);

	std::string str;

	if (!dir.isEmpty())
	{
		str = dir.toStdString();
		//ui.lineedit_directory->setText(str.c_str());

		local_video = str;
		ui.label_local_name->setText(str.c_str());

		QStringList args = { "-i", str.c_str(), "-ss", "00:00:05.01", "-frames:v", "1", (working_directory + "local_thumb.png").c_str() };
		start_new_process("ffmpeg.exe", args, "local thumb");
	}
}


//Init
Download_and_Clip::Download_and_Clip(QWidget* parent) :QMainWindow(parent)
{
	setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

	ui.setupUi(this);

	dark_stylesheet = this->styleSheet();

	connect(ui.button_downloadytdl, SIGNAL(clicked()), this, SLOT(download_ytdl()));
	connect(ui.button_downloadffmpeg, SIGNAL(clicked()), this, SLOT(download_ffmpeg()));
	connect(ui.button_download, SIGNAL(clicked()), this, SLOT(run_ytdl()));
	connect(ui.button_clip, SIGNAL(clicked()), this, SLOT(run_ffmpeg()));
	connect(ui.lineedit_outputname, SIGNAL(returnPressed()), this, SLOT(run_ffmpeg()));

	connect(ui.lineedit_videoid, SIGNAL(returnPressed()), this, SLOT(run_ytdl()));

	connect(ui.button_cleardownload, SIGNAL(clicked()), this, SLOT(clear_download()));
	connect(ui.button_showworking, SIGNAL(clicked()), this, SLOT(show_folder_working()));
	connect(ui.button_showoutput, SIGNAL(clicked()), this, SLOT(show_folder_output()));
	connect(ui.button_choose_directory, SIGNAL(clicked()), this, SLOT(choose_output_directory()));
	connect(ui.button_choose_local, SIGNAL(clicked()), this, SLOT(choose_local_video()));

	connect(ui.slider_quality, SIGNAL(valueChanged(int)), ui.spinbox_quality, SLOT(setValue(int)));
	connect(ui.spinbox_quality, SIGNAL(valueChanged(int)), ui.slider_quality, SLOT(setValue(int)));

	connect(ui.checkbox_dark, SIGNAL(clicked(bool)), this, SLOT(darkmode_toggle(bool)));

	connect(ui.lineedit_outputname, SIGNAL(textChanged(QString)), this, SLOT(typing_clip_name()));

	ui.lineedit_directory->setText(working_directory.c_str());

	if (fs::exists("config.txt"))
	{
		std::ifstream infile("config.txt");
		std::string dir;
		std::getline(infile, dir);
		update_status(dir);
		ui.lineedit_directory->setText(dir.c_str());
		infile.close();
		ui.lineedit_directory->setText(dir.c_str());
	}

	remove((working_directory + "local_thumb.png").c_str());

	check_for_ytdl();

	if (!(fs::exists(working_directory)))
	{
		fs::create_directory(working_directory);
	}

	ui.label_thumb_download->setText("");
	ui.label_thumb_local->setText("");
	ui.label_download_title->setText("");

	check_for_downloaded_files();

	ui.table_clipinfo->resizeRowsToContents();

}