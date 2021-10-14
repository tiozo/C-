#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a;i<b;++i)
bool check(string x,int i, int l){
	rep(j,l,i){
		if (x[j]==x[i]) return 0;
	}
	return 1;
}
vector<string> a;
void per(string x, int l, int h){
	if (l==h) a.push_back(x);
	rep(i,l,h+1){
		if (check(x,i,l)) {
			swap(x[i],x[l]);
			per(x,l+1,h);
			swap(x[i],x[l]);
		}
	}
}

#define all(p) p.begin(),p.end()
int main() {
    string s; cin >> s;
    per(s,0,s.size()-1);
    sort(all(a));
    cout << a.size() << '\n';
    for (auto &a:a) {
        cout << a << '\n';
    }
    return 0;
}