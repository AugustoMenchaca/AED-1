#include <stdio.h>
#include <stdbool.h>

bool verifica(int c_letra, int i, int z, char** board, char* word);

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i, z, c_letra = 0;
    
    char *teste=word,**teste_board=board;

    for (i = 0; i < *boardColSize; i++) {
        for (z = 0; z < boardSize; z++) {
            if (word[c_letra] == board[i][z]) {
                if (verifica(c_letra, i, z, teste_board, teste)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool verifica(int c_letra, int i, int z, char** board, char* word) {
    c_letra++;
    if (word[c_letra] != '\0') {
        if (z!=0 && word[c_letra] == board[i][z - 1]){
            z=z-1;
            return verifica(c_letra, i, z, board, word);
        }
        if(word[c_letra] == board[i][z+1]){
            z=z+1;
            return verifica(c_letra, i, z, board, word);
        }
        if(i!=0 && word[c_letra] == board[i-1][z]){
            i=i-1;
            return verifica(c_letra, i, z, board, word);
        }
        if(word[c_letra] == board[i+1][z]){
            i=i+1;
            return verifica(c_letra, i, z, board, word);
        }
        } else {
            return false;
        }
    }
    return true;
}