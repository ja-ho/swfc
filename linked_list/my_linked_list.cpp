#include "my_linked_list.h"
#include <cstdlib>
#include <cstdio>
#include <cassert>

void init_list(list *ptr)
{
	ptr->head = (node *)malloc(sizeof(node));
	ptr->head->next = NULL;
	ptr->head->before = NULL;
	ptr->tail = ptr->head;
	ptr->tail->before = ptr->head;
	ptr->size = 0;
	return;
}
void push_back(list *ptr, int value)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->next = NULL;
	temp->data = value;
	temp->before = ptr->tail;
	if (ptr->tail == ptr->head) {
		ptr->tail = temp;
		ptr->tail->next = ptr->head;
		ptr->head->next = temp;
	}
	else {
		ptr->tail->next = temp;
		ptr->tail = temp;
		ptr->tail->next = ptr->head;
	}

	ptr->size++;
	return;
}
void push_front(list *ptr, int value)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->next = NULL;
	temp->data = value;
	temp->next = ptr->head->next;
	ptr->head->next->before = temp;
	temp->before = ptr->head;
	ptr->head->next = temp;
	ptr->size++;
	return;
}

int pop_back(list *ptr)
{
	node *temp = ptr->tail;
	assert(!is_empty(ptr));
	int temp_data = temp->data;
	temp->before->next = ptr->head;
	ptr->tail = temp->before;
	free(temp);
	ptr->size--;
	return temp_data;
}

int get_idx(list *ptr, int idx)
{
	node *temp = ptr->head->next;
	int cnt = 0;
	while (temp->next != ptr->head->next) {		//check: 마지막 요소까지 정상적으로 찾는가
		if (idx == cnt) {
			return temp->data;
		}
		cnt++;
		temp = temp->next;
	}
	return -1;	//찾고자 하는 값이 없음.
}
int count_target(list *ptr, int target)
{
	node *temp = ptr->head->next;
	int cnt = 0;
	while (temp->next != ptr->head->next) {
		if (target == temp->data) cnt++;
		temp = temp->next;
	}
	return cnt;
}
int get_size(list *ptr)
{
	return ptr->size;
}

bool is_empty(list *ptr)
{
	return !(ptr->size);
}

void list_clear(list *ptr)
{
	while (!is_empty(ptr)) {
		pop_back(ptr);
	}
	return;
}