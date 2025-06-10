int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int i,contador = 0, anterior, diferenca,range_anterior;

    for(i = 0; i < timeSeriesSize; i++){
        if(i == 0){
            anterior = timeSeries[i];
            range_anterior = timeSeries[i] + duration - 1;
            contador += duration;
            continue;
        }
        if(timeSeries[i] <= range_anterior){
            contador += timeSeries[i] - anterior;
            anterior = timeSeries[i];
            range_anterior = timeSeries[i] + duration - 1;
        }else{
            contador += duration;
            anterior = timeSeries[i];
            range_anterior = timeSeries[i] + duration - 1;
        }
    }
    return contador;
}

int main(){
    int timeSeries[] = {1, 5, 6};
    int duration = 2;
    findPoisonedDuration(timeSeries,3,duration);
}