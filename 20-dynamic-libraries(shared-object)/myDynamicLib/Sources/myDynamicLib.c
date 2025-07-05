#include <stdio.h>

#include "../../../20-dynamic-libraries(shared-object)/myDynamicLib/Headers/myLib.h"

void print(void)
{
    printf("\n\nprint() called from a DYNAMIC library\n\n");
}