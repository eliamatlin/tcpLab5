#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <mygraphicview.h>
#include <ctime>
//#include <windows.h>
//#include <dos.h>
//#include <QTimer>
#include <QTime>

Cell c1;
 static int f = 0;
 static bool live = false;
 static bool start = false;
 static int gen;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myPicture = new MyGraphicView();
    ui->Graphics->addWidget(myPicture);
    tmr = new QTimer();

    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Generate()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Start()));
    QObject::connect(tmr,SIGNAL(timeout()), this, SLOT(timer_overflow()));

    connect(myPicture, SIGNAL(MouseMoved()), this, SLOT(MouseM()));
    connect(myPicture, SIGNAL(MousePressed()), this, SLOT(MouseP()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Generate()
{
    int number = 0;
    srand(time(NULL));

    gen = gen%4;

    switch (gen)
    {
    case 0:{
 Array [1][6].alive = Array [1][7].alive = Array [2][6].alive = Array [2][7].alive = Array [6][6].alive = Array [6][7].alive = Array [6][8].alive = Array [7][6].alive = Array [7][7].alive = Array [7][8].alive = true;
  Array [8][5].alive =  Array [8][9].alive =  Array [9][4].alive =  Array [9][10].alive =  Array [10][5].alive =  Array [10][9].alive =  Array [11][6].alive =  Array [11][7].alive =  Array [11][8].alive = true;
   Array [16][5].alive =  Array [16][7].alive =  Array [17][5].alive =  Array [17][8].alive =  Array [18][7].alive = Array [18][8].alive = Array [18][10].alive = Array [20][7].alive = Array [21][7].alive = true;
   Array [21][9].alive = Array [21][10].alive = Array [22][8].alive = Array [25][2].alive = Array [25][3].alive = Array [25][7].alive = Array [25][8].alive= true;
   Array [26][3].alive = Array [26][4].alive = Array [26][5].alive = Array [26][6].alive = Array [26][7].alive = Array[27][3].alive = Array[27][4].alive = Array[27][6].alive = Array[27][7].alive = true;
   Array[28][3].alive = Array[28][4].alive = Array[28][6].alive = Array[28][7].alive = Array[29][4].alive= Array[29][5].alive = Array[29][6].alive = true;
   Array[35][4].alive = Array[35][5].alive = Array[36][4].alive = Array[36][5].alive = true;
    break;
    }
    case 1:
    {
        for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    Array[x][y].alive = false;
                }
             }
        myPicture->Clean();
        Array[15][4].alive = Array[15][5].alive = Array[15][6].alive = Array[15][10].alive = Array[15][11].alive = Array[15][12].alive = Array[17][2].alive = Array[17][7].alive = Array[17][9].alive = Array[17][14].alive = true;
        Array[18][2].alive = Array[18][7].alive = Array[18][9].alive = Array[18][14].alive = Array[19][2].alive = Array[19][7].alive = Array[19][9].alive = Array[19][14].alive = Array[20][4].alive = Array[20][5].alive = Array[20][6].alive = Array[20][10].alive = Array[20][11].alive = Array[20][12].alive = true;
        Array[22][4].alive = Array[22][5].alive = Array[22][6].alive = Array[22][10].alive = Array[22][11].alive = Array[22][12].alive =  Array[23][2].alive = Array[23][7].alive = Array[23][9].alive = Array[23][14].alive = true;
         Array[24][2].alive = Array[24][7].alive = Array[24][9].alive = Array[24][14].alive  =  Array[25][2].alive = Array[25][7].alive = Array[25][9].alive = Array[25][14].alive = Array[27][4].alive = Array[27][5].alive = Array[27][6].alive = Array[27][10].alive = Array[27][11].alive = Array[27][12].alive = true;
    break;
    }
    case 2:
    {
        for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    Array[x][y].alive = false;
                }
             }
        myPicture->Clean();
        for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {

                        int temp = rand() % 2;
                        switch (temp) {
                        case 0: Array[x][y].alive = false;
                            break;
                        case 1:
                        {
                                Array[x][y].alive = true;
                                number++;
                                break;
                        }

                        }

                }
            }
        break;
    }
    case 3:
    {
        for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    Array[x][y].alive = false;
                }
             }
        myPicture->Clean();
        Array[3][3].alive = Array[3][4].alive = Array[3][6].alive = Array[3][7].alive = Array[3][8].alive = Array[3][9].alive = Array[3][10].alive = Array[3][11].alive = true;
        Array[4][3].alive = Array[4][4].alive = Array[4][6].alive = Array[4][7].alive = Array[4][8].alive = Array[4][9].alive = Array[4][10].alive = Array[4][11].alive = true;
        Array[5][3].alive = Array[5][4].alive = Array[6][3].alive = Array[6][4].alive = Array[6][10].alive = Array[6][11].alive = true;
        Array[7][3].alive = Array[7][4].alive = Array[7][10].alive = Array[7][11].alive = Array[8][3].alive = Array[8][4].alive = Array[8][10].alive = Array[8][11].alive = true;
        Array[9][10].alive = Array[9][11].alive =  Array[10][3].alive = Array[10][4].alive = Array[10][4].alive = Array[10][5].alive = Array[10][6].alive = Array[10][7].alive = Array[10][8].alive = Array[10][10].alive = Array[10][11].alive = true;
        Array[11][3].alive = Array[11][4].alive = Array[11][4].alive = Array[11][5].alive = Array[11][6].alive = Array[11][7].alive = Array[11][8].alive = Array[11][10].alive = Array[11][11].alive = true;
        break;
    }
}

gen++;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (Array[x][y].alive == true)
            {
                myPicture->Draw(N, x, y, true);
            }
        }
    }
}

void MainWindow::Start()
{
    start = true;
    tmr->start(100);
}

void MainWindow::NewGeneration(int N)
{
    int neighboors = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (Array[(x-1)%N][(y-1)%N].alive == true)
            {
                neighboors++;
            }
            if (Array[x%N] [(y-1)%N].alive == true) {
                neighboors++;
            }
            if (Array[(x+1)%N][(y-1)%N].alive == true) {
                neighboors++;
            }
            if (Array[(x+1)%N][y%N].alive == true) {
                neighboors++;
            }
            if (Array[(x+1)%N][(y+1)%N].alive == true) {
                neighboors++;
            }
            if (Array[x%N][(y+1)%N].alive == true){
                neighboors++;
            }
            if (Array[(x-1)%N][(y+1)%N].alive == true) {
                neighboors++;
            }
            if (Array[(x-1)%N][y%N].alive == true) {
                neighboors++;
            }

            if (Array[x][y].alive == true)
            {
                switch (neighboors) {
                case 2:
                    Array[x][y].action = true;
                    break;
                case 3:
                    Array[x][y].action = true;
                    break;
                default:
                    Array[x][y].action = false;
                    break;
                }
            }
            else
                switch (neighboors) {
                case 3:
                    Array[x][y].action = true;
                    break;
                default:
                    Array[x][y].action = false;
                    break;
                }
            neighboors = 0;
        }
    }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (Array[x][y].action == true) Array[x][y].alive = true;
                else Array[x][y].alive = false;
            }
        }
}

void MainWindow::timer_overflow()
{
    NewGeneration(N);
        myPicture->Clean();
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (Array[x][y].alive == true)
                {
                    myPicture->Draw(N, x, y, true);
                }
            }
        }
        f++;
        if (f==10000) tmr->stop();
}

void MainWindow::MouseM()
{
    if (start == true) return;
    ui->label->setText(QString("x = %1, y = %2").arg(myPicture->x).arg(myPicture->y));
    myPicture->Clean();
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (Array[x][y].alive == true) live = true;
            else live = false;
            myPicture->Draw(N, x, y, live);
        }
    }
}

void MainWindow::MouseP()
{
    if (start == true) return;
    myPicture->Clean();
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (Array[x][y].alive == true) live = true;
            else live = false;
            int ret = myPicture->Draw(N, x, y, live);
            if (ret == -1)
            {
                if (live == true)
                {
                    Array[x][y].alive = false;
                    live = false;
                }
                else
                {
                    Array[x][y].alive = true;
                    live = true;
                }
            }

        }
    }
for (int y = 0; y < N; y++)
   {
        for (int x = 0; x < N; x++)
        {
            if (Array[x][y].alive == true) live = true;
            else live = false;
            myPicture->Draw(N, x, y, live);
        }
    }
}
