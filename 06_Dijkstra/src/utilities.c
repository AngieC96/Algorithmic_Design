#include "utilities.h"

void int_printer(const void *value)
{
  printf("%d ", *((const int *)value));
}

void float_printer(const void *value)
{
  printf("%f ", *((const float *)value));
}

double test(void (*dijkstra)(Graph* G, int s), 
            Graph* G, int s, const unsigned int n, 
            const unsigned int rep)
{
  struct timespec requestStart, requestEnd;
  double accum;

  // Collecting time for copy A into B and sorting B
  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t i = 0; i < rep; i++) {
    dijkstra(G, s);
  }
  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;

  double secs = accum / rep;

  return (secs<0?0:secs);
}

void create_random_graph(const unsigned int n) 
{
  FILE *fp = fopen("data/input.txt", "w");
  if(fp == NULL) {
    printf("Error creating file!\n");
    exit(1);
  }

  int S, outNode, inNode, weight;
  srand(10);
  
  S = rand() % n;

  fprintf(fp, "%d %d %d\n", n, n, S);

  for (unsigned int i = 0; i < n; ++i) {
    outNode = rand() % n;
    do {
      inNode = rand() % n;
    } while(inNode == outNode);
    weight = rand() % 20 + 1;
    fprintf(fp, "%d %d %d\n", outNode, inNode, weight);
  }

  fclose(fp);

  return;
}