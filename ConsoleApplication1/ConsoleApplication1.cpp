#include "stdafx.h"
#include "fcbibl.h"

int main()
{
	srand((unsigned)time(NULL));
	jogo jogo = prepararjogo();
	int teclado = ' ', x_ant = -1, y_ant = -1;
	printjogo(jogo);
	while (teclado != '/' && teclado != '0')
	{
		teclado = getch();
		if (teclado == 'q' && x_ant == -1)
		{
			x_ant = jogo.cx;
			y_ant = jogo.cy;
			clear;
			printjogo(jogo);
			switch (x_ant)
			{
			case 0:
				switchcarta(jogo.celulas[y_ant]);
				printf(" selecionada\n");
				break;
			case 1:
				switchcarta(jogo.colunas[y_ant].cartas[jogo.colunas[y_ant].qtd - 1]);
				printf(" selecionada\n");
				break;
			}
		}
		else
		{
			if (teclado == 'q' && x_ant != -1)
			{
				if (x_ant != jogo.cx || y_ant != jogo.cy)
				{
					jogo = mover_carta(jogo, x_ant, y_ant);
				}
				x_ant = -1;
				y_ant = -1;
				clear;
				printjogo(jogo);
			}
			else
				if (teclado == 'a' || teclado == 'd' || teclado == 'w' || teclado == 's')
				{
					jogo = mover(teclado, jogo);
						switch (x_ant)
						{
						case 0:
							switchcarta(jogo.celulas[y_ant]);
							printf(" selecionada\n");
							break;
						case 1:
							switchcarta(jogo.colunas[y_ant].cartas[jogo.colunas[y_ant].qtd - 1]);
							printf(" selecionada\n");
							break;
						}
				}
		}
		if (checar_vitoria(jogo))
		{
			clear;
			printjogo(jogo);
			printf("Parabens, Vitoria!");
			break;
		}
	}
	system("PAUSE");
	return 0;
}