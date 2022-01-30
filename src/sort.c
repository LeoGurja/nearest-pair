#include "../include/sort.h"

void swap(Point **points, int i, int j)
{
  printf("item swapped: %s <=> %s\n", to_string(points[i]), to_string(points[j]));
  Point *temp = points[i];
  points[i] = points[j];
  points[j] = temp;
}

int partition_by_x(Point **points, int left, int right)
{
  left--;
  Point *pivot = points[right];

  while (true)
  {
    while (points[++left]->x < pivot->x)
    {
    }
    while (right > 0 && points[--right]->x > pivot->x)
    {
    }

    if (left >= right)
      break;
    else
      swap(points, left, right);
  }

  printf("swapping pivot:\n");
  swap(points, left, right);
  return left;
}

int partition_by_y(Point **points, int left, int right)
{
  left--;
  Point *pivot = points[right];

  while (true)
  {
    while (points[++left]->y < pivot->y)
    {
    }
    while (right > 0 && points[--right]->y > pivot->y)
    {
    }

    if (left >= right)
      break;
    else
      swap(points, left, right);
  }

  printf("swapping pivot:\n");
  swap(points, left, right);
  return left;
}

void sort_by_x(Point **points, int left, int right)
{
  if (right - left <= 0)
    return;

  int pivot = partition_by_x(points, left, right);
  sort_by_x(points, left, pivot - 1);
  sort_by_x(points, pivot + 1, right);
}

void sort_by_y(Point **points, int left, int right)
{
  if (right - left <= 0)
    return;

  int pivot = partition_by_y(points, left, right);
  sort_by_y(points, left, pivot - 1);
  sort_by_y(points, pivot + 1, right);
}