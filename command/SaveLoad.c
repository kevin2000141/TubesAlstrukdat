#include <stdio.h>
#include <string.h>
#include "../ADT/tipebentukan.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"
#include "../ADT/boolean.h"
#include "../ADT/stackt.h"
#include "../ADT/queue.h"
#include "SaveLoad.h"

// (int)strtol(<string>, (char **)NULL, 10);



void Load (Player *P, Queue *AntrianLuar, ruang *ruangan, arrayC *arrayCust, DaftarO *DaftarOrder){
    // typedef char peta[9][9];
    // peta ruang[5];
    int i,j,N;
    KataString test;
    boolean koma;
    CreateEmpty(AntrianLuar,10);
    // char Nama[NMax+1];
    // int Money;
    // int Life;
    // int Time;
    STARTKATA();
    while(CC != MARK){
        if (strcmp(CKata.TabKata, "Name") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            strcpy(Name(*P),CKata.TabKata);
        }
        else if (strcmp(CKata.TabKata, "Position") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Posisi(*P).X = 0;
            Posisi(*P).Y = 0;
            i = 0;
            koma = false;
            while (i <= CKata.Length-1){
                if (CKata.TabKata[i] == ','){
                    koma = true;
                }
                else {
                    if (!koma){
                        Posisi(*P).X *= 10;
                        Posisi(*P).X += (int)CKata.TabKata[i] - 48;
                    }
                    else {
                        Posisi(*P).Y *= 10;
                        Posisi(*P).Y += (int)CKata.TabKata[i] - 48;
                    }
                }
                i++;
            }
        }
        else if (strcmp(CKata.TabKata, "Room") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Room(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Room(*P) *= 10;
                Room(*P) += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Money") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Money(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Money(*P) *= 10;
                Money(*P) += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Life") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Life(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Life(*P) *= 10;
                Life(*P) += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Time") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Time(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Time(*P) *= 10;
                Time(*P) += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Kitchen") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){    
                    ADV();
                }
                Ruang(*ruangan,4,i,j) = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "Room1") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){    
                    ADV();
                }
                Ruang(*ruangan,1,i,j) = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "Room2") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){    
                    ADV();
                }
                Ruang(*ruangan,2,i,j) = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "Room3") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){    
                    ADV();
                }
                Ruang(*ruangan,3,i,j) = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "AntrianLuar") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            N = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                N *= 10;
                N += (int)CKata.TabKata[i] - 48;
            }
            if (N != 0){
                Head(*AntrianLuar) = 1;
                for (i = 1; i <= N; i++){
                    Tail(*AntrianLuar) = i;
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    InfoTail(*AntrianLuar).jumlah = 0;
                    for (j = 0; j <= CKata.Length-1; j++){
                        InfoTail(*AntrianLuar).jumlah *= 10;
                        InfoTail(*AntrianLuar).jumlah += (int)CKata.TabKata[i] - 48;
                    }
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    InfoTail(*AntrianLuar).patience = 0;
                    for (j = 0; j <= CKata.Length-1; j++){
                        InfoTail(*AntrianLuar).patience *= 10;
                        InfoTail(*AntrianLuar).patience += (int)CKata.TabKata[i] - 48;
                    }
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    InfoTail(*AntrianLuar).qpatience = 0;
                    for (j = 0; j <= CKata.Length-1; j++){
                        InfoTail(*AntrianLuar).qpatience *= 10;
                        InfoTail(*AntrianLuar).qpatience += (int)CKata.TabKata[i] - 48;
                    }
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    for (j = 0; j <= CKata.Length-1; j++){
                        if (CKata.TabKata[j] == '_'){
                            CKata.TabKata[j] = ' ';
                        }
                    }
                    strcpy(InfoTail(*AntrianLuar).order,CKata.TabKata);
                    InfoTail(*AntrianLuar).isi = false;
                }
            }
            else {
                Head(*AntrianLuar) = 0;
            }
        }
        else if (strcmp(CKata.TabKata, "Customer") == 0){
            for (i = 1; i <= 12; i++){
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                arrayCust1(*arrayCust,i).jumlah = 0;
                for (j = 0; j <= CKata.Length-1; j++){
                    arrayCust1(*arrayCust,i).jumlah *= 10;
                    arrayCust1(*arrayCust,i).jumlah += (int)CKata.TabKata[i] - 48;
                }
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                arrayCust1(*arrayCust,i).patience = 0;
                for (j = 0; j <= CKata.Length-1; j++){
                    arrayCust1(*arrayCust,i).patience *= 10;
                    arrayCust1(*arrayCust,i).patience += (int)CKata.TabKata[i] - 48;
                }
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                arrayCust1(*arrayCust,i).qpatience = 0;
                for (j = 0; j <= CKata.Length-1; j++){
                    arrayCust1(*arrayCust,i).qpatience *= 10;
                    arrayCust1(*arrayCust,i).qpatience += (int)CKata.TabKata[i] - 48;
                }
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                for (j = 0; j <= CKata.Length-1; j++){
                    if (CKata.TabKata[j] == '_'){
                        CKata.TabKata[j] = ' ';
                    }
                }
                strcpy(arrayCust1(*arrayCust,i).order,CKata.TabKata);
                arrayCust1(*arrayCust,i).isi = true;
            }
        }
        else if (strcmp(CKata.TabKata, "Order") == 0){
            for (i = 1; i <= 12; i++){
                while (CC == ' ' || CC == '\n'){    
                    ADV();
                }
                ADVKATA();
                for (j = 0; j <= CKata.Length-1; j++){
                    if (CKata.TabKata[j] == '_'){
                        CKata.TabKata[j] = ' ';
                    }
                }
                strcpy(DaftarOrder1(*DaftarOrder,i),CKata.TabKata);
            }
        }
        else if (strcmp(CKata.TabKata, "Hand") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            N = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                N *= 10;
                N += (int)CKata.TabKata[i] - 48;
            }
            Top((*P).Hand) = N;
            if (N != 0){
                for (i = 1; i <= N; i++){
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    for (j = 0; j <= CKata.Length-1; j++){
                        if (CKata.TabKata[j] == '_'){
                            CKata.TabKata[j] = ' ';
                        }
                    }
                    strcpy(((*P).Hand).TI[i],CKata.TabKata);
                }
            }
        }
        else if (strcmp(CKata.TabKata, "FoodStack") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            N = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                N *= 10;
                N += (int)CKata.TabKata[i] - 48;
            }
            Top((*P).FoodStack) = N;
            if (N != 0){
                for (i = 1; i <= N; i++){
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    for (j = 0; j <= CKata.Length-1; j++){
                        if (CKata.TabKata[j] == '_'){
                            CKata.TabKata[j] = ' ';
                        }
                    }
                    strcpy(((*P).FoodStack).TI[i],CKata.TabKata);
                }
            }
        }
        while (CC == ' ' || CC == '\n'){    
            ADV();
        }
        ADVKATA();
    }
    // printf("Name: %s\n", Name(*P));
    // printf("Position: %d,%d\n", Posisi(*P).X, Posisi(*P).Y);
    // printf("Money: %d\n", Money(*P));
    // printf("Life: %d\n", Life(*P));
    // printf("Time: %d\n", Time(*P));
    // printf("Ruang 1: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",*ruangan1[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("Ruang 2: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",*ruangan2[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("Ruang 3: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",*ruangan3[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("Kitchen: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",*ruangan4[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("Food stack:");
    // while (!IsStackEmpty(FoodStack(*P))){
    //     Pop(&(FoodStack(*P)), test);
    //     printf("%s ",test);
    // }
}

void Save(){

}

