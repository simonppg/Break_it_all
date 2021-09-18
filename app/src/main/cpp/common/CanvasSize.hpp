#ifndef BREAK_IT_ALL_CANVASSIZE_H
#define BREAK_IT_ALL_CANVASSIZE_H

class CanvasSize {
public:
    CanvasSize(void);
    CanvasSize(float width, float height);

    float getWidth();
    float getHeight();
    float aspectRatio();

private:
    const float width, height;
};

#endif //BREAK_IT_ALL_CANVASSIZE_H
