#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	char name[15];
	int value;
	_node *prev;
	_node *next;
} node;

typedef struct _list {
	node *head;
	node *tail;
	node *current;
	int size;
} list;


void push_back(list *list, int value)
{
	node *temp = (node *)malloc(sizeof(node));
	strcpy(temp->name, "new_node");
	temp->value = value;
	temp->prev = NULL;
	temp->next = NULL;
	temp->next = list->tail;
	temp->prev = list->tail->prev;
	list->tail->prev->next = temp;
	list->tail->prev = temp;
	list->size++;
	return;
}

void push_front(list *list, int value)
{
	node *temp = (node *)malloc(sizeof(node));
	strcpy(temp->name, "from_front");
	temp->value = value;
	temp->next = list->head->next;
	list->head->next->prev = temp;
	list->head->next = temp;
	temp->prev = list->head;
	list->size++;
	return;
}

int pop_front(list *list)
{
	node *delete_node = list->head->next;
	int temp = delete_node->value;
	list->size--;
	list->head->next = list->head->next->next;
	list->head->next->prev = list->head;
	free(delete_node);
	return temp;
}

int find_node(list *list, int target)
{
	node *temp;
	int idx = 1;
	temp = list->head->next;
	while (temp->next != NULL) {
		if (temp->value == target) {
			return idx;
		}
		idx++;
		temp = temp->next;
	}
	return -1;
}

void clear_list(list *list)
{
	list->current = list->head->next;
	node *temp;
	while (list->current->next != NULL) {
		temp = list->current;
		list->current = list->current->next;
		free(temp);
	}
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->size = 0;
	return;
}


int main() {
	list temp_list;
	temp_list.head = (node *)malloc(sizeof(node));
	temp_list.tail = (node *)malloc(sizeof(node));
	temp_list.head->prev = NULL;
	temp_list.head->next = temp_list.tail;
	temp_list.tail->prev = temp_list.head;
	temp_list.tail->next = NULL;
	temp_list.current = NULL;
	temp_list.size = 0;

	for (int i = 1; i <= 10; i++) {
		push_back(&temp_list, i);
	}

	printf("find value is 10. 10's index is : %d\n", find_node(&temp_list, 10));

	for (int i = 0; i < 10; i++) {
		printf("%d ", pop_front(&temp_list));
	}
	printf("\n");
	clear_list(&temp_list);

	return 0;
}