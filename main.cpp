#include<cmath>
#include<cstdio>
 
using namespace std;
 
int T = 0, n;
int circle[20];
bool used[20];
 
bool is_prime(int p) {
    for(int i = 2; i <= sqrt(p); i++)
        if(p % i == 0) return false;
    return true;
}
 
void search(int m) {
    if(m == n - 1 && is_prime(circle[n - 1] + circle[n])) {
        for(int i = 0; i < n; i++)
            printf(i == n - 1? "%d" : "%d ", circle[i]);
        printf("\n");
        return;
    }
    for(int i = 2; i <= n; i++)
        if(!used[i] && is_prime(circle[m] + i)) {
            used[i] = true;
            circle[m + 1] = i;
            search(m + 1);
            used[i] = false;
        }
}
 
int main() {
    while(scanf("%d", &n) == 1) {
        T++;
        if(T > 1) printf("\n");
        circle[0] = circle[n] = 1;
        printf("Case %d:\n", T);
        search(0);
    }
}