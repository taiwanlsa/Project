#include <stdio.h>
#include <stdlib.h> 

int check_ID(int *, int *, int N);
int remove_ID(int *, int*, int N);
void new_ID(int *, int *, int N);


int superID= 0x12345678;


int main(int argc, char *argv[]){

    int n = 2;
    int *ID_list;
    char mode;
    int ID;

    ID_list = calloc(1000,sizeof(int));
    ID_list[0]=0xDEADDEAD;
    ID_list[1]=0x87654321;

    while(1){

SYS_LOOP:
        printf(">請輸入卡號：");
        scanf("%x", &ID);

  
        if(ID == superID)
        {
super_USER: 
            printf("-------\e[38;5;10msuperID mode：\e[m------\n");
            printf("新增卡號(a),移除卡號(d),離開超級帳號(e):\n");
            printf("n = %d", n);
            scanf("%s", &mode);

            
            switch (mode)
            {
                case 'a'://新增卡號
                    new_ID(&ID, ID_list, n);
                    n++;
                    goto super_USER;

                case 'd'://移除卡號
                    remove_ID(&ID, ID_list, n);
                    goto super_USER;

                case 'e'://離開
                    printf("已離開超級帳號\n");
                    goto SYS_LOOP;
            }
        }

        //檢查是否為合法ID
        check_ID(&ID, ID_list, n);
    }

    return 0;
}

//funtion區域：

//檢查ID
int check_ID(int * id, int *list, int N){
    //---------------------
    printf("N = %d\n",N);

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