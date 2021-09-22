#ifndef COMMON_DIMENSION_H
#define COMMON_DIMENSION_H

class Dimension {
public:
    Dimension(void);
    Dimension(float width, float height);

    float getWidth();
    float getHeight();
    float aspectRatio();

private:
    const float width, height;
};

#endif //COMMON_DIMENSION_H
