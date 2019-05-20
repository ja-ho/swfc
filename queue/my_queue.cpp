#include "my_queue.h"
#include <cstdlib>
#include <cstdio>

int front = -1;
int rear = -1;
int queue_size = -1;
int *q_ptr;

void create_queue(int size)
{
	if (size > MAX_SIZE) {
		printf("MAX_SIZE IS %d\n", MAX_SIZE);
		return;
	}
	q_ptr = (int *)malloc(sizeof(int)*size);
	queue_size = size;
	front = -1;
	rear = -1;
}
int get_front()
{
	if (is_empty()) {
		printf("this queue is empty\n");
		return -1;
	}
	return q_ptr[(front + 1) % queue_size];
}
void push(int item)
{
	if (is_full()) {
		printf("this queue is full. expand the queue size by double\n");
		if ((queue_expand())) {
			printf("can't expand...");
			return;
		}
	}
	rear = (rear + 1) % queue_size;
	q_ptr[rear] = item;
}
void pop()
{
	if (is_empty()) {
		printf("this queue is empty\n");
		return;
	}
	front = (front + 1) % queue_size;
}
bool is_empty()
{
	return (front == rear);
}
bool is_full()
{
	return ((rear + 1) % queue_size == front);
}

int queue_expand()
{
	if (queue_size * 2 > MAX_SIZE) {
		printf("queue_size is over the MAX queue size\n");
		return -1;
	}

	int *new_queue = (int*)malloc(sizeof(int) * queue_size * 2);		//2�� �������� ���ο� queue�� �Ҵ�
	int idx = 0;
	for (int i = front + 1; i < queue_size; i++) {
		new_queue[idx++] = q_ptr[i];
	}
	
	for (int i = 0; i <= rear; i++) {
		new_queue[idx++] = q_ptr[i];
	}
	front = queue_size * 2 - 1;				//front�� ������ �ε���
	rear = idx - 1;								//rear�� �� ������
	queue_size *= 2;
	free(q_ptr);
	q_ptr = new_queue;
	return 0;
}