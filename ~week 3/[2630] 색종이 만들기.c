// idea: recursive method

#include <stdio.h>
#define MAX_NUM 128

const int d_row[4] = {0, 1, 0, 1};
const int d_col[4] = {0, 0, 1, 1};
int map[MAX_NUM][MAX_NUM];
int white, blue;  // ��� 0, �Ķ��� 1

int cut(int row, int col, int len) {
  // ������
  if (len == 1) {
    if (map[row][col] == 1)
      blue++;
    else
      white++;
    return map[row][col];
  }
  // ������ 4���

  len /= 2;
  int area[4], sum = 0, same = 1;
  for (int i = 0; i < 4; i++) {
    area[i] = cut(row + d_row[i] * len, col + d_col[i] * len, len);
    if (area[i] != -1)
      sum += area[i];
    else
      same = 0;
  }

  // ��ġ��
  // ���� �Ķ�
  if (same && sum == 4) {
    blue -= 3;
    return 1;
  }
  // ���� �Ͼ�
  if (same && sum == 0) {
    white -= 3;
    return 0;
  }

  else
    return -1;
}

int main() {
  int N;
  scanf("%d", &N);

  // ���� �Է�
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  cut(0, 0, N);

  printf("%d\n%d\n", white, blue);

  return 0;
}