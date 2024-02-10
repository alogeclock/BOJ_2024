// sum �迭, 1000 * 100000�� ��� 10^3 * 10^5
// 10^8 = 1���̹Ƿ� int �ڷ����� �Է� ����

#include <stdio.h>
#define MAX_NUM 100001

int arr[MAX_NUM];
int sum[MAX_NUM];

int main() {
  // �ԷµǴ� ���� ����, ���� ���ؾ� �ϴ� ȸ��
  int N, M;
  scanf("%d %d", &N, &M);

  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
    if (i == 1)
      sum[i] = arr[i];
    else
      sum[i] = sum[i - 1] + arr[i];
  }

  while (M--) {
    int start, end, res;
    scanf("%d %d", &start, &end);
    res = sum[end] - sum[start] + arr[start];

    printf("%d\n", res);
  }
  return 0;
}