#include <dbug/stubs.h>
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
pthread_mutex_t mutex2;

void *my_func(void *args) {
  printf("child %ld start\n", (long)args);
  dbug_off();
  dbug_on();
  pthread_mutex_lock(&mutex);
  printf("child %ld\n", (long)args);
  pthread_mutex_unlock(&mutex);  

  dbug_off();

  pthread_mutex_lock(&mutex2);
  printf("child2 %ld\n", (long)args);
  pthread_mutex_unlock(&mutex2);  

  dbug_on();
}

int main() {
  dbug_off();
  const int nt = 2;
  pthread_t t[nt];

  dbug_on();
  pthread_mutex_init(&mutex, NULL);
  dbug_off();

  pthread_mutex_init(&mutex2, NULL);

  for (int i = 0; i < nt; i++) {
    dbug_on();
    pthread_create(&t[i], NULL, my_func, (void *)i);
    dbug_off();
  }

  dbug_on();
  pthread_mutex_lock(&mutex);
  printf("parent\n");
  pthread_mutex_unlock(&mutex);  
  dbug_off();

  for (int i = 0; i < nt; i++) {
    dbug_on();
    pthread_join(t[i], NULL);
    dbug_off();
  }

  dbug_on();
  pthread_mutex_destroy(&mutex);
  dbug_off();

  dbug_on();
  return 0;
}
