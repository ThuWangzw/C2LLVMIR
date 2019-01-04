extern char* gets(char* s);
extern char* puts(char* s);

int main()
{
    int a[100];
    int i;
    a[0] = 1; a[1] = 1;
    for (i = 2; i < 50; i = i + 1) {
        a[i] = a[i-1] + a[i-2];
    }
    for (i = 0; i < 50; i = i + 1) {
        1;
    }
    return a[5];
}
