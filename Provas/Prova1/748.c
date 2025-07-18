#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int asc_letra, contador = 0, min_tamanho = 0 , i, j,z, idx = 0;
    
    char **verifica = (char**)malloc((wordsSize) * sizeof(char*));

    for(i = 0; i < wordsSize; i++){
        int tamanho = strlen(words[i]);
        verifica[i] = (char*)malloc((tamanho + 1 )* sizeof(char));
        strcpy(verifica[i], words[i]);
    }

    int tamanho_license = strlen(licensePlate);

    char *letras = (char*)malloc((tamanho_license + 1) * sizeof(char));

    
    for(i = 0; i < tamanho_license; i++){
        asc_letra = licensePlate[i];
        
        if(asc_letra > 64 && asc_letra < 91 ){
            letras[contador] = tolower(licensePlate[i]);
            contador++;
        }
        
        if(asc_letra > 96 && asc_letra < 123){
            letras[contador] = licensePlate[i];
            contador++;
        }
    }
    letras[contador] = '\0';
    int tamanho_letras = strlen(letras);
    contador = 0;

    for(i = 0; i < wordsSize; i++){
        int tamanho_palavra = strlen(words[i]);
        contador = 0;
        for(j = 0; j < tamanho_letras; j++){
            for(z = 0; z < tamanho_palavra; z++){
                if(letras[j] == words[i][z] && verifica[i][z] != '0') {
                    contador++;
                    verifica[i][z] = '0';
                    break;
                }
            }
        }
        if(contador == tamanho_letras){
            if(min_tamanho == 0){ 
                min_tamanho = tamanho_palavra;
                idx = i;
            }
            if(tamanho_palavra < min_tamanho){ 
                min_tamanho = tamanho_palavra;
                idx = i;
            }
        }
        free(verifica[i]);
    }
    free(verifica);
    free(letras);

    return words[idx];
}

int main() {
    char licensePlate[] = "1s3 PSt";
    char *words[] = {"step", "steps", "stripe", "stepple"};
    int wordsSize = sizeof(words) / sizeof(words[0]);

    char *result = shortestCompletingWord(licensePlate, words, wordsSize);
}
