#include "include/nearest_pair.h"

Point **_nearest_pair(Point **points, int begin, int end)
{
  Point **result = (Point **)malloc(sizeof(Point *) * 2);
  double minimum_distance = INFINITY, current_distance;

  if (end - begin <= 1)
    exit(1);

  for (int i = begin; i < end - 1; i++) // só é preciso ir até o penúltimo
    for (int j = i + 1; j < end; j++)   // só é preciso começar a partir de i
    {
      current_distance = distance(points[i], points[j]);
      if (current_distance < minimum_distance)
      {
        minimum_distance = current_distance;
        result[0] = points[i];
        result[1] = points[j];
      }
    }
  return result;
}

Point **nearest_pair(Point **points, int size)
{
  return _nearest_pair(points, 0, size);
}