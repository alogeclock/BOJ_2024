// binary search/hashmap
// how to sort strings by qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUMBER 100001

typedef struct pokemon_dict {
  int num;
  char name[25];
} Pokedex;

// �������� ����: strcmp > 0�̾�� a~z ������ ������
int compare(const void *a, const void *b) {
  Pokedex A = *(Pokedex *)a;
  Pokedex B = *(Pokedex *)b;

  if (strcmp(A.name, B.name) > 0)
    return 1;
  else
    return -1;
}

int main() {
  int pokemon, question;
  Pokedex *pokedex;
  Pokedex *sorted_pokedex;

  scanf("%d %d", &pokemon, &question);

  pokedex = (Pokedex *)malloc(sizeof(Pokedex) * pokemon);
  sorted_pokedex = (Pokedex *)malloc(sizeof(Pokedex) * pokemon);

  for (int i = 0; i < pokemon; i++) {
    scanf(" %s", pokedex[i].name);
    pokedex[i].num = i + 1;
    sorted_pokedex[i] = pokedex[i];
  }

  qsort(sorted_pokedex, pokemon, sizeof(sorted_pokedex[0]), compare);

  printf("!!!%s", sorted_pokedex[0].name);

  for (int i = 0; i < question; i++) {
    char input[25];
    scanf(" %s", input);

    if (input[0] < 58) {
      int idx = atoi(input);  // atoi() �Լ��� ǥ���Լ��� �ش�
      printf("%s\n", pokedex[idx - 1].name);
    }

    // �Է°��� ������ ��� (�ؽø�/�̺� Ž��)
    // ���ڿ��� ��� �̺� Ž���� ���ΰ�?
    else {
      int left, right, mid;
      left = 0, right = pokemon - 1;

      while (left <= right) {
        mid = (left + right) / 2;
        int cmp = strcmp(input, sorted_pokedex[mid].name);

        if (cmp == 0) {
          printf("%d\n", sorted_pokedex[mid].num);
          break;
        } else if (cmp > 0)
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
  }

  free(pokedex);
  free(sorted_pokedex);

  return 0;
}