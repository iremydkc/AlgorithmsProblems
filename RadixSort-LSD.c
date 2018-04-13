#include <stdio.h>
#define SIZE 10


int hundredsDigit(int number){
    return number / 100; 
}
int tensDigit(int number){
    return (number % 100) / 10; 
}
int onesDigit(int number){
    return (number % 10) / 1; 
}

void resetCountSort(int arr[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = -1;
        }
    }
}



int main(){


    int G[SIZE],S1[SIZE], S2[SIZE];

    int count_sort[SIZE][SIZE];
    int counter;
    int error;
    resetCountSort( count_sort);

    for(int i = 0; i < SIZE; i++){

    scanf ("%d",&G[i]);

    }


    // RADIX

    for(int i = 0; i < SIZE; i++){ 

        S1[i] = G[i];

    }

    // 1ler basamağı sıralama
    for(int i = 0; i < SIZE; i++){
        count_sort[onesDigit(S1[i])][i] = S1[i];
    }

    counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(count_sort[i][j] != -1){
                S1[counter] = count_sort[i][j];
                counter++;
            }
        }
    } 

    resetCountSort( count_sort );

    // 10lar basamağı sıralama
    for(int i = 0; i < SIZE; i++){

        count_sort[tensDigit(S1[i])][i] = S1[i];

    }

    counter = 0;
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){

            if(count_sort[i][j] != -1){

                S1[counter] = count_sort[i][j];
                counter++;

            }
        }

    } 

    resetCountSort( count_sort);

    // 100ler basamağı sıralama
    for(int i = 0; i < SIZE; i++){

        count_sort[hundredsDigit(S1[i])][i] = S1[i];

    }

    counter = 0;
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){

            if(count_sort[i][j] != -1){

                S1[counter] = count_sort[i][j];
                counter++;

            }

        }

    } 

    resetCountSort( count_sort);


    for(int j=0; j<10;j++)
        printf("%d ",S1[j]);


    // HOLLERITH  

    for(int i = 0; i < SIZE; i++){

         S2[i] = G[i];

    }

    //100ler basamağı sıralama
    for(int i = 0; i < SIZE; i++){

        count_sort[hundredsDigit(S2[i])][i] = S2[i];

    }

    counter = 0;

    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){

            if(count_sort[i][j] != -1){

                S2[counter] = count_sort[i][j];
                counter++;

            }

        }

    }

    resetCountSort( count_sort );

    //10lar basamağı sıralama
    for(int i = 0; i < SIZE; i++){

        count_sort[tensDigit(S2[i])][i] = S2[i];

    }

    counter = 0;
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){

            if(count_sort[i][j] != -1){

                S2[counter] = count_sort[i][j];
                counter++;

            }

        }

    }
        resetCountSort( count_sort);

    //1ler basamağı sıralama
    for(int i = 0; i < SIZE; i++){

        count_sort[onesDigit(S2[i])][i] = S2[i];

    }

    counter = 0;
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){

            if(count_sort[i][j] != -1){

                S2[counter] = count_sort[i][j];
                counter++;

            }
        }

    } 

resetCountSort( count_sort);

   
        printf("\n");
        for(int j=0; j<10;j++)
             printf("%d ",S2[j]);

    //hata oranı hesaplama

    counter = 0;
    for(int i = 0; i < SIZE; i++){

        if( S1[i] != S2[i]){

            counter++;
        }
    }

    error = counter * 10;

    printf("\nHollerith algortitması %%%d hata\n",error);

return 0;
}
