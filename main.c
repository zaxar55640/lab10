#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char n[100];
int sum = 0;
int num_sum(int n){
    int i;
    if (n/10 == 0) {
        sum = sum + n;
        return sum;
    }
    if (n/10 != 0){
        i = n % 10;
        n = n / 10;
    }
    sum = sum + i;
    num_sum(n);
}
void del_spc(char * n, int k){
    int i = 0;
    if (n[i] == ' ' && n[i+1] == ' ')
        del_spc(n, k + 1);
    if (n[i] == '(' && n[i+1] == ' ')
        del_spc(n, k + 1);
    for (i = k; i < strlen(n) - 1; i++)
        n[i] = n[i + 1];
    n[i] = 0;
}
int main() {

    int i;
    scanf("%[^\n]s", n);
    for (i = 0; i < strlen(n); i++)
    {
        if((n[i] == ' ' && n[i + 1] == ' ') || (n[i] == '(' && n[i + 1] == ' '))
            del_spc(n, i+1);
    }
    printf("%s", n);
    int k;
    scanf("%d", &k);
    int x = num_sum(k);
    printf("%d", x);

    return 0;

}