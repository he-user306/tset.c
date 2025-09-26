#include<stdio.h>
#include<string.h>
int main()
{
    char input[20];
    while (1) {
        printf("请输入：");
        scanf("%s", input);
        if(strcmp(input, "dian") == 0){
            printf("2002\n");
        }
        else if(strcmp(input, "Quit") == 0){
            printf("退出程序\n");
            break;
        }
        else{
            printf("error\n");
        }
    }
    return 0;
}