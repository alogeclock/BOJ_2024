#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_NUMBER 10001

int havingLAN[MAX_LEN_NUMBER];
int num;  // ���� ������ ����

int binSearch(long long min, long long max, int target);
int lanNum(long long mid);

int main() {
  int neededLAN, minlen, maxlen, len_LAN;
  long long sum = 0;
  scanf("%d %d", &num, &neededLAN);

  for (int i = 0; i < num; i++) {
    scanf("%d", &havingLAN[i]);
    sum += havingLAN[i];  // sum�� ���� ������ ��� ����
  }

  maxlen = sum / neededLAN;  // ������ ���̰� �� �� �ִ� ���� ū ���ڷ� �ʱ�ȭ
  printf("%d\n", binSearch(1, maxlen, neededLAN));

  return 0;
}

int binSearch(long long min, long long max, int target) {
  if (min > max) {
    return max;
  }

  long long mid = (min + max) / 2;  // mid�� ��7�̴� ������ ����
  int num = lanNum(mid);

  if (num < target)  // mid ���̰� Ÿ�ٺ��� �� ��
    binSearch(min, mid - 1, target);
  else {  // mid ���̰� Ÿ�ٺ��� ª�� �� (�� ���� �� ����)
    if (num == target && lanNum(mid + 1) != target)
      return mid;
    else if (lanNum(mid + 1) < target)
      return mid;
    else
      binSearch(mid + 1, max, target);
  }
}

// ���� ���̴�� �߶��� �� ������ ����
int lanNum(long long mid) {
  int len_LAN = 0;
  for (int i = 0; i < num; i++) {
    len_LAN += havingLAN[i] / mid;
  }
  return len_LAN;
}