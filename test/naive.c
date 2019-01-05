extern char* gets(char* s);
extern char* puts(char* s);
extern int printf(char *s);

// bug report here
int a = 0; int b = 1;
int s[100];
char str[100];

int func(){
    int i = 0; int len;
    while(str[len] > '\0') {len = len + 1;}
    for (i = 0; i < len; i = i + 1) {
        puts("lalalalal");
    }
    return 0;
}

int main()
{
    // bug 1
    // a = 0; b = 1;
    // if ((a == 0) || (b == 0)) {
    //     puts("lalalalal");
    //     s[10] = 9;
    // }

    // bug 2
    puts("请输入表达式");
    printf("后缀表达式为:");
    gets(str);
    func();
    return 0;
}
