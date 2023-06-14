#include <iostream>
#include <conio.h>
/*
    vou usar o _getch(); para conseguir identificar qual tecla está
    sendo pressionada
*/
#include <ctime>
/*
    vou usar o time_t para conseguir o tempo atual e gerar um valor
    aleatorio
*/


using namespace std;

const int largura = 8;
const int altura = 8;

const int parado=0,direita=1,esquerda=2,cima=3,baixo=4;
int cabecaX,cabecaY,score=0;
int fruitX,fruitY,quantidadeFruta=0;
int dir=0;
bool gameOver;
int mapa[largura][altura];
int caudaX[((altura*largura)-(altura * 2)-(largura * 2)+4)];
int caudaY[((altura*largura)-(altura * 2)-(largura * 2)+4)];
int x,y,tamanhoCauda;

char teclaDigitada(){
    char tecla = _getch();
    return tecla;
}

void move(){
    if(_kbhit()){
        char tecla = _getch();
        if(tecla == 'd' ){
            dir = direita;
        }
        else if(tecla == 'a'){
            dir = esquerda;
        }
        else if(tecla == 'w' ){
            dir = cima;
        }
        else if(tecla == 's'){
            dir = baixo;
        }
    }
}

int valorAleatorio(){
    int vR;
    time_t tempoAtual = time (nullptr);
    vR = tempoAtual;
    return vR;
}

void movimento(){

    tamanhoCauda=score;

    if(quantidadeFruta == 0){
        fruitX=(valorAleatorio() % 6 + 2);
        fruitY=(valorAleatorio() % 3 + 2);
        mapa[fruitX][fruitY]=6;
    }

    if( score == 0){
    mapa[cabecaX][cabecaY]=0;
    }

    else if ( score >= 1){
        mapa[x][y]=0;
        caudaX[tamanhoCauda]=cabecaX;
        caudaY[tamanhoCauda]=cabecaY;

        for(int i=0; i<tamanhoCauda;i++){
            x = caudaX[tamanhoCauda];
            y = caudaY[tamanhoCauda];
            mapa[x][y]=3;
        }
    }


    move();
    if(dir == direita){
        cabecaY++;
    }else if(dir == esquerda){
        cabecaY--;
    }else if(dir == cima){
        cabecaX--;
    }else if(dir == baixo){
        cabecaX++;
    }

}

void imprimirMatriz(int matriz[largura][altura]){
    for(int i=0;i<largura;i++){
        for(int j=0;j<altura;j++){
            if ( i == 0 || i == largura - 1 || j == 0 || j == altura -1){
                cout << "# ";
            }else{
            cout << matriz[i][j] << " ";
            }
        }
        cout<< endl;
    }
}


void Iniciar(){
    mapa[largura][altura]={};
    gameOver=false;
    cabecaX= (valorAleatorio() % 6) + 1;
    cabecaY= (valorAleatorio() % 3) + 1;
}

int main()
{
    Iniciar();

    while(gameOver == false ){
        mapa[cabecaX][cabecaY]=1;
        system("cls");
        imprimirMatriz(mapa);
        movimento();
        _sleep(300);
    }
}
