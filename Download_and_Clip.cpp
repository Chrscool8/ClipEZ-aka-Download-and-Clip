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

#include <map>
#include <algorithm>
#include <string>

#include "base64.cpp"
#include <nlohmann/json.hpp>

#include <filesystem>
namespace fs = std::filesystem;

std::string status = "";
QString dark_stylesheet;

std::string local_video;
std::string local_thumb;
std::vector<QProcess*> QProcesses;

std::map<std::string, std::string> probe_info;

// Settings //
enum setting
{
	exe_ytdl,
	exe_ffmpeg,
	exe_ffprobe,
	working_directory,
	output_directory,
	last_download_url,
	settings_num
};

std::string settings[settings_num + 1];

std::string Download_and_Clip::get_setting(int setting)
{
	return base64_decode(settings[setting]);
}

void Download_and_Clip::set_setting(int setting, std::string value)
{
	settings[setting] = base64_encode(value);

	file_save_settings();
}

void Download_and_Clip::init_settings()
{
	if (get_setting(working_directory) == "")
	{
		set_setting(working_directory, (QDir::currentPath().toStdString() + "/working_directory/").c_str());
	}
}

void Download_and_Clip::file_load_settings()
{
	QFile inputFile("config.txt");
	if (inputFile.open(QIODevice::ReadOnly))
	{
		QTextStream in(&inputFile);

		int index = 0;
		while (!in.atEnd())
		{
			QString line = in.readLine();
			settings[index] = line.toStdString();
			index += 1;
		}
		inputFile.close();
	}
}

void Download_and_Clip::file_save_settings()
{
	remove("config.txt");
	QFile outputFile("config.txt");
	if (outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream stream(&outputFile);

		int index = 0;

		while (index < settings_num + 1)
		{
			stream << settings[index].c_str() << endl;
			index += 1;
		}
		outputFile.close();
	}
}

//////////////


void Download_and_Clip::load_downloaded_thumbnail()
{
	for (auto& p : fs::directory_iterator(get_setting(working_directory)))
	{
		std::string file = p.path().string();
		if (file.find("downloaded_thumb") != std::string::npos)
		{
			if (!file.empty())
			{
				QPixmap image(file.c_str());
				ui.download_image->setPixmap(image);
				ui.download_check_thumb->setChecked(true);
				ui.download_thumb_gif->clear();

			}
		}
	}
}

void Download_and_Clip::load_local_thumbnail()
{
	local_thumb = "";

	for (auto& p : fs::directory_iterator(get_setting(working_directory)))
	{
		std::string file = p.path().string();
		if (file.find("local_thumb") != std::string::npos)
		{
			if (!file.empty())
			{
				QPixmap image(file.c_str());
				ui.download_image->setPixmap(image);
				local_thumb = file;
			}
		}
	}
}

std::string Download_and_Clip::find_fuzzy(std::string filename)
{
	for (auto& p : fs::directory_iterator(get_setting(working_directory)))
	{
		std::string file = p.path().string();
		if (file.find(filename) != std::string::npos)
		{
			return file;
		}
	}

	return "";
}

std::string just_file_name(std::string filename)
{
	std::size_t found = filename.find_last_of("/\\");
	return filename.substr(found + 1);
}

void Download_and_Clip::check_full_download()
{
	if (ui.download_check_video->isChecked() && ui.download_check_thumb->isChecked() && ui.download_check_description->isChecked() && !ui.download_check_probe->isChecked())
	{
		ui.download_check_probe->setChecked(true);
		ui.download_probe_gif->clear();

		// .\ffprobe.exe downloaded_video.mkv -show_streams -show_format -print_format json -pretty > probe.json.txt
		std::string video_name = just_file_name(find_fuzzy("downloaded_video"));
		QStringList args = { (get_setting(working_directory) + video_name).c_str(), "-show_streams", "-show_format", "-print_format", "json", "-pretty" };
		start_new_process("ffprobe.exe", args, "probe download video", (get_setting(working_directory) + "probe.txt").c_str());
	}
}

void Download_and_Clip::load_video_info()
{
	for (auto& p : fs::directory_iterator(get_setting(working_directory)))
	{
		std::string file = p.path().string();
		if (file.find("downloaded_info") != std::string::npos)
		{
			if (!file.empty())
			{
				ui.download_check_description->setChecked(true);
				ui.download_description_gif->clear();

				/*QFile inFile(file.c_str());
				inFile.open(QIODevice::ReadOnly);
				QByteArray data = inFile.readAll();
				inFile.close();
				QJsonParseError errorPtr;
				QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
				if (doc.isNull())
				{
					update_status("Parse failed", ui.setup_status);
				}
				QJsonObject rootObj = doc.object();
				//ui.label_download_title->setText(rootObj.value("title").toString());
				ui.focus_table->setItem(0, 0, new QTableWidgetItem(rootObj.value("title").toString()));
				//ui.lineedit_videoid->setText(rootObj.value("webpage_url").toString());
				//downloaded_info = file;
				//check_for_ffmpeg();
				*/
			}
		}
	}
}

void Download_and_Clip::load_downloaded_video()
{
	//downloaded_video = "";

	/*for (auto& p : fs::directory_iterator(get_setting(working_directory)))
	{
		std::string file = p.path().string();

		if (file.find("downloaded_video") != std::string::npos)
		{
			downloaded_video = file;
		}
	}*/
	//ui.button_download->setEnabled(true);
	//check_for_ffmpeg();
	//ui.progressBar->setValue(100);

	ui.download_check_video->setChecked(true);
	ui.download_video_gif->clear();

}

void Download_and_Clip::encode_done()
{
	std::string s = ui.encode_lineedit_filename->text().toStdString() + get_ext();

	if (fs::exists(ui.encode_lineedit_directory->text().toStdString() + s))
	{
		std::string full = working_directory + s.c_str();

		update_status("Your clip was saved to: ", ui.setup_status);
		update_status(full, ui.setup_status);

		QString valueText = this->locale().formattedDataSize(fs::file_size(full));
		update_status(valueText.toStdString(), ui.encode_status);
	}
	else
	{
		update_status("Uh oh!!! Your clip might not have worked??", ui.encode_status);
	}
}

void Download_and_Clip::processStateChange(std::string program, QProcess::ProcessState newState, std::string tag)
{
	switch (newState)
	{
	case QProcess::Starting:
	{
		update_status(tag + " Starting", ui.setup_status);
	}
	break;
	case QProcess::Running:
	{
		update_status(tag + " Running", ui.setup_status);
	}
	break;
	case QProcess::NotRunning:
	{
		update_status(tag + " Done", ui.setup_status);

		if (tag == "download video thumbnail")
		{
			load_downloaded_thumbnail();
			check_full_download();
		}
		else if (tag == "download video")
		{
			load_downloaded_video();
			check_full_download();
		}
		else if (tag == "download video info")
		{
			load_video_info();
			check_full_download();
		}
		else if (tag == "encode")
		{
			encode_done();
		}
		else if (tag == "local thumb")
		{
			load_local_thumbnail();
		}
		else if (tag == "probe download video")
		{
			std::string file = get_setting(working_directory) + "probe.txt";
			std::ifstream i(file);
			nlohmann::json ffprobe;
			i >> ffprobe;

			std::string duration = ffprobe["format"]["duration"];
			QString _duration = duration.c_str();
			ui.download_table->setItem(0, 2, new QTableWidgetItem(_duration));


			std::string file2 = get_setting(working_directory) + "downloaded_info.info.json";
			std::ifstream i2(file2);
			nlohmann::json ytdesc;
			i2 >> ytdesc;


			ui.download_table->setItem(0, 0, new QTableWidgetItem(ytdesc["title"].get<std::string>().c_str()));

			QString valueText = this->locale().formattedDataSize(fs::file_size(find_fuzzy("downloaded_video")));
			ui.download_table->setItem(0, 1, new QTableWidgetItem(valueText));

			//std::string size = ytdesc["size"];
			//QString valueText = this->locale().formattedDataSize(fs::file_size(size));
			//ui.download_table->setItem(0, 1, new QTableWidgetItem(valueText));

			std::cout << endl;

			//ui.focus_table->setItem(0, 0, new QTableWidgetItem(rootObj.value("title").toString()));
		}
	}
	break;
	};
}

void Download_and_Clip::start_new_process(std::string program, QStringList args, std::string tag, QString out)
{
	QProcess* info = new QProcess(this);
	QProcesses.push_back(info);
	info->setProgram(program.c_str());
	info->setStandardErrorFile("stderr.txt");
	info->setStandardOutputFile(out);
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
	load_downloaded_video();
}

void Download_and_Clip::update_status(std::string str, QTextEdit* box)
{
	box->append(str.c_str());
	QTextCursor c = box->textCursor();
	c.movePosition(QTextCursor::End);
	box->setTextCursor(c);
}

static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
	return written;
}

int Download_and_Clip::download_file(std::string _url, std::string _file)
{
	/*CURL* curl;
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
	}*/
	return 0;
}

void Download_and_Clip::check_for_ytdl()
{
	/*if (fs::exists(fs::path("youtube-dl.exe")))
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
	}*/
}

void Download_and_Clip::check_for_ffmpeg()
{
	/*if (fs::exists(fs::path("ffmpeg.exe")))
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
	}*/
}

void Download_and_Clip::download_exe_ytdl()
{
	//ui.button_downloadytdl->setEnabled(false);
	download_file("https://yt-dl.org/latest/youtube-dl.exe", "youtube-dl.exe");
	check_for_ytdl();
}

void Download_and_Clip::download_exe_ffmpeg()
{
	//ui.button_downloadytdl->setEnabled(false);
	download_file("https://ffmpeg.zeranoe.com/builds/win64/static/ffmpeg-20200403-52523b6-win64-static.zip", "ffmpeg.zip");
	check_for_ffmpeg();
}

void Download_and_Clip::remove_fuzzy(std::string filename)
{
	for (auto& p : fs::directory_iterator(get_setting(working_directory)))
	{
		std::string file = p.path().string();
		if (file.find(filename) != std::string::npos)
		{
			remove(file.c_str());
		}
	}
}

void Download_and_Clip::execute_ytdl_download()
{
	update_status("Run YT-DL", ui.download_status);
	remove_fuzzy("downloaded_info");
	remove_fuzzy("downloaded_video");
	remove_fuzzy("downloaded_thumb");
	remove_fuzzy("downloaded_probe");

	ui.download_check_video->setChecked(false);
	ui.download_check_thumb->setChecked(false);
	ui.download_check_description->setChecked(false);
	ui.download_check_probe->setChecked(false);

	ui.download_video_gif->setMovie(gif_loading);
	ui.download_description_gif->setMovie(gif_loading);
	ui.download_probe_gif->setMovie(gif_loading);
	ui.download_thumb_gif->setMovie(gif_loading);


	QString video_id = ui.download_linedit->text();

	set_setting(last_download_url, video_id.toStdString());

	QStringList args = { video_id, "-o", (get_setting(working_directory) + "downloaded_info").c_str(), "--skip-download", "--no-playlist", "--write-info-json" };
	start_new_process("youtube-dl.exe", args, "download video info", "stdout.txt");

	QStringList args2 = { video_id, "-o", (get_setting(working_directory) + "downloaded_thumb").c_str(), "--write-thumbnail", "--skip-download", "--no-playlist" };
	start_new_process("youtube-dl.exe", args2, "download video thumbnail", "stdout.txt");

	QStringList args3 = { video_id, "-o", (get_setting(working_directory) + "downloaded_video").c_str(), "-f", "bestvideo+bestaudio/best", "--no-playlist" };
	start_new_process("youtube-dl.exe", args3, "download video", "stdout.txt");
}

std::string Download_and_Clip::get_ext()
{
	std::string type = ui.encode_combo->currentText().toStdString();
	std::string extension = "";
	if (type.compare("x264") == 0 || type.compare("x265") == 0)
		extension = ".mp4";
	else if (type.compare("gif") == 0)
		extension = ".gif";
	else
	{
		extension = ".error";
		update_status("Unknown format??", ui.encode_status);
	}
	return extension;
}

void Download_and_Clip::execute_ffmpeg_encode()
{
	QString directory_name = ui.encode_lineedit_directory->text();
	QString output_name = ui.encode_lineedit_filename->text();

	if (output_name.length() > 0)
	{
		std::string outfile = (directory_name + output_name).toStdString();
		outfile += get_ext();

		update_status(outfile, ui.encode_status);

		bool ripcord = false;

		if (fs::exists(outfile))
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, "File Exists!", (outfile + "\nWant to overwrite?").c_str(), QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes)
			{

			}
			else
			{
				ripcord = true;
			}
		}

		if (!ripcord)
		{
			/*remove(outfile.c_str());

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

			//ui.button_download->setEnabled(false);
			//ui.button_clip->setEnabled(false);
			//ui.progressBar->setValue(0);
			*/
		}
	}
	else
		update_status("Clip Name Too Short", ui.encode_status);

}

void Download_and_Clip::darkmode_toggle(bool state)
{
	darkmode(state);
}

void Download_and_Clip::clear_download()
{
	/*update_status("Clear");
	remove(downloaded_thumb.c_str());
	remove(downloaded_video.c_str());
	remove(downloaded_info.c_str());

	ui.button_downloadffmpeg->setEnabled(false);
	ui.button_downloadffmpeg->setText("Download ffmpeg");
	ui.slider_quality->setEnabled(false);
	ui.spinbox_quality->setEnabled(false);
	ui.lineedit_outputname->setEnabled(false);
	ui.button_clip->setEnabled(false);*/
}

void Download_and_Clip::darkmode(bool on)
{
	if (on)
		this->setStyleSheet(dark_stylesheet);
	else
		this->setStyleSheet("");
}

void Download_and_Clip::set_theme_dark()
{
	darkmode(true);
}

void Download_and_Clip::set_theme_light()
{
	darkmode(false);
}

static char ClearForbidden(char toCheck)
{
	const std::string forbiddenChars = "\\/:?\"<>|,.!*";

	if (forbiddenChars.find(toCheck) != std::string::npos)
	{
		return '_';
	}

	return toCheck;
}

void Download_and_Clip::typing_clip_name()
{
	QString qstr = ui.encode_lineedit_filename->text();

	std::string str = qstr.toStdString();
	std::transform(str.begin(), str.end(), str.begin(), ClearForbidden);
	qstr = str.c_str();
	ui.encode_lineedit_filename->setText(qstr);
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
	std::string str = get_setting(working_directory);
	std::transform(str.begin(), str.end(), str.begin(), fix_slashes);
	system(("explorer \"" + str + "\"").c_str());
}

void Download_and_Clip::show_folder_output()
{
	/*std::string str = ui.lineedit_directory->text().toStdString();
	std::transform(str.begin(), str.end(), str.begin(), fix_slashes);
	system(("explorer \"" + str + "\"").c_str());*/
}

QString Download_and_Clip::choose_directory(std::string hint, QString starting_dir)
{
	return QFileDialog::getExistingDirectory(this, tr(hint.c_str()), starting_dir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}

void Download_and_Clip::choose_output_directory()
{
	QString dir = choose_directory("Open Directory", ui.encode_lineedit_directory->text());

	std::string str;

	if (dir.isEmpty())
		str = get_setting(working_directory);
	else
		str = dir.toStdString() + "/";

	while (str.find("//") != std::string::npos)
	{
		str.replace(str.begin(), str.end(), "//", "/");
	}

	ui.encode_lineedit_directory->setText(str.c_str());

	/*remove("config.txt");
	std::ofstream out;
	out.open("config.txt");
	out << str;
	out.close();*/
}

QString Download_and_Clip::choose_file(std::string hint, QString starting_dir, std::string exts)
{
	return QFileDialog::getOpenFileName(this, tr(hint.c_str()), starting_dir, exts.c_str());
}

void Download_and_Clip::choose_local_video()
{
	QString dir = choose_file("Open Video", ui.local_lineedit->text(), "Video File (*.*)");

	if (!dir.isEmpty())
	{
		std::string str = dir.toStdString();

		local_video = str;
		ui.local_lineedit->setText(str.c_str());

		QStringList args = { "-i", str.c_str(), "-ss", "00:00:05.01", "-frames:v", "1", (get_setting(working_directory) + "local_thumb.png").c_str() };
		start_new_process("ffmpeg.exe", args, "local thumb", "stdout.txt");
	}
}

void Download_and_Clip::browse_for_ytdl()
{
	QString dir = choose_file("Find YouTube-DL", ui.setup_ytdl_lineedit->text(), "YT-DL (youtube-dl.exe)");

	if (!dir.isEmpty())
	{
		ui.setup_ytdl_lineedit->setText(dir);
		set_setting(exe_ytdl, dir.toStdString());
	}
}

void Download_and_Clip::browse_for_ffmpeg()
{
	QString dir = choose_file("Find FFmpeg", ui.setup_ffmpeg_lineedit->text(), "FFmpeg (ffmpeg.exe)");

	if (!dir.isEmpty())
	{
		ui.setup_ffmpeg_lineedit->setText(dir);
		set_setting(exe_ffmpeg, dir.toStdString());
	}
}

void Download_and_Clip::browse_for_ffprobe()
{
	QString dir = choose_file("Find ffprobe", ui.setup_ffprobe_lineedit->text(), "ffprobe (ffprobe.exe)");

	if (!dir.isEmpty())
	{
		ui.setup_ffprobe_lineedit->setText(dir);
		set_setting(exe_ffprobe, dir.toStdString());
	}
}

const int animation_time = 300;
void Download_and_Clip::collapse_panel(QToolBox* toolbox)
{
	animation = new QPropertyAnimation(toolbox, "maximumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(0, toolbox->size().height()));
	animation->start();

	animation = new QPropertyAnimation(toolbox, "minimumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(0, toolbox->size().height()));
	animation->start();
}

void Download_and_Clip::expand_panel(QToolBox* toolbox)
{
	animation = new QPropertyAnimation(toolbox, "maximumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(16777215, toolbox->size().height()));
	animation->start();

	animation = new QPropertyAnimation(toolbox, "minimumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(450, toolbox->size().height()));
	animation->start();
}

void Download_and_Clip::expand_left()
{
	collapse_panel(ui.export_toolbox);
	expand_panel(ui.import_toolbox);
}

void Download_and_Clip::expand_right()
{
	collapse_panel(ui.import_toolbox);
	expand_panel(ui.export_toolbox);
}

void Download_and_Clip::update_ui_from_settings()
{
	auto option = get_setting(exe_ytdl);
	if (option != "")
		ui.setup_ytdl_lineedit->setText(option.c_str());

	option = get_setting(exe_ffmpeg);
	if (option != "")
		ui.setup_ffmpeg_lineedit->setText(option.c_str());

	option = get_setting(exe_ffprobe);
	if (option != "")
		ui.setup_ffprobe_lineedit->setText(option.c_str());

	option = get_setting(last_download_url);
	if (option != "")
		ui.download_linedit->setText(option.c_str());
}

//////
void Download_and_Clip::dragEnterEvent(QDragEnterEvent* event)
{
	// if some actions should not be usable, like move, this code must be adopted
	event->acceptProposedAction();
}

void Download_and_Clip::dragMoveEvent(QDragMoveEvent* event)
{
	// if some actions should not be usable, like move, this code must be adopted
	event->acceptProposedAction();
}

void Download_and_Clip::dragLeaveEvent(QDragLeaveEvent* event)
{
	event->accept();
}

void Download_and_Clip::dropEvent(QDropEvent* event)
{
	const QMimeData* mimeData = event->mimeData();

	if (mimeData->hasUrls())
	{
		QStringList pathList;
		QList<QUrl> urlList = mimeData->urls();

		for (int i = 0; i < urlList.size() && i < 32; ++i)
		{
			pathList.append(urlList.at(i).toLocalFile());
		}

		ui.local_lineedit->setText(urlList.at(0).toLocalFile());


		std::cout << endl;

		//if (openFiles(pathList))
		//	event->acceptProposedAction();
	}
}

//Init
Download_and_Clip::Download_and_Clip(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setAcceptDrops(true);

	dark_stylesheet = this->styleSheet();

	gif_loading = new QMovie();
	gif_loading->setCacheMode(QMovie::CacheAll);
	gif_loading->setFileName("Spin-1s-200px.gif");
	gif_loading->start();

	// Shrink
	this->setMaximumSize(QSize(0, 0));
	this->setMaximumSize(QSize(16777215, 16777215));

	//connect(ui.button_downloadytdl, SIGNAL(clicked()), this, SLOT(download_exe_ytdl()));
	//connect(ui.button_downloadffmpeg, SIGNAL(clicked()), this, SLOT(download_exe_ffmpeg()));

	connect(ui.download_button, SIGNAL(clicked()), this, SLOT(execute_ytdl_download()));
	connect(ui.download_linedit, SIGNAL(returnPressed()), this, SLOT(execute_ytdl_download()));

	connect(ui.encode_button, SIGNAL(clicked()), this, SLOT(execute_ffmpeg_encode()));
	connect(ui.encode_lineedit_filename, SIGNAL(returnPressed()), this, SLOT(execute_ffmpeg_encode()));

	connect(ui.expand_left, SIGNAL(clicked()), this, SLOT(expand_left()));
	connect(ui.expand_right, SIGNAL(clicked()), this, SLOT(expand_right()));

	//connect(ui.button_cleardownload, SIGNAL(clicked()), this, SLOT(clear_download()));
	connect(ui.setup_show_working_dir, SIGNAL(clicked()), this, SLOT(show_folder_working()));
	connect(ui.setup_show_output_dir, SIGNAL(clicked()), this, SLOT(show_folder_output()));

	//connect(ui.button_choose_directory, SIGNAL(clicked()), this, SLOT(choose_output_directory()));
	connect(ui.local_button, SIGNAL(clicked()), this, SLOT(choose_local_video()));

	connect(ui.setup_ytdl_button, SIGNAL(clicked()), this, SLOT(browse_for_ytdl()));
	connect(ui.setup_ffmpeg_button, SIGNAL(clicked()), this, SLOT(browse_for_ffmpeg()));
	connect(ui.setup_ffprobe_button, SIGNAL(clicked()), this, SLOT(browse_for_ffprobe()));

	connect(ui.encode_slider, SIGNAL(valueChanged(int)), ui.encode_spinbox, SLOT(setValue(int)));
	connect(ui.encode_spinbox, SIGNAL(valueChanged(int)), ui.encode_slider, SLOT(setValue(int)));

	connect(ui.menu_actionLight, SIGNAL(triggered()), this, SLOT(set_theme_light()));
	connect(ui.menu_actionDark, SIGNAL(triggered()), this, SLOT(set_theme_dark()));

	//connect(ui.menu_actionExit, SIGNAL(triggered()), this, SLOT());

	//QCoreApplication::quit();



	//connect(ui.checkbox_dark, SIGNAL(clicked(bool)), this, SLOT(darkmode_toggle(bool)));

	//connect(ui.lineedit_outputname, SIGNAL(textChanged(QString)), this, SLOT(typing_clip_name()));

	//ui.lineedit_directory->setText(working_directory.c_str());

	//load_settings("config.json");

	file_load_settings();
	init_settings();

	update_ui_from_settings();

	{
		QPixmap image("16x9.png");
		ui.focus_image->setPixmap(image);
		ui.focus_image->setScaledContents(true);

		ui.download_image->setPixmap(image);
		ui.download_image->setScaledContents(true);
	}

	/*if (fs::exists("config.txt"))
	{
		std::ifstream infile("config.txt");
		std::string dir;
		std::getline(infile, dir);
		update_status(dir, ui.setup_status);
		//ui.lineedit_directory->setText(dir.c_str());
		infile.close();
		ui.lineedit_directory->setText(dir.c_str());
	}*/

	//remove((working_directory + "local_thumb.png").c_str());

	//check_for_ytdl();

	std::string dir = get_setting(working_directory);
	if (!(fs::exists(dir)))
	{
		fs::create_directory(dir);
	}

	ui.export_toolbox->setMinimumWidth(0);
	ui.export_toolbox->setMaximumWidth(0);

	//collapse_panel(ui.export_toolbox, false);

	/*ui.label_thumb_download->setText("");
	ui.label_thumb_local->setText("");
	ui.label_download_title->setText("");*/

	//check_for_downloaded_files();

	ui.download_table->resizeRowsToContents();
	ui.focus_table->resizeRowsToContents();

	ui.import_toolbox->setCurrentIndex(0);
	ui.export_toolbox->setCurrentIndex(0);

}