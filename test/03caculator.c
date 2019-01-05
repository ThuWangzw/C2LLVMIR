extern char* gets(char* s);
extern char* puts(char* s);
extern int printf(char* s);

char str[100];
char char_stack[100];
int char_top = 0;
int num_stack[100];
int num_top = 0;
char postfix[100];
int post_index = 0;

int push_char(char c) { char_stack[char_top] = c; char_top = char_top + 1; return 0; }
char pop_char() { char_top = char_top - 1; return char_stack[char_top]; }
char get_top_char() {return char_stack[char_top - 1]; }

int push_int(int t) { num_stack[num_top] = t; num_top = num_top + 1; return 0; }
int pop_int() { num_top = num_top - 1; return num_stack[num_top]; }
int get_top_int() { return num_stack[num_top - 1]; }

int push_post(char c) { postfix[post_index] = c; post_index = post_index + 1; return 0; }

int lower_than_plus(char s){
    int res = 0;
    if (s == '#' || s == '(') {res = 1;}
    return res;
}
int lower_than_mul(char s){
    int res = 0;
    if (s == '#' || s == '(' || s == '+' || s == '-') {res = 1;}
    return res;
}
int get_num(char s){
    int ans = 0;
    if (s == '0') { ans = 0; }
    if (s == '1') { ans = 1; } if (s == '2') { ans = 2; } if (s == '3') { ans = 3; }
    if (s == '4') { ans = 4; } if (s == '5') { ans = 5; } if (s == '6') { ans = 6; }
    if (s == '7') { ans = 7; } if (s == '8') { ans = 8; } if (s == '9') { ans = 9; }
    return ans;
}

int toPostfix() {
    int len; int i = 0; int flag = 0; char c;
    char_top = 0;
    while(str[len] > '\0') { len = len + 1; }
    push_char('#');
    for (i = 0; i < len; i = i + 1) {
        if (str[i] >= '0' && str[i] <= '9') { push_post(str[i]); }
        if (str[i] == '('){ push_char('('); }
        if (str[i] == ')'){
            flag = 1;
            while (flag > 0) {
                c = get_top_char();
                if (c == '(') { pop_char(); flag = 0; }
                else { pop_char(); push_post(c); }
            }
        }
        if (str[i] == '+' || str[i] == '-') {
            flag = 1;
            while (flag > 0) {
                c = get_top_char();
                if (lower_than_plus(c) > 0) { flag = 0; }
                else { pop_char(); push_post(c); }
            }
            push_char(str[i]);
        }
        if (str[i] == '*' || str[i] == '/'){
            flag = 1;
            while (flag > 0) {
                c = get_top_char();
                if (lower_than_mul(c) > 0) { flag = 0; }
                else { pop_char(); push_post(c); }
            }
            push_char(str[i]);
        }
    }
    while(char_top > 0) {
        c = pop_char(); 
        if (c != '#') {push_post(c);}
    }
    return 0;
}

int calculate() {
    int i; int left; int right; int len; int result; int zero_flag = 0;
    num_top = 0;
    while(postfix[len] > '\0') { len = len + 1; }

    for (i = 0; zero_flag == 0 && i < len; i = i + 1) {
        if (postfix[i] >= '0' && postfix[i] <= '9'){
            push_int(get_num(postfix[i]));
        }
        if (postfix[i] == '+') {
            right = pop_int();
            left = pop_int();
            push_int(left + right);
        }
        if (postfix[i] == '-') {
            right = pop_int();
            left = pop_int();
            push_int(left - right);
        }
        if (postfix[i] == '*') {
            right = pop_int();
            left = pop_int();
            push_int(left * right);
        }
        if (postfix[i] == '/') {
            right = pop_int();
            left = pop_int();
            if (right == 0) { puts("divided by zero."); zero_flag = 1;}
            else { push_int(left / right); }
        }
    }
    if (zero_flag == 0) { printf("计算结果为: %d\n", get_top_int()); }
    return 0;
}

int main() {
    puts("请输入表达式");
    gets(str);
    toPostfix();
    printf("后缀表达式为:");
    puts(postfix);
    calculate();
    return 0;
}