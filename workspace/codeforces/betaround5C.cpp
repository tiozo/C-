#include<bits/stdc++.h>
using namespace std;

const int maxlen = 1e6;
int E[maxlen+1], S[maxlen+1], F[maxlen+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    //cout << s << '\n';
    int mx = 0;
    stack<int> st;
    for (int i=0;i<s.size();++i) {
        char c = s[i];
        if (c=='(') {
            st.push(i);
        } else {
            if (st.empty()) {
                S[i] = E[i] = -1;
            } else {
                int id = st.top();
                st.pop();
                S[i] = E[i] = id;
                if (id>0 && s[id-1]==')' && S[id-1]>=0) {
                    E[i] = E[id-1];
                }
                int l = i-E[i]+1;
                F[l]++;
                mx = max(mx,l);
            }
        }
    }
    F[0] = 1;
    cout << mx << ' ' << F[mx];
    return 0;
}