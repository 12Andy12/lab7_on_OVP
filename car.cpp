#include "car.h"
/*
Car::Car(QObject *parrent = 0) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;
    setRotation(angle);
}*/

QRectF Car::boundingRect() const
{
    return QRectF(-25, -25,50, 50);
}

void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(QBrush(QColor(0xFF, 0xFE, 0xFF)));
    painter->drawEllipse(QRect(-25, -25,50, 50));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Car::slotGameTimer()
{

}

void Car::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void Car::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Car::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
