/*********************************************************************************
  *
  *
  *FileName:          ImageTextDrawer.h
  *
  *Author:         	   PatchLion
  *
  *Date:         	       2017-5-2
  *
  *Description:		文字绘制器	
**********************************************************************************/
#ifndef ImageTextDrawer_H
#define ImageTextDrawer_H

#include <QtGui>
#include <QtCore>

class CImageTextDrawer
{
private:
	struct stTextDrawInfo
	{
		stTextDrawInfo()
		{
			strokeSize = 0;
			isVertical = false;
		}
		QString text;
		QColor color;
		QFont font;
		QPoint pos;
		int strokeSize;
		QColor storkeColor;
		bool isVertical;
	};

	typedef QList<stTextDrawInfo> ListTextDrawInfo;

public:
	CImageTextDrawer(const QSize& size= QSize(800, 600));
	~CImageTextDrawer();


public:
	/*
	*Method: addText		
	*Descrption:		添加文字
	*Returns: void
	*Parameter: (const QString &)text 文本
	*Parameter: (const QFont &)font 文本样式
	*Parameter: (const QPoint &)pos 文本位置
	*Parameter: (int)strokeSize 描边宽度
	*Parameter: (const QColor &)storkeColor 描边颜色
	*Parameter: (bool)isVertical 是否竖排
	*/
	void addText(const QString& text, const QColor& color, const QFont& font, const QPoint& pos, int strokeSize = 0, const QColor& storkeColor = Qt::lightGray, bool isVertical = false);


	/*
	*Method: outputImage
	*Descrption:  输出图片
	*Returns: QImage 输出的图片
	*Parameter: (const QColor &)bgColor 图片的背景颜色
	*/
	QImage outputImage(const QColor& bgColor = Qt::transparent);

private:
	void drawTextOnImage(QPainter& painter, const stTextDrawInfo& info);

private:
	QSize m_imageSize;
	ListTextDrawInfo m_listDrawInfo;
};

#endif // ImageTextDrawer_H
