#pragma once

class BoundingBox : public QRect 
{

public:

	explicit BoundingBox(QRect x) : QRect(x) { }
	QString name;
};


class GraphicsView : public QGraphicsView
{

public:
	GraphicsView(QWidget* parent = 0);

	bool containsImage = false;

	void openImage(QString file);

protected:
	void wheelEvent(QWheelEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void drawForeground(QPainter* painter, const QRectF& rect);

private:
	QRect drawRect;
	QRect* moveRect;

	double viewScale = 1;

	int startX;
	int startY;

	int currentX;
	int currentY;

	bool isPanning = false;
	bool isDrawing = false;
	bool isMoving = false;

	QGraphicsItem* item;
	QGraphicsScene* _scene;
};

