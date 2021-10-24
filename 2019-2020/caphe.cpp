#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int maxm = 10010;
int call[maxm];

int main() {
    int n; cin >> n;
    int t1,t2; cin >> t1 >> t2;
    int m; cin >> m;
    int q = m;
    int cur_time = 0,cur_table = 1;
    double long sum = 0;  
    while (q--) {
        int timecall, ith_table;
        cin >> timecall >> ith_table;
        if (timecall > cur_time) cur_time = timecall;
        if (ith_table == cur_table)  {
            goto done;
        } else {
            int with_clock = abs(ith_table - cur_table);
            int counter_clock = n - with_clock;
            if (with_clock <= counter_clock) {
                cur_time += t1 * with_clock;
                cur_table = ith_table;
                //cout << with_clock << ' ';
            } else {
                cur_time += t1 * counter_clock;
                cur_table = ith_table;
                //cout << counter_clock << ' ';
            }
        }
        done:
        cur_time += t2;
        sum = sum + (cur_time - timecall);
        cout << cur_time << ' ' << cur_time - timecall << '\n';
    }
    cout << fixed << setprecision(3) << (sum/m);
    return 0;
}

/*
    coffee table is a round sequence
    robot di chuyen theo cac buc tuong.
    the wall is also a round seq
    the call is sort from small -> large
    move shortest distant 
    ton t1 giay phuc vu, t2 giay dua thuc uong.
    test case
10
2 11
6 
10 1
21 1
22 7
23 2
200 2
201 1
    u -> v in t1 time
    u -> u in t2 time
    stand by at u
    printf avg time
    phan tich de
    q1: bot doesn't move 
    cur += t2; 21 
    q2: 32
    q2: call at 22 but doing till 32 so order will be take at 32
    cur += t2; 
    q3: no longger at table 1 its at table 7
    7 - 1 + 1 > half so its move from
    1 -> 10 -> 9 -> 8 -> 7 
    cur += t1 * 4 + t2 = 51
    7 -> 8 -> 9 -> 10 -> 1 -> 2 // equal
    7 -> 6 -> 5 -> 4 -> 3 -> 2
    cur += t1 * 5 + 11; = 72
    stay at 2 
    cur 211
    cur 201
    11 sec
    11
    29 sec
    49 sec
    11
    23
*/