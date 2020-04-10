#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Download_and_Clip.h"

class Download_and_Clip : public QMainWindow
{
	Q_OBJECT

public:
	Download_and_Clip(QWidget *parent = Q_NULLPTR);

private:
	Ui::Download_and_ClipClass ui;
};
