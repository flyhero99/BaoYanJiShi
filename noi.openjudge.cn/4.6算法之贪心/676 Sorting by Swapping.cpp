#include <cstdio>
#include <cstring>
#define MAX 10000 + 10

int a[MAX];

void swap( int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    return ;
}

int main()
{
    int t;
    scanf("%d", &t);

    while ( t --){
        int n;
        scanf("%d", &n);

        for ( int i = 0; i < n; i ++){
            scanf("%d", &a[i + 1]);
        }

        int ans = 0;
        for ( int i = 1; i <= n; i ++){
            while ( i != a[i]){
                ans ++;
                swap( i, a[i]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}