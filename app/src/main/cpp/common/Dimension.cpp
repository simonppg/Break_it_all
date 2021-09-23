#include "Dimension.hpp"

Dimension::Dimension(void) : width(450.0f), height(800.0f) {}
Dimension::Dimension(float width, float height) : width(width), height(height) {}

float Dimension::getWidth() { return width; }
float Dimension::getHeight() { return height; }

float Dimension::aspectRatio() {
    return width / height;
}
