#include<bits/stdc++.h>
using namespace std;
#define int long long
string ans="";
const long long mod = 727355608;

void solve() {
    int s; cin >> s;
    vector<int> ch(4,0); cin >> ch[1] >> ch[2] >> ch[3];
    ch[0] = s - ch[1] - ch[2] - ch[3];
    string mid = "";
    if (s%2==0) {
        for (auto c:ch) {
            if (c%2) {
                cout << "Bedao!" << '\n';
                return;
            }
        }
    } else {
        for (int i=0;i<4;++i) {
            if (ch[i]%2) {
                if (mid!="") {
                    cout << "Bedao!" << '\n';
                    return;
                }
                mid += char('0'+i);
                ch[i]--;
            }
        } 
    }
    for (int i=0;i<4;++i) {
        if (i>0) {
            if (ch[i]) {
                ans += char('0'+i);
                ch[i] -= 2;
                break;
            }
        }
    }
    if (ans=="" && s>1) {
        cout << "Bedao!" << '\n';
        return;
    }
    for (int i=0;i<4;++i) {
        for (int j=0;j<ch[i]/2;++j) {
            ans += char('0'+i);
        }
    }
    string right = ans;
    reverse(right.begin(),right.end());
    ans = ans + mid + right;
    long long res = 0;
    for (char c:ans) {
        res = (res*4+(c-'0'))%mod;
    }
    cout << res << '\n';
}

int32_t main() {
    solve();
    return 0;
}

/*
    3
    2 1 0
    a = 2
    b = 1
    c = 0
    2 1 2
    a + b + c == S
    S%2!=0
    chon ra a thang nho nhat. 

    3 
    1 2 
    212
*/