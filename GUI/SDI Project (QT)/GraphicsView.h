#pragma once

#include "pch.h"

class BoundingBox : public QRect
{

public:

    explicit BoundingBox(QRect x) : QRect(x) { }

    //QRubberBand q = new QRubberBand(QRubberBand::Shape, nullptr);
	QString name;
    QColor colour;

};


class GraphicsView : public QGraphicsView
{

public:
	GraphicsView(QWidget* parent = 0);

	bool containsImage = false;

	void openImage(QString file);

    QString current;

protected:
	void wheelEvent(QWheelEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void drawForeground(QPainter* painter, const QRectF& rect);

    void keyPressEvent(QKeyEvent* event);
    void deleteSelected();

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
    bool isResizing = false;

    BoundingBox* selected = nullptr;
    QString resizeName;

	QGraphicsItem* item;
	QGraphicsScene* _scene;

};



class Output : public QPushButton
{

public:

    Output(QWidget* parent = 0);

    QString folderName;
    QString fileName;

    int width;
    int height;

protected:

    void mousePressEvent(QMouseEvent* event);
};



