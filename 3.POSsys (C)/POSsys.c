#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define meals_number 5
#define STRLEN_BET 25

//物件化，以後更新才方便
typedef struct product
{
    char name[STRLEN_BET];
    unsigned int price;
    int *next; 
} Product;

typedef struct order_list
{
    char name[STRLEN_BET];
    unsigned int oder_amount;
    unsigned int subtotal;
} Order_list;




int main(int argc, char *argv[])
{
    Product breakfast[meals_number] = {
        {.name = "三明治", .price = 15},
        {.name = "漢堡", .price = 30},
        {.name = "蛋餅", .price = 15},
        {.name = "豆漿", .price = 20},
        {.name = "奶茶", .price = 20},
    };


    Order_list order[meals_number];

    int list_count = 0;
    int totla_Price = 0;
    unsigned int amount = 0;




    while (1){

Order:        
        printf("\e[38;5;15m請點餐:\em");
        scanf("%s",order[list_count].name);

        if(!strcmp(order[list_count].name,"菜單"))
        {
            printf("\e[38;5;11m----菜單----\em\n");
            for (int i = 0; i < meals_number; i++)
            {
                printf("%s %d元\n",breakfast[i].name,breakfast[i].price);
            }
            // 結束顏色字元  \e[m
            printf("------------\e[m\n");
            goto Order;
        }

        if(!strcmp(order[list_count].name,"結帳"))
            goto Checkout;

        for(int j = 0; j <= meals_number; j++)
        {
            if(!strcmp(order[list_count].name, breakfast[j].name))
            {
                //比對是否有重複項目
                
                
                //記算數量
                printf("單價%d，",breakfast[j].price);
                printf("輸入數量:");
                scanf("%u" , &order[list_count].oder_amount);
                order[list_count].subtotal = order[list_count].oder_amount * breakfast[j].price;
                

                //算金額
                totla_Price += (breakfast[j].price * order[list_count].oder_amount);
                printf("目前金額:%d\n",totla_Price);
                // printf("j = :%d\n",j);
                // printf("list_count:%d\n",list_count);
                printf("--------------\n");
                break;

                //都沒有算到價格，代表點錯東西了

            }

            if(j == meals_number)
                {
                printf("無效餐點，目前金額%3d\n",totla_Price);
                printf("--------------\n");
                goto Order;
                }

                
        }
        

        list_count++;
    }

Checkout:

    printf("\e[38;5;10m\em");
    printf("餐點如下：\n");
    //項目金額
    for(int i = 0; i < list_count; i++)
    {
        printf("%s   數量 %d   小計%d\n",order[i].name, order[i].oder_amount,order[i].subtotal);
    }

    //總金額
    printf("---------------------\n");
    printf("          總金額為 %d\n",totla_Price);
    printf("\n");


    

    return 0;
}