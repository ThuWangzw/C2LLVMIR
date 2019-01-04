#include<stdio.h>
#include<string.h>
int main(void)
{
    char string[100];
    int index = 1;
    int sum = 0;
    int temval = 1;
    char ope, c,inope;
    memset(string, 0, 100);
    scanf("%s",string);

    sum += (string[0] - 48);
    while(string[index] != '\0')
    {
        c = string[index];
        switch(c)
        {
            case '+':ope = '+';index++;
                break;
            case '-':ope = '-';index++;
                break;
            case '*':ope = '*';index++;
                break;
            case '/':ope = '/';index++;
                break;
            default:temval = c - 48;index++;
                while(string[index] != '+' && string[index] != '-'&&string[index] != '\0')
                {
                    inope = string[index];
                    if(inope == '*')
                    {
                        temval *= (string[++index] - 48);
                        index++;
                    }
                    if(inope == '/')
                    {
                        temval /= (string[++index] - 48);
                        index++;
                    }
                }
                if(ope =='+')
                {
                    sum +=temval;
                }
                if(ope == '-')
                {
                    sum -= temval;
                }
        }
    }
    printf("\n表达式%s的值为:%d\n",string,sum);
    return 0;
}