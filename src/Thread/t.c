#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

void *printTask(void *arg) {
  int i;

  for (i = 0; i < 10; i++) {
    pthread_mutex_lock(&lock);
    printf("%s", (char *)arg);
    pthread_mutex_unlock(&lock);
  }
}

int main(void) {
  int err;
  char *msg1 = "A";
  char *msg2 = "B";
  char *msg3 = "C";
  pthread_t tids[3];
  
  err = pthread_create(&tids[0], NULL, printTask, (void *)msg1);
  err = pthread_create(&tids[1], NULL, printTask, (void *)msg2);
  err = pthread_create(&tids[2], NULL, printTask, (void *)msg3);
  
  int i;
  for (i = 0; i < 3; i++) {
    pthread_join(tids[i], NULL);
  }
  pthread_mutex_destroy(&lock);
   
  return 0;
}
