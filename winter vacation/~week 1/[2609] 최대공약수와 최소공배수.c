#include <stdio.h>

int main() {
  int a, b, remain;
  scanf("%d %d", &a, &b);

  int lcm = a * b;  // <= 10000�̹Ƿ� ���ϱ� ����
  if (a < b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
  }

  while (1) {  // remain�� 0�̸� ����
    remain = a % b;
    if (remain == 0) break;
    a = b;
    b = remain;
  }

  printf("%d\n", b);
  printf("%d\n", lcm / b);
}