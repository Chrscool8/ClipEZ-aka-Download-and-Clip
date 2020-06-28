#pragma once

#include <QWidget>
#include "ui_Task_Man.h"
#include <QtCore\qprocess.h>

class Task_Man : public QWidget
{
	Q_OBJECT

public:
	Task_Man(QWidget* parent = Q_NULLPTR);
	~Task_Man();

	void activate_process_table();

	std::vector<QProcess*>* QProcesses = NULL;

private:
	Ui::Task_Man ui;
};
