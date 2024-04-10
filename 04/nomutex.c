#include <stdio.h>
#include <pthread.h>

#define LOOPS 250
int money = 4000;
int conter=0;

void *ATM1()
{
  for (int i=0; i<LOOPS; i++) {
    money = money - 1;
  }
  return NULL;
}

void *ATM2()
{
  for (int i=0; i<LOOPS; i++) {
    money = money - 1;
  }
  return NULL;
}


int main() 
{
    while(1){
        money = 4000;
        conter++;
        pthread_t thread1, thread2;

        pthread_create(&thread1, NULL, ATM1, NULL);
        pthread_create(&thread2, NULL, ATM2, NULL);

        pthread_join( thread1, NULL);
        pthread_join( thread2, NULL);
        printf("money=%d ::c=%d \n", money ,conter);
        if(money!=3500){
            printf("An error occurred in round %d",conter);
            break;
        }
    }
}