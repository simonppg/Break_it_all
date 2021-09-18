#include "CanvasSize.hpp"

CanvasSize::CanvasSize(void) : width(0.0), height(0.0) {}
CanvasSize::CanvasSize(float width, float height) : width(width), height(height) {}

float CanvasSize::getWidth() { return width; }
float CanvasSize::getHeight() { return height; }

float CanvasSize::aspectRatio() {
    return width / height;
}
