/*********************************************************************************
  *
  *
  *FileName:          TextOnImageDrawer.h
  *
  *Author:         	   PatchLion
  *
  *Date:         	       2017-5-2
  *
  *Description:		ÎÄ×Ö»æÖÆÆ÷	
**********************************************************************************/
#ifndef TEXTONIMAGEDRAWER_H
#define TEXTONIMAGEDRAWER_H

#include <QtGui>
#include <QtCore>

class CTextOnImageDrawer
{
public:
	CTextOnImageDrawer(const QSize& size= QSize(800, 600));
	~CTextOnImageDrawer();


public:
	void addText(const QString& text, const QFont& font, int strokeSize = 0, const QColor& storkeColor = Qt::lightGray);

public:
	QImage image() const;

private:
	QSize m_imageSize;
};

#endif // TEXTONIMAGEDRAWER_H
