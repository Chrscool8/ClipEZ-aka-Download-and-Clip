#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Download_and_Clip.h"
#include <QtCore>
#include <QtWidgets>

class Download_and_Clip : public QMainWindow
{
	Q_OBJECT

public:
	Download_and_Clip(QWidget* parent = Q_NULLPTR);

	void init_elements();
	std::string get_setting(int setting);
	void set_setting(int setting, std::string value);
	void load_downloaded_thumbnail();
	void load_local_thumbnail();
	void load_video_info();
	void load_video();
	void start_new_process(std::string program, QStringList args, std::string tag);
	void check_for_downloaded_files();
	void update_status(std::string str, QTextEdit* box);
	int download_file(std::string _url, std::string _file);
	void check_for_ytdl();
	void check_for_ffmpeg();
	void download_exe_ffmpeg();
	void remove_fuzzy(std::string file);
	void darkmode(bool on);
	std::string get_ext();
	QString Download_and_Clip::choose_directory(std::string hint, QString starting_dir);
	void collapse_panel(QToolBox* toolbox);
	void expand_panel(QToolBox* toolbox);

	//void load_settings(std::string filename);
	//bool setting_exists(std::string setting);

	void init_settings();
	void file_load_settings();
	void file_save_settings();
	void update_ui_from_settings();
	QString choose_file(std::string hint, QString starting_dir, std::string exts);


private slots:
	void download_exe_ytdl();
	void execute_ytdl_download();

	void expand_left();
	void expand_right();



	void execute_ffmpeg_encode();

	void darkmode_toggle(bool state);

	void clear_download();
	void typing_clip_name();

	void show_folder_working();
	void show_folder_output();

	void choose_output_directory();


	void choose_local_video();

	void browse_for_ytdl();

	void browse_for_ffmpeg();

	void browse_for_ffprobe();


	void processStateChange(std::string, QProcess::ProcessState newState, std::string tag);

private:
	Ui::Download_and_ClipClass ui;



};


