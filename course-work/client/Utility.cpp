#include "Utility.h"

QPoint getFieldCoord(const QPoint& pos)
{
    QPoint res;
    res.setX(-1);
    res.setY(-1);

    if (pos.x() < FIELD_X || pos.x() > (FIELD_X + FIELD_WIDTH) || pos.y() < FIELD_Y || pos.y() > (FIELD_Y + FIELD_HEIGHT))
    {
        return res;
    }

    res.setX(1.0 * (pos.x() - FIELD_X) / (0.1 * FIELD_WIDTH));

    qDebug() << "X: " << pos.x() - FIELD_X;
    qDebug() << "Y: " << pos.y() - FIELD_Y;

    res.setY(1.0 * (pos.y() - FIELD_Y) / (0.1 * FIELD_HEIGHT));
    return res;
}