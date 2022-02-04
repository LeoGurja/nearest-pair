#include "include/divide_and_conquer_nearest_pair.h"

double combine_middle(Point **points, int size, double delta)
{
  double minimum_distance = delta, current_distance;

  qsort(points, size, sizeof(Point *), compare_y);

  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size && (points[j]->y - points[i]->y) < minimum_distance; j++)
    {
      current_distance = distance(points[i], points[j]);

      if (current_distance < minimum_distance)
        minimum_distance = current_distance;
    }

  return minimum_distance;
}

double _divide_and_conquer_nearest_pair(Point **points, int begin, int end)
{
  int size = end - begin;

  // base case
  if (size <= 3)
    return _nearest_pair(points, begin, end);

  // divide
  int division_index = (begin + end) / 2;

  // conquer
  double delta_left = _divide_and_conquer_nearest_pair(points, begin, division_index),
         delta_right = _divide_and_conquer_nearest_pair(points, division_index, end),
         delta = MIN(delta_left, delta_right);

  // combine
  Point **middle_section = (Point **)malloc(sizeof(Point *) * size);
  int middle_section_size = 0;

  for (int i = begin; i < end; i++)
    if (abs(points[i]->x - points[division_index]->x) < delta)
      middle_section[middle_section_size++] = points[i];

  return MIN(combine_middle(middle_section, middle_section_size, delta), delta);
}

double divide_and_conquer_nearest_pair(Point **points, int size)
{
  return _divide_and_conquer_nearest_pair(points, 0, size);
}