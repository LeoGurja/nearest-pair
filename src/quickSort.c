#include "../include/quickSort.h"

void swap(Point **points, int i, int j)
{
  printf("item swapped: %s <=> %s\n", to_string(points[i]), to_string(points[j]));
  Point *temp = points[i];
  points[i] = points[j];
  points[j] = temp;
}

int partition(Point **points, int left, int right)
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

void quickSort(Point **points, int left, int right)
{
  if (right - left <= 0)
    return;

  int pivot = partition(points, left, right);
  quickSort(points, left, pivot - 1);
  quickSort(points, pivot + 1, right);
}