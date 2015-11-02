#include "Init.h"
#include "DigitsDriver.h"

static bool DIGIT [11][7]=
{
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1},
    {0,0,0,0,0,0,0},
}; // Contient les "fonts" pour afficher des chiffres ou rien
// les bits representent les segments de haut en bas, (gauche droite))

void dispshift(int x) // affiche un nombre en le shiftant visuellement
{
    int x3=x/1000;
    int x2=(x%1000)/100;
    int x1=(x%100)/10;
    int x0 = x%10;
    
    if ((x3==0) && (x2==0) && (x1==0))
    x1=10;
    if ((x3==0) && (x2==0))
    x2=10;
    if (x3==0)
    x3=10;
    
    if ((x%1000)==0)
        clearshift(3);
    if ((x%100)==0)
        clearshift(2);
    if ((x%10)==0)
        clearshift(1);
    else
        clearshift(0);

    
    RF1=DIGIT[x0][0]; //mapping des segments d'en haut
    RF5=DIGIT[x1][0];
    RG2=DIGIT[x2][0];
    RE1=DIGIT[x3][0];
    __delay_ms(30); 
     
    RF2=DIGIT[x0][1]; // mapping des segments de niveau 2
    RF6=DIGIT[x1][1];
    RG1=DIGIT[x2][1];
    RE2=DIGIT[x3][1];
    __delay_ms(30); //?
    
    RF0=DIGIT[x0][2]; // niveau 2
    RF4=DIGIT[x1][2];
    RG3=DIGIT[x2][2];
    RE0=DIGIT[x3][2];
    __delay_ms(30);
    
    RF3=DIGIT[x0][3]; // barres du milieu...
    RF7=DIGIT[x1][3];
    RG0=DIGIT[x2][3];
    RE3=DIGIT[x3][3];
    __delay_ms(30);
    
    RA0=DIGIT[x0][4];
    RC0=DIGIT[x1][4];
    RD0=DIGIT[x2][4];
    RE4=DIGIT[x3][4];
    __delay_ms(30);
    
    RA2=DIGIT[x0][5];
    RA4=DIGIT[x1][5];
    RD2=DIGIT[x2][5];
    RE6=DIGIT[x3][5];
    __delay_ms(30);
    
    RA1=DIGIT[x0][6];
    RC1=DIGIT[x1][6];
    RD1=DIGIT[x2][6];
    RE5=DIGIT[x3][6];
    __delay_ms(30);
}

void clearshift(int nb_dig) //efface en shiftant
{
    RF1=0;
    if (nb_dig>0)
        RF5=0;
    if (nb_dig>1)
        RG2=0;
    if (nb_dig>2)
        RE1=0;
    
    __delay_ms(20);
    
        
    RF2=0;
    if (nb_dig>0)
        RF6=0;
    if (nb_dig>1)
        RG1=0;
    if (nb_dig>2)
        RE2=0;
    
    RF0=0;
    if (nb_dig>0)
        RF4=0;
    if (nb_dig>1)
        RG3=0;
    if (nb_dig>2)
        RE0=0;
    
    __delay_ms(20);
    
    RF3=0;
    if (nb_dig>0)
        RF7=0;
    if (nb_dig>1)
        RG0=0;
    if (nb_dig>2)
        RE3=0;
    
    __delay_ms(20);
    
    
    RA0=0;
    if (nb_dig>0)
        RC0=0;
    if (nb_dig>1)
        RD0=0;
    if (nb_dig>2)
        RE4=0;
    
    RA2=0;
    if (nb_dig>0)
        RA4=0;
    if (nb_dig>1)
        RD2=0;
    if (nb_dig>2)
        RE6=0;
    
    __delay_ms(20);
    
    
    RA1=0;
    if (nb_dig>0)
        RC1=0;
    if (nb_dig>1)
        RD1=0;
    if (nb_dig>2)
        RE5=0;
    
    __delay_ms(20);
      
}


void display(int x) // fonction de base pour afficher un nombre
{                   // affichage des negatifs > -1000. Fonction a ameliorer
    bool neg =0;
    
    if(x<0)
    {
        neg=1;
        x=-1*x;
    }
    
    
    int x3=x/1000;
    int x2=(x%1000)/100;
    int x1=(x%100)/10;
    int x0 = x%10;
    
    if ((x3==0) && (x2==0) && (x1==0))
    x1=10;
    if ((x3==0) && (x2==0))
    x2=10;
    if (x3==0)
    x3=10;


    
    RF1=DIGIT[x0][0];
    RF2=DIGIT[x0][1];
    RF0=DIGIT[x0][2];
    RF3=DIGIT[x0][3];
    RA0=DIGIT[x0][4];
    RA2=DIGIT[x0][5];
    RA1=DIGIT[x0][6];
    
    RF5=DIGIT[x1][0];
    RF6=DIGIT[x1][1];
    RF4=DIGIT[x1][2];
    RF7=DIGIT[x1][3];
    RC0=DIGIT[x1][4];
    RA4=DIGIT[x1][5];
    RC1=DIGIT[x1][6];
    
    RG2=DIGIT[x2][0];
    RG1=DIGIT[x2][1];
    RG3=DIGIT[x2][2];
    RG0=DIGIT[x2][3];
    RD0=DIGIT[x2][4];
    RD2=DIGIT[x2][5];
    RD1=DIGIT[x2][6];
    
    RE1=DIGIT[x3][0];
    RE2=DIGIT[x3][1];
    RE0=DIGIT[x3][2];
    RE3=DIGIT[x3][3];
    RE4=DIGIT[x3][4];
    RE6=DIGIT[x3][5];
    RE5=DIGIT[x3][6];
    
    if(neg)
        RE3=1;
    
}


