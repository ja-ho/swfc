#pragma once
#include "my_linked_list.h"

typedef struct _queue
{
	node *front;
	node *rear;
	int size;
} queue;


void init_queue(queue *q_ptr);
void enqueue(queue *q_ptr, int value);
void dequeue(queue *q_ptr);
int get_front(queue *q_ptr);
int queue_size(queue *q_ptr);
bool is_empty(queue *q_ptr);