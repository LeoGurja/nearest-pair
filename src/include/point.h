#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef POINT_H
#define POINT_H

typedef struct PointStruct
{
  double x, y;
} Point;

#endif

Point *new_point(double x, double y);

double distance(Point *a, Point *b);

char *to_string(Point *p);

int compare_y(const void *a, const void *b);
