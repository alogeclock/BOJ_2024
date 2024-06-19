#include <bits/stdc++.h>
using namespace std;

#define MAX_NUMBER 3001

int matrix[MAX_NUMBER][MAX_NUMBER];
int minus_paper, zero_paper, one_paper;         // 0���� �ʱ�ȭ
const int dr[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};  // �� �̵�
const int dc[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};  // �� �̵�

int cut(int row, int col, int len) {
  if (len == 1) {
    int val = matrix[row][col];
    if (val == -1)
      minus_paper++;
    else if (val == 0)
      zero_paper++;
    else
      one_paper++;

    return matrix[row][col];
  }

  int same_check = 0;  // ��ȩ ������ ������ Ȯ��
  int find;
  len /= 3;

  for (int i = 0; i < 9; i++) {
    int val = cut(row + dr[i] * len, col + dc[i] * len, len);
    if (i == 0) {
      find = val;
      continue;
    }
    if (find != val) {
      same_check = 1;  // ��ȩ ������ �ٸ� ���
    }
  }

  if (same_check == 0) {  // ��ȩ ������ ���Ҵٸ� ����
    if (find == -1)
      minus_paper -= 8;
    else if (find == 0)
      zero_paper -= 8;
    else if (find == 1)
      one_paper -= 8;
    return find;
  }

  return -9;  // �ٸ� ���� ��ȯ�� �������� ���� ���� �� ����
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> matrix[i][j];

  cut(0, 0, N);

  cout << minus_paper << endl << zero_paper << endl << one_paper << endl;

  return 0;
}