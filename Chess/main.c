#include <stdio.h>
#include <stdlib.h>
#include "chesslib.h"
int main(int argc, char *argv[]) {
	//Hocam sadece piyon ve kale �al���yor
    poz ilk;
	ilk.dusey=4;
	ilk.yatay='E';
	char tas='P';
	hareketYazdir(tas,ilk);
	return 0;
}
