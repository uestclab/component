#ifndef GW_MSG_QUEUE_H
#define GW_MSG_QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>  
#include <pthread.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <signal.h>   
#include <string.h>  
#include <errno.h>  
#include <sys/msg.h> 
#include <ctype.h>

#include "priorityQueue.h"

#define MAX_QUEUE_ID 1024
#define MAX_TEXT 2048

struct msg_st  
{  
    long int msg_type;
	int      msg_number;
	void*    tmp_data;
	int      tmp_data_len;
	int      msg_len;  
    char     msg_json[MAX_TEXT];  
};

typedef struct g_msg_queue_para{
	int                msgid;
	priorityQueue*	   queue;
	
	pthread_mutex_t*   mutex_;
	int                seq_id;
}g_msg_queue_para;


g_msg_queue_para* createMsgQueue();
int delMsgQueue(g_msg_queue_para* g_msg_queue);

int postMsgQueue(struct msg_st* data, int level, g_msg_queue_para* g_msg_queue);
struct msg_st* getMsgQueue(g_msg_queue_para* g_msg_queue);


#ifdef __cplusplus
}
#endif

#endif//GW_MSG_QUEUE_H


