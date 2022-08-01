#ifndef COMMON_POINT2D_HPP
#define COMMON_POINT2D_HPP

class Point2D {
public:
    Point2D(void);
    Point2D(float x, float y);
    Point2D(const Point2D &point);

    float getX();
    float getY();

    Point2D incrementX(float delta);
    Point2D decrementX(float delta);
    Point2D incrementY(float delta);
    Point2D decrementY(float delta);
private:
    float x, y;
};

#endif // COMMON_POINT2D_HPP
