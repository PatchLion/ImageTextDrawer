/*********************************************************************************
  *
  *
  *FileName:          ImageTextDrawer.h
  *
  *Author:         	   PatchLion
  *
  *Date:         	       2017-5-2
  *
  *Description:		���ֻ�����	
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
	*Descrption:		�������
	*Returns: void
	*Parameter: (const QString &)text �ı�
	*Parameter: (const QFont &)font �ı���ʽ
	*Parameter: (const QPoint &)pos �ı�λ��
	*Parameter: (int)strokeSize ��߿��
	*Parameter: (const QColor &)storkeColor �����ɫ
	*Parameter: (bool)isVertical �Ƿ�����
	*/
	void addText(const QString& text, const QColor& color, const QFont& font, const QPoint& pos, int strokeSize = 0, const QColor& storkeColor = Qt::lightGray, bool isVertical = false);


	/*
	*Method: outputImage
	*Descrption:  ���ͼƬ
	*Returns: QImage �����ͼƬ
	*Parameter: (const QColor &)bgColor ͼƬ�ı�����ɫ
	*/
	QImage outputImage(const QColor& bgColor = Qt::transparent);

private:
	void drawTextOnImage(QPainter& painter, const stTextDrawInfo& info);

private:
	QSize m_imageSize;
	ListTextDrawInfo m_listDrawInfo;
};

#endif // ImageTextDrawer_H
