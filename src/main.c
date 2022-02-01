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

double test_quick_sort(int size)
{
  double *list = (double *)malloc(sizeof(double) * size);
  double start_time, end_time;

  for (int i = 0; i < size; i++)
    scanf("%lf", &list[i]);

  start_time = get_CPU_time();
  quicksort(list, 0, size - 1);
  end_time = get_CPU_time();

  return end_time - start_time;
}

double test_divide_and_conquer(int size)
{
  double start_time, end_time;
  Point **points = read_points(size);
  start_time = get_CPU_time();
  divide_and_conquer_nearest_pair(points, size);
  end_time = get_CPU_time();
  return end_time - start_time;
}

double test_nearest_pair(int size)
{
  double start_time, end_time;
  Point **points = read_points(size);
  start_time = get_CPU_time();
  nearest_pair(points, size);
  end_time = get_CPU_time();
  return end_time - start_time;
}

int main()
{
  int size;
  double time;

  scanf("%d", &size);
  time = test_nearest_pair(size);
  // time = test_divide_and_conquer(size);
  // time = test_quick_sort(size);

  printf("%d\t%lf\n", size, time);
  return 0;
}