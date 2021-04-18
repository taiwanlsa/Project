#include <stdio.h>
#include <string.h>


//funtion區域：

//檢查ID
int check_ID(int * id, int *list, int N){

    for(int i =0; i < N; i++ ){
        if(*id == *(list + i)){
            printf("-------\e[38;5;10m[ACCESS]\e[m------\n");
            return 0;
        }
    }

    printf("------\e[38;5;9m[invalid]\e[m------\n");
    return 1;
}

//新增ID
void new_ID(int *id, int *list, int N){

    printf("輸入要新增的卡號:\n");
    scanf("%x", id);
    
    *(list + N) = *id;
    printf("卡號%x新增成功:\n",*(list + N));

    
}


//移除ID
int remove_ID(int *id, int *list, int N){

    
    printf("輸入要移除的卡號:\n");
    scanf("%x",id);
    for(int i =0; i < N; i++ ){
        if(*id == *(list + i)){
            *(list + i) = 0;
            printf("卡號%x已移除\n", *id);
            return 0;
        }
        
    }
    printf("查無卡號\n");
    return 1;
    
}