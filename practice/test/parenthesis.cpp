#include <stdio.h>

#define MAX_BUFFER 256
#define MAX_STACK 100

struct stack {
	char st[MAX_STACK];
	int top;
};

struct stack st;

void push(char c)
{
	if (st.top >= MAX_STACK) {
		printf("stack is full\n");
		return;
	}

	st.st[++st.top] = c;
	return;
}

char get_top()
{
	return st.st[st.top];
}

void pop()
{
	if (st.top == -1) return;
	st.top--;
	return;
}

bool is_empty()
{
	if (st.top == -1) return true;
	else return false;
}

int main() {
	char buffer[MAX_BUFFER];
	st.top = -1;
	while (true) {
		fgets(buffer, MAX_BUFFER, stdin);
		if (buffer[0] == '.') break;
		int idx = 0;
		bool err = false;
		while (st.top != -1) pop();
		while (buffer[idx] != '\n') {
			char temp = buffer[idx];
			if (temp == '(') {
				push(temp);
			}
			else if (temp == ')') {
				if (get_top() == '(') {
					pop();
				}
				else {
					err = true;
					break;
				}
			}
			else if (temp == '[') {
				push(temp);
			}
			else if (temp == ']') {
				if (get_top() == '[') {
					pop();
				}
				else {
					err = true;
					break;
				}
			}
			else {
				
			}
			idx++;
		}
		if (!err && is_empty()) {
			printf("%s\n", "yes");
		}
		else {
			printf("%s\n", "no");
		}
	}
	return 0;
}