#include "ball.h"
#include <random>
#include <QRandomGenerator>
/*
Ball::Ball(QObject *parrent = 0) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;
    setRotation(angle);
}*/


QRectF Ball::boundingRect() const
{
    
    return QRectF(-25, -25,50, 50);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(QBrush(QColor(0xFA, 0xFE, 0x78)));
    painter->drawEllipse(QRectF(-25, -25,50, 50));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

bool mousePress = false;
qreal xx = 3;
qreal yy = 3;
int moveCounter = 0;

void moveReset()
{
    do
    {
        xx = rand()%7-3;
        yy = rand()%7-3;
        moveCounter = 0;
    }while(xx==0 || yy ==0);
}

void Ball::slotGameTimer()
{
    /** Перемещаем треугольник в зависимости от нажатых кнопок
     * */
    if(GetAsyncKeyState('A')){
        this->setX(this->x() - 2);
        /* Проверяем на столкновение,
         * если столкновение произошло,
         * то возвращаем героя обратно в исходную точку
         * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setX(this->x() + 2);
        }
    }
    else if(GetAsyncKeyState('D')){
        this->setX(this->x() + 2);
        /* Проверяем на столкновение,
         * если столкновение произошло,
         * то возвращаем героя обратно в исходную точку
         * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setX(this->x() - 2);
        }
    }
    else if(GetAsyncKeyState('W')){
        this->setY(this->y() - 2);
        /* Проверяем на столкновение,
         * если столкновение произошло,
         * то возвращаем героя обратно в исходную точку
         * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setY(this->y() + 2);
        }
    }
    else if(GetAsyncKeyState('S')){
        this->setY(this->y() + 2);
        /* Проверяем на столкновение,
         * если столкновение произошло,
         * то возвращаем героя обратно в исходную точку
         * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setY(this->y() - 2);
        }
    }
    else {
        QPointF oldPos = this->pos();
        if(!mousePress)
        {
            this->setY(this->y()+ 2*xx);
            this->setX(this->x()+ 2*yy);
            moveCounter++;
        }

        if(moveCounter == 120)
        {
            moveReset();
        }
        if(!scene()->collidingItems(this).isEmpty())
        {
            this->setPos(oldPos);
            moveReset();
        }

    }
}

void Ball::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    QPointF oldPos = this->pos();
    this->setPos(mapToScene(event->pos()));
    if(!scene()->collidingItems(this).isEmpty()){
        this->setPos(oldPos);
        moveReset();
    }
}

void Ball::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    mousePress = true;
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Ball::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    mousePress = false;
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
