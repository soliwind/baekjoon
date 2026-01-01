#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, k;
    cin >> n >> k;
    long long l = 0, h = 10000000000;
    while(l + 1 < h) {
        long long m = (l + h) / 2;
        long long cnt = 0;
        for(long long i = 1; i <= n; i++) {
            cnt += min(m / i, n);
        }
        if(cnt >= k) {
            h = m;
        } else {
            l = m;
        }
    }
    cout << h;
    return 0;
}