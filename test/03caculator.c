#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


/**************************************************************************
int CheckNum(char *c)
���������
    char *c: ������ַ���
���ز�����
    0���ַ������в����Ϲ涨���ַ�
    1: �ַ����ַ����Ϲ涨��û�в����Ϲ涨���ַ�.
���ܣ�
    ����ַ������з���� 0-9, +,-,*,/,(,),֮��������ַ���
    ����У��򷵻�0, ��ʾ���ִ���
    ��û�У��򷵻�1,�ַ������ݺϷ���
**************************************************************************/
int CheckNum(char *c)
{
    char *s=c;
    while(*s!='\0'){
        if((*s>='0' && *s<='9') || *s=='+' ||*s=='-' || *s=='*' || *s=='/' ||*s=='.' || *s=='(' ||  *s==')' ){
            s++;
        }else{
            printf("����:���� %s �����в����Ϲ淶���ַ���\n",c);
            return 0;
        }
    }
    return 1;
}

/**************************************************************************
double StrToNum(char *c)
���������
    char *c :�����ֺ�С������ɵ��ַ�������ת����double�͵���ֵ��
���ز�����
    num:����ת���õ�ֵ��
���ܣ�
    ��������ַ���ת����Double�͵ĸ�����
***************************************************************************/
double StrToNum(char *c)
{
    if(CheckNum(c)==0){
        return -1;
    }
    double num=0;
    int len=strlen(c);
    int start=0,fla=1;  //start���ַ��������ֿ�ʼ��λ�ã�fla����Ƿ��Ǹ���
    if(*c=='-'){
        start=1;
        fla=-1;
    }
    num=c[start]-'0';
    int t=-1;  //С�����ּ��������10��ָ�����ֵ�ֵ
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
���������
    char *s :������ַ���
    int len :�ַ����ĳ���
    int index:��Ҫ�ƶ�����ʼλ��
���ܣ�
    ��������ַ�����λ�õ��ַ�ɾ�����ƶ�������ַ�λ��
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
���������
    char *s :���������
    int len :����ĳ���
    int index:��Ҫ�ƶ�����ʼλ��
���ܣ�
    ������������λ�õ�����ɾ�����ƶ����������λ��
***************************************************************************/
int MyRemove(double *s,int len,int index){
    for(int i=index;i<len-1;i++){
        s[i]=s[i+1];
    }
    return len-1;
}

/**************************************************************************
double MyCalculate(char *c)
���������
    char *c :��������������ַ�������ѧ���ʽ����3.5+(2*3/5)
���ز�����
    s[0]:������������s[0]��
���ܣ�
    ��������ַ����е����ֱַ����convnum(char *c)����������ֵ�任���ٽ�����
    �δ���doulbe s[i]�У����Ӽ��˳���������δ����ַ����������� char f[i]�У�
    Ȼ������������ţ��������ڵ��ַ���������һ�ַ������У�Ȼ���ô�
    good(char *c) �ݹ麯�����еݹ����㡣 Ȼ������ȳ˳�����Ӽ���˳�����
    �����������ֵ�� �ݴ����ַ������������������������㡣�������s[0]�С�
    �������ս����
***************************************************************************/
double MyCalculate(char *c)
{
    //puts(c);
    double digit[100];  //�������������
    char symbol[100];   //��������ķ���
    int di=0;  //����������������
    int si=0;  //�����ַ���������
    int ni=0;  //��¼��Ҫת�������ֵ��ַ��������
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