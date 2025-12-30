#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n;
    
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        if(minHeap.size() >= maxHeap.size()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        while((!maxHeap.empty() && !minHeap.empty()) && maxHeap.top() > minHeap.top()) {
            int tem = minHeap.top();
            minHeap.pop();
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(tem);
        }
        
        cout << maxHeap.top() << '\n';
    }
    return 0;
}
