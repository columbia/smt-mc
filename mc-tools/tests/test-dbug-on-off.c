#include <dbug/interposition/stubs.h>
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
pthread_mutex_t mutex2;

void *my_func(void *args) {
  //dbug_off();
  pthread_mutex_lock(&mutex);
  printf("child %ld\n", (long)args);
  pthread_mutex_unlock(&mutex);  
  //dbug_on();
  pthread_mutex_lock(&mutex2);
  pthread_mutex_unlock(&mutex2);
}

int main() {
  const int nt = 2;
  pthread_t t[nt];
  pthread_mutex_init(&mutex, NULL);
  pthread_mutex_init(&mutex2, NULL);
  for (int i = 0; i < nt; i++)
    pthread_create(&t[i], NULL, my_func, (void *)i);
  //dbug_off();
  pthread_mutex_lock(&mutex);
  printf("parent\n");
  pthread_mutex_unlock(&mutex);
  //dbug_on();
  for (int i = 0; i < nt; i++)
    pthread_join(t[i], NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}
