#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int n, int c, int m) {
    c--;
    int last = 0;
    bool ret = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] - arr[last] >= m) {
            c--;
            last = i;
            if(c == 0) {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, c;
    vector<int> arr;
    cin >> n >> c;
    
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int l = 1, h = 1000000001;
    while(l + 1 < h) {
        int m = (l + h) / 2;
        if(check(arr, n, c, m)) {
            l = m;
        } else {
            h = m;
        }
    }
    
    cout << l;
    return 0;
}
