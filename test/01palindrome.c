extern char* gets(char* s);
extern char* puts(char* s);

int main()
{
    char a[100];
    int len = 0;
    int i = 0;
    int flag = 1;
    puts("please input a string");
    gets(a);
    while(a[len] > '\0') {len = len + 1;}
    for( i = 0; flag > 0 && i <= len/2 ;i = i + 1)
    {
        if(a[i]!=a[len-i-1])
        {
            puts("False");
            flag = 0;
        }
    }
    if (flag == 1) { puts("True"); }
    return 0;
}