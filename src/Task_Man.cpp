#include "Task_Man.h"
#include <QTime>

void delay()
{
	QTime wake_time = QTime::currentTime().addMSecs(250);
	while (QTime::currentTime() < wake_time)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}

std::string just_file_name_(std::string filename)
{
	std::size_t found = filename.find_last_of("/\\");
	return filename.substr(found + 1);
}

QString state_string(int state)
{
	switch (state)
	{
	case 0: return QString("Not Running");
	case 1: return QString("Starting");
	case 2: return QString("Running");
	default: return QString("Uh oh.");
	}
}

void Task_Man::activate_process_table()
{
	while (this->isVisible())
	{
		int row = ui.tableWidget->currentRow();
		int col = ui.tableWidget->currentColumn();

		while (ui.tableWidget->rowCount() > 0)
			ui.tableWidget->removeRow(0);

		// Prune finished
		for (int i = 0; i < QProcesses->size(); i++)
		{
			if (QProcesses->at(i)->processId() == 0)
			{
				QProcesses->erase(QProcesses->begin() + i);
				i--;
			}
		}

		for (int i = 0; i < QProcesses->size(); i++)
			ui.tableWidget->insertRow(i);

		for (int i = 0; i < QProcesses->size(); i++)
		{
			QProcess* p = QProcesses->at(i);
			QString name = just_file_name_(p->program().toStdString()).c_str();
			QString pid = QString::number(p->processId());
			QString status = QString::number(p->state());
			QString args = p->arguments().join(" ");

			ui.tableWidget->setItem(i, 0, new QTableWidgetItem(name));
			ui.tableWidget->setItem(i, 1, new QTableWidgetItem(pid));
			ui.tableWidget->setItem(i, 2, new QTableWidgetItem(status));
			ui.tableWidget->setItem(i, 3, new QTableWidgetItem(args));
		}

		if (QProcesses->size() == 0)
		{
			ui.tableWidget->insertRow(0);
		}

		ui.tableWidget->setCurrentCell(row, col);

		delay();
	}
}

Task_Man::Task_Man(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Task_Man::~Task_Man()
{
}
