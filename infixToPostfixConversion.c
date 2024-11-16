#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
int main() {
    char infix[MAX];
    printf("Enter the infix expression : ");
    scanf("%d",infix);
    char postfix[MAX],stack[MAX];
    int top=-1,k=0,i=0;
    
    while(infix[i]!='\0') {
        char c=infix[i];
        if(isalpha(c)) {
            postfix[k++]=c;
        }
        else if(c=='(') {
            stack[top++]=c;
        }
        else if(c=='(') {
            while(top!=-1 && stack[top]!='(') {
                postfix[k++]=stack[top--];
            }
            if(top!=-1 && stack[top]!='(') {
                top--;
            }
        }
        else {
            int precedence(char op) {
                switch(op) {
                    case '+':
                    case '-': return 1;
                    case '*':
                    case '/': return 2;
                    case '^': return 3;
                    default : return 0;
                }
            }
            while(top!=-1 && precedence(stack[top])>=precedence(c)) {
                postfix[k++]=stack[top--];
            }
            stack[top++]=c;
        }
        i++;
    }
    while(top!=-1) {
        postfix[k++]=stack[top--];
    }
     postfix[k]='\0';
    printf("Infix Expression :%s\n",infix);
    printf("Postfix Expression :%s\n",postfix);
    return 0;
}