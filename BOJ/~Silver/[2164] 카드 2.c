#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *link;
} node;
typedef node *np;

np head = NULL;
np tail = NULL;

void createNode(int key) {
  np new = (np)malloc(sizeof(node));
  new->key = key;

  if (head == NULL) {
    head = new;
    tail = new;
  } else {
    tail->link = new;
    tail = new;
  }

  new->link = head;
}

void delJosephusNode(np *node, int K) {
  np cur = *node;  // tail6
  np next = NULL;

  while (cur != cur->link) {
    next = cur->link;        // cur�� �� ĭ ������
    cur->link = next->link;  // ������� ����
    cur = cur->link;         // cur �̵�
    free(next);
  }

  printf("%d\n", cur->key);
  free(cur);
}

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    createNode(i);
  }

  delJosephusNode(&tail, 2);

  return 0;
}