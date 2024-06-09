#include <iostream>

using namespace std;

#define MOD 1'000'000'007

typedef unsigned long long ll;

// 37

int n, m;
int sum[11][2001]; // sum[i][j] = 길이가 i 인 수열, 숫자 j 로 시작하는 경우의 수
int dp[11][2001];

void solution() {
    for(int i = 1; i <= m; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j * 2 > m) break;

            for(int k = j * 2; k <= m; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << endl;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    solution();

    return 0;
}