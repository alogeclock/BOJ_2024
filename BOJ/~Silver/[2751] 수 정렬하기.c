// �� ����

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 1000001

int heap[MAX_ELEMENT];
int heap_size = 0;

void insert_min_heap(int key) {
  int i;
  i = ++heap_size;

  while ((i != 1) && (key < heap[i / 2])) {
    heap[i] = heap[i / 2];
    i /= 2;
  }
  heap[i] = key;
}

int delete_min_heap() {
  int parent, child;
  int key, temp;

  key = heap[1];
  temp = heap[heap_size--];  // ������ ���

  parent = 1;
  child = 2;

  // �ڽ� ��尡 �����Ѵٸ�
  while (child <= heap_size) {
    // �ڽ��� �� ��� �����ϰ�, ������ �ڽ� ��尡 �� �۴ٸ� ������ ���� �̵�
    if (child < heap_size && (heap[child] > heap[child + 1])) {
      child++;
    }
    // temp�� �� ���� �ڽ� ��庸�� �۴ٸ� while�� ���� (parent�� ����)
    if (temp <= heap[child]) {
      break;
    }

    // �� ū �ڽ� ��庸�� ������ ��尡 ������, �θ� ���� �� ū �ڽ� ��� ��ȯ
    heap[parent] = heap[child];
    parent = child;
    child *= 2;
  }

  // ������ ��带 �� ��ġ�� ����
  heap[parent] = temp;
  // �ִ� ��ȯ
  return key;
}

int main() {
  int N, key;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &key);
    insert_min_heap(key);
  }

  for (int i = 0; i < N; i++) {
    printf("%d\n", delete_min_heap());
  }

  return 0;
}