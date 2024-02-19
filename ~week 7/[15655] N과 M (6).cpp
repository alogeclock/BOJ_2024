#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

int N, M;
int input[10], state[10];
bool vst[10];

void backtracking(int k) {
  if (k > M) {
    for (int i = 1; i <= M; i++) cout << state[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < N; i++) {
    if (!vst[i] && input[i] >= state[k - 1]) {
      state[k] = input[i];
      vst[i] = true;
      backtracking(k + 1);
      vst[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> input[i];
  sort(input, input + N);
  state[0] = 0;
  backtracking(1);
}