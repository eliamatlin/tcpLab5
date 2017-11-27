#include "mygraphicview.h"
#include <math.h>

static bool pressed = false;
static bool change = false;

MyGraphicView::MyGraphicView(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene( scene );          // Устанавливаем сцену в виджет

    this->setMouseTracking(true);
}

MyGraphicView::~MyGraphicView()
{
}

void MyGraphicView::Clean()
{
    scene->clear();
}

void MyGraphicView::mouseMoveEvent(QMouseEvent *ev)
{
        x = ev->x();
        y = ev->y();
        MouseMoved();
}

void MyGraphicView::mousePressEvent(QMouseEvent *ev)
{
    x = ev->x();
    y = ev->y();
    pressed = true;
    MousePressed();
}

int MyGraphicView::Draw(int S, int x, int y, bool l)
{
    int a = this->width();
    int b = this->height();
    int CellW = a/S;
    int CellH = b/S;
    QPen pen = QPen(Qt::gray);
    QPen pen2 = QPen(Qt::green);

    QBrush brush = QBrush(Qt::lightGray);
    QBrush brush2 = QBrush(Qt::green);
    QPoint *center = new QPoint(0+x*CellW+CellW/2 , 0+y*CellH+CellH/2);

    if (sqrt(pow(center->x() - this->x,2)+pow(center->y() - this->y,2))>CellH/2)
    {
        if (l == true) scene->addRect(0+x*CellW, 0+y*CellH, CellW, CellH, pen, brush);
        return 0;
    }
    else
    {
        if (pressed == false) scene->addRect(0+x*CellW, 0+y*CellH, CellW, CellH, pen, brush2);
        else
        {
            pressed = false;
            return -1;
                //scene->addRect(0+x*CellW, 0+y*CellH, CellW/2, CellH/2, pen, brush2);
        }
        return 0;
    }
}
