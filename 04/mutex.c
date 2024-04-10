#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
#define LOOPS 250
int money = 4000;

void *ATM1()
{
  for (int i=0; i<LOOPS; i++) {
    pthread_mutex_lock( &mutex1 );
    money = money - 1;
    pthread_mutex_unlock( &mutex1 );
  }
  return NULL;
}

void *ATM2()
{
  for (int i=0; i<LOOPS; i++) {
    pthread_mutex_lock( &mutex1 );
    money = money - 1;
    pthread_mutex_unlock( &mutex1 );
  }
  return NULL;
}


int main() 
{
    int conter=0;
    while(1){
        money = 4000;
        conter++;
	    pthread_t thread1, thread2;

	    pthread_create(&thread1, NULL, ATM1, NULL);
        pthread_create(&thread2, NULL, ATM2, NULL);

        pthread_join( thread1, NULL);
        pthread_join( thread2, NULL);
        printf("money=%d ::c=%d \n", money ,conter);
        if(conter==100000){
            printf("No errors occurred in a total of %d rounds of testing",conter);
            break;
        }
    }
}