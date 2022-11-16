#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include "ball.h"
#include "car.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->resize(600,600);
    this->setFixedSize(620,670);
    QGraphicsScene *scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    //Car *car = new Car();
    Ball *ball = new Ball();
    //Ball *ball2 = new Ball();
    //Car car = new Car;
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0,0,600,600);
    scene->addRect(0,0,600,10,QPen(Qt::NoPen),QBrush(Qt::darkRed));
    scene->addRect(0,590,600,10,QPen(Qt::NoPen),QBrush(Qt::darkRed));
    scene->addRect(590,0,10,600,QPen(Qt::NoPen),QBrush(Qt::darkGreen));
    scene->addRect(0,0,10, 600,QPen(Qt::NoPen),QBrush(Qt::darkGreen));
    QPixmap pixCar("C:\\Users\\Andrey\\source\\repos\\Lab7CarAndBoll\\car.png");
    car=scene->addPixmap(pixCar.scaledToWidth(300));
    car->setPos(130,170);
    car->setFlags(QGraphicsItem::ItemIsMovable);
    car->setZValue(1);
    car->setData(0,"Car");
    car->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    QPixmap pixwheel1("C:\\Users\\Andrey\\source\\repos\\Lab7CarAndBoll\\koleso.png");
    wheel1=scene->addPixmap(pixwheel1.scaledToWidth(45));
    wheel1->setPos(158,205);
    wheel1->setFlags(QGraphicsItem::ItemIsMovable);
    wheel1->setZValue(1);
    wheel1->setData(0,"Car");
    wheel1->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);

    QPixmap pixwheel2("C:\\Users\\Andrey\\source\\repos\\Lab7CarAndBoll\\koleso.png");
    wheel2=scene->addPixmap(pixwheel2.scaledToWidth(45));
    wheel2->setPos(340,205);
    wheel2->setFlags(QGraphicsItem::ItemIsMovable);
    wheel2->setZValue(1);
    wheel2->setData(0,"Car");
    wheel2->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    ball->setPos(300,300);
    //->setPos(200,200);
    //car->setPos(100,100);
    scene->addItem(ball);
    //scene->addItem(ball2);
    //scene->addItem(car);
    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, ball, &Ball::slotGameTimer);
   // connect(timer, &QTimer::timeout, car, &Car::slotGameTimer);
    timer->start(1000/50);
}

MainWindow::~MainWindow()
{
    delete ui;
}
