#include "ImageTextDrawerTest.h"
#include <QtWidgets>

CImageTextDrawerTest::CImageTextDrawerTest(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	pushButtonApply->hide();

	m_textDrawer.setImageSize(QSize(1000, 1000));

	on_pushButtonApply_clicked(false);
}

CImageTextDrawerTest::~CImageTextDrawerTest()
{

}

void CImageTextDrawerTest::on_pushButtonApply_clicked(bool checked)
{
	m_image = currentImage();

	update();
}

void CImageTextDrawerTest::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	QRect drawAreaRect = widgetDrawArea->geometry();

	QImage drawImage = m_image.scaled(drawAreaRect.size(), Qt::KeepAspectRatio);
	painter.drawImage(drawAreaRect.center().x() - drawImage.width() / 2, drawAreaRect.center().y() - drawImage.height() / 2.0, drawImage);
}

void CImageTextDrawerTest::on_fontComboBox_currentFontChanged(const QFont & font)
{
	on_pushButtonApply_clicked(false);
}

void CImageTextDrawerTest::on_spinBoxFontSize_valueChanged(int value)
{
	on_pushButtonApply_clicked(false);
}

void CImageTextDrawerTest::on_lineEditText_textEdited(const QString & text)
{
	on_pushButtonApply_clicked(false);
}

void CImageTextDrawerTest::on_pushButtonOutput_clicked(bool checked)
{
	const QString path = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存图片到..."), "itd_test.png", "Images (*.png *.bmp *.jpg)");

	if (!path.isEmpty())
	{
		QImage image = currentImage();

		if (image.save(path))
		{
			QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("成功保存到本地!"));
#ifdef Q_OS_WIN
			system(path.toLocal8Bit().data());
#endif
		}
		else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit("保存到本地失败!"));
		}
	}

}

QImage CImageTextDrawerTest::currentImage()
{
	m_textDrawer.clearTexts();
	QFont font = fontComboBox->currentFont();
	font.setPointSize(spinBoxFontSize->value());
	m_textDrawer.addText(lineEditText->text(), Qt::red, font, QPoint(10, 10), 1);
	QImage image = m_textDrawer.outputImage(Qt::blue);

	return image;
}
