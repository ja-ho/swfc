#include <stdio.h>
#include <stdlib.h>

typedef struct _qnode {
	_qnode *next, *prev;
	int pagenum;
} qnode;

typedef struct _queue {
	qnode *head, *tail;
	int size;
	int c_size;
} queue;

queue q;

void q_init(int size)
{
	q.head = q.tail = NULL;
	q.size = size;
	q.c_size = 0;
	return;
}

qnode *new_node(int value)
{
	qnode *temp = (qnode *)malloc(sizeof(qnode));
	temp->next = temp->prev = NULL;
	temp->pagenum = value;
	return temp;
}

void enqueue(int value)
{
	if (q.c_size == q.size) {
		printf("queue is full\n");
		return;
	}
	qnode *temp = new_node(value);

	if (q.c_size == 0) {
		q.head = q.tail = temp;
	}
	else {
		temp->prev = q.tail;
		q.tail->next = temp;
		q.tail = temp;
	}
	q.c_size++;
	return;
}

void dequeue()
{
	if (q.c_size == 0) {
		//printf("queue is empty\n");
		return;
	}
	qnode *temp = q.head;
	if (q.head == q.tail) {
		free(temp);
		q.tail = q.head = NULL;
	}
	else {
		q.head = q.head->next;
		free(temp);
	}
	q.c_size--;
	return;
}

bool is_empty()
{
	return !q.c_size;
}

bool is_full()
{
	return q.c_size == q.size;
}

int get_front()
{
	if (is_empty()) {
		//printf("queue is empty\n");
		return - 1;
	}
	return q.head->pagenum;
}

qnode *search_q(int value)
{
	if (is_empty()) {
		//printf("queue is empty\n");
		return NULL;
	}
	qnode *temp = q.head;
	while (temp) {
		if (temp->pagenum == value) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void delete_node(qnode *node)
{
	if (node == q.head || node == q.tail) {
		if (node == q.head) {
			q.head = q.head->next;
		} else {
			q.tail = q.tail->prev;
		}
	}
	else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node);
	q.c_size--;
	return;
}


void lru_insert(int pagenum)
{
	qnode *temp = search_q(pagenum);
	if (temp) {
		delete_node(temp);
	}
	else {
		if (is_full()) {
			dequeue();
		}
		printf("page fault %d!\n", pagenum);
	}
	enqueue(pagenum);
}

void print_q()
{
	if (is_empty()) return;
	qnode *p = q.head;
	while (p) {
		printf("%d ", p->pagenum);
		p = p->next;
	}
	printf("\n");
	return;
}

void clear_q()
{
	qnode *temp = q.head;
	while (temp) {
		qnode *delete_node = temp;
		temp = temp->next;
		free(delete_node);
	}
	return;
}

int main() {
	q_init(3);
	int data[] = { 0, 1, 2, 3, 4, 1, 3, 2, 3, 4, 0, 1 };
	int length = sizeof(data) / sizeof(int);
	for (int i = 0; i < length; i++) {
		lru_insert(data[i]);
		print_q();
	}

	return 0;
}