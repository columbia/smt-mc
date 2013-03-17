#include <dbug/interposition/stubs.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

pthread_mutex_t mutex;
sem_t sem;

void *my_func(void *args) {
  dbug_off();
  fprintf(stderr, "child blocks.\n");
  sem_wait(&sem);
  fprintf(stderr, "child wakes up.\n");
  dbug_on();
}

int main() {
  dbug_off();

  pthread_t t;
  sem_init(&sem, 0, 0);

  dbug_on();
  pthread_create(&t, NULL, my_func, NULL);
  dbug_off();

  fprintf(stderr, "parent exit.\n");
  dbug_on();
  return 0;
}
