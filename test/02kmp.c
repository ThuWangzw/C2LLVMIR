extern char* gets(char *s);
extern char* puts(char *s);
extern int printf(char *s);

int main() {
    char s[100];
    char p[100];
    int prefix[100];
    int k = 0; int j = 0;
    int i = 1; int plen = 0; int slen = 0;
    int found_match = 0;

    puts("输入目标串");
    gets(s);
    puts("输入模式串");
    gets(p);
    while(s[slen] > '\0') { slen = slen + 1; }
    while(p[plen] > '\0') { plen = plen + 1; }
    prefix[0] = 0;

    for(i=1; i < plen; i = i + 1) {
        while(k>0 && p[k]!=p[i]) { k=prefix[k-1]; }
        if(p[k]==p[i]) {
            //说明p[0...k-1]共k个都匹配了
            k=k+1;
        }
        prefix[i]=k;
    }
    for(i=0; i < slen;i = i + 1) {
        while(j!=0&&(s[i]!=p[j])) {
            j = prefix[j-1];
        }
        if(s[i]==p[j]) {
            j = j + 1;
            if(j == plen) {
                found_match = found_match + 1;
                printf("found match in postion %d\n",i-j+1);
                //j = 0;//上一个在s匹配的字符串,不能成为下一个匹配字符串的一部分
                j = prefix[j-1];//上一个在s匹配的字符串,也能成为下一个匹配字符串的一部分
            }
        }
    }
    if (found_match == 0) { puts("pattern string not found"); }
    return 0;
}