// ��� ��: '1 << N' (2^n ǥ��), 4��� �Ǻ�(���� �湮 X)

#include <stdio.h>

int find_order(int N, int r, int c) {
  int order = 0;
  int size = 1 << N;

  while (size > 1) {
    size /= 2;

    // 4����� ���� �� ��� �ش��ϴ��� �Ǻ�
    int quadrant = (r >= size) * 2 + (c >= size);

    if (quadrant == 1) {  // ������ ���
      order += size * size;
      c -= size;
    } else if (quadrant == 2) {  // ���� �ϴ�
      order += size * size * 2;
      r -= size;
    } else if (quadrant == 3) {  // ������ �ϴ�
      order += size * size * 3;
      r -= size;
      c -= size;
    }
    // ���� ��ܿ� ������ �߰� ��� ���� ���� �ܰ��
  }

  return order;
}

int main() {
  int N, r, c;
  scanf("%d %d %d", &N, &r, &c);
  printf("%d\n", find_order(N, r, c));
  return 0;
}