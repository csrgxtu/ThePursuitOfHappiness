#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s1;
sem_t s2;
sem_t s3;

void *printTask1(void *arg) {
  int i;
  
  for (i = 0; i < 10; i++) {
    sem_wait(&s3);
    printf("%s", (char *)arg);
    sem_post(&s1);
  }
}

void *printTask2(void *arg) {
  int i;

  for (i = 0; i < 10; i++) {
    sem_wait(&s1);
    printf("%s", (char *)arg);
    sem_post(&s2);
  }
}


void *printTask3(void *arg) {
  int i;

  for (i = 0; i < 10; i++) {
    sem_wait(&s2);
    printf("%s", (char *)arg);
    sem_post(&s1);
  }
}

int main(void) {
  int err;
  char *msg1 = "A";
  char *msg2 = "B";
  char *msg3 = "C";
  pthread_t tids[3];
  
  sem_init(&s1, 0, 0); 
  sem_init(&s2, 0, 0); 
  sem_init(&s3, 0, 0); 
  err = pthread_create(&tids[0], NULL, printTask1, (void *)msg1);
  err = pthread_create(&tids[1], NULL, printTask2, (void *)msg2);
  err = pthread_create(&tids[2], NULL, printTask3, (void *)msg3);
  
  int i;
  for (i = 0; i < 3; i++) {
    pthread_join(tids[i], NULL);
  }
   
  return 0;
}
