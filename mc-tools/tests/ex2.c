#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "tern/user.h"
#include <dbug/stubs.h>

pthread_mutex_t mutex;
pthread_mutex_t mutex2;
pthread_barrier_t bar;

const int nt = 3;

void *
thread(void *args)
{
dbug_off();
  //assert(pthread_mutex_lock(&mutex) == 0);
  //printf("Critical section slave.\n");
  //assert(pthread_mutex_unlock(&mutex) == 0);

dbug_on();
  pcs_enter();
  int n = 0;
  //for (n = 0; n < 2; n++) {
    printf("\n\n\n\n\n\n\n\n\n============== start non-det self %u  =====================\n\n", (unsigned)pthread_self());
    int i = 0;
    //for (i = 0; i < 2; i++) {
      printf("\n\n============== start lock self %u  =====================\n\n", (unsigned)pthread_self());
      assert(pthread_mutex_lock(&mutex2) == 0);
      printf("Critical section slave2.\n");
      assert(pthread_mutex_unlock(&mutex2) == 0);
      printf("\n\n============== end lock self %u  =====================\n\n", (unsigned)pthread_self());
    //}
    printf("\n\n============== end non-det self %u  =====================\n\n\n\n\n\n\n\n\n\n", (unsigned)pthread_self());
  //}
  pcs_exit();
dbug_off_barrier(0, nt);
pthread_barrier_wait(&bar);

dbug_on();
  //pthread_exit(0);
  return NULL;
}

int 
main(int argc, char *argv[])
{
  dbug_off();
  //return 0;
  int i;
  pthread_t tid[nt];
  assert(pthread_mutex_init(&mutex,NULL) == 0);
  pthread_barrier_init(&bar, NULL, nt);

  dbug_on();
  pcs_enter();
  assert(pthread_mutex_init(&mutex2,NULL) == 0);
  pcs_exit();
    dbug_off();

    dbug_on();
  for (i = 0; i < nt; i++)
    assert(pthread_create(&tid[i],NULL,thread,NULL) == 0);
  dbug_off();


    //sleep(10);
  dbug_on();
  for (i = 0; i < nt; i++)
    assert(pthread_join(tid[i], NULL) == 0);
  dbug_off();

  assert(pthread_mutex_destroy(&mutex) == 0);


  dbug_on();
  return 0;
}

