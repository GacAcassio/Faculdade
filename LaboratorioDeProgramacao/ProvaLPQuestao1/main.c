//feito em linux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define o limite de carcteres por linha como 168(o mesmo do meu bloco de notas)
#define limCharL 161
#define limLinha 1000
#define clscr printf("\e[1;1H\e[2J")

void Listar(char list[][limCharL], int linI, int linF) {
  clscr;
  for (linI--; linI < linF; linI++) {
    printf("%d\t\t%s\n", linI+1, list[linI]);
  }
  printf("\n\n");
}

void Editar(char edit[][limCharL], int linE) {
  clscr;
  char str[limCharL];
  printf("%d\t%s", linE, edit[linE - 1]);
  printf("\n");
  printf("\nDigite o novo texto da linha: \n");
  getchar();
  scanf("%[^\n]s", str);
  strcpy(edit[linE - 1], str);
  printf("\n");
}

void Inserir(char insert[][limCharL], int linI, int tam) {
  clscr;
  char strI[limCharL];
  for (int j = tam; j > linI; j--) {
    strcpy(insert[j], insert[j - 1]);
  }
  printf("\nDigite o texto da nova linha: \n");
  getchar();
  scanf("%[^\n]s", strI);
  strcpy(insert[linI], strI);
  printf("\n");
}

void Apagar(char delet[][limCharL], int linD, int tam) {
  clscr;
  for (int j = linD - 1; j < tam; j++) {
    strcpy(delet[j], delet[j + 1]);
  }
}
int main(void) {

  char nomeArquivo[101], cc[limCharL], pag[limLinha][limCharL];
  int opcao, quantLinhas, j, continua;
  // recebe o arquivo e verifica se ele tem conteúdo
  // apenas arquivos com conteúdo são aceitos
  do {
    continua = 1;
    printf("Insira o nome do arquivo:\n");
    fflush(stdin);
    scanf("%[^\n]s", nomeArquivo);
    FILE *f = fopen(nomeArquivo, "a+");
    int i = 0;
    if (f == NULL) {
      printf("O documento não exite");
    } else {
      while (!feof(f)) {
        continua = 0;
        fgets(cc, 168, f);
        strcpy(pag[i], cc);
        pag[i][strlen(cc) - 1] = '\0';
        i++;
      }
      strcpy(pag[i - 1], cc);
      if (strlen(cc) == 0 && i == 1)
        continua = 1;
    }
    fclose(f);
    if (continua) {
      clscr;
      printf("\nArquivo invalido\n");
      remove(nomeArquivo);
      getchar();
    }
    quantLinhas = i;
  } while (continua);

  clscr;
  do {
    do {
      printf("1\tLISTAR\n");
      printf("2\tEDITAR\n");
      printf("3\tINSERIR\n");
      printf("4\tAPAGAR\n");
      printf("5\tABANDONAR\n");
      printf("6\tSALVAR E SAIR\n");
      printf("_________________\n");
      printf("Digite a opcao: ");
      fflush(stdin);
      scanf("%d", &opcao);
      clscr;
    } while (opcao > 6 || opcao < 1);
    int x, y;
    switch (opcao) {
    case 1:
      clscr;
      do {
        printf("\n1\tLISTAR TUDO\n");
        printf("2\tLISTAR DA LINHA X ATÉ O FIM\n");
        printf("3\tLISTAR DA LINHA X A LINHA Y\n");
        printf("4\tLISTAR DA APENAS A LINHA X\n");
        printf("____________________________________\n");
        printf("Digite a opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        clscr;
      } while (opcao > 4 || opcao < 1);
      if (opcao == 1)
        Listar(pag, 1, quantLinhas);
      if (opcao == 2) {
        do {
          clscr;
          printf("As linhas variam entre 1 e %d\n", quantLinhas);
          printf("Digite a linha inicial: ");
          scanf("%d", &x);
        } while (x < 1 || x > quantLinhas);
        Listar(pag, x, quantLinhas);
      }
      if (opcao == 3) {
        do {
          clscr;
          printf("As linhas variam entre 1 e %d\n", quantLinhas);
          printf("Digite a linha inicial: ");
          scanf("%d", &x);
          printf("Digite a linha final: ");
          scanf("%d", &y);
        } while (x < 1 || x > y || y > quantLinhas);
        Listar(pag, x, y);
      }
      if (opcao == 4) {
        do {
          clscr;
          printf("As linhas variam entre 1 e %d\n", quantLinhas);
          printf("Digite a linha: ");
          scanf("%d", &x);
        } while (x < 1 || x > quantLinhas);
        Listar(pag, x, x);
      }
      break;
    case 2:
      do {
        clscr;
        Listar(pag, 1, quantLinhas);
        printf("As linhas variam entre 1 e %d\n", quantLinhas);
        printf("Digite a linha a ser editada: ");
        fflush(stdin);
        scanf("%d", &x);
      } while (x < 1 || x > quantLinhas);
      Editar(pag, x);
      break;
    case 3:
      do {
        clscr;
        Listar(pag, 1, quantLinhas);
        printf("As linhas variam entre 1 e %d\n", quantLinhas);
        printf("Digite onde inserir a linha: ");
        fflush(stdin);
        scanf("%d", &x);
      } while (x < 1 || x > quantLinhas);
      Inserir(pag, x, quantLinhas);
      quantLinhas++;
      break;
    case 4:
      do {
        clscr;
        Listar(pag, 1, quantLinhas);
        printf("As linhas variam entre 1 e %d\n", quantLinhas);
        printf("Digite a linha a ser apagada: ");
        fflush(stdin);
        scanf("%d", &x);
      } while (x < 1 || x > quantLinhas);
      do {
        clscr;
        Listar(pag, x, x);
        printf("Deseja realmente apagar essa linha?\n1\tsim\n2\tnao\nOpcao:  ");
        scanf("%d", &opcao);
      } while (opcao < 1 || opcao > 2);
      if (opcao == 1) {
        Apagar(pag, x, quantLinhas);
        quantLinhas--;
      }
      clscr;
      break;
    case 5:
      do {
        clscr;
        printf("Deseja realmente abandonar?\n1\tsim\n2\tnao\nOpcao:  ");
        scanf("%d", &opcao);
      } while (opcao < 1 || opcao > 2);
      clscr;
      if (opcao == 1)
        return 0;
      break;
    case 6:
      do {
        clscr;
        printf("Deseja realmente salvar?\n1\tsim\n2\tnao\nOpcao:  ");
        scanf("%d", &opcao);
      } while (opcao < 1 || opcao > 2);
      if (opcao == 1)
        opcao =6;
      clscr;
      break;
    }
  } while (opcao != 6);
  FILE *f1 = fopen(nomeArquivo, "w");
  for (int j = 0; j < quantLinhas; j++) {
    if (j == quantLinhas - 1)
      fprintf(f1, "%s", pag[j]);
    else
      fprintf(f1, "%s\n", pag[j]);
  }
  fclose(f1);
  return 0;
}
