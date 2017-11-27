#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QMouseEvent>
#include <QEvent>

struct Coor;

class MyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicView(QWidget *parent = 0);
    ~MyGraphicView();

    int Draw (int S, int x, int y, bool l);
    void Clean();

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);

    int x, y;

private:
    QGraphicsScene      *scene;

signals:
    void MouseMoved();
    void MousePressed();
};

#endif // MYGRAPHICVIEW_H
