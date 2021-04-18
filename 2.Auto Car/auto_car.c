#include <stdio.h>


void remote_control(int control, int *turn_right);


int main(int argc, char *argv[])
{
    int turn_right;
    int go_forward;
    int remoter = 0;
    int speed = 10;

    turn_right = 0;
    go_forward = 0;

    while(1)
    {
        scanf("%d", &remoter);
        remote_control(remoter, &turn_right);
        
    }
    

    


    return 0;
}

//左轉右轉
void turn (int* right, int ANGLE)
{
    int angle = 10;
    //右轉
    if(ANGLE > 0){
        *right += angle;
    }
    //左轉
    else{
        *right -= angle;
    }

    //開始轉
    if (*right > 0){
        printf("車子向前偏右 %d 度\n", *right);
    }
    else if(*right == 0){
        printf("車子直線向前\n");
    }
    else {
        printf("車子向前偏左 %d 度\n",0 - *right);
    }
        
}

//前進後退
void foward (int* right){

}

//判斷遙控輸入
void remote_control(int control, int *turn_right){
    switch (control)
    {
        case 1:
            
            break;
        case 2:
        
            break;
        case 3:
            turn(turn_right,1);
            break;
        case 4:
            turn(turn_right,-1);
            break;
        default:
            break;

    }
}

