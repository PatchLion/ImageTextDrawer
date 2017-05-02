#include "ImageTextDrawer.h"
#include <QFontMetrics>

CImageTextDrawer::CImageTextDrawer(const QSize& size)
	: m_imageSize(size)
{

}

CImageTextDrawer::~CImageTextDrawer()
{

}

void CImageTextDrawer::drawTextOnImage(QPainter& painter, const stTextDrawInfo& info)
{
	painter.save();
	painter.setBrush(Qt::transparent);
	painter.setPen(info.color);
	painter.setFont(info.font);

	QFontMetrics fontM(info.font);
	QRect textBR = fontM.boundingRect(info.text);
	painter.drawText(info.pos.x(), info.pos.y() + textBR.height() /2.0, info.text);

	//TODO: Ãè±ßºÍÐý×ª
	painter.restore();
}

QImage CImageTextDrawer::outputImage(const QColor& bgColor)
{
	QImage image(m_imageSize, QImage::Format_RGBA8888);
	image.fill(bgColor);

	QPainter p(&image);
	Q_FOREACH(stTextDrawInfo drawInfo, m_listDrawInfo)
	{
		drawTextOnImage(p, drawInfo);
	}

	return image;
}

void CImageTextDrawer::addText(const QString& text, const QColor& color, const QFont& font, const QPoint& pos, int strokeSize /*= 0*/, const QColor& storkeColor /*= Qt::lightGray*/, bool isVertical /*= false*/)
{
	stTextDrawInfo drawInfo;
	drawInfo.text = text;
	drawInfo.color = color;
	drawInfo.font = font;
	drawInfo.pos = pos;
	drawInfo.strokeSize = strokeSize;
	drawInfo.storkeColor = storkeColor;
	drawInfo.isVertical = isVertical;

	m_listDrawInfo.append(drawInfo);
}
