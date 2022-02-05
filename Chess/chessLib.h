#define CHESSLIB_H_

typedef struct poz{
    short dusey;
    char yatay;
} poz;

 void hareketYazdir(char,poz);
  poz *hareketSah(poz);
  poz *hareketVezir(poz);
  poz *hareketFil(poz);
  poz *hareketAt(poz);
  poz *hareketKale(poz);
  poz *hareketPiyon(poz);
