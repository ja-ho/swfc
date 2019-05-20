#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check[10001];
int dist[10001];
char how[10001];
int from[10001];

typedef struct _qnode {
	int data;
	_qnode *next, *prev;
} qnode;

typedef struct _queue {
	qnode *head, *tail;
	int c_size;
	int size;
} queue;

queue q;

void q_init()
{
	q.head = q.tail = NULL;
	q.c_size = 0;
	q.size = 0;
	return;
}

qnode *new_node(int value)
{
	qnode *temp = (qnode *)malloc(sizeof(qnode));
	temp->data = value;
	temp->next = temp->prev = NULL;
	return temp;
}

void enqueue(int value)
{
	if (q.head == NULL) {
		//q.head = (qnode *)malloc(sizeof(qnode));
		//q.tail = (qnode *)malloc(sizeof(qnode));
		qnode *node = new_node(value);
		q.head = q.tail = node;
		q.c_size++;
		return;
	}
	else {
		if (q.c_size == q.size) {
			printf("it's full\n");
			return;
		}
		qnode *node = new_node(value);
		q.tail->next = node;
		node->prev = q.tail->prev;
		q.tail = node;
		q.c_size++;
	}
	return;
}

int dequeue()
{
	if (q.c_size == 0) {
		printf("it's empty\n");
		return -1;
	}
	else {
		qnode *temp = q.head;
		int ret = temp->data;
		q.head = q.head->next;
		free(temp);
		q.c_size--;
		return ret;
	}
}

int get_front()
{
	if (q.c_size == 0) {
		printf("it's empty\n");
		return -1;
	}
	return q.head->data;
}

void delete_q()
{
	while (q.head) {
		dequeue();
	}
	return;
}

int calc_dslr(int now, int dir)
{
	if (dir == 0) {
		return (now * 2) % 10000;
	}
	else if (dir == 1) {
		if (now == 0) return 9999;
		else return now - 1;
	}
	else if (dir == 2) {
		return now / 1000 + (now % 1000) * 10;
	}
	else {
		return (now % 10) * 1000 + now / 10;
	}
}

void go(int now, int goal)
{
	if (now == goal) {
		return;
	}
	check[now] = true;
	dist[now] = 0;
	from[now] = -1;
	enqueue(now);
	while (q.c_size != 0) {
		int now = dequeue();
		if (now == -1) return;
		for (int i = 0; i < 4; i++) {
			int next = calc_dslr(now, i);
			if (check[next]) continue;
			check[next] = true;
			dist[next] = dist[now] + 1;
			from[next] = now;
			if (i == 0) how[next] = 'D';
			else if (i == 1) how[next] = 'S';
			else if (i == 2) how[next] = 'L';
			else how[next] = 'R';
			if (next == goal) return;
			enqueue(next);
		}		
	}
	return;
}

void print_how(int a, int b)
{
	if (a == b) return;
	print_how(a, from[b]);
	printf("%c", how[b]);
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	q_init();
	q.size = 10000;
	while (t--) {
		delete_q();
		for (int i = 0; i < 10000; i++) {
			check[i] = false;
			from[i] = 0;
			how[i] = '\0';
			dist[i] = 0;
		}
		int a, b;
		scanf("%d %d", &a, &b);
		go(a, b);
		print_how(a, b);
		printf("\n");
	}
	return 0;
}