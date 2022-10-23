//WINDOWS
/*************************************************************
Descrição do Algoritmo:
Disciplina: Algoritmo II
Professor: Leonair Neves de Sousa
Alunos: Joelma Silva Campos Godoy
	Gabriel Acassio Correia
Turma: 2021/3
RGA: 202115310001
     202111310049
Data da entrega: 10/08/2022
**************************************************************/

#include<conio2.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//programa principal
int main()
{	
	system("MODE con cols=170 lines=60"); //abre o prompt com tamanho definido
	int tamanho;
	gotoxy(30,3);printf("Ola, para iniciar a construção da sua tabela de frequencia insira o numero de elementos da amostra: ");
	scanf("%d", &tamanho);
	int amostra[tamanho];
	
	int i, j;
	float soma=0;
	for(i=0; i<tamanho; i++)
	{
		gotoxy(30,4+i);
		printf("Insira o elemento [%d] da amostra= ", i+1);
		scanf("%d", &amostra[i]);
		soma+=amostra[i];
	}
	
	//Ordenação	
	int cont=1, primeiro=0, aux, menor, maior;			
	while(cont<=tamanho)
	{
		menor=primeiro;
		for(i=primeiro+1; i<tamanho; i++)
		{
			if(amostra[menor]>amostra[i])
			{
				menor=i;
			}
		}
		aux=amostra[primeiro];
		amostra[primeiro]=amostra[menor];
		amostra[menor]=aux;
		primeiro=primeiro + 1;
		cont++;
	}
	
	//definindo valores
	int k, at, atc;
	k=((int)(ceil(sqrt(tamanho))));
	at=amostra[tamanho-1]-amostra[0];
	atc=ceil(at/((float)k));
	
	//media
	float media=0;
	media=soma/tamanho;
	
	//mediana
	float mediana=0;
	if(tamanho%2==1)
	{
		mediana=amostra[(tamanho-1)/2];
	}
	else
	{
		mediana=((float)(amostra[(tamanho/2)-1]+amostra[tamanho/2]))/2;
	}
	
	//moda
	void ImprimeModa(int *tamanho,int amostra[]);//declara uma função local para calcular a moda
		
	//definindo a tabela	
	float tabela[k][8];
	int acumuloAux=0, acumulo=0, maiorFI=0;
	for(i=0; i<k; i++)
	{
		tabela[i][0]=amostra[0]+acumulo;
		acumulo+=atc;
		tabela[i][1]=tabela[i][0]+atc-1;
		if (tabela[k-1][1]<amostra[tamanho-1])//verifica se a ultima classe superior é menor que o maior elemento, caso seja ela é substituída pelo ultimo elemento
		{
			tabela[k-1][1]=amostra[tamanho-1];
		}		
		tabela[i][3]=(tabela[i][0]+tabela[i][1])/2;
		tabela[i][6]=tabela[i][0]-0.5;
		tabela[i][7]=tabela[i][1]+0.5;	
		tabela[i][2]=0;
		for(j=0; j<tamanho;  j++)
		{
			if(amostra[j]>=tabela[i][0]&&amostra[j]<=tabela[i][1])
			{
				tabela[i][2]++;
			}
		}
		if(maiorFI<tabela[i][2])
		{
			maiorFI=tabela[i][2];
		}
		tabela[i][4]=(tabela[i][2]*100)/tamanho;
		acumuloAux+=tabela[i][2];
		tabela[i][5]=acumuloAux;	
	}

	//imprimindo o resultado
	system("cls");
	gotoxy(78,2);printf("AMOSTRA");
	gotoxy(82-(tamanho*3/2),4);
	for(i=0; i<tamanho; i++)
	{
		(amostra[i]>9)? printf("%d ", amostra[i]): printf("%d  ", amostra[i]) ;
	}
	gotoxy(37,6);printf(" MEDIA AMOSTRAL: %4.2f", media);
	gotoxy(37,7);printf(" MEDIANA : %4.2f", mediana);
	gotoxy(37,8);ImprimeModa(&tamanho, amostra);
	gotoxy(37,9);printf(" _________________________________________________________________________________________");
	gotoxy(37,10);printf("|                     |          |          |           |          |                      |");
	gotoxy(37,11);printf("|       CLASSES       |          |          |           |          | FRONTEIRA DE CLASSES |");
	gotoxy(37,12);printf("|_____________________|__________|__________|___________|__________|______________________|");
	gotoxy(37,13);printf("|          |          |          |          |           |          |          |           |");
	gotoxy(37,14);printf("|    CI    |   CS     |    FI    |    XI    |    FR     |   FCA    |   FCI    |    FCS    |");
	gotoxy(37,15);printf("|__________|__________|__________|__________|___________|__________|__________|___________|");
	gotoxy(37,16);printf("|          |          |          |          |           |          |          |           |");
	int l=0;
  	for(i=0; i<k; i++)//imrpime uma nova linha na tabela para cada classe k
  	{
  		gotoxy(37,17+l);
    		printf("|");
		for(j=0; j<8; j++) 
		{ 
    			(j==4)? printf("%8.2f%%  |", tabela[i][j]) : (j==7)? printf("% 8.2f   |", tabela[i][j]) : printf("%8.2f  |", tabela[i][j]);        
		}
		l++;
		gotoxy(37, 17+l);
        	printf("|__________|__________|__________|__________|___________|__________|__________|___________|");
        	l++;
        	gotoxy(37,17+l);
        	if (i!=k-1)
		{
			printf("|          |          |          |          |           |          |          |           |");
			l++;	
		} 
		else
		{
		 	l++;
		}
	}
	  
	//Grafico
    	gotoxy(77 , 18+k*3);
	printf("HISTOGRAMA");
	int corGraf[k];//vetor para armazenar as cores de cada coluna
	for(i=0; i<k; i++)//atribui k cores para as k colunas
	{
		corGraf[i]=rand()%9+1;//sorteia uma cor alaeatorria para cada item i do vetor	
	}
	for(j=2*maiorFI+2; j>=0; j--)//define a quantidade de linhas do histograma como j, onde cada unidade de FI ocupa 2 caracteres. j é decrementado pois se imprime do topo para a base
	{
		gotoxy(82-(k*5/2), 21+2*maiorFI+k*3-j);//centraliza o histograma levando em conta k(numero de colunas) e maiorFI(maior coluna)
	    	for(i=0; i<k; i++)//define o numero de coluna como k, o numero de classses
	    	{   
			if(2*tabela[i][2]>=j)//verifica se a camada da coluna deve ser preenchida ou vazia, a coluna possuí largura de cinco caracteres
			{
				textcolor(corGraf[i]);//define a cor de acordo com o i(indice da coluna) 
				if(2*tabela[i][2]==j)//quando a condição é verdadeira significa que está no topo da coluna preenchida
				{
					(tabela[i][2]>9)? printf("  %.f ", tabela[i][2]) : printf("  %.f  ", tabela[i][2]);//imprime o numero de elementos no topo da coluna, centralizando caso tenha um ou dois caracteres
				}
				else
				{
					printf("%c%c%c%c%C", 178, 178, 178, 178, 178);//imprime uma camada preenchida da coluna, caso seja necesssário	
				}
			}
			else
			{
				printf("     ");//imprime uma camda vazia da coluna, caso seja necessario
			}
		}
		textcolor(7);//retorna a cor para branco
		printf("\n");	
	}	
	system("pause");
	return 0;
}

//função para encontrar e imprimir a moda
void ImprimeModa(int *tamanho,int amostra[])
{
	int i, j, quantRepet=1;
	for(i=1; i<*tamanho; i++)
	{
		if(amostra[i-1]!=amostra[i])
		{
			quantRepet++;//verifica a quantidade de numeros diferentes da amostra
		}
	}
	int acumulo=0, moda;
	if(quantRepet==*tamanho||quantRepet==1)//define automaticamente se há ou não moda para o caso mais simples
	{
		printf(" AMODAL");
	}
	else
	{
		int matRepet[2][quantRepet];//vetor que armazena na linha 0 o elemento da amostra e na linha 2 seu numero de repetições
		j=0;
		for(i=1; i<*tamanho; i++)//conta as reptições comprando o emento i-1 com i
		{
			if((amostra[i-1]!=amostra[i])||((amostra[*tamanho-1]==amostra[*tamanho-2])&&(i==*tamanho-1)))//identifica a fronteira entre os elementos diferentes e para oultimo numero identicia se ele é igual ao anterior
			{
				matRepet[0][j]=amostra[i-1];
				if(j==0)
				{
					matRepet[1][j]=i;
					moda=j;
				}
				else
				{
					acumulo+=matRepet[1][j-1];//acumulo guarda os valor das repetições anteriores 
					if(amostra[*tamanho-1]==amostra[*tamanho-2]&&(i==*tamanho-1))//verifica se os dois ultimos elementos são iguais e seo for esta no fim do vetor
					{
						acumulo--;
					}
					matRepet[1][j]=i-acumulo;
					if(matRepet[1][moda]<matRepet[1][j])//extrai o numero com mais repetições
					{
						moda=j;
					}
				}
				j++;
			}
		}
		int outrasModas=0;
		for(j=0; j<quantRepet; j++)// verifica se há mais numeros com a mesma quantidade de repetições da moda
		{	
			if(matRepet[1][moda]==matRepet[1][j])
			{
				outrasModas++;
			}
		}
		if(outrasModas* matRepet[1][moda]==*tamanho)//verifica se todos os numeros tem a mesma quantidade de repetições
		{
			printf(" AMODAL");
		}
		else
		{
			switch(outrasModas)
			{
				case 1:
					printf(" A MODA E %d", matRepet[0][moda]);
					printf(". REPETIDA %d VEZES.", matRepet[1][moda]);
					break;
				default:
					int vetOutrasModas[outrasModas];//como ha mais de uma moda o vetor armazena elas para posteriormente imprimi-las
					i=0;
					for(j=0; j<quantRepet; j++)//encontra todas as modas
					{
						if(matRepet[1][moda]==matRepet[1][j])
						{
							vetOutrasModas[i]=matRepet[0][j];
							i++;	
						}
					}
					printf(" AS MODAS SAO ");
					for(i=0;i<outrasModas;i++)
					{
						(i!=outrasModas-1&&i!=0)? printf(", "): (i==outrasModas-1)? printf(" e "): printf("");
						printf("%d",vetOutrasModas[i]);
					}
					printf(". REPETIDAS %d VEZES.", matRepet[1][moda]);	
					break;	
			}	
		}
	}			
}
