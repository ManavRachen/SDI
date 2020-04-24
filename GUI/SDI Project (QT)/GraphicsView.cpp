#include "pch.h"

SDI::Array<BoundingBox*> boxes;

// Graphics View Controlls

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent)
{

}

void GraphicsView::wheelEvent(QWheelEvent* event)
{

    if(!isDrawing && !isResizing){

        double scaleFactor = 1.2;

        if (event->delta() > 0)
            { scale(scaleFactor, scaleFactor); }
        else
            { scale(1 / scaleFactor, 1 / scaleFactor); }
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

    // Drawing and Resizing
    if (event->button() == Qt::LeftButton && containsImage)
    {

        setCursor(Qt::CrossCursor);

        // Resize
        if(!(selected == nullptr)){

            qDebug() << "resizing " << selected->name;

            resizeName = selected->name;

            startX = selected->x();
            startY = selected->y();

            deleteSelected();

            isResizing = true;

        }

        // Draw
        else if((selected == nullptr) && !current.isNull()) {

            qDebug() << "drawing " << current;

            startX = event->x();
            startY = event->y();

            isDrawing = true;

        }

    }

	// Move
    if (event->button() == Qt::MiddleButton)
	{
        if (!boxes.isEmpty()) {

            QPoint mouseOrigin = mapFromGlobal(QCursor::pos());
            QPointF relativeOrigin = mapToScene(mouseOrigin);

            selected = nullptr;

            for (BoundingBox* box : boxes) {
                if ((*box).contains(QPoint(relativeOrigin.x(), relativeOrigin.y()))) {

                    selected = box;
                    qDebug() << "Selected " << selected->name;

                    isMoving = true;
                    moveRect = box;

                    return;
                }
            }

            qDebug() << "No Item Under Mouse";

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

    // Drawing and Resizing
    if (event->button() == Qt::LeftButton && containsImage && (isDrawing || isResizing))
    {
        if(isDrawing && current.isNull()) { return; }

        boxes.pushBack( new BoundingBox(drawRect) );
        (*boxes.back())->colour = QColor(128, 128, 255, 128);
        selected = nullptr;

        // Drawing
        if (isDrawing) {
            (*boxes.back())->name = current;
            isDrawing = false;
        }

        // Resizing
        else {
            (*boxes.back())->name = resizeName;
            isResizing = false;

        }

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

    // Drawing and Resizing
    else if (isDrawing || isResizing)
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

    QPointF start;

    if (isDrawing || isResizing){

        if (isDrawing)
            { start = mapToScene(startX,startY); }

        if(isResizing)
            { start = QPoint(startX,startY); }

        drawRect = QRect(
            start.x(),
            start.y(),
            relativeOrigin.x() - start.x(),
            relativeOrigin.y() - start.y()
        );

        painter->fillRect(drawRect, QBrush(QColor(128, 128, 0, 128)));
        painter->drawRect(drawRect);

    }


	if (!boxes.isEmpty()) {
		for (BoundingBox* box : boxes) {

			painter->drawRect(*box);
            painter->fillRect(*box, QBrush(box->colour));

            // Font Size
            {
                int size;

                if (box->width() > box->height())
                    { size = box->height()/5; }
                else
                    { size = box->width()/5; }

                if (size <=12 )
                    { size = 12; }

                QFont font;
                font.setPixelSize(size);
                painter->setFont(font);
            }



            if (box == selected)
                { painter->fillRect(*box, QColor(128, 128, 0, 128)); }

            painter->drawText(box->topLeft(), box->name);
		}
	}

	_scene->update();
	
	
}

void GraphicsView::openImage(QString file)
{

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

void GraphicsView::keyPressEvent(QKeyEvent* event)
{

    if(event->key() == Qt::Key_Delete && !(selected == nullptr) ){
        qDebug() << "deleting " << selected->name;
        deleteSelected();
    }

}

void GraphicsView::deleteSelected()
{
    for (int i = 0; i < boxes.size(); i++){
        if(boxes[i] == selected){

            boxes.erase(i);

            selected = nullptr;
        }
    }
}




Output::Output(QWidget* parent) : QPushButton(parent)
{

}

void addXML (QTextStream* stream, QString string, bool startTag){

    if(startTag){
        *stream << endl << "<" << string << ">";
    }
    else {
        *stream << "</" << string << ">";
    }

}



void Output::mousePressEvent(QMouseEvent* event)
{

    if (boxes.size() > 0){



        srand(time(NULL));

        std::string randString = std::to_string(rand() % 999999 + 100000);

        QString qs = QString::fromStdString(randString);

        QFile file(qs + ".xml");

        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writing";
            return;
        }
        else
        {
            QTextStream stream(&file);

            stream << "<" << "annotation" << ">" << endl;

            addXML(&stream, "folder", true);
            stream << folderName;
            addXML(&stream, "folder", false);

            addXML(&stream, "filename", true);
            stream << fileName;
            addXML(&stream, "filename", false);

            stream << endl;

            addXML(&stream, "size", true);

            addXML(&stream, "width", true);
            stream << width;
            addXML(&stream, "width", false);

            addXML(&stream, "height", true);
            stream << height;
            addXML(&stream, "height", false);

            stream << endl;

            addXML(&stream, "size", false);

            stream << endl;

            for (BoundingBox* box : boxes)
            {

                addXML(&stream, "bndbox", true); // Start Boundbox tag


                addXML(&stream, "name", true);
                stream << box->name;
                addXML(&stream, "name", false);

                addXML(&stream, "x", true);
                stream << box->x();
                addXML(&stream, "x", false);

                addXML(&stream, "y", true);
                stream << box->y();
                addXML(&stream, "y", false);

                addXML(&stream, "width", true);
                stream << box->width();
                addXML(&stream, "width", false);

                addXML(&stream, "height", true);
                stream << box->height();
                addXML(&stream, "height", false);


                stream << endl;
                addXML(&stream, "bndbox", false); // End Boundbox tag

                stream << endl;

            }

            stream << endl;

            addXML(&stream, "annotation", false);

            file.close();

            qDebug() << "Wrote to file";
            QDesktopServices::openUrl( QUrl::fromLocalFile(QDir::currentPath()) );
        }

    }
    else {
        QMessageBox::warning(this, "title", "No Info to Save");
    }

}


