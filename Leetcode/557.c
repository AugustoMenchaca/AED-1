#include <string.h>
#include <stdio.h>

char* reverseWords(char* s) {
    int i = 0,temp = 0, conta_s = 0;
    char temp2;
    int tamanho = strlen(s);

    for(i = 0; i <= tamanho; i++){
        if(s[i] == ' ' || s[i] == '\0'){
            for(int z = i - 1; z >= temp;z--,temp++){
                temp2 = s[z];

                s[z] = s[temp];

                s[temp] = temp2;
            }
            temp = i + 1;
        }
    }
    return s;
}

int main(){
    reverseWords("Let's take LeetCode contest");
}