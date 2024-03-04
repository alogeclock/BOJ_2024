// 100C3 <= 100,0000�̱� ������ n^3�� �˰����̾ Ǯ �� ���� ������?

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numberCards, target;
  int* cards;
  int sum = 0;

  scanf("%d %d", &numberCards, &target);
  cards = (int*)malloc(sizeof(int) * numberCards);
  for (int i = 0; i < numberCards; i++) {
    scanf("%d", &cards[i]);
  }

  for (int i = 0; i < numberCards; i++) {
    for (int j = i + 1; j < numberCards; j++) {
      for (int k = j + 1; k < numberCards; k++) {
        int cardSum = cards[i] + cards[j] + cards[k];
        if (cardSum <= target && cardSum > sum) sum = cardSum;
      }
    }
  }

  printf("%d\n", sum);
}