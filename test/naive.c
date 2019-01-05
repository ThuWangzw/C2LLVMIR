extern char* gets(char* s);
extern char* puts(char* s);
extern int printf(char *s);

int max(int a, int b) {
    int ans;
    if (a > b) { ans = a; }
    else {ans = b;}
    return ans;
}

int main()
{
    // a = 10;
    // char b[100];
    int ans;
    ans = max(1, 0);
    // a = 't';
    printf("result %d", ans);
    // gets(b);
    // puts(b);
    return 0;
}
