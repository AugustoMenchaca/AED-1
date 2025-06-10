char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int asc_letra, contador = 0, min_tamanho = 0 , i, j,z, w, idx = 0;
    
    char **verifica = (char**)malloc((wordsSize) * sizeof(char));

    for(i = 0; i <= wordsSize; i++){
        int tamanho = strlen(words[i]);
        verifica[i] = (char*)malloc(tamanho * sizeof(char));
    }

    int tamanho_license = strlen(licensePlate);

    char *letras = (char*)malloc(tamanho_license * sizeof(char));

    for(i = 0; i < tamanho_license; i++){
        asc_letra = licensePlate[i];

        if(asc_letra > 64 && asc_letra < 91 ){
            tolower(licensePlate[i]);
            contador++;
            letras[contador] = licensePlate[i];
        }

        if(asc_letra > 96 && asc_letra < 123){
            contador++;
            letras[contador] = licensePlate[i];
        }
    }
    contador = 0;

    for(i = 0; i < wordsSize; i++){
        int tamanho_palavra = strlen(words[i]);
        for(j = 0; j < tamanho_license; j++){
            for(z = 0; z < tamanho_palavra; z++){
                if(letras[j] == words[i][z] && verifica[i][z] != '0') {
                    contador++;
                    verifica[i][z] = '0';
                    break;
                }
            }
        }
        if(contador == tamanho_license){
            if(min_tamanho = 0){ 
                min_tamanho = tamanho_palavra;
                idx = i;
            }
            if(tamanho_palavra < min_tamanho){ 
                min_tamanho = tamanho_palavra;
                idx = i;
            }
        }
    }

    return words[idx];

}