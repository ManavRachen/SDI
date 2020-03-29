#include "pch.h"

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent)
{

}

SDI::Array<BoundingBox*> boxes;

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

	// Drawing
	if (event->button() == Qt::LeftButton)
	{
		setCursor(Qt::CrossCursor);

		QPoint mouseOrigin = mapFromGlobal(QCursor::pos());
		QPointF relativeOrigin = mapToScene(mouseOrigin);

		isDrawing = true;
		startX = event->x();
		startY = event->y();
	}

	// Move
	if (event->button() == Qt::MiddleButton)
	{
		if (!boxes.isEmpty()) {
			
			startX = event->x();
			startY = event->y();

			QPoint mouseOrigin = mapFromGlobal(QCursor::pos());
			QPointF relativeOrigin = mapToScene(mouseOrigin);


			for (BoundingBox* box : boxes) {
				if ((*box).contains(QPoint(relativeOrigin.x(), relativeOrigin.y()))) {
					isMoving = true;
					moveRect = box;
				}
			}
		}
	}
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event) {

	setCursor(Qt::ArrowCursor);


	// Panning
	if (event->button() == Qt::RightButton)
	{
		isPanning = false;
	}

	// Drawing
	if (event->button() == Qt::LeftButton)
	{
		boxes.pushBack( new BoundingBox(drawRect) );
		(*boxes.back())->name = "test";
		isDrawing = false;
	}

	// Move
	if (event->button() == Qt::MiddleButton)
	{
		isMoving = false;


	}

	

}

void GraphicsView::mouseMoveEvent(QMouseEvent *event) {

	// Panning
	if (isPanning)
	{
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
	}

	// Drawing
	else if (isDrawing)
	{
		currentX = event->x();
		currentY = event->y();

		if (containsImage) {
			scene()->invalidate(scene()->sceneRect());
		}

	}

	// Move
	else if (isMoving) 
	{
		QPoint mouseOrigin = mapFromGlobal(QCursor::pos());
		QPointF relativeOrigin = mapToScene(mouseOrigin);


		(*moveRect).moveCenter(QPoint(relativeOrigin.x(), relativeOrigin.y()));
		scene()->invalidate(scene()->sceneRect());

		
	}

}

void GraphicsView::drawForeground(QPainter* painter, const QRectF& rect)
{
	
	
	QGraphicsView::drawForeground(painter, rect);

	QPoint mouseOrigin = mapFromGlobal(QCursor::pos());
	QPointF relativeOrigin = mapToScene(mouseOrigin);

	QPointF start = mapToScene(startX,startY);

	if (isDrawing) {

		drawRect = QRect(
			start.x(),
			start.y(),
			relativeOrigin.x() - start.x(),
			relativeOrigin.y() - start.y()
		);

		painter->setPen(QPen(Qt::green));

		painter->drawRect(drawRect);

	}

	if (!boxes.isEmpty()) {
		for (BoundingBox* box : boxes) {
			qDebug() << boxes.size();

			painter->drawRect(*box);

			painter->drawText(box->topLeft(), box->name);
		}
	}

	_scene->update();
	
	
}

void GraphicsView::openImage(QString file) {

	// Save XML stuff

	boxes.clear();

	QPixmap picture(file);

	item = new QGraphicsPixmapItem(picture);
	_scene = new QGraphicsScene(this);
	setScene(_scene);

	_scene->addItem(item);
	containsImage = true;

	// Open XML
	QString boxesFile = file;

}
