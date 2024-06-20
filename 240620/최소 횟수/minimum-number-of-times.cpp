#include <iostream>
#include <deque>

using namespace std;

#define MAX 100001

int a, b;
int vis[MAX];

int bfs() {
    deque<int> dq;

    dq.push_back(a);
    vis[a] = 1;

    while(!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();

        if(curr == b) return vis[b] - 1;

        if(curr + 1 < MAX && !vis[curr + 1]) {
            dq.push_back(curr + 1);
            vis[curr + 1] = vis[curr] + 1;
        }

        if(curr - 1 < MAX && !vis[curr - 1]) {
            dq.push_back(curr - 1);
            vis[curr - 1] = vis[curr] + 1;
        }

        if(curr * 2 < MAX && !vis[curr * 2]) {
            dq.push_front(curr * 2);
            vis[curr * 2] = vis[curr];
        }
    }

    return -1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;

    cout << bfs() << endl;

    return 0;
}