#include "mainwindow.h"
#include "math.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <iostream>
#include "figure.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
    timer->start(10);

    const int figures = 13;

    field = new Field{ figures };
    field->print();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    static int i{ 0 };

    Q_UNUSED(e);
    QPainter painter(this);

    field->tick();
    field->draw(&painter);

    ui->labelNew->setText(
        QString("Figures: %1\nRectangles: %2\nCircles: %3")
                .arg(field->getFiguresN())
                .arg(field->getRectanglesN())
                .arg(field->getCirclesN())
    );

    if (++i % 100 == 0) {
        field->print();
    }
}
