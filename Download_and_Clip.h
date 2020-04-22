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


	void load_thumbnail();
	void load_video_info();
	void load_video();
	void start_new_process(std::string program, QStringList args, std::string tag);
	void check_for_downloaded_files();
	void update_status(std::string str);
	int download_file(std::string _url, std::string _file);
	void check_for_ytdl();
	void check_for_ffmpeg();
	void download_ffmpeg();
	void darkmode(bool on);



private slots:
	void download_ytdl();
	void run_ytdl();
	
	void run_ffmpeg();

	void darkmode_toggle(bool state);

	void clear_download();
	void typing_clip_name();

	void show_folder();

	

	void processStateChange(std::string, QProcess::ProcessState newState, std::string tag);

private:
	Ui::Download_and_ClipClass ui;



};


