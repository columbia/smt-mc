#include <dbug/interposition/stubs.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

pthread_mutex_t mutex;
sem_t sem;

void *my_func(void *args) {
  dbug_off();
  

  //dbug_detach();
  dbug_on();
  pthread_mutex_lock(&mutex);  
   pthread_mutex_unlock(&mutex);
  dbug_off();

  dbug_detach();
  fprintf(stderr, "child blocks.\n");
  sem_wait(&sem);
  fprintf(stderr, "child wakes up.\n");
  dbug_on();
}

int main() {
  pthread_mutex_init(&mutex, NULL);
  dbug_off();

  pthread_t t;
  sem_init(&sem, 0, 0);

  dbug_on();
  pthread_create(&t, NULL, my_func, NULL);

pthread_mutex_lock(&mutex);
   pthread_mutex_unlock(&mutex);

  dbug_off();

  fprintf(stderr, "parent exit.\n");
  dbug_on();
  return 0;
}
