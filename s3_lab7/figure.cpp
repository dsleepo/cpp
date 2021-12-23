#include "figure.h"
#include <algorithm>
#include <QPainter>

const int drawSizeMultiplier = 4;

bool compMin(double a, double b)
{
    return a < b;
}

bool compMax(double a, double b)
{
    return a < b;
}

double Box::minX()
{
    return std::min({ one_x, two_x, three_x, four_x }, compMin);
}

double Box::maxX()
{
    return std::max({ one_x, two_x, three_x, four_x }, compMin);
}

double Box::minY()
{
    return std::min({ one_y, two_y, three_y, four_y }, compMax);
}

double Box::maxY()
{
    return std::max({ one_y, two_y, three_y, four_y }, compMax);
}

void Box::debug()
{
    qDebug("one: [%f, %f], two: [%f, %f], three: [%f, %f], four: [%f, %f], minX: %f, maxX: %f, minY: %f, maxY: %f",
           one_x, one_y, two_x, two_y, three_x, three_y, four_x, four_y, minX(), maxX(), minY(), maxY());
}

std::ostream& operator<<(std::ostream& os, const Figure* c)
{
    return c->format(os);
}

Circle::Circle(double x, double y, double radius)
{
    geometry = new double[circleSize];
    geometry[0] = x;
    geometry[1] = y;
    geometry[2] = radius;

    speed = new double[coordinatesSize];
    speed[0] = 0.15 * 20;
    speed[1] = 0.2 * 20;
    speed[2] = 0.1;
}

Circle::~Circle()
{
    delete[] geometry;
    delete[] speed;
}

void Circle::move(double dt, Field *field)
{
    geometry[0] += speed[0] * dt;
    geometry[1] += speed[1] * dt;
    angle += speed[2] * dt;

    Box* box = rotate();

    if (box->maxX() > field->getX0() + field->getSideSize()) {
        speed[0] = -speed[0];
        speed[2] = -speed[2];
    }

    if (box->maxY() > field->getY0() + field->getSideSize()) {
        speed[1] = -speed[1];
        speed[2] = -speed[2];
    }

    if (box->minX() < field->getX0()) {
        speed[0] = -speed[0];
        speed[2] = -speed[2];
    }

    if (box->minY() < field->getY0()) {
        speed[1] = -speed[1];
        speed[2] = -speed[2];
    }

    delete box;
}

Box* Circle::rotate()
{
    return new Box{
        geometry[0] - geometry[2], // tl
        geometry[1] - geometry[2],

        geometry[0] + geometry[2], // tr
        geometry[1] - geometry[2],

        geometry[0] + geometry[2], // br
        geometry[1] + geometry[2],

        geometry[0] - geometry[2], // bl
        geometry[1] + geometry[2],
    };
}

void Circle::draw(QPainter *painter)
{
    painter->drawEllipse(
        (geometry[0] - geometry[2]) * drawSizeMultiplier,
        (geometry[1] - geometry[2]) * drawSizeMultiplier,
        geometry[2] * 2 * drawSizeMultiplier,
        geometry[2] * 2 * drawSizeMultiplier
    );
}

std::ostream& Circle::format(std::ostream& os) const
{
    os << "c\tx=" << geometry[0] << "\ty=" << geometry[1] << "\tr=" << geometry[2];
    return os;
}

Rectangle::Rectangle(double x, double y, double width, double height) {
    geometry = new double[rectangleSize];
    geometry[0] = x;
    geometry[1] = y;
    geometry[2] = width;
    geometry[3] = height;

    speed = new double[coordinatesSize];
    speed[0] = 0.1 * 10;
    speed[1] = 0.4 * 10;
    speed[2] = 0.1;
}

Rectangle::~Rectangle()
{
    delete[] geometry;
    delete[] speed;
}

void Rectangle::move(double dt, Field *field)
{
    geometry[0] += speed[0] * dt;
    geometry[1] += speed[1] * dt;
    angle += speed[2] * dt;

    Box* box = rotate();

    if (box->maxX() > field->getX0() + field->getSideSize()) {
        speed[0] = -speed[0];
        speed[2] = -speed[2];
    }

    if (box->maxY() > field->getY0() + field->getSideSize()) {
        speed[1] = -speed[1];
        speed[2] = -speed[2];
    }

    if (box->minX() < field->getX0()) {
        speed[0] = -speed[0];
        speed[2] = -speed[2];
    }

    if (box->minY() < field->getY0()) {
        speed[1] = -speed[1];
        speed[2] = -speed[2];
    }

    delete box;
}

Box* Rectangle::rotate()
{
    // координаты от начала оси координат
    double tl_x, tl_y, tr_x, tr_y, br_x, br_y, bl_x, bl_y;

    tl_x = geometry[0] - geometry[2] / 2;
    tl_y = geometry[1] - geometry[3] / 2;

    tr_x = tl_x + geometry[2];
    tr_y = tl_y;

    br_x = tr_x;
    br_y = tr_y + geometry[3];

    bl_x = tl_x;
    bl_y = tl_y + geometry[3];

    // координаты от центра фигуры
    double s_tl_x, s_tl_y, s_tr_x, s_tr_y, s_br_x, s_br_y, s_bl_x, s_bl_y;

    s_tl_x = geometry[0] - tl_x;
    s_tl_y = geometry[1] - tl_y;

    s_tr_x = geometry[0] - tr_x;
    s_tr_y = geometry[1] - tr_y;

    s_br_x = geometry[0] - br_x;
    s_br_y = geometry[1] - br_y;

    s_bl_x = geometry[0] - bl_x;
    s_bl_y = geometry[1] - bl_y;

    // повернутые от центра фигуры
    double r_tl_x, r_tl_y, r_tr_x, r_tr_y, r_br_x, r_br_y, r_bl_x, r_bl_y;

    r_tl_x = s_tl_x * cos(angle) - s_tl_y * sin(angle);
    r_tl_y = s_tl_x * sin(angle) + s_tl_y * cos(angle);

    r_tr_x = s_tr_x * cos(angle) - s_tr_y * sin(angle);
    r_tr_y = s_tr_x * sin(angle) + s_tr_y * cos(angle);

    r_br_x = s_br_x * cos(angle) - s_br_y * sin(angle);
    r_br_y = s_br_x * sin(angle) + s_br_y * cos(angle);

    r_bl_x = s_bl_x * cos(angle) - s_bl_y * sin(angle);
    r_bl_y = s_bl_x * sin(angle) + s_bl_y * cos(angle);


    // повернуты от начала оси координат
    double t_tl_x, t_tl_y, t_tr_x, t_tr_y, t_br_x, t_br_y, t_bl_x, t_bl_y;

    t_tl_x = geometry[0] + r_tl_x;
    t_tl_y = geometry[1] + r_tl_y;

    t_tr_x = geometry[0] + r_tr_x;
    t_tr_y = geometry[1] + r_tr_y;

    t_br_x = geometry[0] + r_br_x;
    t_br_y = geometry[1] + r_br_y;

    t_bl_x = geometry[0] + r_bl_x;
    t_bl_y = geometry[1] + r_bl_y;

    return new Box{
        t_tl_x,
        t_tl_y,
        t_tr_x,
        t_tr_y,
        t_br_x,
        t_br_y,
        t_bl_x,
        t_bl_y,
    };
}

void Rectangle::draw(QPainter *painter)
{
    Box* box = rotate();

    const QPoint r_points[4] = {
        QPoint(box->one_x * drawSizeMultiplier, box->one_y * drawSizeMultiplier),
        QPoint(box->two_x * drawSizeMultiplier, box->two_y * drawSizeMultiplier),
        QPoint(box->three_x * drawSizeMultiplier, box->three_y * drawSizeMultiplier),
        QPoint(box->four_x * drawSizeMultiplier, box->four_y * drawSizeMultiplier),
    };

    painter->drawPolygon(r_points, 4);

    delete box;
}

std::ostream& Rectangle::format(std::ostream& os) const {
    os << "r\t x=" << geometry[0] << "\t y=" << geometry[1] << "\t w=" << geometry[2] << "\t h=" << geometry[3]
       << "\t alpha=" << angle << "\t vx=" << speed[0] << "\t vy=" << speed[1] << "\t omega=" << speed[2];
    return os;
}

Field::Field(const short int fSize): figuresN{ fSize }
{
     assert(step <= sideSize);
     assert(maxSideSize <= sideSize);

    double x = x0;
    double y = y0;

    figures = new Figure*[fSize];
    for (short int i{ 0 }; i < fSize; i++) {
        double sideSize = (rand() % (maxSideSize - 1)) + 1;

        if (x - sideSize < 0) {
            x = sideSize;
        }

        if (y - sideSize < 0) {
            y = sideSize;
        }

        if (x + sideSize > sideSize) {
            x = sideSize;
            y += step;
        }

        if (y + sideSize > sideSize) {
            y = sideSize;
        }

        if (rand() % (static_cast<int>(1 / prob))) {
            Figure* c = new Circle(x, y, sideSize);
            figures[i] = c;
            ++circles;
        } else {
            Figure* r = new Rectangle(x, y, sideSize, sideSize);
            figures[i] = r;
            ++rectangles;
        }

        x += step;
    }
}

Field::~Field()
{
     delete[] figures;
}

double Field::getX0()
{
    return x0;
}

double Field::getY0()
{
    return y0;
}

short int Field::getSideSize()
{
    return sideSize;
}

void Field::print()
{
    std::cout << "rectangles: " << rectangles << "\t" << "circles: " << circles << "\r" << std::endl;

    for (int i { 0 }; i < figuresN; i++)
    {
        std::cout << figures[i] << "\r" << std::endl;
    }
}

void Field::tick()
{
    for (int i{ 0 }; i < figuresN; i++)
    {
        figures[i]->move(dt, this);
    }
}

void Field::draw(QPainter *painter)
{
    painter->fillRect(x0, y0, sideSize * drawSizeMultiplier, sideSize * drawSizeMultiplier, Qt::red);

    for (int i{ 0 }; i < figuresN; i++)
    {
        figures[i]->draw(painter);
    }
}

int Field::getFiguresN()
{
    return figuresN;
}

int Field::getRectanglesN()
{
    return rectangles;
}

int Field::getCirclesN()
{
    return circles;
}
