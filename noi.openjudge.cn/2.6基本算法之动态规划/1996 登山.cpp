#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 1005;

int a[maxn], dp[maxn], dq[maxn];


//正反两次LIS
int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    	dp[i] = 1; dq[i] = 1;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++) {
    	for(int j = 1; j < i; j++) {
    		if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
    	}
    	// ans = max(ans, dp[i]);
    }
    for(int i = n-1; i >= 1; i--) {
    	for(int j = n; j > i; j--) {
    		if(a[i] > a[j]) dq[i] = max(dq[i], dq[j]+1);
    	}
    	// ans = max(ans, dq[i]);
    }
    for(int i = 1; i <= n; i++) {
    	ans = max(ans, dp[i]+dq[i]-1);
    }
    cout << ans << endl;
    return 0;
}