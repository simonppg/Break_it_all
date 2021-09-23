#ifndef COMMON_DIMENSION_H
#define COMMON_DIMENSION_H

class Dimension {
public:
    Dimension(void);
    Dimension(float width, float height);
    Dimension(const Dimension &dimension);

    float getWidth();
    float getHeight();
    float aspectRatio();

private:
    float width, height;
};

#endif //COMMON_DIMENSION_H
