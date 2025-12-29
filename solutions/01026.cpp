#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    vector<int> a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tem;
        cin >> tem;
        a.push_back(tem);
    }    
    for(int i = 0; i < n; i++) {
        int tem;
        cin >> tem;
        b.push_back(tem);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++) {
        ans += a[i] * b[n-i-1];
    }
    cout << ans;
    return 0;
}