#include "include/time.h"

double get_CPU_time()
{
  struct rusage ptempo;

  getrusage(0, &ptempo);

  long seg_CPU = ptempo.ru_utime.tv_sec;
  long useg_CPU = ptempo.ru_utime.tv_usec;

  return (seg_CPU + 0.000001 * useg_CPU) * 1000;
}