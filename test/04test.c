extern char* puts(char* s);
extern int printf(char* s);
int max(int a, int b){
    int c = 0;
    if(a>b){
        c = a;
    } else{
        c = b;
    }
    if((c>0)||(c<0)){
        printf("then");
    } else{
        printf("else");
    }
    return c;
}

int main(){
    char a[100];
    a[1];
    //max(123,456);
    printf("%d",max(123,456));
    return 0;
}