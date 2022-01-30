#include "../include/main.h"

Point **read_points(int size)
{
  double x, y;
  Point **points = (Point **)malloc(sizeof(Point *) * size);

  for (int i = 0; i < size; i++)
  {
    scanf("%lf", &x);
    scanf("%lf", &y);
    points[i] = new_point(x, y);
  }
  return points;
}

int main()
{
  int size;
  double start_time, end_time;

  scanf("%d", &size);
  Point **points = read_points(size);

  start_time = get_CPU_time();
  // Point **result = divide_and_conquer_nearest_pair(points, size);
  Point **result = nearest_pair(points, size);
  end_time = get_CPU_time();

  printf("\nsize: %d\n", size);
  printf("result: %s <=> %s\n", to_string(result[0]), to_string(result[1]));
  printf("time: %f\n", end_time - start_time);
  return 0;
}