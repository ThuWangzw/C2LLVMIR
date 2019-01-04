extern char* gets(char* s);
extern char* puts(char* s);
int main(){
    char s[100];  // 存放输入的字符串
    int i;
    int j;
    int n;
    int flag = 1;
    int zeroflag = 1;
    for(i=0;i<100;i = i + 1)
    {
        s[i] = '\0';
        1;
    }
    gets(s);
    for(i=0;(i<100)&&(zeroflag==1);i = i + 1)
    {
        if(s[i]=='\0'){
            n = i;
            zeroflag = 0;
        }
    }
    i=0;
    j=n-1;
    while ((i!=j)&&(flag == 1)) {

        if(s[i]!=s[j]){
            flag = 0;
            puts("no");
        }
        if(i==j){
            puts("yes");
            1;
        }
        i = i + 1;
        j = j - 1;
    }
    return 0;
}