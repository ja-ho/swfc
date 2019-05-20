#pragma once

typedef struct _node {
	_node *before;
	_node *next;
	int data;
} node;

typedef struct _list {
	node *head;
	node *tail;
	int size;
} list;

void init_list(list *ptr);
void push_back(list *ptr, int value);
void push_front(list *ptr, int value);
int pop_back(list *ptr);
int get_idx(list *ptr, int idx);
int count_target(list *ptr, int target);
int get_size(list *ptr);
bool is_empty(list *ptr);
void list_clear(list *ptr);