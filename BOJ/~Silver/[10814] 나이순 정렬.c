#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_AGE 201

typedef struct node {
  char name[100];
  struct node* link;
} node;
typedef node* node_pointer;

int exist[MAX_AGE] = {0};
node_pointer head[MAX_AGE];
node_pointer tail[MAX_AGE];

int main() {
  int N, member_age;
  char member_name[100];
  scanf("%d", &N);

  // ��ũ�� ����Ʈ ����
  for (int i = 0; i < N; i++) {
    node_pointer cur = (node_pointer)malloc(sizeof(node));
    scanf("%d %s", &member_age, member_name);
    strcpy(cur->name, member_name);  // ���ڿ� ����
    if (head[member_age] == NULL) {
      head[member_age] = cur;
      tail[member_age] = cur;
      exist[member_age] = 1;
    } else {
      tail[member_age]->link = cur;
      tail[member_age] = cur;
    }
    cur->link = NULL;
  }

  // ���� exist[i]�� �����Ѵٸ�, null�� ���� ������ ��� �ݺ�
  for (int i = 1; i < 201; i++) {
    if (exist[i] == 1) {
      while (head[i] != NULL) {
        printf("%d %s\n", i, head[i]->name);
        head[i] = head[i]->link;
      }
    }
  }

  return 0;
}