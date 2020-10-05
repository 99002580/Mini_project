#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>
#include<string.h>
sem_t mutex; 

struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message;

void* thread(void* arg) 
{ 
	key_t key; 
	int msgid;

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 
	message.mesg_type = 1; 

	//wait 
	sem_wait(&mutex); 
/*********************************************************************/
	int ch;

printf("enter your order\n1-Margherita\n2-Double Cheese Margherita\n3-PANEER MAKHANI\n4-CHEESE N CORN\n");
scanf("%d",&ch);
if(ch==1)
{
strcpy(message.mesg_text,"margherita");
msgsnd(msgid, &message, sizeof(message),0);
printf("your order is : %s \n",message.mesg_text);
}
if(ch==2)
{
strcpy(message.mesg_text,"Double Cheese Margherita");
msgsnd(msgid, &message, sizeof(message),0);
printf("your order is : %s \n",message.mesg_text);
}
if(ch==3)
{
strcpy(message.mesg_text,"panner makhani");
msgsnd(msgid, &message, sizeof(message),0);
printf("your order is : %s \n",message.mesg_text);
}
if(ch==4)
{
strcpy(message.mesg_text,"cheese n corn");
msgsnd(msgid, &message, sizeof(message),0);
printf("your order is : %s \n",message.mesg_text);
}
/**********************************************************************/
	sem_post(&mutex); 
} 


int main() 
{ 
	sem_init(&mutex, 0, 1); 
	pthread_t t1,t2,t3,t4,t5; 
	pthread_create(&t1,NULL,thread,NULL); 
	pthread_create(&t2,NULL,thread,NULL);
	pthread_create(&t3,NULL,thread,NULL);
	pthread_create(&t4,NULL,thread,NULL);
	pthread_create(&t5,NULL,thread,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	sem_destroy(&mutex); 
	return 0; 
} 
