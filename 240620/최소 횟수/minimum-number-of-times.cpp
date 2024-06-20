#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

#define MAX_SIZE 100001

int n, k;
int visited[MAX_SIZE];

// 최단 거리를 찾는 bfs 함수입니다.
int bfs() {
    deque<int> dq;
    dq.push_back(n);
    visited[n] = 1;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        // b에 도달한 경우 해당 거리를 반환합니다.
        if(cur == k) return visited[k] - 1;

        // 2번 연산의 경우, 2 * cur의 위치로 이동 가능합니다.
        // 2번 연산은 몇번을 해도 상관 없으므로 덱의 앞쪽에 추가합니다.
        if (cur * 2 < MAX_SIZE && !visited[cur * 2]) {
            dq.push_front(cur * 2);
            visited[cur * 2] = visited[cur];
        }

        // 1번 연산은 cur + 1 또는 cur - 1로 이동합니다.
        // 1번 연산은 덱의 뒤쪽에 추가합니다.
        if (cur + 1 < MAX_SIZE && !visited[cur + 1]) {
            dq.push_back(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }

        if (cur - 1 >= 0 && !visited[cur - 1]) {
            dq.push_back(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
    }
}

int main() {
    // 시작점과 도착점을 입력받습니다.
    cin >> n >> k;

    // bfs 함수를 호출한 결과를 출력합니다.
    cout << bfs() << endl;
    
    return 0;
}