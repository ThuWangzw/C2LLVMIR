#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main() {
    char s[9] = "ababacaba";
    char p[4] = "aba";
    int pLength = strlen(p);
    int prefix[100];
    prefix[0]=0;
    int k = 0;//前缀的长度
    for(int i=1; i<pLength; i++)
    {
        while(k>0&&p[k]!=p[i])
        {
            k=prefix[k-1];
        }
        if(p[k]==p[i])//说明p[0...k-1]共k个都匹配了
        {
            k=k+1;
        }
        prefix[i]=k;
    }
    int pPoint=0;
    int sLength = strlen(s);
    for(int i=0; i<=sLength-pLength;i++)
    {
        while(pPoint!=0&&(s[i]!=p[pPoint]))
        {
            pPoint = prefix[pPoint-1];
        }
        if(s[i]==p[pPoint])
        {
            pPoint++;
            if(pPoint == pLength)
            {
                printf("找到:%d \n",i-pPoint+1);
                //pPoint = 0;//上一个在s匹配的字符串,不能成为下一个匹配字符串的一部分
                pPoint=prefix[pPoint-1];//上一个在s匹配的字符串,也能成为下一个匹配字符串的一部分
            }
        }
    }
    return 0;
}