#include "fcprotot.h"

int checar_vitoria(jogo jogo)
{
	int x;
	for (x = 0; x < 4; x++)
	{
		if (n_carta(jogo.quadros[x]) != 13)
			return 0;
	}
	return 1;
}

jogo mover_carta(jogo jogo, int x_ant, int y_ant)
{
	if (jogo.cx == 0) // movendo para celula ou para um quadro
	{
		if (jogo.cy < 4) // movendo para uma celula
		{
			if (jogo.celulas[jogo.cy] == VAZIO) // checando se a celula esta disponivel
			{
				if (x_ant == 0) // de outra celula
				{
					jogo.celulas[jogo.cy] = jogo.celulas[y_ant];
					jogo.celulas[y_ant] = VAZIO;
				}
				else // do topo de uma coluna
				{
					jogo.celulas[jogo.cy] = topo(jogo.colunas[y_ant]);
					jogo.colunas[y_ant].cartas[jogo.colunas[y_ant].qtd - 1] = VAZIO;
					jogo.colunas[y_ant].qtd--;
				}
			}
		}
		else // movendo para um quadro
		{
			if (x_ant == 0 && y_ant < 4) // de uma celula
			{
				if ((n_carta(jogo.quadros[jogo.cy - 4]) == n_carta(jogo.celulas[y_ant])-1) && naipeIgual(jogo.quadros[jogo.cy-4],jogo.celulas[y_ant]))
				{
					jogo.quadros[jogo.cy - 4] = jogo.celulas[y_ant];
					jogo.celulas[y_ant] = VAZIO;
				}
			}
			else // de uma coluna
			{
				if ((n_carta(jogo.quadros[jogo.cy - 4]) == n_carta(topo(jogo.colunas[y_ant])) - 1) && naipeIgual(jogo.quadros[jogo.cy - 4], jogo.colunas[y_ant].cartas[jogo.colunas[y_ant].qtd - 1]))
				{
					jogo.quadros[jogo.cy - 4] = topo(jogo.colunas[y_ant]);
					jogo.colunas[y_ant].cartas[jogo.colunas[y_ant].qtd - 1] = VAZIO;
					jogo.colunas[y_ant].qtd--;
				}
			}
			
		}
	}
	else
	{
		if (jogo.cx == 1) //movendo para uma coluna
		{
			if (x_ant == 0 && jogo.celulas[y_ant] != VAZIO) //de uma celula
			{
				if (corDif(jogo.celulas[y_ant], topo(jogo.colunas[jogo.cy])) && (n_carta(topo(jogo.colunas[jogo.cy])) == n_carta(jogo.celulas[y_ant]) + 1))//checar se pode ser colocada
				{
					jogo.colunas[jogo.cy].cartas[jogo.colunas[jogo.cy].qtd] = jogo.celulas[y_ant];
					jogo.colunas[jogo.cy].qtd++;
					jogo.celulas[y_ant] = VAZIO;
				}
			}
			else // de outra coluna
			{
				if (topo(jogo.colunas[y_ant]) != VAZIO)
				{
					if (corDif(topo(jogo.colunas[y_ant]), topo(jogo.colunas[jogo.cy])) && (n_carta(topo(jogo.colunas[jogo.cy])) == n_carta(topo(jogo.colunas[y_ant])) + 1))//checar se pode ser colocada
					{
						jogo.colunas[jogo.cy].cartas[jogo.colunas[jogo.cy].qtd] = topo(jogo.colunas[y_ant]);
						jogo.colunas[jogo.cy].qtd++;
						jogo.colunas[y_ant].cartas[jogo.colunas[y_ant].qtd - 1] = 0;
						jogo.colunas[y_ant].qtd--;
					}
				}
			}
		}
	}
	return jogo;
}

int naipeIgual(int carta1, int carta2)
{
	if (carta1 == 0 && carta2 != 0 || carta1 != 0 && carta2 == 0)
	{
		return 1;
	}
	else
	{
		if (carta1 > 13 && carta2 > 13)
		{
			return 1;
		}
		else
		{
			if (carta1 > 0 && carta1 < 13 && carta2 > 0 && carta2 < 13)
			{
				return 1;
			}
			else
			{
				if (carta1 > -14 && carta1 < 0 && carta2 > -14 && carta2 < 0)
				{
					return 1;
				}
				else
				{
					if (carta1 < -13 && carta2 < -13)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}
}

int corDif(int carta1, int carta2)
{
	return ((carta1 > 0 && carta2 < 0) || (carta1 < 0 && carta2 > 0));
}

int n_carta(int carta)
{
	if (carta>13)
	{
		carta -= 13;
	}
	else
	{
		if (carta < 0)
		{
			if (carta<-13)
			{
				carta = (carta + 13)*(-1);
			}
			else
			{
				carta = carta*(-1);
			}
		}
	}
	return carta;
}

void printR(jogo jogo)
{
	int x, y;
	printf("Celulas:\n");
	for (x = 0; x < 4; x++)
		printf("%d ", jogo.celulas[x]);
	printf("\n");
	for (x = 0; x < 8; x++)
	{
		printf("Coluna %d\n", x + 1);
		printf("%d cartas na coluna\n", jogo.colunas[x].qtd);
		for (y = 0; y < 19; y++)
		{
			printf("%d ", jogo.colunas[x].cartas[y]);
		}
		printf("\n");
	}
}

jogo mover(int teclado, jogo jogo)
{
	switch (teclado)
	{
		case 'a':
			if (jogo.cy > 0)
			{
				jogo.cy--;
				clear;
				printjogo(jogo);
			}
			break;
		case 'd':
			
			if (jogo.cy < 7)
			{
				jogo.cy++;
				clear;
				printjogo(jogo);
			}
			break;
		case 'w':
			if (jogo.cx > 0)
			{
				jogo.cx--;
				clear;
				printjogo(jogo);
			}
			break;
		case 's':
			if (jogo.cx < 1)
			{
				jogo.cx++;
				clear;
				printjogo(jogo);
			}
			break;
		default:
			break;
	}
	return jogo;
}

jogo prepararjogo()
{
	jogo jogo;
	int x, y, lim=7, carta[52],r;
	for (x = 0; x < 52; x++)
	{
		carta[x] = 0;
	}
	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 19; y++)
		{
			jogo.colunas[x].cartas[y] = 0;
		}
		jogo.colunas[x].qtd = 0;
	}
	for (x = -26; x <= 26; x++)
	{
		if (x != 0)
		{
			r = rand() % 52;
			while (carta[r] != 0)
			{
				r = rand() % 52;
			}
			carta[r] = x;
		}
	}
	r = 0;
	for (x = 0; x < 8; x++)
	{
		if (x >= 4)
		{
			lim = 6;
		}
		else
		{
			jogo.celulas[x] = VAZIO;
			jogo.quadros[x] = VAZIO;
		}
		for (y = 0; y < lim; y++)
		{
			jogo.colunas[x].cartas[y] = carta[r];
			jogo.colunas[x].qtd++;
			r++;
		}
	}
	jogo.cx = 1;
	jogo.cy = 0;
	return jogo;
}

void printjogo(jogo jogo)
{
	int x, y,to=0;
	for (x = 0; x < 4; x++)
		printf(" Cl%d ",x+1);
	for (x = 0; x < 4; x++)
		printf(" Qd%d ", x + 1);
	printf("\n");
	for (x = 0; x < 4; x++)
	{
		if (jogo.cx == 0 && jogo.cy == x)
		{
			printf("{");
			switchcarta(jogo.celulas[x]);
			printf("}");
		}
		else
		{
			printf(" ");
			switchcarta(jogo.celulas[x]);
			printf(" ");
		}
	}
	for (x = 0; x < 4; x++)
	{
		if (jogo.cx == 0 && jogo.cy == x+4)
		{
			printf("{");
			switchcarta(jogo.quadros[x]);
			printf("}");
		}
		else
		{
			printf(" ");
			switchcarta(jogo.quadros[x]);
			printf(" ");
		}
	}
	printf("\n\n");
	for (x = 0; x < 19; x++)
	{
		if (x == 0)
		{
			for (y = 0; y < 8; y++)
				printf(" CO%d ", y + 1);
			printf("\n\n");
		}
		for (y = 0; y < 8; y++)
		{
			if (jogo.colunas[y].qtd > x)
			{
				if (jogo.cx == 1 && jogo.cy == y && jogo.colunas[y].qtd == x+1)
				{
					printf("{");
					switchcarta(jogo.colunas[y].cartas[x]);
					printf("}");
				}
				else
				{
					printf(" ");
					switchcarta(jogo.colunas[y].cartas[x]);
					printf(" ");
				}
			}
			else
			{
				printf("     ");
			}
		}
		printf("\n");
	}
}

int topo(coluna coluna)
{
	return coluna.cartas[coluna.qtd-1];
}

int modulo(int valor)
{
	return valor < 0 ? valor=-valor: valor;
}

void switchcarta(int carta)
{
	switch (carta)
	{
	case VAZIO:
		printf("[ ]");
		break;
	case EK:
		printf("K E");
		break;
	case EQ:
		printf("Q E");
		break;
	case EJ:
		printf("J E");
		break;
	case E10:
		printf("10E");
		break;
	case E9:
		printf("9 E");
		break;
	case E8:
		printf("8 E");
		break;
	case E7:
		printf("7 E");
		break;
	case E6:
		printf("6 E");
		break;
	case E5:
		printf("5 E");
		break;
	case E4:
		printf("4 E");
		break;
	case E3:
		printf("3 E");
		break;
	case E2:
		printf("2 E");
		break;
	case EA:
		printf("A E");
		break;
	case PK:
		printf("K P");
		break;
	case PQ:
		printf("Q P");
		break;
	case PJ:
		printf("J P");
		break;
	case P10:
		printf("10P");
		break;
	case P9:
		printf("9 P");
		break;
	case P8:
		printf("8 P");
		break;
	case P7:
		printf("7 P");
		break;
	case P6:
		printf("6 P");
		break;
	case P5:
		printf("5 P");
		break;
	case P4:
		printf("4 P");
		break;
	case P3:
		printf("3 P");
		break;
	case P2:
		printf("2 P");
		break;
	case PA:
		printf("A P");
		break;
	case CK:
		printf("K C");
		break;
	case CQ:
		printf("Q C");
		break;
	case CJ:
		printf("J C");
		break;
	case C10:
		printf("10C");
		break;
	case C9:
		printf("9 C");
		break;
	case C8:
		printf("8 C");
		break;
	case C7:
		printf("7 C");
		break;
	case C6:
		printf("6 C");
		break;
	case C5:
		printf("5 C");
		break;
	case C4:
		printf("4 C");
		break;
	case C3:
		printf("3 C");
		break;
	case C2:
		printf("2 C");
		break;
	case CA:
		printf("A C");
		break;
	case DK:
		printf("K D");
		break;
	case DQ:
		printf("Q D");
		break;
	case DJ:
		printf("J D");
		break;
	case D10:
		printf("10D");
		break;
	case D9:
		printf("9 D");
		break;
	case D8:
		printf("8 D");
		break;
	case D7:
		printf("7 D");
		break;
	case D6:
		printf("6 D");
		break;
	case D5:
		printf("5 D");
		break;
	case D4:
		printf("4 D");
		break;
	case D3:
		printf("3 D");
		break;
	case D2:
		printf("2 D");
		break;
	case DA:
		printf("A D");
		break;
	default:
		printf(" %d "), carta;
		break;
	}
}