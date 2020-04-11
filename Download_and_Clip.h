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
	void update_status(std::string str);
	bool is_file_exist(const char* fileName);
	int download_file(std::string _url, std::string _file);
	void check_for_ytdl();
	void check_for_ffmpeg();
	void download_ffmpeg();

private slots:
	void download_ytdl();
	void run_ytdl();
	void processStarted_ytdl();
	void readyReadStandardOutput_ytdl();
	void encodingFinished_ytdl();

	void run_ffmpeg();
	void processStarted_ffmpeg();
	void readyReadStandardOutput_ffmpeg();
	void encodingFinished_ffmpeg();

	void darkmode_toggle(bool state);

private:
	Ui::Download_and_ClipClass ui;


	
};


