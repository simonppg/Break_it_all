#ifndef COMMON_CANVASSIZE_H
#define COMMON_CANVASSIZE_H

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

#endif //COMMON_CANVASSIZE_H
