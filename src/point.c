#include "include/point.h"

Point *new_point(double x, double y)
{
  Point *p = (Point *)malloc(sizeof(Point));
  p->x = x;
  p->y = y;
  return p;
}

double distance(Point *a, Point *b)
{
  return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

char *to_string(Point *p)
{
  char *string = (char *)malloc(sizeof(char) * 50);
  sprintf(string, "(%.2f,%.2f)", p->x, p->y);
  return string;
}

int compare_y(const void *a, const void *b)
{
  Point *p1 = *(Point **)a, *p2 = *(Point **)b;
  return (p1->y - p2->y);
}
