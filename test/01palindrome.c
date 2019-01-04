#include <stdio.h>
#include <string.h>
#include <string.h>
int main(){
    char s[100];  // 存放输入的字符串 
    int i;
    int j;
    int n;
    gets(s);
    
    n=strlen(s);
    i=0;
    j=n-1;
    while (i<=j) {
        if(i==j){
            //printf("是回文串\n");
            break;
        }
        if(s[i]!=s[j]){
            //printf("不是回文串\n");
            break;
        }
        i = i + 1;
        j = j - 1;
    }
    return 0;
}