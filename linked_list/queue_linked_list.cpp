#include "my_linked_list.h"
#include "queue_linked_list.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

void init_queue(queue *q_ptr)
{
	q_ptr->front = (node *)malloc(sizeof(node));
	q_ptr->front->data = 0;
	q_ptr->front->next = q_ptr->rear = NULL;
	q_ptr->size = 0;
}
void enqueue(queue *q_ptr, int value)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->next = NULL;
	if (q_ptr->front->next == NULL) {
		q_ptr->front->next = temp;
		q_ptr->rear = temp;
		q_ptr->size++;
		return;
	}
	else {
		q_ptr->rear->next = temp;
		q_ptr->rear = temp;
		q_ptr->size++;
	}
	return;
}
void dequeue(queue *q_ptr)
{
	node *temp;
	assert(!is_empty(q_ptr));
	temp = q_ptr->front->next;
	q_ptr->front->next = q_ptr->front->next->next;
	free(temp);
	q_ptr->size--;
	return;
}
int get_front(queue *q_ptr)
{
	assert(!is_empty(q_ptr));
	return q_ptr->front->next->data;
}
int queue_size(queue *q_ptr)
{
	return q_ptr->size;
}
bool is_empty(queue *q_ptr)
{
	return !q_ptr->size;
}