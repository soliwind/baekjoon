#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<vector<int> > graph(n, vector<int>(n, 0)); // graph[i][j]: i가 j보다 등수높음, i->j
        for(int i = 0; i < n; i++) {
            int tem;
            cin >> tem;
            arr[tem - 1] = i + 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i] < arr[j]) {
                    graph[i][j] = 1;
                }
            }
        }
        
        int m;
        cin >> m;
        while(m--) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            graph[a][b] ^= 1;
            graph[b][a] ^= 1;
        }
        
        vector<int> degree(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                degree[j] += graph[i][j];
            }
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 1;
        vector<int> ans(n, -1);
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            ans[v] = cnt;
            cnt++;
            
            for(int i = 0; i < n; i++) {
                degree[i] -= graph[v][i];
                if(degree[i] == 0 && ans[i] == -1) {
                    q.push(i);
                }
            }
        }
        
        bool isImpossible = 0;
        for(int i = 0; i < n; i++) {
            if(degree[i] != 0) {
                isImpossible = 1;
            }
        }
        
        if (isImpossible == 1) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            vector<int> result(n);
            for(int i = 0; i < n; i++) {
                result[ans[i] - 1] = i + 1;
            }
            for(int i = 0; i < n; i++) {
                cout << result[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
