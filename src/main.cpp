#include "Download_and_Clip.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Download_and_Clip window_dnc;
	window_dnc.show();

	return app.exec();
}