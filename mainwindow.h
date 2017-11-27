#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <mygraphicview.h>

namespace Ui {
class MainWindow;
}

struct Cell
{
    bool alive;
    bool action;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static const int N = 40;
    //static const int M = 40;
    Cell Array[N][N] = {{false}};

    void NewGeneration(int N);
    QTimer* tmr;
    //bool& operator[](int a);
    bool& insteadofoperator(int a, int b);

    MyGraphicView* myPicture;

private slots:
    void Generate();
    void timer_overflow();
    void Start();
    void MouseM();
    void MouseP();

private:
    Ui::MainWindow *ui;
    struct Cell;
};

#endif // MAINWINDOW_H
