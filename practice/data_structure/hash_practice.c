#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_node {
	char *key;
	void *data;
	struct hash_node *next;
};

struct hash_table {
	int size;
	int c_size;
	struct hash_node **h_table;
};

struct hash_table h_table;


//hash table 초기화
void hash_init(int size)
{
	h_table.size = size;
	h_table.c_size = 0;
	h_table.h_table = (struct hash_node **)malloc(sizeof(struct hash_node *) * size + 1);
	for (int i = 0; i < size + 1; i++) {
		h_table.h_table[i] = NULL;
	}
	return;
}

//새로운 hash 노드를 반환하는 util function
struct hash_node *new_node(char *key, void *value)
{
	struct hash_node *temp = (struct hash_node *)malloc(sizeof(struct hash_node));
	temp->data = value;
	temp->key = (char *)malloc(sizeof(char) * strlen(key) + 1);
	strcpy(temp->key, key);
	temp->next = NULL;
	return temp;
}

//hash function. g가31인 이유는 소수이면서 31은 (1<<5) - 1로 계산이 쉽기 때문.
//hash function이 이런식으로 구성되어 있기 때문에 같은 alphabet이 들어와도 다른 hash값을 만들어내기 때문에 collision이 줄어듬.
int calc_hash_code(char *key)
{
	int g = 31;
	int hash = 0;
	int length = strlen(key);
	for (int i = 0; i < length; i++) {
		hash = g * hash + (int)key[i];
	}
	return hash;
}

void *add_hash(char *key, void *data)
{
	int idx = calc_hash_code(key) % h_table.size;
	struct hash_node *temp = h_table.h_table[idx];

	while (temp) {
		if (!strcmp(temp->key, key)) {
			void *ret = temp->data;
			temp->data = data;
			return ret;
		}
		temp = temp->next;
	}
	temp = (struct hash_node *)malloc(sizeof(struct hash_node));
	temp->data = data;
	temp->key = (char *)malloc(sizeof(char) * strlen(key) + 1);
	strcpy(temp->key, key);
	temp->next = h_table.h_table[idx];
	h_table.h_table[idx] = temp;
	h_table.c_size++;
	return NULL;
}

void *get_hash(char *key)
{
	int idx = calc_hash_code(key) % h_table.size;
	struct hash_node *temp = h_table.h_table[idx];
	while (temp) {
		if (!strcmp(temp->key, key)) {
			return temp->data;
		}
		temp = temp->next;
	}
	return NULL;
}

void *delete_hash(char *key)
{
	int idx = calc_hash_code(key) % h_table.size;
	struct hash_node *temp = h_table.h_table[idx];
	struct hash_node *prev = NULL;
	while (temp) {
		if (!strcmp(temp->key, key)) {
			void *ret = temp->data;
			if (prev) {
				prev->next = temp->next;
			}
			else {
				h_table.h_table[idx] = temp->next;
			}
			free(temp);
			h_table.c_size--;
			return ret;
		}
		prev = temp;
		temp = temp->next;
	}
	return NULL;
}

void hash_list_keys(char **k)
{
	int ki = 0;
	int i = h_table.size;
	while (--i) {
		struct hash_node *temp = h_table.h_table[i];
		while (temp) {
			k[ki++] = temp->key;
			temp = temp->next;
		}
	}
	return;
}

void hash_list_values(char **v)
{
	int vi = 0;
	int i = h_table.size;
	while (--i) {
		struct hash_node *temp = h_table.h_table[i];
		while (temp) {
			v[vi++] = temp->data;
			temp = temp->next;
		}
	}
	return;
}

int main() {
	hash_init(1024);
	add_hash("foo", "bar");
	printf("%s\n", (char *)get_hash("foo"));
	add_hash("foo", "hey");
	printf("%s\n", (char *)get_hash("foo"));
	delete_hash("foo");
	if (!get_hash("foo")) {
		printf("foo is removed\n");
	}
	add_hash("foo", "bar");
	add_hash("hihi", "haha");
	printf("listing keys\n");
	char **keys = (char **)malloc(sizeof(char *) * h_table.c_size);
	hash_list_keys(keys);
	for (int i = 0; i < h_table.c_size; i++) {
		printf("%s\n", keys[i]);
	}
	printf("listing values\n");
	void **values = (void **)malloc(sizeof(void *) * h_table.c_size);
	hash_list_values(values);
	for (int i = 0; i < h_table.c_size; i++) {
		printf("%s\n", (char *)values[i]);
	}


	return 0;
}