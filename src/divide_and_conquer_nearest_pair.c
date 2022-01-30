#include "../include/divide_and_conquer_nearest_pair.h"

Point **_divide_and_conquer_nearest_pair(Point **points, int begin, int end)
{
  int size = end - begin;

  if (size <= 1)
    exit(2);

  if (size <= 3)
    return _nearest_pair(points, begin, end);

  int division_index = begin + end / 2;

  Point **left_pair = _divide_and_conquer_nearest_pair(points, begin, division_index),
        **right_pair = _divide_and_conquer_nearest_pair(points, division_index, end);
  double delta_left = distance(left_pair[0], left_pair[1]),
         delta_right = distance(right_pair[0], right_pair[1]);

  double delta = MIN(delta_left, delta_right),
         join_middle = (left_pair[1]->x + right_pair[0]->x) / 2;
  int lower_index = division_index, upper_index = division_index;

  for (lower_index = division_index; lower_index > begin; lower_index--)
  {
    if (join_middle - points[lower_index]->x > delta)
      break;
  }

  for (upper_index = division_index; upper_index < end; upper_index++)
  {
    if (points[upper_index]->x - join_middle > delta)
      break;
  }

  Point **middle_pair = _divide_and_conquer_nearest_pair(points, lower_index, upper_index);
  if (distance(middle_pair[0], middle_pair[1]) < delta)
    return middle_pair;
  if (delta_left < delta_right)
    return left_pair;
  return right_pair;
}

Point **divide_and_conquer_nearest_pair(Point **points, int size)
{
  sort_by_x(points, 0, size);
  return _divide_and_conquer_nearest_pair(points, 0, size);
}