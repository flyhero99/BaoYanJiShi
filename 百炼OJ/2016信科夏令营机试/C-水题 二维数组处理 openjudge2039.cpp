#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100005;

int main() {
    int rol, col;
    string str;
    cin >> col >> str;
    rol = str.length() / col;
    // cout << "rol: " << rol << " col: " << col << endl;
    char mp[105][105];
    for(int i = 1; i <= rol; i++) {
        if(i & 1) {
            for(int j = 1; j <= col; j++) {
                mp[i][j] = str[(i-1)*col+j-1];
            }
        }
        else {
            for(int j = 1; j <= col; j++) {
                mp[i][j] = str[i*col-j];
            }
        }
    }
    // for(int i = 1; i <= col; i++) {
    //     for(int j = 1; j <= rol; j++) {
    //         cout << mp[i][j];
    //     }
    // }
    for(int i = 1; i <= col; i++) {
        for(int j = 1; j <= rol; j++) {
            cout << mp[j][i];
        }
    }cout << endl;
    return 0;
}