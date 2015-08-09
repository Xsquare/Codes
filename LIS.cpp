#include <bits/stdc++.h>
//not for strictly increasing
using namespace std;
vector<int> d;
int ans, n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        vector <int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else (*it) = x;
    }
    printf("%d", (int)d.size());
    return 0;
}
