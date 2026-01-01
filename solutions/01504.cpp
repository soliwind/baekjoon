#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 62;

struct compare {
    bool operator()(pair<long long, int> a, pair<long long, int> b) {
        return a.first > b.first;
    }
};

long long getShortestPath(int n, vector<vector<pair<int, long long> > >& graph, int v1, int v2) {
    vector<long long> dist(n, INF), visited(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, compare> pq;
    
    dist[v1] = 0;
    pq.push(make_pair(dist[v1], v1));
    
    for(int i = 0; i < n - 1; i++) {
        int idx = -1;     
        while(!pq.empty()) {
            pair<long long, int> top = pq.top();
            pq.pop();
            if(visited[top.second] == 0) {
                idx = top.second;
                break;
            }
        }
        if(idx == -1) {
            break;
        }
        visited[idx] = 1;
        
        for(int j = 0; j < graph[idx].size(); j++) {
            int u = graph[idx][j].first;
            if(dist[idx] + graph[idx][j].second < dist[u]){
                dist[u] = dist[idx] + graph[idx][j].second;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
    
    return dist[v2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, e, v1, v2;
    cin >> n >> e;
    vector<vector<pair<int, long long> > > graph(n);
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(make_pair(b, (long long)c));
        graph[b].push_back(make_pair(a, (long long)c));
    }
    cin >> v1 >> v2;
    v1--;
    v2--;
    long long s_v1 = getShortestPath(n, graph, 0, v1);
    long long v1_e = getShortestPath(n, graph, v1, n-1);
    long long s_v2 = getShortestPath(n, graph, 0, v2);
    long long v2_e = getShortestPath(n, graph, v2, n-1);
    long long v1_v2 = getShortestPath(n, graph, v1, v2);
    
    long long ans = INF;
    if(s_v1 < INF && v1_v2 < INF && v2_e < INF) {
        ans = min(ans, s_v1 + v1_v2 + v2_e);
    }
    if(s_v2 < INF && v1_v2 < INF && v1_e < INF) {
        ans = min(ans, s_v2 + v1_v2 + v1_e);
    }
    if(ans == INF) {
        cout << "-1";
    } else {
        cout << ans;
    }
    return 0;
}
