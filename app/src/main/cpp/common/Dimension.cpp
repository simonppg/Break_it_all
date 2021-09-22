#include "Dimension.hpp"

Dimension::Dimension(void) : width(0.0), height(0.0) {}
Dimension::Dimension(float width, float height) : width(width), height(height) {}

float Dimension::getWidth() { return width; }
float Dimension::getHeight() { return height; }

float Dimension::aspectRatio() {
    return width / height;
}
