// idea: patty ������ cheese ������ ��, ������ �ذ��
// ������ ������ patty�� cheese�� ������ ���� ����

#include <stdio.h>

int main() {
  int patty, cheese;
  scanf("%d %d", &patty, &cheese);

  int burger = patty - cheese;

  if (burger <= 0 || burger > cheese) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  printf("%d\n", burger);

  while (burger-- != 1) {
    printf("aba\n");
    cheese--;
  }

  for (int i = 0; i < cheese; i++) {
    printf("ab");
  }
  printf("a\n");

  return 0;
}