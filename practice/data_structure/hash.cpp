#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _hash_node {
	_hash_node *next;	//for chaining
	char *key;
	void *data;
} hash_node;

typedef struct _hash_table {
	int size;
	int current_size;
	hash_node **table;
} hash_table;

hash_table *h_table;

int calc_hash_code(char *key)
{
	int length = strlen(key);
	int g = 31;
	int hash = 0;
	for (int i = 0; i < length; i++) {
		hash = g * hash + (int)key[i];
	}
	return hash;
}

void *add_hash_node(char *key, void *data)
{
	int idx = calc_hash_code(key) % h_table->size;
	hash_node *temp = h_table->table[idx];

	while (temp) {
		if (!strcmp(temp->key, key)) {
			void *ret = temp->data;
			temp->data = data;
			return ret;
		}
		temp = temp->next;
	}
	temp = (hash_node *)malloc(sizeof(hash_node));
	temp->data = data;
	temp->key = (char *)malloc(sizeof(strlen(key)) + 1);
	strcpy(temp->key, key);
	temp->next = h_table->table[idx];
	h_table->table[idx] = temp;
	h_table->current_size++;
	return NULL;
}

void *hash_get(char *key)
{
	int idx = calc_hash_code(key) % h_table->size;
	hash_node *temp = h_table->table[idx];
	while (temp) {
		if (!strcmp(temp->key, key)) {
			return temp->data;
		}
		temp = temp->next;
	}
	return NULL;
}

void *hash_delete(char *key)
{
	int idx = calc_hash_code(key) % h_table->size;
	hash_node *temp = h_table->table[idx];
	hash_node *prev = NULL;
	void *ret;
	while (temp) {
		if (!strcmp(temp->key, key)) {
			ret = temp->data;
			if (prev != NULL) {
				prev->next = temp->next;
			}
			else {
				h_table->table[idx] = temp->next;
			}
			free(temp);
			h_table->current_size--;
			return ret;
		}
		prev = temp;
		temp = temp->next;
	}
	return NULL;
}

void hash_list_keys(char **k, int len) 
{
	if (len < h_table->current_size)
		return;
	int ki = 0;
	int i = h_table->size;
	while (--i) {
		hash_node *temp = h_table->table[i];
		while (temp) {
			k[ki++] = temp->key;
			temp = temp->next;
		}
	}
	return;
}

void hash_list_values(void **v, int len)
{
	if (len < h_table->current_size)
		return;
	int vi = 0;
	int i = h_table->size;
	while (--i) {
		hash_node *temp = h_table->table[i];
		while (temp) {
			v[vi++] = temp->data;
			temp = temp->next;
		}
	}
	return;
}


int main() {
	int size;
	scanf("%d", &size);
	h_table = (hash_table *)malloc(sizeof(hash_table));
	h_table->current_size = 0;
	h_table->size = size;
	h_table->table = (hash_node **)malloc(sizeof(hash_node *) * size);
	for (int i = 0; i < size; i++) {
		h_table->table[i] = NULL;
	}

	add_hash_node("foo", "bar");
	printf("%s\n", (char *)hash_get("foo"));
	add_hash_node("foo", "hey");
	printf("%s\n", (char *)hash_get("foo"));
	hash_delete("foo");
	if (!hash_get("foo")) {
		printf("foo is removed\n");
	}
	add_hash_node("foo", "bar");
	add_hash_node("hihi", "haha");
	printf("listing keys\n");
	char **keys = (char **)malloc(sizeof(char *) * h_table->current_size);
	hash_list_keys(keys, h_table->current_size);
	for (int i = 0; i < h_table->current_size; i++) {
		printf("%s\n", keys[i]);
	}
	printf("listing values\n");
	void **values = (void **)malloc(sizeof(void *) * h_table->current_size);
	hash_list_values(values, h_table->current_size);
	for (int i = 0; i < h_table->current_size; i++) {
		printf("%s\n", (char *)values[i]);
	}
	return 0;
}