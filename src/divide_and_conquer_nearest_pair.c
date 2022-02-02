#include "include/divide_and_conquer_nearest_pair.h"

Point **_divide_and_conquer_nearest_pair(Point **points, int begin, int end)
{
  int size = end - begin;

  if (size <= 1)
    return NULL;

  if (size <= 3)
    return _nearest_pair(points, begin, end);

  int division_index = (begin + end) / 2;

  Point **left_pair = _divide_and_conquer_nearest_pair(points, begin, division_index),
        **right_pair = _divide_and_conquer_nearest_pair(points, division_index, end),
        **pair;
  double delta_left = distance(left_pair[0], left_pair[1]),
         delta_right = distance(right_pair[0], right_pair[1]),
         delta;

  if (delta_left > delta_right)
  {
    pair = right_pair;
    delta = delta_right;
    free(left_pair);
  }
  else
  {
    pair = left_pair;
    delta = delta_left;
    free(right_pair);
  }

  double middle_x = (points[division_index]->x + points[division_index + 1]->x) / 2,
         lower_bound = middle_x - delta,
         upper_bound = middle_x + delta;

  int lower_index, upper_index;

  for (lower_index = division_index; lower_index > begin && points[lower_index]->x >= lower_bound; lower_index--)
  {
  }

  for (upper_index = division_index; upper_index < end && points[upper_index]->x <= upper_bound; upper_index++)
  {
  }

  Point **middle_pair = _divide_and_conquer_nearest_pair(points, lower_index + 1, upper_index);
  if (middle_pair != NULL && distance(middle_pair[0], middle_pair[1]) < delta)
  {
    free(pair);
    return middle_pair;
  }
  else
  {
    free(middle_pair);
    return pair;
  }
}

Point **divide_and_conquer_nearest_pair(Point **points, int size)
{
  return _divide_and_conquer_nearest_pair(points, 0, size);
}