#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool strongPasswordCheckerII(char* password) {
    int i , verifica ;
    bool check_int , check_upper , check_special;

    static char special[] = "!@#$%^&*()-+";

    if( strlen(password) < 8){
        return false;
    }else{
        for(i=0;i<strlen(password);i++){
            verifica = password[i];

            if(verifica > 47 && verifica < 58) check_int = true;

            if(verifica > 64 && verifica < 91) check_upper = true;
            
            for(int z = 0; z < strlen(special); z++){
                if(password[i] == special[z]) check_special = true;
            }
        }
        if(check_int && check_upper && check_special) return true;
    }
    return false;
}

int main(){
    strongPasswordCheckerII("Augus!aa1");
}