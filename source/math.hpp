#include "math.h"

// math helpers -------------------------------------
int constrain(int val, int min, int max) {
  return std::max(std::min(val, max), min);
}

bool pointInRectangle(int px, int py, int x1, int y1, int x2, int y2) {
  return (px > x1 && px < x2 && py > y1 && py < y2);
}

int dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

float distanceToLine(int px, int py, int x1, int y1, int x2, int y2) {
  float A = px - x1;
  float B = py - y1;
  float C = x2 - x1;
  float D = y2 - y1;

  float dot = A * C + B * D;
  float len_sq = C * C + D * D;
  float param = -1;

  if (len_sq != 0) {
    param = dot / len_sq;
  }

  float xx, yy;

  if (param < 0) {
    xx = x1;
    yy = y1;
  } else if (param > 1) {
    xx = x2;
    yy = y2;
  } else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  float dx = px - xx;
  float dy = py - yy;

  return sqrt(dx * dx + dy * dy);
}