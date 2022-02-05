#include <stdio.h>
#include <stdlib.h>
#include "chesslib.h"
 poz *hareketSah(poz ilk){}
 poz *hareketVezir(poz ilk){}
 poz *hareketFil(poz ilk){}
 poz *hareketAt(poz ilk){}
 poz *hareketKale(poz ilk){
 poz *kale;
 kale=(poz*)malloc(sizeof(poz)*16);
 	int i; 
		 for(i=1; i<17; i++){
 			kale[i].dusey=ilk.dusey;
 			kale[i].yatay=(char)i+64;	
		if(i>8){
			kale[i].dusey=i-8;
 			kale[i].yatay=ilk.yatay;
		}
		}
		return kale;
	}
 poz *hareketPiyon(poz ilk){
 	poz *piyon;
 	piyon=(poz*)malloc(sizeof(poz));
 	if(ilk.dusey >1){			
 	(*piyon).dusey=ilk.dusey-1;
 	(*piyon).yatay=ilk.yatay;
	}
	else{			
	(*piyon).dusey=ilk.dusey;
 	(*piyon).yatay=ilk.yatay;
	}
 	return piyon;
 }
void hareketYazdir(char tas, poz ilk){
	int **board;
	int i,j;			
	board = (int**) calloc(sizeof(int*), 8);
	for (i = 1; i < 9; i++) {
		board[i] = (int*) calloc(sizeof(int), 8);
	}
	poz*(*satrancHareketleri[])(poz)={&hareketSah,&hareketVezir,&hareketFil,&hareketAt,&hareketKale,&hareketPiyon};
    if(tas == 'S'){
	poz *sah;
	sah=satrancHareketleri[0](ilk);
	}
	if(tas == 'V'){
    poz *vezir;
	vezir=satrancHareketleri[1](ilk);
	}
	if(tas == 'F'){
  	poz *fil;
	fil=satrancHareketleri[2](ilk);
	}
	if(tas == 'A'){
    poz *at;
	at=satrancHareketleri[3](ilk);
	}
	if(tas == 'K'){
    poz *kale;
	kale=satrancHareketleri[4](ilk);
	int i;
	 for(i=1; i<17; i++){
 	 board[kale[i].dusey][(int)(kale[i].yatay)-64]=1;	
	}
	board[ilk.dusey][((int)ilk.yatay)-64]=2;
	}
	if(tas == 'P'){					
	poz *piyon;
	piyon=satrancHareketleri[5](ilk);		//fonksyidan poz piyondan dönen diziyi burda tanýmladýðýma atadým
	board[piyon->dusey][(int)(piyon->yatay)-64]=1; //fonksiyondan dönen indis deðerlerini boardaki indislere koydum
	board[ilk.dusey][((int)ilk.yatay)-64]=2;
	}
	for (i = 1; i < 9; i++) {
        for (j = 1; j < 9; j++) {
             printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}


