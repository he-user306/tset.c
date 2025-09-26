#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_KEY 11
#define MAX_VALUE 11
#define MAX_KEY_VALUE_PAIRS 100
#define MAX_LINE 100
typedef struct{
    char key[MAX_KEY];
    char value[MAX_VALUE];//定义结构体
}keyvalue;
int main(){
    char line[MAX_LINE];
    keyvalue keyvalues[MAX_KEY_VALUE_PAIRS];
    FILE* file = fopen("D:\\code\\data.txt", "r");//打开文件
    int count = 0;
    if(file == NULL){
        printf("无法打开文件\n");
        return 1;
    }
    while(fgets(line, MAX_LINE, file) != NULL){
        int len = strlen(line);//去空行
        if(len == 0){
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        char* a = strchr(line, ':');//找：位置
        if(a == NULL){
            continue;//去除没有冒号
        }
        char key[MAX_KEY] = {0};
        char value[MAX_VALUE] = {0};
        int keylen = a - line;
        int valuelen = strlen(a + 1);
        char* b = a + 1;
        strncpy(key, line, MAX_KEY);//分割键和值
        strncpy(value, b, MAX_VALUE);
        key[keylen] = '\0';
        value[valuelen] = '\0';
        if(keylen <= 0|| valuelen <= 0|| keylen > 10 || valuelen > 10){
            continue;
        }
        if(keylen <= 10 && valuelen<= 10 && keylen > 0 && valuelen > 0){
            strcpy(keyvalues[count].key, key);
            strcpy(keyvalues[count].value, value);
            count++;
        }
    }
    fclose(file);
    char input[MAX_KEY];
    while(1){
        printf("请输入键:");
        scanf("%s", input);
        if(strcmp(input, "Quit") == 0){
            break;
        }
        int found = 0;
        for(int i = 0; i < count; i++){
            if(strcmp(input, keyvalues[i].key) == 0){//对照输入和键
                printf("%s\n", keyvalues[i].value);//输出键
                found = 1;
            }
        }
        if(!found){
            printf("error\n");
        }
    }
    return 0;
}