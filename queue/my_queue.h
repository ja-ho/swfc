#pragma once

#define MAX_SIZE 5000

void create_queue(int size);
int get_front();
void push(int item);
void pop();
bool is_empty();
bool is_full();
int queue_expand();
