#include "pch.h"

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent)
{

}


void GraphicsView::wheelEvent(QWheelEvent* event)
{

	setTransformationAnchor(QGraphicsView::AnchorViewCenter);
	
	double scaleFactor = 1.2;

	if (event->delta() > 0) {
		viewScale *= 1/scaleFactor;
		scale(scaleFactor, scaleFactor);
	}
	else {
		viewScale *= scaleFactor;
		scale(1 / scaleFactor, 1 / scaleFactor);
	}

}

void GraphicsView::mousePressEvent(QMouseEvent *event) {

	// Panning
	if (event->button() == Qt::RightButton)
	{
		setCursor(Qt::ClosedHandCursor);
		isPanning = true;
		startX = event->x();
		startY = event->y();
	}

	//Drawing
	if (event->button() == Qt::LeftButton)
	{
		setCursor(Qt::CrossCursor);
		isDrawing = true;
		startX = event->x();
		startY = event->y();
	}

}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event) {

	// Panning
	if (event->button() == Qt::RightButton)
	{
		isPanning = false;
		setCursor(Qt::ArrowCursor);
	}

	//Drawing
	if (event->button() == Qt::LeftButton)
	{
		isDrawing = false;
		setCursor(Qt::ArrowCursor);
	}

}

void GraphicsView::mouseMoveEvent(QMouseEvent *event) {

	// Panning
	if (isPanning)
	{
		qDebug() << "1";
		int deltaX = event->x() - startX;
		int deltaY = event->y() - startY;
		
		int scrollX = horizontalScrollBar()->value();
		int scrollY = verticalScrollBar()->value();

		horizontalScrollBar()->setValue
			(scrollX - deltaX);

		verticalScrollBar()->setValue
			(scrollY - deltaY);


		startX = event->x();
		startY = event->y();
		qDebug() << "2";
	}

	//Drawing
	if (isDrawing)
	{
		currentX = event->x();
		currentY = event->y();


		scene()->invalidate(scene()->sceneRect());

		


	}

}

void GraphicsView::drawForeground(QPainter* painter, const QRectF& rect)
{
	QGraphicsView::drawForeground(painter, rect);
	qDebug() << view.topLeft().rx();
	if (isDrawing) {
		painter->setPen(QPen(Qt::green));
		painter->setBrush(Qt::Dense7Pattern);

		//painter->drawRect(QRect(
		//	startX,
		//	startY,
		//	currentX-startX,
		//	currentY-startY
		//));

		painter->drawRect(QRect(
			rect.x(),
			rect.y(),
			(currentX-horizontalScrollBar()->value())*viewScale + view.topLeft().rx(),
			(currentY-verticalScrollBar()->value())*viewScale + view.topLeft().ry()
		));


	}
	else {
		view = rect;
	}

	
}

