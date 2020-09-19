#include "utilities.h"

void int_printer(const void *value)
{
  printf("%d ", *((const int *)value));
}

void float_printer(const void *value)
{
  printf("%f ", *((const float *)value));
}