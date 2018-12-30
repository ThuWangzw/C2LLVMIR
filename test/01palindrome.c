#include <stdio.h>
#include <string.h>
#include <string.h>
int main(){
    char s[100];  // 存放输入的字符串 
    int i;
    int j;
    int n;
    printf("输入字符串：");
    gets(s);
    
    n=strlen(s);
    i=0;
    j=n-1;
    while (i<j) {
        if(s[i]!=s[j]) break;
        if(i>=j)
            printf("是回文串\n");
        else
            printf("不是回文串\n");
        i = i + 1;
        j = j - 1;
    }
    return 0;
}