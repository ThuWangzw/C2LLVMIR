#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


/**************************************************************************
int CheckNum(char *c)
输入参数：
    char *c: 输入的字符串
返回参数：
    0：字符串中有不符合规定的字符
    1: 字符串字符符合规定，没有不符合规定的字符.
功能：
    检查字符串中有否除了 0-9, +,-,*,/,(,),之外的其他字符，
    如果有，则返回0, 表示出现错误。
    若没有，则返回1,字符串内容合法。
**************************************************************************/
int CheckNum(char *c)
{
    char *s=c;
    while(*s!='\0'){
        if((*s>='0' && *s<='9') || *s=='+' ||*s=='-' || *s=='*' || *s=='/' ||*s=='.' || *s=='(' ||  *s==')' ){
            s++;
        }else{
            printf("错误:数字 %s 里面有不符合规范的字符。\n",c);
            return 0;
        }
    }
    return 1;
}

/**************************************************************************
double StrToNum(char *c)
输入参数：
    char *c :由数字和小数点组成的字符，用以转换成double型的数值。
返回参数：
    num:返回转换好的值。
功能：
    将输入的字符串转化成Double型的浮点数
***************************************************************************/
double StrToNum(char *c)
{
    if(CheckNum(c)==0){
        return -1;
    }
    double num=0;
    int len=strlen(c);
    int start=0,fla=1;  //start是字符串的数字开始的位置，fla标记是否是负数
    if(*c=='-'){
        start=1;
        fla=-1;
    }
    num=c[start]-'0';
    int t=-1;  //小数部分计算过程中10的指数部分的值
    bool hasPoint=false;
    for(int i=start+1;i<len;i++){
        if(c[i]=='.'){
            hasPoint=true;
            continue;
        }
        if(hasPoint){
            num=num+(c[i]-'0')*pow(10,t);
            t--;
        }else{
            num=num*10+c[i]-'0';
        }
    }
    return num*fla;
}

/**************************************************************************
int MyRemove(char *s,int len,int index){
输入参数：
    char *s :输入的字符串
    int len :字符串的长度
    int index:需要移动的起始位置
功能：
    将输入的字符串该位置的字符删掉，移动后面的字符位置
***************************************************************************/
int MyRemove(char *s,int len,int index){
    int i;
    for(i=index;i<len-1;i++){
        s[i]=s[i+1];
    }
    s[i]='\0';
    return len-1;
}

/**************************************************************************
int MyRemove(double *s,int len,int index){
输入参数：
    char *s :输入的数组
    int len :数组的长度
    int index:需要移动的起始位置
功能：
    将输入的数组该位置的数字删掉，移动后面的数字位置
***************************************************************************/
int MyRemove(double *s,int len,int index){
    for(int i=index;i<len-1;i++){
        s[i]=s[i+1];
    }
    return len-1;
}

/**************************************************************************
double MyCalculate(char *c)
输入参数：
    char *c :即将进行运算的字符串型数学表达式。如3.5+(2*3/5)
返回参数：
    s[0]:计算结果将放入s[0]中
功能：
    将输入的字符串中的数字分别调用convnum(char *c)函数进行数值变换，再将其依
    次存入doulbe s[i]中，将加减乘除运算符依次存入字符串符号数组 char f[i]中，
    然后如果遇到括号，则将括号内的字符串存入另一字符数组中，然后用此
    good(char *c) 递归函数进行递归运算。 然后根据先乘除，后加减的顺序对已
    存入数组的数值根 据存入字符串符号数组的运算符进行运算。结果存入s[0]中。
    返回最终结果。
***************************************************************************/
double MyCalculate(char *c)
{
    //puts(c);
    double digit[100];  //四则运算的数字
    char symbol[100];   //四则运算的符号
    int di=0;  //保存数字数组的序号
    int si=0;  //保存字符数组的序号
    int ni=0;  //记录需要转化成数字的字符串的序号
    while(*c!='\0'){

        char num[22];
        switch(*c){
            case '+':
            case '-':
            case '*':
            case '/':
                symbol[si++]=*c;
                if(*(c-1)!=')'){
                    num[ni]='\0';
                    ni=0;
                    digit[di++]=StrToNum(num);
                }
                break;
            case '(':
                {
                    int k=1;
                    char str[100];
                    int j=0;
                    while(k>0){
                        c++;
                        str[j++]=*c;
                        if(*c=='('){
                            k++;
                        }else if(*c==')'){
                            k--;
                        }

                    }
                    str[j-1]='\0';
                    digit[di++]=MyCalculate(str);
                    break;
                }
            default:
                num[ni++]=*c;
                if(*(c+1)=='\0'){
                    num[ni]='\0';
                    ni=0;
                    digit[di++]=StrToNum(num);
                }
                break;
        }
        c++;
    }
    symbol[si]='\0';
    for(int i=0;i<si;i++){
        if(symbol[i]=='*'){
            digit[i+1]=digit[i]*digit[i+1];
            di=MyRemove(digit,di,i);
            si=MyRemove(symbol,si,i);
        }else if(symbol[i]=='/'){
            digit[i+1]=digit[i]/digit[i+1];
            di=MyRemove(digit,di,i);
            si=MyRemove(symbol,si,i);
        }
    }
    for(int i=0;i<si;i++){
        if(symbol[i]=='+'){
            digit[i+1]=digit[i]+digit[i+1];
            di=MyRemove(digit,di,i);
            si=MyRemove(symbol,si,i);
        }else if(symbol[i]=='-'){
            digit[i+1]=digit[i]-digit[i+1];
            di=MyRemove(digit,di,i);
            si=MyRemove(symbol,si,i);
        }
    }
    return digit[0];
}


int main()
{
    char str[11111],s1[999];

    //2.3*((2+3)*3+1)+11
    while(scanf("%s",s1)!=EOF){
        //printf("-----%d\n",strlen(s1));
        strcat(str,s1);
    }
    puts(str);
    printf("%s = %lf\n",str,MyCalculate(str));
    return 0;
}