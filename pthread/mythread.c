#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
void *thread_run(void* arg)
{
  pthread_detach(pthread_self());
  while(1){
    printf("%s,%lu,pid : %d\n",(char*)arg,pthread_self(),getpid());
    sleep(1);
    break;
  }
  int a = 10;
  a /= 0;
  return (void*)10;
}

int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,thread_run,"thread 1");


  printf("main : %lu,pid : %d\n",pthread_self(),getpid());
  sleep(3);

  
  
  void* ret = NULL;
  printf("thread quit code :%d\n",(long long)ret);//对于云服务器是x64平台，所以需要8位
  return 0;
}
