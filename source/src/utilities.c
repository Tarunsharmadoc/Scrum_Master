#include<stdio.h>

int checkLogin(int userId,char password[]){
    if (userId==23345 && password=="abcd123"){
        return 1;
    }
    else{
        return 0;
    }

}