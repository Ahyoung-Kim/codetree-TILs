#include <iostream>
#include <deque>

#define MAX 100001

int a, b;
int vis[MAX];

int bfs() {
    deque<int> dq;

    dq.push_back(a);
    vis[a] = 1;

    while(!dq.empty()) {
        int curr = dq.front(); dq.pop_front();

        if(curr == b) return vis[b] - 1;

        for(int i = 0; i < 2; i++) {
            int next = curr;

            if(i == 0) next += 1;
            else if(i == 1) next -= 1;
            
            if(next < MAX && !vis[next]) {
                dq.push_back(next);
                vis[next] = vis[curr] + 1;
            }
        }

        if(curr * 2 < MAX && !vis[curr * 2]) {
            dq.push_front(curr * 2);
            vis[curr * 2] = vis[curr];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;

    cout << bfs() << endl;

    return 0;
}