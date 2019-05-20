#include <stdio.h>

typedef struct _queue {
	int front;
	int rear;
	int size;
	int q[101];
} queue;

void enqueue(queue *q, int value)
{
	if ((q->rear + 1) % q->size == q->front) {
		printf("it's full\n");
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = value;
	return;
}

void dequeue(queue *q)
{
	if (q->front == q->rear) {
		printf("it's empty\n");
	}
	q->front = (q->front + 1) % q->size;
	return;
}

int get_front(queue *q)
{
	if (q->front == q->rear) {
		printf("it's empty\n");
		return -1;
	}
	return q->q[(q->front + 1) % q->size];
}


int main() {
	queue q;
	q.front = 0;
	q.rear = 0;
	q.size = 0;

	q.size = 10;
	for (int i = 10; i >= 1; i--) {
		enqueue(&q, i);
	}

	for (int i = 0; i < q.size; i++) {
		if (i == 9) {
			printf("hey\n");
		}
		printf("%d ", get_front(&q));
		dequeue(&q);
	}
	printf("\n");

	return 0;
}