#include "Download_and_Clip.h"
#include <QtWidgets>
#include <QApplication>
#include <QProgressBar>
#include <QSlider>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Download_and_Clip window;

	QSpinBox* spinbox_quality = window.findChild<QSpinBox*>("spinbox_quality");
	Q_ASSERT(spinbox_quality);

	QSlider* slider_quality = window.findChild<QSlider*>("slider_quality");
	Q_ASSERT(slider_quality);

	QObject::connect(slider_quality, SIGNAL(valueChanged(int)), spinbox_quality, SLOT(setValue(int)));
	QObject::connect(spinbox_quality, SIGNAL(valueChanged(int)), slider_quality, SLOT(setValue(int)));


	window.show();
	return app.exec();
}
