#pragma once

class GraphicsView : public QGraphicsView
{

public:
	GraphicsView(QWidget* parent = 0);

protected:
	void wheelEvent(QWheelEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void drawForeground(QPainter* painter, const QRectF& rect);
	//void paintEvent(QPaintEvent* event);

private:
	double viewScale = 1;
	QRectF view;

	int startX;
	int startY;

	int currentX;
	int currentY;

	bool isPanning = false;
	bool isDrawing = false;
};

