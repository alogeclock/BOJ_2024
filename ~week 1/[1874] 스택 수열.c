// ���� ������ ���� ���� �ִ� ���ں��� �� ���� ���ڸ� �䱸�� ��� NO

#include <stdio.h>
#define MAX_STACK_NUMBER 100001

int order[MAX_STACK_NUMBER];
int stack[MAX_STACK_NUMBER] = {0};
char calculation[MAX_STACK_NUMBER * 2] = {0};
int top = -1;
int sequence = 1; // ����
int cal = 0;

void push();
void pop();

int main() {
  int num, chk = 0, NO = 0, max = 0;
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    scanf("%d", &order[i]);

    // ���� ���길���� ���� ã�� ���� �� continue
    if (top != -1 && stack[top] > order[i])
      NO = 1;

    if (NO == 1)
      continue;
    while (top == -1 || order[i] > stack[top])
      push();
    if (order[i] == stack[top])
      pop();
  }

  if (NO == 1) {
    printf("NO\n");
    return 0;
  }

  for (int i = 0; calculation[i]; i++) {
    printf("%c\n", calculation[i]);
  }

  return 0;
}

void push() {
  if (top >= MAX_STACK_NUMBER)
    return;
  stack[++top] = sequence++;
  calculation[cal++] = '+';
}

void pop() {
  if (top < 0)
    return;
  calculation[cal++] = '-';
  top--;
}