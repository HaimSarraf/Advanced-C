#include <stdbool.h>
#include <stdio.h>

//* line styles
#define SOLID 0
#define DOTTED 1
#define DASHED 2

//* primary colors
#define BLUE 4
#define GREEN 2
#define RED 1

//* mixed colors
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colors[8] = {"black", "red",     "green", "yellow",
                         "blue",  "magenta", "cyan",  "white"};

struct box_props {
  bool opaque : 1;
  unsigned int fill_color : 3;
  unsigned int : 4;
  bool show_border : 1;
  unsigned int border_color : 3;
  unsigned int border_style : 2;
  unsigned int : 2;
};

void show_setting(const struct box_props *pb);

int main() {

  //* crate and initialize box_props structure
  struct box_props box = {true, YELLOW, true, GREEN, DASHED};

  printf("Original Box Settings : \n");
  show_setting(&box);

  //* modify the box
  box.opaque = false;
  box.fill_color = WHITE;
  box.border_color = MAGENTA;
  box.border_style = SOLID;

  printf("---------------------------------\n\n");
  printf("Modified Box Settings : \n");
  show_setting(&box);

  return 0;
}

void show_setting(const struct box_props *pb) {
  printf("Box is %s.\n", pb->opaque == true ? "Opaque" : "Transparent");
  printf("The Fill-Color is %s.\n", colors[pb->fill_color]);
  printf("Border is %s.\n", pb->show_border == true ? "Shown" : "Not Shown");
  printf("The Border Color is %s.\n", colors[pb->border_color]);
  printf("The Border Style is ");

  switch (pb->border_style) {
  case SOLID:
    printf("Solid.\n");
    break;
  case DOTTED:
    printf("Dotted.\n");
    break;
  case DASHED:
    printf("Dashed.\n");
    break;
  default:
    printf("Unknown type.\n");
  }
}