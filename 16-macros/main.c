#include <stdio.h>

#define PI 3.14
#define CIRCLE_AREA(x) ((PI) * (x) * (x))

double circleArea(double x);

int main() {

  int c = 5;

  int area = CIRCLE_AREA(c + 2);
  // area = ((3.14) * (c+2) * (c+2));

  printf("in MACROS  , Area is %d\n", area);
  printf("in FUNCTION, Area is %f\n", circleArea((int)c + 2));

  return 0;
}

double circleArea(double x) { return 3.14 * x * x; }