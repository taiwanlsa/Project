#include <stdio.h>
#include <stdlib.h> 

#include "cardOpt.h"


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
            
            printf("-----\e[38;5;10m[superID mode]\e[m----\n");
            printf("新增卡號(a),移除卡號(d),離開超級帳號(e):\n");
            //printf("n = %d", n);
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

