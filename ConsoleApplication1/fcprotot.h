#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
//cartas pretas < 0, vermelhas > 0
#define VAZIO 0
//E = espadas
#define EK (-26)
#define EQ (-25)
#define EJ (-24)
#define E10 (-23)
#define E9 (-22)
#define E8 (-21)
#define E7 (-20)
#define E6 (-19)
#define E5 (-18)
#define E4 (-17)
#define E3 (-16)
#define E2 (-15)
#define EA (-14)
//P = paus
#define PK (-13)
#define PQ (-12)
#define PJ (-11)
#define P10 (-10)
#define P9 (-9)
#define P8 (-8)
#define P7 (-7)
#define P6 (-6)
#define P5 (-5)
#define P4 (-4)
#define P3 (-3)
#define P2 (-2)
#define PA (-1)
//C = copas
#define CA (1)
#define C2 (2)
#define C3 (3)
#define C4 (4)
#define C5 (5)
#define C6 (6)
#define C7 (7)
#define C8 (8)
#define C9 (9)
#define C10 (10)
#define CJ (11)
#define CQ (12)
#define CK (13)
//D = diamante
#define DA (14)
#define D2 (15)
#define D3 (16)
#define D4 (17)
#define D5 (18)
#define D6 (19)
#define D7 (20)
#define D8 (21)
#define D9 (22)
#define D10 (23)
#define DJ (24)
#define DQ (25)
#define DK (26)

#define clear system("cls")

typedef struct colunas
{
	int cartas[19];
	int qtd;
} coluna;

typedef struct jogo
{
	coluna colunas[8];
	int celulas[4];
	int quadros[4];
	int cx;
	int cy;
} jogo;

int naipeIgual(int carta1, int carta2);
int corDif(int carta1,int carta2);
int n_carta(int carta);
jogo mover_carta(jogo jogo);
void switchcarta(int carta);
void printjogo(jogo jogo);
void printR(jogo jogo);
jogo prepararjogo();
int topo(coluna coluna);
int modulo(int valor);
jogo mover(int teclado, jogo jogo);