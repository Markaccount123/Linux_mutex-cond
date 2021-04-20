#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int ticket = 100;
pthread_mutex_t lock;//大家都要加同一把锁，所以应该让他们都看得见锁，所以锁需要设定为全局变量

void *get_ticket(void *arg)
{
  int num = (int)arg;
  usleep(1000);
  while(1){
    pthread_mutex_lock(&lock);
    if(ticket>0){
      usleep(1000);
      printf("thread %d,get a ticket,no: %d\n",num,ticket);
      ticket--;
      pthread_mutex_unlock(&lock);
    }
    else{
      pthread_mutex_unlock(&lock);
      break;
    }
  }
}

int main()
{
  pthread_t tid[4];
  pthread_mutex_init(&lock,NULL);
  int i = 0;
  for(;i<4;++i)
  {
    pthread_create(tid+i,NULL,get_ticket,(void*)i);
  }
  

  for(i = 0;i<4;++i)
  {
    pthread_join(tid[i],NULL);
  }

  pthread_mutex_destroy(&lock);
  return 0;
}
