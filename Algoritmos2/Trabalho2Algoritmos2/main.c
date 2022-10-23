//WINDOWS 
/*************************************************************
Descrição do Algoritmo: trabalho II
Disciplina: Algoritmo II
Professor: Leonair Neves de Sousa
Alunos: Joelma Silva Campos Godoy
	Gabriel Acassio Correia
Turma: 2021/3
RGA: 202115310001
     202111310049
Data da entrega: 12/08/2022
**************************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> 
#include<conio2.h>
#include <windows.h>
typedef struct 
{
	int dia,mes,ano;
}data;
typedef struct 
{
 	int codigo;
	char nome[20];
	int flag;
}genero; 
typedef struct  
{
	int codfilme, codgen, ano, flag;
	char nome[80], classificacao [10];
	float valor;	
}filme; 
typedef struct 
{
    int codcliente;
	char nome[80];
	char rg [15];
	char cpf[15];
	data datanasc;
	char email[30];
	char endereco [50];
	char fone[11];
	int flag;
}cliente; 
typedef struct 
{
	int codfunc;
	char nome[80];
	char rg [15];
	char cpf[15];
	data datanasc;
	char email[30];
	char endereco [50];
	char fone[11];
	data dataadmissao;
	int flag;
}funcionario; 
typedef struct
{
    int codloc, quant, codcliente, codfunc, flag, pag;
	data dataloc, datadevol;
	float valortotal, juro, desc;
}locacao; 
typedef struct
{
	int codloc, flag, codfilme;
}locfilme;
typedef struct 
{
	int codloc;
	data dataLoc;
	data datadevo;
	float valororiginal;
	float valorpago;
	int diasatraso;
}devolucao;
void cadastroGenero();
int codGenero();
void listarGenero(int i);
void excluirGenero();
void cadastroFilme();
int codFilme();
void listarFilme(int i);
void excluirFilme();
void cadastroCliente();
int codCliente();
void listarCliente(int i);
void excluirCliente();
void cadastroFuncionario();
int codFuncionario();	
void listarFuncionario(int i);
void excluirFuncionario();
void cadastroLocacao();
void listarLocacao(int i);
void excluirLocacao(int cod);
float registrarLocFilme(int i, int cont, int flag);
int codLoc();
int contGenero();
int contFuncionario();
int contLoc();
int contFilme();
void listarLocFilme(int i);
void listarLocFilmeData(int i);
void excluirLocFilme(int cod);
float buscaValorB(int cod);
data buscaData(int cod);
void registrarDevolucao();
void listarDevolucao(int i);
void editarDevolucao();
void excluirDevolucao();
data calculaDatDev(data dataLoc, int ad);
void listarFilmeEmAtraso(int i);
int calculaAtraso(data dataLocE, data dataFE);
float buscaValor(int cod);
void erro(int n);
void imprimeFilme(int i);
void imprimeCliente(int i);
void menuPrincipal();
void fixaTela();
int contCliente();

int main()
{
	fixaTela();
	menuPrincipal();

}
void fixaTela()
{
	//impede o redimensionamento. 
	//acessado em<https://stackoverflow.com/questions/47358043/can-i-prevent-the-user-of-my-program-to-resize-the-console-window-in-c>
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, 
	GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	int x,y;
    HWND cW = GetConsoleWindow();
    x = GetSystemMetrics(SM_CXSCREEN);   /* quantidade de pixel por linhas da tela   */
    y = GetSystemMetrics(SM_CYSCREEN);   /* quantidade de pixel por coluna da tela  */
	SetWindowPos( cW, 0, x/18, y/18, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
}
void menuPrincipal()
{
	fixaTela();
	system("title Sistema Locadora GabJo *filmes[]");
	system("MODE con cols=148 lines=40"); //abre o prompt com tamanho definido
  	int menu;
	do
	{
		system("cls");
		system("COLOR F0");
		void imprimeDesenhos();
		imprimeDesenhos();
		textbackground(15);
		textcolor(0);
		gotoxy(59,3); 		
		printf("  Locadora GabJo *filmes[]  ");
		textbackground(15);
		gotoxy(68,8); 	
		printf(" OPCOES ");
		gotoxy(58,12); 	
		printf(" 1. Generos ");
		gotoxy(58,17);  
		printf(" 3. Clientes ");
		gotoxy(58,22);	
		printf(" 5. Locacoes ");
		gotoxy(76,12);
		printf(" 2. Filmes ");	
		gotoxy(76,17);
		printf(" 4. Funcionarios "); 		
		gotoxy(76,22); 		
		printf(" 6. Devolucoes ");
		gotoxy(68,27);		
		printf(" 7. Sair ");
		gotoxy(54,32); 		
		printf(" Insira o numero da opcao desejada: ");
		scanf("%d", &menu);
		int subOp;
		switch(menu)
		{
			case 1:
				do
	    		{
	    			do
					{
						system("cls");
						system("COLOR F0");
						textbackground(14);   
						gotoxy(59,3); 		
						printf("  Locadora GabJo *filmes[]  ");
						gotoxy(68,8); 	
						printf(" GENEROS ");       
			      		gotoxy(63,12);		
						printf(" 1. Listar Generos ");
						gotoxy(62,16); 		
						printf(" 2. Cadastrar Generos ");
						gotoxy(63,20); 		
						printf(" 3. Excluir Generos ");
						gotoxy(68,24);		
						printf(" 4. Sair ");
						gotoxy(54,32); 		
						printf(" Insira o numero da opcao desejada: ");
			      		scanf("%d",&subOp);
			      	}while(subOp<1||subOp>4);
			      	switch(subOp)
			      	{
			      		case 1:
			      			system("cls");
			      			system("COLOR F0");
			      			listarGenero(-28);
			      			break;
			      		case 2:
			      			cadastroGenero();
			      			break;
			      		case 3:
			      			excluirGenero();
			      			break;
			      		case 4:
			      			break;
					}
					fflush(stdin);         
				}while(subOp!=4);
				menu=13; 
				break;	           
		    case 2: 
	    		do
	    		{
					do
					{
						system("cls");
						system("COLOR F0");
						textbackground(11);   
						gotoxy(59,3); 		
						printf("  Locadora GabJo *filmes[]  ");
						gotoxy(69,8); 	
						printf(" FILMES ");       
			      		gotoxy(64,12);		
						printf(" 1. Listar Filmes ");
						gotoxy(63,16); 		
						printf(" 2. Cadastrar Filmes ");
						gotoxy(63,20); 		
						printf(" 3. Excluir Filmes ");
						gotoxy(68,24);		
						printf(" 4. Sair ");
						gotoxy(54,32); 		
						printf(" Insira o numero da opcao desejada: ");
						scanf("%d",&subOp);
					}while(subOp<1||subOp>4);
					switch(subOp)
			      	{
			      		case 1:
			      			system("cls");
			      			system("COLOR F0");
			      			listarFilme(-16);
			      			break;
			      		case 2:
			      			cadastroFilme();
			      			break;
			      		case 3:
			      			excluirFilme();
			      			break;
			      		case 4:
			      			break;
					}
					fflush(stdin);
				}while(subOp!=4);
				menu=13; 
		       	break;             
		    case 3:
				do
				{
					do
					{
						system("cls");
						system("COLOR F0");
						textbackground(10);   
						gotoxy(59,3); 		
						printf("  Locadora GabJo *filmes[]  ");
						gotoxy(68,8); 	
						printf(" CLIENTES ");       
			      		gotoxy(63,12);		
						printf(" 1. Listar Clientes ");
						gotoxy(62,16); 		
						printf(" 2. Cadastrar Clientes ");
						gotoxy(63,20); 		
						printf(" 3. Excluir Clientes ");
						gotoxy(68,24);		
						printf(" 4. Sair ");
						gotoxy(54,32); 		
						printf(" Insira o numero da opcao desejada: ");
						scanf("%d",&subOp);
					}while(subOp<1||subOp>4);
					switch(subOp)
			      	{
			      		case 1:
			      			system("cls");
			      			system("COLOR F0");
			      			listarCliente(-29);
			      			break;
			      		case 2:
			      			cadastroCliente();
			      			break;
			      		case 3:
			      			excluirCliente();
			      			break;
			      		case 4:
			      			break;
					}
					fflush(stdin); 
				}while(subOp!=4);
				menu=13; 
				break;     
			case 4: 
		    	do
		    	{
					do
					{
						system("cls");
						system("COLOR F0");
						textbackground(12);   
						gotoxy(59,3); 		
						printf("  Locadora GabJo *filmes[]  ");
						gotoxy(65,8); 	
						printf(" FUNCIONARIOS ");       
			      		gotoxy(60,12);		
						printf(" 1. Listar Funcionarios ");
						gotoxy(59,16); 		
						printf(" 2. Cadastrar Funcionarios ");
						gotoxy(60,20); 		
						printf(" 3. Excluir Funcionarios ");
						gotoxy(68,24);		
						printf(" 4. Sair ");
						gotoxy(54,32); 		
						printf(" Insira o numero da opcao desejada: ");
						scanf("%d",&subOp);
					}while(subOp<1||subOp>4);
										switch(subOp)
			      	{
			      		case 1:
			      			system("cls");
			      			system("COLOR F0");
			      			listarFuncionario(-23);
			      			break;
			      		case 2:
			      			cadastroFuncionario();
			      			break;
			      		case 3:
			      			excluirFuncionario();
			      			break;
			      		case 4:
			      			break;
					}
					fflush(stdin);
				}while(subOp!=4);
				menu=13; 
		       	break;    
		    case 5:
				do
				{
					do
					{
						system("cls");
						system("COLOR F0");
						textbackground(10);   
						gotoxy(59,3); 		
						printf("  Locadora GabJo *filmes[]  ");
						gotoxy(67,8); 	
						printf(" LOCACOES ");       
			      		gotoxy(62,12);		
						printf(" 1. Listar Locacoes ");
						gotoxy(57,16); 		
						printf(" 2. Listar Locacoes Em Uma Data ");
						gotoxy(58,20); 		
						printf(" 3. Listar Locacoes Atrasadas ");
						gotoxy(61,24); 		
						printf(" 4. Cadastrar Locacoes ");
						gotoxy(62,28); 		
						printf(" 5. Excluir Locacoes ");
						gotoxy(68,32);		
						printf(" 6. Sair ");
						gotoxy(54,36); 		
						printf(" Insira o numero da opcao desejada: ");
						scanf("%d",&subOp);
					}while(subOp<1||subOp>6);
					switch(subOp)
			      	{
			      		case 1:
			      			system("cls");
			      			system("COLOR F0");
			      			listarLocacao(-22);
			      			break;
			      		case 2:
			      			system("cls");
			      			system("COLOR F0");
			      			listarLocFilmeData(0);
			      			break;
			      		case 3:
			      			system("cls");
			      			system("COLOR F0");
			      			listarFilmeEmAtraso(0);
			      			break;
			      		case 4:
			      			cadastroLocacao();
			      			break;
			      		case 5:
						 	int cod;
							system("cls");
							system("COLOR F0");
							listarLocacao(0);
							gotoxy(10,6);
							printf("Digite o código de locacao");
							gotoxy(10,7);
							scanf("%d", &cod);
							excluirLocacao(cod);
			      			break;
						case 6:
							break;	
					}
					fflush(stdin);   
				}while(subOp!=6);
				menu=13; 
				break;
		    case 6:
				do
				{
					do
					{
						system("cls");
						system("COLOR F0");
						textbackground(13);   
						gotoxy(59,3); 		
						printf("  Locadora GabJo *filmes[]  ");
						gotoxy(67,8); 	
						printf(" LOCACOES ");       
			      		gotoxy(62,12);		
						printf(" 1. Listar Devolucao ");
						gotoxy(62,16); 		
						printf(" 2. Fazer Devolucao ");
						gotoxy(68,20);		
						printf(" 3. Sair ");
						gotoxy(54,32); 		
						printf(" Insira o numero da opcao desejada: ");
						scanf("%d",&subOp);
					}while(subOp<1||subOp>3);
					switch(subOp)
					{
						case 1:
							listarDevolucao(0);
							break;
						case 2:
							registrarDevolucao();
							break;
						case 3:
							break;
					}
					gotoxy(47,35);          
				}while(subOp!=3);
				menu=13; 
				break;  
		    case 7:
				menu=15;
		        break;   
		    default:
		     	erro(0);
				break;	             
		}
	    gotoxy(56,35);
		printf(" Deseja sair!!! Utilize a opção 7... ");   
	}while(menu==13);
	system("cls");
	system("COLOR C0");
	gotoxy(65,20);
	printf("OBRIGADO<3");
	gotoxy(34,36);
	exit(0);
}
void erro(int n)
{
	int menu;
	system("cls");
	system("COLOR C0");
	switch (n)
	{
		case 0:
			gotoxy(57, 19);
			printf(" Ops, insira um numero valido!!! ");
			while(menu!=13)
			{
				menu=getch();
        	}
        	getchar();
			break;
		case 1:
			gotoxy(57, 19);
			printf(" Ops, erro ao abrir o arquivo ;-; ");
			fflush(stdin);
			while(menu!=13)
			{
				menu=getch();
        	}
			break;
		case 2:
			gotoxy(41, 19);
			printf(" Ops, voce ainda nao cadastrou nenhum genero, para continuar cadastre um. ");
			gotoxy(62,35);
			printf("Tecle[ENTER] para continuar"); 
			while(menu!=13)
			{
				menu=getch();
        	}		
			break;	
		case 3:	
			gotoxy(41, 19);
			printf(" Ops, voce ainda nao cadastrou nenhum filme, para continuar cadastre um. ");
			gotoxy(62,35);
			printf("Tecle[ENTER] para continuar"); 
			while(menu!=13)
			{
				menu=getch();
        	}	
			break;
		case 4:
			gotoxy(41, 19);
			printf(" Ops, voce ainda nao cadastrou nenhum cliente, para continuar cadastre um. ");
			gotoxy(62,35);
			printf("Tecle[ENTER] para continuar"); 
			while(menu!=13)
			{
				menu=getch();
        	}
			break;	
		case 5:
			gotoxy(41, 19);
			printf(" Ops, voce ainda nao cadastrou nenhum funcionario, para continuar cadastre um. ");
			gotoxy(62,35);
			printf("Tecle[ENTER] para continuar"); 
			while(menu!=13)
			{
				menu=getch();
        	}
			break;
		case 6:
			gotoxy(41, 19);
			printf(" Ops, voce ainda nao registrou nenhuma locacao, para continuar registre uma. ");
			gotoxy(62,35);
			printf("Tecle[ENTER] para continuar"); 
			while(menu!=13)
			{
				menu=getch();
        	}
			break;
		case 7:
			gotoxy(41, 19);
			printf(" Ops, voce ainda nao registrou nenhuma devolucao, para continuar registre uma. ");
			gotoxy(62,35);
			printf("Tecle[ENTER] para continuar"); 
			while(menu!=13)
			{
				menu=getch();
        	}
			break;	
	}	
	
}
imprimeDesenhos()
{
    //imprime desenho 1
	textbackground(8);
	gotoxy(115,33);
	printf("     ");
	textbackground(4);
	printf("                ");
	textbackground(8);
	printf("     ");
    textbackground(8);
	gotoxy(115,34);
	printf("                          ");
	textbackground(0);
	gotoxy(141,34);
	printf("  ");
	gotoxy(141,33);
	printf("  ");
    textbackground(8);
	gotoxy(115,35);
	printf("       ");
	textbackground(4);
	printf("   ");
	textbackground(8);
	printf("      ");
	textbackground(4);
	printf("   ");
	textbackground(8);
	printf("       ");
	textbackground(0);
	printf("  ");
	textbackground(8);
	gotoxy(115,36);
	printf("      ");
	textbackground(4);
	printf("  ");
	textbackground(0);
	printf(" ");
	textbackground(4);
	printf("  ");
	textbackground(8);
	printf("    ");
	textbackground(4);
	printf("  ");
	textbackground(0);
	printf(" ");
	textbackground(4);
	printf("  ");
	textbackground(8);
	printf("      ");
	textbackground(0);
	printf("  ");
    textbackground(8);
	gotoxy(115,37);
	printf("       ");
	textbackground(4);
	printf("   ");
	textbackground(8);
	printf("      ");
	textbackground(4);
	printf("   ");
	textbackground(8);
	printf("       ");
	textbackground(0);
	printf("  ");
	gotoxy(115,38);
	textbackground(8);
	printf("                          ");
	textbackground(0);
	printf("  ");
	gotoxy(115,39);
	textbackground(8);
	printf("                          ");
	gotoxy(116,32);
	textbackground(0);
	printf("                         ");
	textbackground(0);
	printf("  ");
	
	//desenho 2
	textbackground(0);
	gotoxy(5,3);
	printf("     ");
	textbackground(4);
	printf("                ");
	textbackground(0);
	printf("     ");
	textbackground(8);
	printf("  ");
    textbackground(0);
	gotoxy(5,4);
	printf("                          ");
	textbackground(8);
	printf("  ");
    textbackground(0);
	gotoxy(5,5);
	printf("       ");
	textbackground(4);
	printf("   ");
	textbackground(0);
	printf("      ");
	textbackground(4);
	printf("   ");
	textbackground(0);
	printf("       ");
	textbackground(8);
	printf("  ");
	textbackground(0);
	gotoxy(5,6);
	printf("      ");
	textbackground(4);
	printf("  ");
	textbackground(8);
	printf(" ");
	textbackground(4);
	printf("  ");
	textbackground(0);
	printf("    ");
	textbackground(4);
	printf("  ");
	textbackground(8);
	printf(" ");
	textbackground(4);
	printf("  ");
	textbackground(0);
	printf("      ");
	textbackground(8);
	printf("  ");
    textbackground(0);
	gotoxy(5,7);
	printf("       ");
	textbackground(4);
	printf("   ");
	textbackground(0);
	printf("      ");
	textbackground(4);
	printf("   ");
	textbackground(0);
	printf("       ");
	textbackground(8);
	printf("  ");
	gotoxy(5,8);
	textbackground(0);
	printf("                          ");
	textbackground(8);printf("  ");
	gotoxy(5,9);
	textbackground(0);
	printf("                          ");
	gotoxy(6,2);
	textbackground(8);
	printf("                         ");
	textbackground(8);
	printf("  ");
}
void cadastroGenero()
{
	FILE *cadGenero=fopen("arquivoGenero.dat","ab");
	genero escreverGenero;
	escreverGenero.codigo=0;
	if(cadGenero==NULL)
	{
		erro(1);	
	}
	else
	{
		fflush(stdin);
		system("cls");
		system("COLOR F0");
		listarGenero(0);
		fflush(stdin);
		gotoxy(10,6); 
		printf("Insira o nome do genero:");
		gotoxy(10,7);
		scanf("%[^\n]", escreverGenero.nome);
		fflush(stdin);
		escreverGenero.codigo=codGenero();
		fflush(stdin);	
		escreverGenero.flag=2;
		fwrite(&escreverGenero, sizeof(genero), 1, cadGenero);
	}
	fclose(cadGenero);
	listarGenero(0);
}
int codGenero()
{
	FILE *cdgGenero=fopen("arquivoGenero.dat","rb");
	int cont=0;
	genero cdg;
	while(!feof(cdgGenero))
	{
		if(fread(&cdg, sizeof(genero), 1, cdgGenero)!=0)
		{
			cont++;
		}
	}
	fclose(cdgGenero);
	return cont;
}
int contGenero()
{
	FILE *cdgGenero=fopen("arquivoGenero.dat","rb");
	int cont=0;
	genero cdg;
	while(!feof(cdgGenero))
	{
		if(fread(&cdg, sizeof(genero), 1, cdgGenero)!=0)
		{
			if(cdg.flag==2)
			{
				cont++;
			}
		}
	}
	fclose(cdgGenero);
	return cont;
}
void listarGenero(int i)
{
	FILE *listGenero=fopen("arquivoGenero.dat","rb");
	genero lerGenero;
	if(listGenero==NULL||contGenero()==0)
	{
		erro(2);	
	}
	else
	{
		int l=0;
		textbackground(14);
		gotoxy(84+i,6); printf("Generos listados sao:           ");
		while(!feof(listGenero))
		{
			if(fread(&lerGenero, sizeof(genero), 1, listGenero)!=0)
			{
				if(lerGenero.flag)
				{
					++l;
					gotoxy(84+i,6+l);
					((l)%2==0)? textbackground(14) : textbackground(15);
					printf("                                ");
					gotoxy(84+i,6+l);
					printf("%d-%s ", lerGenero.codigo, lerGenero.nome);
				}
			}
		}
	}
	textbackground(15);
	fclose(listGenero);
}
void excluirGenero()
{
	FILE *f=fopen("arquivoGenero.dat","rb+");
	int codigo;
    genero reg; 
	genero dado;
	genero excluido; 
	if(f==NULL)   
	{
		erro(2);   
	}
	else    
	{
		system("cls");
		system("COLOR F0");
		listarGenero(0);
		gotoxy(10,6);
		printf("Informe qual registro deseja excluir: "); 
		gotoxy(10,7);         
		scanf("%d",&codigo);  
		while(!feof(f))  
		{ 
			if(fread(&dado,sizeof(genero),1,f)!=0)
			{
				if(dado.codigo==codigo)
			    { 
				    excluido.codigo=dado.codigo;
					excluido.flag=0;  
				}
			}
		}  
		fseek(f,codigo*sizeof(genero),SEEK_SET); 	                  
		fwrite(&excluido, sizeof(genero),1,f);      		                 
		fclose(f);
	}  
}
void cadastroFilme()
{
	FILE *cadFilme=fopen("arquivoFilme.dat","ab");
	filme escreverFilme;
	escreverFilme.codfilme=0;
	if(cadFilme==NULL)
	{
		erro(1);
	}
	else
	{
		system("cls");
		system("COLOR F0");
		listarFilme(0);
		fflush(stdin);
		gotoxy(10,6);
		printf("Insira o nome do filme:");
		gotoxy(10,7);
		scanf("%23[^\n]", escreverFilme.nome);
		listarGenero(16);
		fflush(stdin);
		gotoxy(10,8);
		printf("Insira o código do genero: ");
		gotoxy(10,9);
		scanf("%d", &escreverFilme.codgen);
		fflush(stdin);
		gotoxy(10,10);
		printf("Insira o ano de lancamento do filme:");
		gotoxy(10,11);
		scanf("%d", &escreverFilme.ano);
		gotoxy(10,12);
		printf("Insira a classificacao do filme: ");
		fflush(stdin);
		gotoxy(10,13);
		scanf("%[^\n]", escreverFilme.classificacao);
		gotoxy(10,14);
		printf("Insira o valor do filme: ");
		gotoxy(10,15);
		scanf("%f", &escreverFilme.valor);
		escreverFilme.codfilme=codFilme();
		escreverFilme.flag=2;
		fwrite(&escreverFilme, sizeof(filme), 1, cadFilme);
	}
	fclose(cadFilme);
	listarFilme(0);		
}
int codFilme()
{
	FILE *codFilme=fopen("arquivoFilme.dat","rb");
	filme cdg;
	int cont=0;
	while(!feof(codFilme))
	{
		if(fread(&cdg, sizeof(filme), 1, codFilme)!=0)
		{
			cont++;	
		}
	}
	fclose(codFilme);
	return cont;	
}
int contFilme()
{
	FILE *codFilme=fopen("arquivoFilme.dat","rb");
	filme cdg;
	int cont=0;
	while(!feof(codFilme))
	{
		if(fread(&cdg, sizeof(filme), 1, codFilme)!=0)
		{
			if(cdg.flag==2)
			{	
				cont++;	
			}
		}
	}
	fclose(codFilme);
	return cont;	
}
void listarFilme(int i)
{
	FILE *listFilme=fopen("arquivoFilme.dat","rb");
	filme lerFilme;
	lerFilme.codfilme=0;
	if(listFilme==NULL||contFilme()==0)
	{
		erro(3);
	}
	else
	{
		textbackground(11);
		gotoxy(68+i,6);
		printf("Os filmes listados sao:          ");
		int l=0;
		while(!feof(listFilme))
		{
			if(fread(&lerFilme, sizeof(filme), 1, listFilme)!=0)
			{
				if(lerFilme.flag)
				{
					++l;
					((l)%2==0)? textbackground(11) : textbackground(15);
					gotoxy(68+i, 6+l);
					printf("                                 ");
					gotoxy(68+i, 6+l);
					printf("%d-%s=R$ %.2f", lerFilme.codfilme, lerFilme.nome, lerFilme.valor); 
				}
			}
		}
	}
	fclose(listFilme);
	textbackground(15);	
}
void excluirFilme()
{
	FILE *f=fopen("arquivoFilme.dat","rb+");
	int codigo;
    filme reg; 
	filme dado;
	filme excluido; 
	if(f==NULL)   
	{
		erro(3);   
	}
	else    
	{
		system("cls");
		system("COLOR F0");
		listarFilme(0);
		gotoxy(10,6);
		printf("Informe qual registro deseja excluir: ");    
		gotoxy(10,7);      
		scanf("%d",&codigo);  
		while(!feof(f))  
		{
			if(fread(&dado,sizeof(filme),1,f)!=0)
			{
				if(dado.codfilme==codigo)
			    { 
				    excluido.codfilme=dado.codfilme;
					strcpy(excluido.nome,dado.nome);
					excluido.flag=0;  
				}
			}
		}  
		fseek(f,codigo*sizeof(filme),SEEK_SET); 	                  
		fwrite(&excluido, sizeof(filme),1,f);      		                 
		fclose(f);
	}
}
void listarLocFilmeData(int i)
{
	FILE *f=fopen("arquivoCadastroLocacao.dat","rb");
	locacao dado;
	float valor;	
	if(f==NULL)   
	{
		erro(1);   
	}
	else    
	{
		system("cls");
		data dataH;
		int l=0,lx=0,i=0;
		gotoxy(10,6);
		printf("Insira a data:");	
		gotoxy(10,7);
		printf("dia: ");scanf("%d", &dataH.dia);
		gotoxy(10,8);
		printf("mes: ");scanf("%d", &dataH.mes);
		gotoxy(10,9);
		printf("ano: ");scanf("%d", &dataH.ano);
		textbackground(10);
		gotoxy(74,6);
		printf("                                       ");
		gotoxy(74,6);
		printf("Filmes locado nesse dia:");
		while(!feof(f))  
		{
			if(fread(&dado,sizeof(locacao),1,f)!=0)
			{
				if(dado.flag) 
			    { 
			    	if((dataH.dia==dado.dataloc.dia)&&((dataH.ano==dado.dataloc.ano)&&(dataH.mes==dado.dataloc.mes)))
			    	{
						++l;
						++lx;
						(lx%2==0)? textbackground(10) : textbackground(15);
						gotoxy(74+i,6+l);
						printf("                                       ");
						gotoxy(74+i,6+l);
						printf("%d-", dado.codloc);
						imprimeCliente(dado.codcliente);
						printf("  %d/%d/%d", dado.datadevol.dia,dado.datadevol.mes,dado.datadevol.ano);
						++l;
						gotoxy(74+i,6+l);
						printf("                                       ");
						gotoxy(74+i,6+l);
						imprimeFilme(dado.codloc);
					}
				}
			}
		} 
		fclose(f);	
		textbackground(15);	                 
	} 
}
void listarFilmeEmAtraso(int i)
{
	FILE *f=fopen("arquivoCadastroLocacao.dat","rb");
	locacao dado;
	float valor;	
	if(f==NULL)   
	{
		erro(1);   
	}
	else    
	{
		system("cls");
		data dataH;
		int l=0,lx=0,i=0;
		gotoxy(10,6);
		printf("Insira a data da locacao");	
		gotoxy(10,7);
		printf("dia: ");scanf("%d", &dataH.dia);
		gotoxy(10,8);
		printf("mes: ");scanf("%d", &dataH.mes);
		gotoxy(10,9);
		printf("ano: ");scanf("%d", &dataH.ano);
		textbackground(10);
		gotoxy(74,6);
		printf("                                       ");
		gotoxy(74,6);
		printf("Filmes em atraso:");
		while(!feof(f))  
		{
			if(fread(&dado,sizeof(locacao),1,f)!=0)
			{
				if(dado.flag) 
			    { 
			    	int atraso=0;
			    	atraso=calculaAtraso(dataH,dado.datadevol);
			    	if(atraso<0)
			    	{
						++l;
						++lx;
						(lx%2==0)? textbackground(10) : textbackground(15);
						gotoxy(74+i,6+l);
						printf("                                       ");
						gotoxy(74+i,6+l);
						printf("%d-", dado.codloc);
						imprimeCliente(dado.codcliente);
						printf("  %d/%d/%d", dado.datadevol.dia,dado.datadevol.mes,dado.datadevol.ano);
						++l;
						gotoxy(74+i,6+l);
						printf("                                       ");
						gotoxy(74+i,6+l);
						imprimeFilme(dado.codloc);
					}
				}
			}
		} 
		fclose(f);
		textbackground(15);		                 
	} 
}
int calculaAtraso(data dataLocE, data dataFE)
{
	data dataLoc, dataF;
	int	m=1;
	if(dataFE.ano<dataLocE.ano)
	{
		dataF=dataLocE;
		dataLoc=dataFE;
		m=-1;
	}
	else if ((dataFE.ano==dataLocE.ano)&&(dataFE.mes<dataLocE.mes))
	{
		dataF=dataLocE;
		dataLoc=dataFE;
		m=-1;
	}
	else if ((dataFE.ano==dataLocE.ano)&&((dataFE.mes==dataLocE.mes)&&(dataFE.dia<dataLocE.dia)))
	{
		dataF=dataLocE;
		dataLoc=dataFE;
		m=-1;
	}
	else
	{
		dataF=dataFE;
		dataLoc=dataLocE;
		m=1;
	}
	int acDias[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	int acDiasBi[12]={0,31,60,91,121,152,181,212,244,273,305,335};
	int difDias,cont=0,flag=0,flag2=0,difAno, anoLoc, anoF, x=1,i,result;
	difDias=(dataF.dia-dataLoc.dia)*24;
	for(i=dataLoc.ano; i<=dataF.ano; i++)
	{
		bool bi=(i%4==0&&i%100!=0)||(i%100==0&&i%400==0);
		if(bi)
		{
			if(i==dataF.ano)
			{
				flag=1;
				cont--;
			}
			if(i==dataLoc.ano)
			{
				flag2=1;
				cont--;
			}
			cont++;
		}
	}
	if(flag==1)
	{
		anoF=(acDiasBi[dataF.mes-1])*24;
	}
	else
	{
		anoF=(acDias[dataF.mes-1])*24;
	}
	if(flag2==1)
	{
		anoLoc=(366-acDiasBi[dataF.mes-1])*24;
	}
	else
	{
		anoLoc=(365-acDias[dataF.mes-1])*24;
	}
	difAno=((dataF.ano-dataLoc.ano-cont-x)*365+cont*366)*24;
	result=(difDias+difAno+anoLoc+anoF)/24;
	result*=m;
	return result;
}
void cadastroCliente()
{
	FILE *cadCliente=fopen("arquivoCliente.dat","ab");
	cliente escreverCliente;
	escreverCliente.codcliente=0;
	if(cadCliente==NULL)
	{
		erro(1);
	}
	else
	{
		system("cls");
		system("COLOR F0");
		listarCliente(0);
		fflush(stdin);
		gotoxy(10,6);
		printf("Insira o nome do cliente:");
		gotoxy(10,7);
		scanf("%[^\n]", escreverCliente.nome);
		fflush(stdin);
		gotoxy(10,8);
		printf("Insira o CPF:");
		gotoxy(10,9);
		scanf("%[^\n]", escreverCliente.cpf);	
		fflush(stdin);
		gotoxy(10,10);
		printf("Insira o RG:");
		gotoxy(10,11);
		scanf("%[^\n]",  escreverCliente.rg);
		fflush(stdin);
		gotoxy(10,12);
		printf("Insira a data de nascimento:");
		gotoxy(10,13);
		printf("dia: ");
		scanf(" %d", &escreverCliente.datanasc.dia);
		gotoxy(10,14);
		printf("mes: ");
		scanf("%d", &escreverCliente.datanasc.mes);
		gotoxy(10,15); 
		printf("ano: ");
		scanf("%d", &escreverCliente.datanasc.ano);
		fflush(stdin);
		gotoxy(10,16); 	
		printf("Insira o endereco:");
		gotoxy(10,17); 
		scanf("%[^\n]",  escreverCliente.endereco);
		fflush(stdin);
		gotoxy(10,18); 
		printf("Insira o e-mail:");
		gotoxy(10,19); 
		scanf("%[^\n]", escreverCliente.email);	
		fflush(stdin);
		gotoxy(10,20); 
		printf("Insira o telefone:");
		gotoxy(10,21); 
		scanf("%[^\n]",  escreverCliente.fone);
		fflush(stdin);
		escreverCliente.codcliente=codCliente();
		escreverCliente.flag=2;
		fwrite(&escreverCliente, sizeof(cliente), 1, cadCliente);
	}
	fclose(cadCliente);
}
int codCliente()
{
	FILE *codCliente=fopen("arquivoCliente.dat","rb");
	cliente cdg;
	int cont=0;
	while(!feof(codCliente))
	{
		if(fread(&cdg, sizeof(cliente), 1, codCliente)!=0)
		{
		cont++;
		}
	}
	fclose(codCliente);
	return cont;	
}
int contCliente()
{
	FILE *codCliente=fopen("arquivoCliente.dat","rb");
	cliente cdg;
	int cont=0;
	while(!feof(codCliente))
	{
		if(fread(&cdg, sizeof(cliente), 1, codCliente)!=0)
		{
			if(cdg.flag==2)
			{
				cont++;
			}
		}
	}
	fclose(codCliente);
	return cont;	
}
void listarCliente(int i)
{
	FILE *listCliente=fopen("arquivoCliente.dat", "ra");
	cliente lerCliente;
	lerCliente.codcliente=0;
	if(listCliente==NULL||contCliente()<=0)
	{
		erro(4);
	}
	else
	{
		int l=0;
		textbackground(10);
		gotoxy(74+i,6);
		printf("Clientes listados:                                  ");
		while(!feof(listCliente))
		{
			if(fread(&lerCliente, sizeof(cliente), 1, listCliente)!=0)
			{
				if(lerCliente.flag)
				{
					++l;
					((l)%2==0)? textbackground(10) : textbackground(15);
					gotoxy(74+i, 6+l);
					printf("                                                    ");
					gotoxy(74+i, 6+l);
					printf("%d-%s", lerCliente.codcliente, lerCliente.nome);
				}
			}
		}
	}
	fclose(listCliente);
	textbackground(15);
}
void excluirCliente()
{
	FILE *f=fopen("arquivoCliente.dat","rb+");
	int codigo;
    cliente reg; 
	cliente dado;
	cliente excluido; 
	if(f==NULL)   
	{
		erro(4);   
	}
	else    
	{
		clrscr() ;
		listarCliente(0);
		gotoxy(10,6);
		printf("Informe qual registro deseja excluir: ");
		gotoxy(10,7);           
		scanf("%d",&codigo);  
		while(!feof(f))  
		{
			if (fread(&dado,sizeof(cliente),1,f)!=0)
			{
				if (dado.codcliente==codigo)
			    { 
				    excluido.codcliente=dado.codcliente;
					excluido.flag=0;  
				}
			}
		}  
		fseek(f,codigo*sizeof(cliente),SEEK_SET); 	                  
		fwrite(&excluido, sizeof(cliente),1,f);      		                 
		fclose(f);
	} 
}
void cadastroFuncionario()
{
	FILE *cadFuncionario=fopen("arquivoFuncionario.dat","ab");
	funcionario escreverFuncionario;
	escreverFuncionario.codfunc=0;
	if(cadFuncionario==NULL)
	{
		erro(1);
	}
	else
	{
		fflush(stdin);
		system("cls");
		system("COLOR F0");
		listarFuncionario(0);
		fflush(stdin);
		gotoxy(10,6);
		printf("Insira o nome do Funcionario:");
		gotoxy(10,7);
		scanf("%[^\n]", escreverFuncionario.nome);
		fflush(stdin);
		gotoxy(10,8);
		printf("Insira o CPF:");
		gotoxy(10,9);
		scanf("%[^\n]", escreverFuncionario.cpf);	
		fflush(stdin);
		gotoxy(10,10);
		printf("Insira o RG:");
		gotoxy(10,11);
		scanf("%[^\n]",  escreverFuncionario.rg);
		fflush(stdin);
		gotoxy(10,12);
		printf("Insira a data de admissao:");
		gotoxy(10,13);
		printf("dia: ");
		scanf("%d", &escreverFuncionario.dataadmissao.dia);
		gotoxy(10,14);
		printf("mes: ");
		scanf("%d", &escreverFuncionario.dataadmissao.mes);
		gotoxy(10,15);
		printf("ano: ");
		scanf("%d", &escreverFuncionario.dataadmissao.ano);
		fflush(stdin);
		gotoxy(10,16);
		printf("Insira a data de nascimento:");
		gotoxy(10,17);printf("dia: ");
		scanf("%d", &escreverFuncionario.datanasc.dia);
		gotoxy(10,18);printf("mes: ");
		scanf("%d", &escreverFuncionario.datanasc.mes);
		gotoxy(10,19);printf("ano: ");
		scanf("%d", &escreverFuncionario.datanasc.ano);
		fflush(stdin);
		gotoxy(10,20);	
		printf("Insira o enderco:");
		gotoxy(10,21);
		scanf("%[^\n]",  escreverFuncionario.endereco);
		fflush(stdin);
		gotoxy(10,22);
		printf("Insira o e-mail:");
		gotoxy(10,23);
		scanf("%[^\n]", escreverFuncionario.email);	
		fflush(stdin);
		gotoxy(10,24);
		printf("Insira o telefone:");
		gotoxy(10,25);
		scanf("%[^\n]",  escreverFuncionario.fone);
		fflush(stdin);
		escreverFuncionario.flag=3;
		escreverFuncionario.codfunc=codFuncionario();	
		fwrite(&escreverFuncionario, sizeof(funcionario), 1, cadFuncionario);		
	}
	fclose(cadFuncionario);
}
int codFuncionario()
{
	FILE *codFuncionario=fopen("arquivoFuncionario.dat","rb");
	funcionario cdg;
	int cont=0;
	while(!feof(codFuncionario))
	{
		if(fread(&cdg, sizeof(funcionario), 1, codFuncionario)!=0)
		{
		cont++;
		}
	}
	fclose(codFuncionario);
	return cont;	
}
int contFuncionario()
{
	FILE *codFuncionario=fopen("arquivoFuncionario.dat","rb");
	funcionario cdg;
	int cont=0;
	while(!feof(codFuncionario))
	{
		if(fread(&cdg, sizeof(funcionario), 1, codFuncionario)!=0)
		{
			if(cdg.flag==2)
			{
				cont++;
			}
		}
	}
	fclose(codFuncionario);
	return cont;	
}
void listarFuncionario(int i)
{
	FILE *listFuncionario=fopen("arquivoFuncionario.dat", "ra");
	funcionario lerFuncionario;
	if(listFuncionario==NULL||contFuncionario()==0)
	{
		erro(5);
	}
	else
	{
		textbackground(12);
		gotoxy(74+i,6);
		printf("Funcionarios listados:                  ");
		int l=0;
		while(!feof(listFuncionario))
		{
			if(fread(&lerFuncionario, sizeof(funcionario), 1, listFuncionario)!=0)
			{
				if(lerFuncionario.flag)
				{
					++l;
					((l)%2==0)? textbackground(12) : textbackground(15);
					gotoxy(74+i,6+l);
					printf("                                        ");
					gotoxy(74+i,6+l);
					printf("%d- %s", lerFuncionario.codfunc, lerFuncionario.nome);
				}
			}
		}
	}
	fclose(listFuncionario);
	textbackground(15);
}
void excluirFuncionario()
{
	FILE *f=fopen("arquivoFuncionario.dat","rb+");
	int codigo;
    funcionario reg; 
	funcionario dado;
	funcionario excluido; 
	if(f==NULL)   
	{
		erro(5);   
	}
	else    
	{
		clrscr() ;
		listarFuncionario(0);
		gotoxy(10,6);
		printf("Informe qual registro deseja excluir: ");
		gotoxy(10,7);           
		scanf("%d",&codigo);  
		while(!feof(f))  
		{ 
			if (fread(&dado,sizeof(funcionario),1,f)!=0)
			{
				if (dado.codfunc==codigo)
			    { 
				    excluido.codfunc=dado.codfunc;
					excluido.flag=0;  
				}
			}
		}  
		fseek(f,codigo*sizeof(funcionario),SEEK_SET); 	                  
		fwrite(&excluido, sizeof(funcionario),1,f);      		                 
		fclose(f);
	} 
	listarFuncionario(0);
}
void listarLocacao(int i)
{
	FILE *listLocacao=fopen("arquivoCadastroLocacao.dat", "rb");
	locacao lerLocacao;
	if(listLocacao==NULL||contLoc()==0)
	{
	   erro(6);	
	}
	else
	{
		gotoxy(74+i,6);
		textbackground(10);
		printf("Locacoes listadas:                     ");
		int l=0,lx=0,x;
		while(!feof(listLocacao))
		{
			if(fread(&lerLocacao, sizeof(locacao), 1, listLocacao)!=0)
			{
					if(lerLocacao.flag)
					{
						++l;
						++lx;
						(lx%2==0)? textbackground(10) : textbackground(15);
						gotoxy(74+i,6+l);
						printf("                                       ");
						gotoxy(74+i,6+l);
						printf("%d-", lerLocacao.codloc);
						imprimeCliente(lerLocacao.codcliente);
						++l;
						gotoxy(74+i,6+l);
						printf("                                       ");
						gotoxy(74+i,6+l);
						imprimeFilme(lerLocacao.codloc);
						(lerLocacao.quant>1)? printf("+%d", lerLocacao.quant): printf("");
					}
				}
				
		}
		fclose(listLocacao);
		textbackground(15);
	}
}
void imprimeCliente(int i)
{
	FILE *listCliente=fopen("arquivoCliente.dat","rb");
	cliente lerCliente;
	if(listCliente==NULL)
	{
		erro(3);
	}
	else
	{
		while(!feof(listCliente))
		{
			if(fread(&lerCliente, sizeof(cliente), 1, listCliente)!=0)
			{
				if(lerCliente.codcliente==i)
				{
					printf("%s", lerCliente.nome);				
				}
				
			}
			
		}
	}
	fclose(listCliente);		
}
void imprimeFilme(int i)
{
	FILE *listLoc=fopen("arquivoLocFilme.dat","rb");
	locfilme lerLoc;
	if(listLoc==NULL)
	{
		erro(3);
	}
	else
	{
		while(!feof(listLoc))
		{
			if(fread(&lerLoc, sizeof(locfilme), 1, listLoc)!=0)
			{
				if(lerLoc.codloc==i)
				{
					i=lerLoc.codfilme;
				}
			}
		}
	}
	fclose(listLoc);	
	FILE *listFilme=fopen("arquivoFilme.dat","rb");
	filme lerFilme;
	if(listFilme==NULL)
	{
		erro(3);
	}
	else
	{
		while(!feof(listFilme))
		{
			if(fread(&lerFilme, sizeof(filme), 1, listFilme)!=0)
			{
				if(lerFilme.codfilme==i)
				{
					printf("%s", lerFilme.nome);
				}
			}
		}
	}
	fclose(listFilme);	
}
void cadastroLocacao()
{
	FILE *cadLocacao=fopen("arquivoCadastroLocacao.dat","ab");
	locacao escreverLocacao;
	if(cadLocacao==NULL)
	{
		erro(1);
	}
	else
	{
		system("cls");
		system("COLOR F0");
		listarCliente(20);
		fflush(stdin);
		escreverLocacao.flag=2;
		gotoxy(10,6);
		printf("Insira o codigo do cliente");
		gotoxy(10,7);
		scanf("%d", &escreverLocacao.codcliente);
		fflush(stdin);
		gotoxy(10,8);
		printf("Insira a data da locacao");	
		gotoxy(10,9);
		printf("dia: ");scanf("%d", &escreverLocacao.dataloc.dia);
		gotoxy(10,10);
		printf("mes: ");scanf("%d", &escreverLocacao.dataloc.mes);
		gotoxy(10,11);
		printf("ano: ");scanf("%d", &escreverLocacao.dataloc.ano);
		listarFuncionario(-21);
		gotoxy(10,12);
		printf("Insira o codigo do funcionario:");
		gotoxy(10,13);
		scanf("%d", &escreverLocacao.codfunc);
		escreverLocacao.codloc=codLoc();
		gotoxy(10,14);
		printf("Insira a quantidade de Filmes:");
		gotoxy(10,15);
		scanf("%d", &escreverLocacao.quant);
		printf("%d", escreverLocacao.quant);
		(escreverLocacao.quant<=3)? escreverLocacao.datadevol=calculaDatDev(escreverLocacao.dataloc, 3) : escreverLocacao.datadevol=calculaDatDev(escreverLocacao.dataloc, 4);
		escreverLocacao.valortotal=registrarLocFilme(escreverLocacao.codloc, escreverLocacao.quant, escreverLocacao.flag);
		system("cls");
		gotoxy(10,6);
		textbackground(14);
		printf("valor total= %.2f", escreverLocacao.valortotal);
		textbackground(15);
		gotoxy(10,7);
		printf("Escolha a forma de pagamento:");
		gotoxy(10,8);
		printf("1-A vista           2-A prazo");
		do 
		{
			gotoxy(10,9);
			printf("                 "); 
			gotoxy(10,9);
			printf("Opcao:");
			scanf("%d", &escreverLocacao.pag);
		}while(escreverLocacao.pag!=2&&escreverLocacao.pag!=1);
		if(escreverLocacao.pag==1)
		{
			gotoxy(10,10);
			printf("Insira o desconto em %%:");
			gotoxy(10,11);
			scanf("%f", &escreverLocacao.desc);
			gotoxy(10,12);
			textbackground(14);
			printf("valor a receber= %.2f", escreverLocacao.valortotal-(escreverLocacao.valortotal*escreverLocacao.desc/100));
			textbackground(15);	
	    }
	    else
	    {
	    	gotoxy(10,10);
			printf("Insira os juros em %%:");
			gotoxy(10,11);
			scanf("%f", &escreverLocacao.juro);	
			gotoxy(10,12);
			textbackground(14);
			printf("valor a receber= %.2f", escreverLocacao.valortotal*escreverLocacao.juro/100+escreverLocacao.valortotal);
			textbackground(15);
	 	}
	 	gotoxy(10,13);
		printf("Devolver em %d/%d/%d", escreverLocacao.datadevol.dia, escreverLocacao.datadevol.mes, escreverLocacao.datadevol.ano);	
		getchar();
		fwrite(&escreverLocacao, sizeof(locacao), 1, cadLocacao);
	}
	fclose(cadLocacao);	
}
data calculaDatDev(data dataLoc, int ad)
{
	int diasFev,limMes, excesso;
	data dataDev;
	switch(dataLoc.mes)//verifica o mes e atribui sua quantidade de dias menos os dias adicionais
	{
		case 1:
			limMes=31-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 2:
			((dataLoc.ano%4==0&&dataLoc.ano%100!=0)||(dataLoc.ano%100==0&&dataLoc.ano%400==0))? diasFev=29 : diasFev=28;//verifica se o ano é bissexto e determina os dias de fev
			limMes=diasFev-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 3:
			limMes=31-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 4:
			limMes=30-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 5:
			limMes=31-ad;
			excesso=dataLoc.dia-limMes;
			break;	
		case 6:
			limMes=30-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 7:
			limMes=31-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 8:
			limMes=31-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 10:
			limMes=31-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 9:
			limMes=30-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 11:
			limMes=30-ad;
			excesso=dataLoc.dia-limMes;
			break;
		case 12:
			limMes=31-ad;
			excesso=dataLoc.dia-limMes;
			break;
	}
	if(dataLoc.dia<limMes)//verifica se esta no limite entre meses 
	{
		dataDev=dataLoc;
		dataDev.dia+=ad;
	}
	else if(dataLoc.mes==12)//verfica se esta no limite anual
	{
		dataDev=dataLoc;
		dataDev.ano++;
		dataDev.mes=01;
		dataDev.dia=excesso;
	}
	else
	{
		dataDev=dataLoc;
		dataDev.mes++;
		dataDev.dia=excesso;
	}
	return dataDev;	
}
float registrarLocFilme(int i, int cont, int flag)
{
	float valorTotal=0;
	system("cls");
	for(int j=1; j<=cont; j++)
	{
		FILE *regLocFilme=fopen("arquivoLocFilme.dat", "ab");
		locfilme escreverLocFilme;
		if(regLocFilme==NULL)
		{
			erro(1);
		}
		else
		{
			system("COLOR F0");
			listarFilme(0);
			fflush(stdin);
			escreverLocFilme.codloc=i;
			escreverLocFilme.flag=flag;
			gotoxy(10,4+j*2);
			printf("Insira o codigo do filme [%d]:", j);
			gotoxy(10,5+j*2);
			scanf("%d", &escreverLocFilme.codfilme);
			valorTotal+=buscaValor(escreverLocFilme.codfilme);
			fwrite(&escreverLocFilme, sizeof(locfilme), 1, regLocFilme);
		}
		fclose(regLocFilme);
	}
	return valorTotal;
}
float buscaValor(int cod)
{
	float valor;
	FILE *listFilme=fopen("arquivoFilme.dat","rb");
	filme lerFilme;
	if(listFilme==NULL)
	{
		erro(3);
	}
	else
	{
		while(!feof(listFilme))
		{
			if(fread(&lerFilme, sizeof(filme), 1, listFilme)!=0)
			{
				if(lerFilme.codfilme==cod)
				{
					valor=lerFilme.valor;
				}
			}
		}
	}
	fclose(listFilme);	
	return valor;
}
int codLoc()
{
	FILE *codLocacao=fopen("arquivoCadastroLocacao.dat","rb");
	locacao cdg;
	int cont=0;
	while(!feof(codLocacao))
	{
		if(fread(&cdg, sizeof(locacao), 1, codLocacao)!=0)
		{
			cont++;
		}
	}
	fclose(codLocacao);
	return cont;
}
int contLoc()
{
	FILE *codLocacao=fopen("arquivoCadastroLocacao.dat","rb");
	locacao cdg;
	int cont=0;
	while(!feof(codLocacao))
	{
		if(fread(&cdg, sizeof(locacao), 1, codLocacao)!=0)
		{
			if(cdg.flag==2)
			{
				cont++;
			}
		}
	}
	fclose(codLocacao);
	return cont;
}
void registrarDevolucao()
{
	FILE *regDevolucao=fopen("arquivoDevolucao.dat","ab");
	devolucao escreverDevolucao;
	if(regDevolucao==NULL)
	{
		erro(1);
	}
	else
	{
		system("cls");
		system("COLOR F0");
		listarLocacao(0);
		fflush(stdin);
		gotoxy(10,6);
		printf("Insira a data da devolucao:");
		gotoxy(10,7);
		printf("dia:");
		scanf("%d", &escreverDevolucao.datadevo.dia);
		gotoxy(10,8);
		printf("mes:");
		scanf("%d", &escreverDevolucao.datadevo.mes);
		gotoxy(10,9);
		printf("ano:");
		scanf("%d", &escreverDevolucao.datadevo.ano);
		gotoxy(10,10);
		printf("Digite o código de locacao");
		gotoxy(10,11);
		scanf("%d", &escreverDevolucao.codloc);
		escreverDevolucao.dataLoc=buscaData(escreverDevolucao.codloc);
		escreverDevolucao.diasatraso=calculaAtraso(escreverDevolucao.dataLoc, escreverDevolucao.datadevo);
		if(escreverDevolucao.diasatraso<=0)
		{
			gotoxy(10,12);
			printf("Sem atrasos");
		}
		else
		{
			gotoxy(10,12);
			textbackground(12);
			escreverDevolucao.valororiginal=buscaValorB(escreverDevolucao.codloc);
			escreverDevolucao.valorpago=escreverDevolucao.valororiginal*escreverDevolucao.diasatraso;
			printf("Multa de atraso: %.2f", escreverDevolucao.valorpago);
			textbackground(15);
		}
		excluirLocacao(escreverDevolucao.codloc);
		fwrite(&escreverDevolucao, sizeof(devolucao), 1, regDevolucao);	
		fclose(regDevolucao);
	}	
}
data buscaData(int cod)
{
	FILE *f=fopen("arquivoCadastroLocacao.dat","rb");
	locacao dado;
	data dataR;	
	if(f==NULL)   
	{
		erro(1);   
	}
	else    
	{
		while(!feof(f))  
		{
			if ((fread(&dado,sizeof(locacao),1,f))!=0)
			{
				if (dado.codcliente==cod)
			    { 
			    	dataR=dado.datadevol;
				}
			}
		} 
		fclose(f);
		return dataR; 		                 
	} 
}
float buscaValorB(int cod)
{
	FILE *f=fopen("arquivoCadastroLocacao.dat","rb");
	locacao dado;
	float valor;	
	if(f==NULL)   
	{
		erro(4);   
	}
	else    
	{
		while(!feof(f))
		{
			if((fread(&dado, sizeof(locacao), 1, f))!=0)
			{
				if (dado.codcliente==cod)
			    { 
			    	valor=dado.valortotal;
				}
			}
		} 
		fclose(f);
		return valor; 		                 
	} 
}
void listarDevolucao(int i)
{
	FILE *listDevolucao=fopen("arquivoDevolucao.dat","rb");
	devolucao lerDevolucao;
	if(listDevolucao==NULL)
	{
		erro(7);
	}
	else
	{
		system("cls");
		system("COLOR F0");
		int l=0;
		gotoxy(50,6);
		textbackground(13);
		printf("Devolucoes:                           ");
		while(!feof(listDevolucao))
		{
			if(fread(&lerDevolucao,sizeof(devolucao), 1, listDevolucao)!=0)
			{
				++l;
				((l)%2==0)? textbackground(13) : textbackground(15);
				gotoxy(50,6+l);
				printf("                                      ");
				gotoxy(50,6+l);
				printf("%d-",lerDevolucao.dataLoc);
				imprimeCliente(lerDevolucao.codloc);
				printf("   %d/%d/%d",lerDevolucao.datadevo.dia,lerDevolucao.datadevo.mes,lerDevolucao.datadevo.ano);				
			}
		}	
    }
	fclose(listDevolucao);		
}
void excluirLocacao(int cod)
{
	FILE *f=fopen("arquivoCadastroLocacao.dat","rb+");
    locacao reg; 
	locacao dado;
	locacao excluido; 	
	if(f==NULL)
	{
		erro(6);   
	}
	else
	{
		while(!feof(f))
		{		
			if(fread(&dado,sizeof(locacao),1,f)!=0)
			{		
				if(dado.codcliente==cod)
			    {    
				    excluido.codloc=dado.codloc;
					excluido.flag=0;  
				}
			}
		}  
		fseek(f, cod*sizeof(locacao),SEEK_SET); 	                  
		fwrite(&excluido, sizeof(locacao),1,f);      		                 
		fclose(f);
	} 
}
