#include "Download_and_Clip.h"
#include "qwidget.h"
#include <fstream>

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

QString dark_stylesheet;

std::vector<QProcess*> QProcesses;

enum focus_type
{
	enum_focus_none,
	enum_focus_downloaded,
	enum_focus_local
};

int focus = enum_focus_none;

// Settings //
enum setting
{
	setting_exe_ytdl,
	setting_exe_ffmpeg,
	setting_exe_ffprobe,
	setting_working_directory,
	setting_output_directory,
	setting_last_download_url,
	setting_last_local_url,
	setting_focus_scroll,
	setting_theme,
	setting_expand_by_default,
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
	if (get_setting(setting_working_directory) == "")
	{
		set_setting(setting_working_directory, (QDir::currentPath().toStdString() + "/working_directory/").c_str());
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
	for (auto& p : fs::directory_iterator(get_setting(setting_working_directory)))
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
	ui.local_check_thumb->setChecked(true);
	std::string file = find_fuzzy(get_setting(setting_working_directory), "local_thumb");
	QPixmap image(file.c_str());
	ui.local_image->setPixmap(image);
}

std::string Download_and_Clip::find_fuzzy(std::string path, std::string filename)
{
	for (auto& p : fs::directory_iterator(path))
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

		std::string video_name = just_file_name(find_fuzzy(get_setting(setting_working_directory), "downloaded_video"));
		QStringList args = { (get_setting(setting_working_directory) + video_name).c_str(), "-show_streams", "-show_format", "-print_format", "json", "-pretty" };
		start_new_process(get_setting(setting_exe_ffprobe), args, "probe download video", ui.download_status, (get_setting(setting_working_directory) + "probe.txt").c_str(), true);
	}
}

void Download_and_Clip::load_video_info()
{
	for (auto& p : fs::directory_iterator(get_setting(setting_working_directory)))
	{
		std::string file = p.path().string();
		if (file.find("downloaded_info") != std::string::npos)
		{
			if (!file.empty())
			{
				ui.download_check_description->setChecked(true);
				ui.download_description_gif->clear();
			}
		}
	}
}

void Download_and_Clip::load_downloaded_video()
{
	ui.download_check_video->setChecked(true);
	ui.download_video_gif->clear();
}

void Download_and_Clip::encode_done()
{
	std::string outed = find_fuzzy(ui.encode_lineedit_directory->text().toStdString(), ui.encode_lineedit_filename->text().toStdString());
	if (outed.length() != 0)
	{
		update_status("Your clip was saved to: ", ui.encode_status);
		update_status(outed, ui.encode_status);

		QString valueText = this->locale().formattedDataSize(fs::file_size(outed));
		update_status(valueText.toStdString(), ui.encode_status);
	}
	else
	{
		update_status("Uh oh!!! Your clip might not have worked??", ui.encode_status);
	}
}

void Download_and_Clip::processStateChange(std::string program, QProcess::ProcessState newState, std::string tag, QTextEdit* box)
{
	//process->readAllStandardOutput();

	switch (newState)
	{
	case QProcess::Starting:
	{
		//update_status(tag + " Starting", box);
	}
	break;
	case QProcess::Running:
	{
		//update_status(tag + " Running", box);
	}
	break;
	case QProcess::NotRunning:
	{
		//update_status(tag + " Done", box);

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
			std::string file = get_setting(setting_working_directory) + "probe.txt";
			if (fs::exists(file))
			{
				std::ifstream i(file);
				nlohmann::json ffprobe;
				i >> ffprobe;

				std::string duration = ffprobe["format"]["duration"];
				QString _duration = duration.c_str();
				ui.download_table->setItem(0, 2, new QTableWidgetItem(_duration));
			}

			file = get_setting(setting_working_directory) + "downloaded_info.info.json";
			if (fs::exists(file))
			{
				std::ifstream i2(file);
				nlohmann::json ytdesc;
				i2 >> ytdesc;

				ui.download_table->setItem(0, 0, new QTableWidgetItem(ytdesc["title"].get<std::string>().c_str()));
			}

			QString valueText = this->locale().formattedDataSize(fs::file_size(find_fuzzy(get_setting(setting_working_directory), "downloaded_video")));
			ui.download_table->setItem(0, 1, new QTableWidgetItem(valueText));
		}
		else if (tag == "probe local video")
		{
			std::string file = get_setting(setting_working_directory) + "local_probe.txt";
			std::ifstream i(file);
			nlohmann::json ffprobe;
			i >> ffprobe;

			ui.local_table->setItem(0, 0, new QTableWidgetItem(just_file_name(ui.local_lineedit->text().toStdString()).c_str()));

			QString valueText = this->locale().formattedDataSize(fs::file_size(ui.local_lineedit->text().toStdString()));
			ui.local_table->setItem(0, 1, new QTableWidgetItem(valueText));

			std::string duration = ffprobe["format"]["duration"];
			QString _duration = duration.c_str();
			ui.local_table->setItem(0, 2, new QTableWidgetItem(_duration));

			ui.local_check_probe->setChecked(true);
		}
	}
	break;
	};
}

void Download_and_Clip::start_new_process(std::string program, QStringList args, std::string tag, QTextEdit* box, QString out, bool to_file)
{
	if (out == "" && to_file)
	{
		// bad!!
		assert(false);
	}

	QProcess* info = new QProcess(this);
	QProcesses.push_back(info);
	info->setProgram(program.c_str());
	info->setArguments(args);

	if (!to_file)
	{
		connect(info, &QProcess::readyReadStandardOutput, [=]()
		{
			processOutput(tag, info, box);
		});

		connect(info, &QProcess::readyReadStandardError, [=]()
		{
			processErrOutput(tag, info, box);
		});
	}
	else
	{
		info->setStandardOutputFile(out);
	}

	connect(info, &QProcess::stateChanged, [=](QProcess::ProcessState newState)
	{
		processStateChange(program, newState, tag, box);
	});

	info->start();
}

void Download_and_Clip::processOutput(std::string tag, QProcess* proc, QTextEdit* box)
{
	if (proc != NULL)
	{
		std::string out = proc->readAllStandardOutput().toStdString();
		out.erase(std::remove(out.begin(), out.end(), '\r'), out.end());
		out.erase(std::remove(out.begin(), out.end(), '\n'), out.end());
		update_status(tag + ": " + out, box);
	}
}

void Download_and_Clip::processErrOutput(std::string tag, QProcess* proc, QTextEdit* box)
{
	if (proc != NULL)
	{
		std::string out = proc->readAllStandardError().toStdString();
		out.erase(std::remove(out.begin(), out.end(), '\r'), out.end());
		out.erase(std::remove(out.begin(), out.end(), '\n'), out.end());
		update_status(tag + ": " + out, box);
	}
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
	box->horizontalScrollBar()->setValue(0);
}

int Download_and_Clip::download_file(std::string _url, std::string _file)
{
	return 0;
}

void Download_and_Clip::check_for_ytdl()
{

}

void Download_and_Clip::check_for_ffmpeg()
{

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
	for (auto& p : fs::directory_iterator(get_setting(setting_working_directory)))
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

	set_setting(setting_last_download_url, video_id.toStdString());

	QStringList args = { video_id, "-o", (get_setting(setting_working_directory) + "downloaded_info").c_str(), "--skip-download", "--no-playlist", "--write-info-json" };
	start_new_process(get_setting(setting_exe_ytdl), args, "download video info", ui.download_status, "", false);

	QStringList args2 = { video_id, "-o", (get_setting(setting_working_directory) + "downloaded_thumb").c_str(), "--write-thumbnail", "--skip-download", "--no-playlist" };
	start_new_process(get_setting(setting_exe_ytdl), args2, "download video thumbnail", ui.download_status, "", false);

	QStringList args3 = { video_id, "-o", (get_setting(setting_working_directory) + "downloaded_video").c_str(), "-f", "bestvideo+bestaudio/best", "--no-playlist" };
	start_new_process(get_setting(setting_exe_ytdl), args3, "download video", ui.download_status, "", false);
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

	if (focus == enum_focus_none)
	{
		update_status("No focused video", ui.encode_status);
	}
	else
		if (directory_name.length() == 0)
		{
			update_status("Directory Name Too Short", ui.encode_status);
		}
		else
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
					std::string source_video = ui.focus_lineedit->text().toStdString();

					std::string type = ui.encode_combo->currentText().toStdString();

					if (type.compare("x264") == 0 || type.compare("x265") == 0)
					{
						QStringList args = { "-i", source_video.c_str(), "-c:v", ("lib" + ui.encode_combo->currentText().toStdString()).c_str(), "-crf", std::to_string(ui.encode_slider->value()).c_str(), "-preset", "ultrafast", "-c:a", "aac", "-strict", "experimental",
							"-b:a", "192k", "-ss", ui.encode_starttime->text(), "-to", ui.encode_endtime->text(), "-ac", "2", outfile.c_str(), "-y" };
						start_new_process(get_setting(setting_exe_ffmpeg), args, "encode", ui.encode_status, "", false);
					}
					else if (type.compare("gif") == 0)
					{
						QStringList args = { "-i", source_video.c_str(), "-crf", std::to_string(ui.encode_slider->value()).c_str(), "-preset", "ultrafast", "-c:a", "aac", "-strict", "experimental",
							"-b:a", "192k", "-ss", ui.encode_starttime->text(), "-to", ui.encode_endtime->text(), "-ac", "2", (outfile).c_str(), "-y" };
						start_new_process(get_setting(setting_exe_ffmpeg), args, "encode", ui.encode_status, "", false);
					}
					else
						update_status("Unknown type???", ui.encode_status);
				}
			}
			else
				update_status("Clip Name Too Short", ui.encode_status);

}

void Download_and_Clip::uncheck_themes()
{
	ui.menu_actionThemeDark->setChecked(false);
	ui.menu_actionThemeLight->setChecked(false);
}

void Download_and_Clip::set_theme_dark()
{
	uncheck_themes();
	ui.menu_actionThemeDark->setChecked(true);
	this->setStyleSheet(dark_stylesheet);
	set_setting(setting_theme, "dark");

}

void Download_and_Clip::set_theme_light()
{
	uncheck_themes();
	ui.menu_actionThemeLight->setChecked(true);
	this->setStyleSheet("");
	set_setting(setting_theme, "light");
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
	std::string str = get_setting(setting_working_directory);
	std::transform(str.begin(), str.end(), str.begin(), fix_slashes);
	system(("explorer \"" + str + "\"").c_str());
}

void Download_and_Clip::show_folder_output()
{
	if (get_setting(setting_output_directory).length() != 0)
	{
		std::string str = ui.encode_lineedit_directory->text().toStdString();
		std::transform(str.begin(), str.end(), str.begin(), fix_slashes);
		system(("explorer \"" + str + "\"").c_str());
	}
}

QString Download_and_Clip::choose_directory(std::string hint, QString starting_dir)
{
	return QFileDialog::getExistingDirectory(this, tr(hint.c_str()), starting_dir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}

void Download_and_Clip::choose_output_directory()
{
	QString dir = choose_directory("Open Directory", ui.encode_lineedit_directory->text());

	if (!dir.isEmpty())
	{
		std::string str = dir.toStdString() + "/";

		while (str.find("//") != std::string::npos)
		{
			str.replace(str.begin(), str.end(), "//", "/");
		}

		ui.encode_lineedit_directory->setText(str.c_str());

		set_setting(setting_output_directory, str);
	}
}

QString Download_and_Clip::choose_file(std::string hint, QString starting_dir, std::string exts)
{
	QString str = QFileDialog::getOpenFileName(this, tr(hint.c_str()), starting_dir, exts.c_str());
	return str;
}

void Download_and_Clip::choose_local_video()
{
	QString dir = choose_file("Open Video", ui.local_lineedit->text(), "Video File (*.*)");

	if (!dir.isEmpty())
	{
		std::string str = dir.toStdString();
		ui.local_lineedit->setText(str.c_str());
	}
}

void Download_and_Clip::browse_for_ytdl()
{
	QString dir = choose_file("Find YouTube-DL", ui.setup_ytdl_lineedit->text(), "YT-DL (youtube-dl.exe)");

	if (!dir.isEmpty())
	{
		ui.setup_ytdl_lineedit->setText(dir);
		set_setting(setting_exe_ytdl, dir.toStdString());
	}
}

void Download_and_Clip::browse_for_ffmpeg()
{
	QString dir = choose_file("Find FFmpeg", ui.setup_ffmpeg_lineedit->text(), "FFmpeg (ffmpeg.exe)");

	if (!dir.isEmpty())
	{
		ui.setup_ffmpeg_lineedit->setText(dir);
		set_setting(setting_exe_ffmpeg, dir.toStdString());
	}
}

void Download_and_Clip::browse_for_ffprobe()
{
	QString dir = choose_file("Find ffprobe", ui.setup_ffprobe_lineedit->text(), "ffprobe (ffprobe.exe)");

	if (!dir.isEmpty())
	{
		ui.setup_ffprobe_lineedit->setText(dir);
		set_setting(setting_exe_ffprobe, dir.toStdString());
	}
}

const int animation_time = 300;
void Download_and_Clip::collapse_panel(QToolBox* toolbox)
{
	animation = new QPropertyAnimation(toolbox, "maximumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(0, 16777215));
	animation->start();

	animation = new QPropertyAnimation(toolbox, "minimumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(0, 500));
	animation->start();
}

void Download_and_Clip::expand_panel(QToolBox* toolbox)
{
	animation = new QPropertyAnimation(toolbox, "maximumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(16777215, 16777215));
	animation->start();

	animation = new QPropertyAnimation(toolbox, "minimumSize");
	animation->setDuration(animation_time);
	animation->setStartValue(toolbox->size());
	animation->setEndValue(QSize(450, 500));
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

void Download_and_Clip::expand_both()
{
	expand_panel(ui.import_toolbox);
	expand_panel(ui.export_toolbox);
}

void Download_and_Clip::load_if_valid(int setting, QLineEdit* destination)
{
	std::string option = get_setting(setting);
	if (fs::exists(option))
	{
		destination->setText(option.c_str());
	}
	else
	{
		set_setting(setting, "");
	}
}

void Download_and_Clip::update_ui_from_settings()
{
	load_if_valid(setting_exe_ytdl, ui.setup_ytdl_lineedit);

	if (get_setting(setting_exe_ytdl).length() != 0)
		ui.import_toolbox->setCurrentIndex(1);

	load_if_valid(setting_exe_ffmpeg, ui.setup_ffmpeg_lineedit);
	load_if_valid(setting_exe_ffprobe, ui.setup_ffprobe_lineedit);

	if (get_setting(setting_exe_ffmpeg).length() != 0 && get_setting(setting_exe_ffprobe).length() != 0)
		ui.export_toolbox->setCurrentIndex(1);

	ui.download_linedit->setText(get_setting(setting_last_download_url).c_str());
	ui.local_lineedit->setText(get_setting(setting_last_local_url).c_str());

	if (get_setting(setting_focus_scroll) == "true")
	{
		ui.menu_setting_scroll_focus->setChecked(true);
	}

	if (get_setting(setting_output_directory).length() != 0)
		ui.encode_lineedit_directory->setText(get_setting(setting_output_directory).c_str());

	//

	std::string theme = get_setting(setting_theme);
	if (theme.length() == 0 || theme == "dark")
	{
		set_setting(setting_theme, "dark");
		set_theme_dark();
	}
	else if (theme == "light")
	{
		set_theme_light();
	}

	//

	if (get_setting(setting_expand_by_default) == "true")
	{
		//expand_both();
		ui.menu_setting_expand_default->setChecked(true);
	}
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
		ui.import_toolbox->setCurrentIndex(2);

		std::cout << endl;
	}
}

void Download_and_Clip::make_focus_local()
{
	ui.focus_lineedit->setText(ui.local_lineedit->text());
	ui.focus_image->setPixmap(ui.local_image->pixmap()->copy());
	focus = enum_focus_local;

	for (int i = 0; i < ui.focus_table->rowCount(); i++)
		ui.focus_table->setItem(i, 0, ui.local_table->item(i, 0)->clone());

	ui.encode_endtime->setText(ui.local_table->item(2, 0)->text());

	if (get_setting(setting_focus_scroll) == "true")
		expand_right();
}

void Download_and_Clip::make_focus_download()
{
	ui.focus_lineedit->setText(find_fuzzy(get_setting(setting_working_directory), "downloaded_video").c_str());
	ui.focus_image->setPixmap(ui.download_image->pixmap()->copy());
	focus = enum_focus_downloaded;

	for (int i = 0; i < ui.focus_table->rowCount(); i++)
		ui.focus_table->setItem(i, 0, ui.download_table->item(i, 0)->clone());

	ui.encode_endtime->setText(ui.focus_table->item(2, 0)->text());

	if (get_setting(setting_focus_scroll) == "true")
		expand_right();
}

void Download_and_Clip::load_local()
{
	ui.local_check_video->setChecked(false);
	ui.local_check_thumb->setChecked(false);
	ui.local_check_probe->setChecked(false);

	if (fs::exists(ui.local_lineedit->text().toStdString()))
	{
		ui.local_check_video->setChecked(true);
	}

	set_setting(setting_last_local_url, ui.local_lineedit->text().toStdString());

	remove_fuzzy("local_thumb");
	QStringList args = { "-i", ui.local_lineedit->text(), "-ss", "00:00:05.01", "-frames:v", "1", (get_setting(setting_working_directory) + "local_thumb.png").c_str(), "-y" };
	start_new_process(get_setting(setting_exe_ffmpeg), args, "local thumb", ui.local_status, "", false);

	remove_fuzzy("local_probe");
	std::string video_name = ui.local_lineedit->text().toStdString();
	QStringList args2 = { (video_name).c_str(), "-show_streams", "-show_format", "-print_format", "json", "-pretty" };
	start_new_process(get_setting(setting_exe_ffprobe), args2, "probe local video", ui.local_status, (get_setting(setting_working_directory) + "local_probe.txt").c_str(), true);
}

void Download_and_Clip::toggle_focus_scroll()
{
	if (get_setting(setting_focus_scroll) == "true")
	{
		set_setting(setting_focus_scroll, "false");
		ui.menu_setting_scroll_focus->setChecked(false);
		update_status("Auto-Scroll when Focus Off", ui.setup_status);
	}
	else
	{
		set_setting(setting_focus_scroll, "true");
		ui.menu_setting_scroll_focus->setChecked(true);
		update_status("Auto-Scroll when Focus On", ui.setup_status);
	}
}

void Download_and_Clip::toggle_default_expand()
{
	if (get_setting(setting_expand_by_default) == "true")
	{
		set_setting(setting_expand_by_default, "false");
		ui.menu_setting_expand_default->setChecked(false);
		update_status("Default Expand Off", ui.setup_status);
	}
	else
	{
		set_setting(setting_expand_by_default, "true");
		ui.menu_setting_expand_default->setChecked(true);
		update_status("Default Expand On", ui.setup_status);
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
	gif_loading->setFileName("assets/Spin-1s-200px.gif");
	gif_loading->start();

	this->setMaximumSize(QSize(0, 0));
	this->setMaximumSize(QSize(16777215, 16777215));

	connect(ui.encode_lineedit_filename, SIGNAL(textChanged()), this, SLOT(typing_clip_name()));

	connect(ui.download_button, SIGNAL(clicked()), this, SLOT(execute_ytdl_download()));
	connect(ui.download_linedit, SIGNAL(returnPressed()), this, SLOT(execute_ytdl_download()));

	connect(ui.encode_go, SIGNAL(clicked()), this, SLOT(execute_ffmpeg_encode()));
	connect(ui.encode_lineedit_filename, SIGNAL(returnPressed()), this, SLOT(execute_ffmpeg_encode()));

	connect(ui.expand_left, SIGNAL(clicked()), this, SLOT(expand_left()));
	connect(ui.expand_right, SIGNAL(clicked()), this, SLOT(expand_right()));
	connect(ui.expand_both, SIGNAL(clicked()), this, SLOT(expand_both()));

	connect(ui.setup_show_working_dir, SIGNAL(clicked()), this, SLOT(show_folder_working()));
	connect(ui.setup_show_output_dir, SIGNAL(clicked()), this, SLOT(show_folder_output()));

	connect(ui.local_button, SIGNAL(clicked()), this, SLOT(choose_local_video()));

	connect(ui.setup_ytdl_button, SIGNAL(clicked()), this, SLOT(browse_for_ytdl()));
	connect(ui.setup_ffmpeg_button, SIGNAL(clicked()), this, SLOT(browse_for_ffmpeg()));
	connect(ui.setup_ffprobe_button, SIGNAL(clicked()), this, SLOT(browse_for_ffprobe()));

	connect(ui.encode_slider, SIGNAL(valueChanged(int)), ui.encode_spinbox, SLOT(setValue(int)));
	connect(ui.encode_spinbox, SIGNAL(valueChanged(int)), ui.encode_slider, SLOT(setValue(int)));

	connect(ui.menu_actionThemeLight, SIGNAL(triggered()), this, SLOT(set_theme_light()));
	connect(ui.menu_actionThemeDark, SIGNAL(triggered()), this, SLOT(set_theme_dark()));
	connect(ui.menu_setting_scroll_focus, SIGNAL(triggered()), this, SLOT(toggle_focus_scroll()));
	connect(ui.menu_setting_expand_default, SIGNAL(triggered()), this, SLOT(toggle_default_expand()));

	connect(ui.download_button_focus, SIGNAL(clicked()), this, SLOT(make_focus_download()));
	connect(ui.local_button_focus, SIGNAL(clicked()), this, SLOT(make_focus_local()));

	connect(ui.local_load, SIGNAL(clicked()), this, SLOT(load_local()));

	connect(ui.encode_browse, SIGNAL(clicked()), this, SLOT(choose_output_directory()));

	ui.import_toolbox->setCurrentIndex(0);
	ui.export_toolbox->setCurrentIndex(0);

	file_load_settings();
	init_settings();

	update_ui_from_settings();

	{
		QPixmap image("assets/16x9.png");
		ui.focus_image->setPixmap(image);
		ui.local_image->setPixmap(image);
		ui.download_image->setPixmap(image);
	}

	std::string dir = get_setting(setting_working_directory);
	if (!(fs::exists(dir)))
	{
		fs::create_directory(dir);
		std::ofstream warning(dir + "Consider this folder temporary, anything in it may be deleted at any time");
		warning.close();
	}

	if (!(get_setting(setting_expand_by_default) == "true"))
	{
		ui.export_toolbox->setMinimumWidth(0);
		ui.export_toolbox->setMaximumWidth(0);
	}

	ui.download_table->resizeRowsToContents();
	ui.focus_table->resizeRowsToContents();

	ui.download_table->resizeColumnsToContents();
	ui.focus_table->resizeColumnsToContents();

}