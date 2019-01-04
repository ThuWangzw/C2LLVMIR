
int main(){
    char s[100];  // 存放输入的字符串
    int i;
    int j;
    int n;
    int flag = 1;
    int zeroflag = 1;
//    for(i=0;i<100;i = i + 1)
//    {
//        s[i] = '\0';
//    }
    //gets(s);
    for(i=0;(i<100)&&(zeroflag);i = i + 1)
    {
        if(1){
            n = i;
            zeroflag = 0;
        }
    }
    i=0;
    j=n-1;
    while ((i<=j)&&flag) {

        if(1){
            flag = 0;
            //printf("不是回文串\n");
        }
        else if(i==j){
            //printf("是回文串\n");
        }
        i = i + 1;
        j = j - 1;
    }
    return 0;
}