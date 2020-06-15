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

	std::string get_setting(int setting);
	void set_setting(int setting, std::string value);
	void load_downloaded_thumbnail();
	void load_local_thumbnail();
	std::string find_fuzzy(std::string path, std::string filename);
	void check_full_download();
	void load_video_info();
	void load_downloaded_video();
	void encode_done();
	void start_new_process(std::string program, QStringList args, std::string tag, QString out, QTextEdit* box);
	void check_for_downloaded_files();
	void update_status(std::string str, QTextEdit* box);
	int download_file(std::string _url, std::string _file);
	void check_for_ytdl();
	void check_for_ffmpeg();
	void download_exe_ffmpeg();
	void remove_fuzzy(std::string file);
	void uncheck_themes();
	std::string get_ext();
	QString Download_and_Clip::choose_directory(std::string hint, QString starting_dir);
	void collapse_panel(QToolBox* toolbox);
	void expand_panel(QToolBox* toolbox);
	void init_settings();
	void file_load_settings();
	void file_save_settings();
	void update_ui_from_settings();
	QString choose_file(std::string hint, QString starting_dir, std::string exts);

	QPropertyAnimation* animation;
	QMovie* gif_loading;
	void load_if_valid(int setting, QLineEdit* destination);

private slots:
	void download_exe_ytdl();
	void execute_ytdl_download();

	void expand_left();
	void expand_right();

	void set_theme_dark();
	void set_theme_light();

	void execute_ffmpeg_encode();

	void typing_clip_name();

	void show_folder_working();
	void show_folder_output();

	void choose_output_directory();
	void choose_local_video();

	void browse_for_ytdl();
	void browse_for_ffmpeg();
	void browse_for_ffprobe();

	void make_focus_local();
	void make_focus_download();

	void load_local();

	void toggle_focus_scroll();

	void processStateChange(std::string, QProcess::ProcessState newState, std::string tag, QTextEdit* box);

private:
	Ui::Download_and_ClipClass ui;

protected:
	// —— events ———————————————————————————
	/*
	 * this event is called when the mouse enters the widgets area during a drag/drop operation
	 */
	void dragEnterEvent(QDragEnterEvent* event);

	/**
	 * this event is called when the mouse moves inside the widgets area during a drag/drop operation
	 */
	void dragMoveEvent(QDragMoveEvent* event);

	/**
	 * this event is called when the mouse leaves the widgets area during a drag/drop operation
	 */
	void dragLeaveEvent(QDragLeaveEvent* event);

	/**
	 * this event is called when the drop operation is initiated at the widget
	 */
	void dropEvent(QDropEvent* event);



};


