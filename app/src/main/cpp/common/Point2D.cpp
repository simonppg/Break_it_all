// Copyright (c) 2022 Simon Puente
#include "Point2D.hpp"

Point2D::Point2D(void) : x(0.0), y(0.0) {}
Point2D::Point2D(float x, float y) : x(x), y(y) {}
Point2D::Point2D(const Point2D &point) : x{point.x}, y{point.y} {}

float Point2D::getX() { return x; }
float Point2D::getY() { return y; }

Point2D Point2D::incrementX(float delta) { return Point2D(x + delta, y); }

Point2D Point2D::decrementX(float delta) { return Point2D(x - delta, y); }

Point2D Point2D::incrementY(float delta) { return Point2D(x, y + delta); }

Point2D Point2D::decrementY(float delta) { return Point2D(x, y - delta); }
