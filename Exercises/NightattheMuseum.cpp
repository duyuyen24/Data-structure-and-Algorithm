//https://codeforces.com/problemset/problem/731/A
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
char a[105];
int main(){
    char now;
    scanf("%s", a);
    now = 'a';
    int ans = 0;
    for(int i=0; a[i]; i++){
        ans += min(abs(a[i]-now), min(abs(a[i]+26-now),abs(now+26-a[i])));
        now = a[i];
    }
    printf("%d\n",ans);
    return 0;
}
