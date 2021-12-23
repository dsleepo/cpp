#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cmath>
#include <QPainter>

const short int circleSize = 3;
const short int rectangleSize = 4;
const short int coordinatesSize = 3;

class Field;

class Box {
public:
    double one_x;
    double one_y;
    double two_x;
    double two_y;
    double three_x;
    double three_y;
    double four_x;
    double four_y;

    double minX();
    double minY();
    double maxX();
    double maxY();

    void debug();
};

class Figure {
protected:
    double *geometry;
    double *speed;
    double angle = 0;

public:
    virtual void move(double dt, Field *field) = 0;

    virtual Box* rotate() = 0;

    virtual void draw(QPainter *painter) = 0;

    virtual std::ostream& format(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure* c);

    virtual ~Figure() {};
};

std::ostream& operator<<(std::ostream& os, const Figure* c);

class Circle : public Figure {
public:
    Circle(double x, double y, double radius);

    ~Circle();

    virtual void move(double dt, Field *field) override;

    virtual Box* rotate() override;

    virtual void draw(QPainter *painter) override;

    virtual std::ostream& format(std::ostream& os) const override;
};

class Rectangle: public Figure {
public:
    Rectangle(double x, double y, double width, double height);

    ~Rectangle();

    virtual void move(double dt, Field *field) override;

    virtual Box* rotate() override;

    virtual void draw(QPainter *painter) override;

    virtual std::ostream& format(std::ostream& os) const override;
};

class Field {
    const int sideSize = 100;
    const int figuresN = 0;
    const int maxSideSize = 30;
    const int step = 10;
    int rectangles = 0;
    int circles = 0;
    double x0 = 0;
    double y0 = 0;

    Figure** figures;

    double dt = 0.1;
    double prob = 0.5;

public:

    Field(const short int fSize = 100);

    ~Field();

    void print();

    void tick();

    void draw(QPainter *painter);

    double getX0();

    double getY0();

    short int getSideSize();

    int getFiguresN();

    int getRectanglesN();

    int getCirclesN();

    QString* statistic();
};

#endif // FIGURE_H
