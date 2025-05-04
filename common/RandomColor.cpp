#include "RandomColor.h"
#include <QRandomGenerator>
#include <QColor>

QString getRandomColorString() {
    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int b = QRandomGenerator::global()->bounded(256);
    QColor color(r, g, b);
    return color.name();  // "#RRGGBB"
}
