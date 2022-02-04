#include "include/main.h"

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

double test_divide_and_conquer(Point **points, int size)
{
  double start_time = get_CPU_time();
  divide_and_conquer_nearest_pair(points, size);
  double end_time = get_CPU_time();
  return end_time - start_time;
}

double test_nearest_pair(Point **points, int size)
{
  double start_time = get_CPU_time();
  nearest_pair(points, size);
  double end_time = get_CPU_time();
  return end_time - start_time;
}

double test_quick_sort(Point **points, int size)
{
  double start_time = get_CPU_time();
  qsort(points, size, sizeof(Point *), compare_y);
  double end_time = get_CPU_time();
  return end_time - start_time;
}

double average(double *list)
{
  double sum = 0;
  for (int i = 0; i < 5; i++)
  {
    sum += list[i];
  }
  return sum / 5.0;
}

int main()
{
  int size;
  double np_times[5], dcnp_times[5], qs_times[5];
  Point **points;

  scanf("%d", &size);

  for (int i = 0; i < 5; i++)
  {
    points = read_points(size);
    np_times[i] = test_nearest_pair(points, size);
    dcnp_times[i] = test_divide_and_conquer(points, size);
    qs_times[i] = test_quick_sort(points, size);
    free(points);
  }

  printf("%d\t%lf\t%lf\t%lf\n", size, average(np_times), average(dcnp_times), average(dcnp_times) + average(qs_times));
  return 0;
}