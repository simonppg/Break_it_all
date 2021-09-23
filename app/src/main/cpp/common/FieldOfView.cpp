#include "FieldOfView.hpp"

FieldOfView::FieldOfView(): ncp(0.1f), fcp(100.0f), fov(60.0f) {}

float FieldOfView::getNcp(){ return ncp; }
float FieldOfView::getFcp(){ return fcp; }
float FieldOfView::getFov(){ return fov; }
