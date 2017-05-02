#ifndef IMAGETEXTDRAWERTEST_H
#define IMAGETEXTDRAWERTEST_H

#include <QWidget>
#include "ui_ImageTextDrawerTest.h"
#include "ImageTextDrawer.h"

class CImageTextDrawerTest : public QWidget, public Ui::CImageTextDrawerTest
{
	Q_OBJECT

public:
	CImageTextDrawerTest(QWidget *parent = 0);
	~CImageTextDrawerTest();

protected:
	void paintEvent(QPaintEvent *event);

protected Q_SLOTS:
	void on_pushButtonApply_clicked(bool checked);
	void on_fontComboBox_currentFontChanged(const QFont & font);
	void on_spinBoxFontSize_valueChanged(int value);
	void on_lineEditText_textEdited(const QString & text);
	void on_pushButtonOutput_clicked(bool checked);

private:
	QImage currentImage();
private:
	QImage m_image;
	CImageTextDrawer m_textDrawer;
};

#endif // IMAGETEXTDRAWERTEST_H
