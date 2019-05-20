#pragma once
#define MAX_SIZE 5000

int *create_stack(int size);
int get_top(int *p);
void push(int *p, int n);
void pop(int *p);
void expand_stack(int *p);
bool is_full(int *p);
bool is_empty(int *p);

