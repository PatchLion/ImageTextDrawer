
#include <QApplication>
#include "ImageTextDrawer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	qDebug() << QString::fromLocal8Bit("开始绘制......");
	CImageTextDrawer drawer(QSize(800, 600));
	QFont font;
	font.setPointSize(20);
	drawer.addText("Qter", Qt::red, font, QPoint(10, 10), 1);
	QImage image = drawer.outputImage(Qt::blue);
	QString path = "c:/itd_test.png";
	image.save(path);
#ifdef Q_OS_WIN
	system(path.toLocal8Bit().data()); //打开图片
#endif
	qDebug() << QString::fromLocal8Bit("绘制完毕! 输出到:") << path;
	return a.exec();
}
