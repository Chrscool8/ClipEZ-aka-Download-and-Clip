#include "Download_and_Clip.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Download_and_Clip window;
	window.show();
	int ret = app.exec();
	return ret;
}
