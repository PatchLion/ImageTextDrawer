
#include <QApplication>
#include "ImageTextDrawerTest.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CImageTextDrawerTest test;
	test.show();

	return a.exec();
}
