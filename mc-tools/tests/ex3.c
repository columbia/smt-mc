#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_mutex_t mutex2;

void *
thread(void *args)
{
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
 

  pthread_exit(0);
}

int 
main(int argc, char *argv[])
{
  const int nt = 1;
  //return 0;
  int i;
  pthread_t tid[nt];
  assert(pthread_mutex_init(&mutex,NULL) == 0);

  assert(pthread_mutex_init(&mutex2,NULL) == 0);

  for (i = 0; i < nt; i++)
    assert(pthread_create(&tid[i],NULL,thread,NULL) == 0);

  assert(pthread_mutex_lock(&mutex2) == 0);
  printf("Critical section master.\n");
  assert(pthread_mutex_unlock(&mutex2) == 0);

    //sleep(10);
  for (i = 0; i < nt; i++)
    assert(pthread_join(tid[i], NULL) == 0);

  assert(pthread_mutex_destroy(&mutex) == 0);
  return 0;
}

