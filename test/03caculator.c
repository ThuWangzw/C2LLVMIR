extern char* gets(char* s);
extern char* puts(char* s);
extern int printf(char* s);

char str[100];
char stack[100];
char postfix[100];
int top = 0; int post_index = 0;

int push(char c) {stack[top] = c; top = top + 1; return 0;}
int put_post(char c) { postfix[post_index] = c; post_index = post_index + 1; return 0; }
char pop() {top = top - 1; return stack[top];}
char get_top() {return stack[top - 1];}

int toPostfix() {
    int len; int i; int flag = 0; char c;
    while(str[len] > '\0') { len = len + 1; }
    push('#');
    for (i = 0; i < len; i = i + 1) {
        if (str[i] >= '0' && str[i] <= '9') { put_post(str[i]); }
        if (str[i] == '('){ push('('); }
        if (str[i] == ')'){
            flag = 1;
            while (flag > 0) {
                c = get_top();
                if (c == '(') {flag = 0;}
                else { pop(); put_post(c); }
            }
        }
        if (str[i] == '+' || str[i] == '-'){
            flag = 1;
            while (flag > 0) {
                c = get_top();
                if (c == '(' || c == '#') {flag = 0;}
                else { pop(); put_post(c); }
            }
            push(str[i]);
        }
        if (str[i] == '*' || str[i] == '/'){
            flag = 1;
            while (flag > 0) {
                c = get_top();
                if (c == '(' || c == '#' || c == '+' || c == '-') {flag = 0;}
                else { pop(); put_post(c); }
            }
            push(str[i]);
        }
    }
    return 0;
}

int main() {
    puts("请输入表达式");
    gets(str);
    toPostfix();
    puts(postfix);
    return 0;
}