#pragma once

#include "pch.h"

/// A Rectangle with Name and Colour
class BoundingBox : public QRect
{

public:

    explicit BoundingBox(QRect x) : QRect(x) { }

    //QRubberBand q = new QRubberBand(QRubberBand::Shape, nullptr);

    /// Defines the boxes' name
	QString name;
    /// Defines the boxes' colour (between selected and unselected)
    QColor colour;

};

/// Handles all activity within the draw canvas
class GraphicsView : public QGraphicsView
{

public:
	GraphicsView(QWidget* parent = 0);

	bool containsImage = false;

	void openImage(QString file);

    QString current;

protected:
    /// Scrolling in and out of the canvas
	void wheelEvent(QWheelEvent* event);
    /// Initiating Drawing or Panning on the canvas
	void mousePressEvent(QMouseEvent* event);
    /// Updating with new info as mouse is dragged across the canvas
	void mouseMoveEvent(QMouseEvent* event);
    /// When the mouse is unpressed on the canvas
	void mouseReleaseEvent(QMouseEvent* event);
    /// Called whenever activity occurs in relation to the canvas
	void drawForeground(QPainter* painter, const QRectF& rect);

    /// Relation to keyboard key presses
    void keyPressEvent(QKeyEvent* event);
    /// Deletes which ever box is currently selected
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


/// Class defining the output data
class Output : public QPushButton
{

public:

    Output(QWidget* parent = 0);

    QString folderName;
    QString fileName;

    int width;
    int height;

protected:

    /// Pressing on the button to output the data of the bounding boxes
    void mousePressEvent(QMouseEvent* event);
};



