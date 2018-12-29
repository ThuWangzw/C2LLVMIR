#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*next数组下标表示字符串长度，因此初始化要多初始化一个位置*/
void compute_next(char *s, int *next)
{
    int i = 0, len = strlen(s);
    int k = 0;

    next[0] = next[1] = 0;
    for(i = 1; i < len; i++)
    {
        while(k > 0 && s[k] != s[i])
            k = next[k];
        if(s[k] == s[i])
            k++;
        next[i+1] = k;
    }
}

char *kmp_strstr(char *s, char *t)
{
    int s_len, t_len, i, j=0;
    int *next = NULL;

    if(!s || !t)
        return NULL;    

    s_len = strlen(s);
    t_len = strlen(t);
    if(t_len == 0)
        return s;
    next = (int *)malloc(sizeof(int) * (t_len + 1));
    if(!next)
        return NULL;

    compute_next(t, next);

    for(i = 0; i < s_len; i++)
    {
        while(j > 0 && s[i] != t[j])
            j = next[j];
        if(s[i] == t[j])
            j++;
        if(j == t_len)
        {
            //printf("match %d\n", i-j+1);
            free(next);
            return s+i-j+1;
        }
    }

    free(next);
    return NULL;
}

int main(int argc, char *argv[])
{
    char *s;
    s = kmp_strstr(argv[1], argv[2]);
    printf("%s\n", s?s:"NULL");
    printf("%s\n", strstr(argv[1], argv[2])?:"NULl");
    return 0;
}