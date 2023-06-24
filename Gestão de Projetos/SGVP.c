#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

/*****************************EFECTS***************************************/
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
#define HALFBRIGHT  "\033[2m"
#define UNDERSCORE  "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m" //TITULOS

/*****************************COLORS***************************************/
#define C_BLACK     "\033[30m"
#define C_RED       "\033[31m" //ULTRAPASSOU
#define C_GREEN     "\033[32m"
#define C_YELLOW    "\033[33m" //QUASE ULTRAPASSANDO
#define C_BLUE      "\033[34m"
#define C_MAGENTA   "\033[35m" //VALIDACAO NAO PASSOU
#define C_CYAN      "\033[36m"
#define C_GRAY      "\033[37m"

/***************************BACKGROUNDS************************************/
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"//VALIDACAO NAO PASSOU
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_GRAY     "\033[47m"

int login();
int menu_perfil_1();
int menu_perfil_2();
void menu_01(nome_pasta);
void menu_02(nome_pasta);
void menu_03(nome_pasta);
void menu_04(nome_pasta);
void menu_05(nome_pasta);
void tutorial();
void cabecalho();
void escreve_BD(info, nome_arq);
void fim_lancamento(nome_arq);

int valida_inteiros();
float valida_reais();


void main() {

    setlocale(LC_ALL, "Portuguese");
    system("color 00");

    //TELA CHEIA
    keybd_event ( VK_MENU, 0x36, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );

    int codigo = 1;
    int permissao;
    int opcao_tutorial;
    char nome_pasta[30];
    int mes, ano;
    char teste;
    char nome_arq[30], cria_pasta[30];

    permissao = login();

    switch(permissao){
        case 1:
            cabecalho();

            printf("\nDeseja ver o tutorial?");
            printf("\n1 - Sim");
            printf("\n2 - N�o\n");
            opcao_tutorial = valida_inteiros();

            switch(opcao_tutorial){
                case 1:
                    system("cls");
                    tutorial();
                    system("cls");
                    break;
                case 2:
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("Op��o Invalida");
                    system("pause");
                    system("cls");
            }

            cabecalho();
            printf("Digite o m�s que deseja trabalhar: \n");
            do{
                mes = valida_inteiros();
                if(mes <1 || mes >12){
                    printf(BG_RED"Digite um valor valido!\n"NONE);
                }
            }while(mes <1 || mes >12);

            printf("Digite o ano que deseja trabalhar: \n");
            do{
                ano = valida_inteiros();
                if(ano <1900 || ano >2023){
                    printf(BG_RED"Digite um valor valido!\n"NONE);
                }
            }while(ano <1900 || ano >2023);

            sprintf(nome_pasta, "%d-%d", ano, mes);
            sprintf(cria_pasta, "mkdir %s", nome_pasta);
            system(cria_pasta);
            system("cls");
        while(codigo != 0){
            codigo = menu_perfil_1();
            switch(codigo){
                case 1:
                    menu_01(nome_pasta);
                    system("cls");
                    break;
                case 2:
                     menu_02(nome_pasta);
                     system("cls");
                     break;
                case 3:
                    menu_03(nome_pasta);
                    system("cls");
                    break;
                case 4:
                    menu_04(nome_pasta);
                    system("cls");
                    break;
                case 5:
                    menu_05(nome_pasta);
                    system("cls");
                    break;
                case 6:
                    tutorial();
                    system("cls");
                case 0:
                    break;
                default:
                    printf(BG_RED"Escreva uma op��o v�lida\n"NONE);
                    system("pause");
                    system("cls");
            }
        }
        break;
        case 2:
            cabecalho();
            printf("Digite o m�s que deseja trabalhar: \n");
            do{
                mes = valida_inteiros();
                if(mes <1 || mes >12){
                    printf(BG_RED"Digite um valor valido!\n"NONE);
                }
            }while(mes <1 || mes >12);

            printf("Digite o ano que deseja trabalhar: \n");
            do{
                ano = valida_inteiros();
                if(ano <1900 || ano >2023){
                    printf(BG_RED"Digite um valor valido!\n"NONE);
                }
            }while(ano <1900 || ano >2023);

            sprintf(nome_pasta, "%d-%d", ano, mes);
            sprintf(cria_pasta, "mkdir %s", nome_pasta);
            system(cria_pasta);
            system("cls");
        while(codigo != 0){

            codigo = menu_perfil_2();

            switch(codigo){
                case 1:
                    menu_03(nome_pasta);
                    system("cls");
                    break;
                case 0:
                    break;
                default:
                    printf(BG_RED"Escreva uma op��o v�lida\n"NONE);
                    system("pause");
                    system("cls");
            }
        }
        break;
    }
return;
}


int login(){

    int login;
    int senha;
    int i = 1;
    int permissao;

    cabecalho ();
    printf ("Seja bem-vindo (a)!\n");
    do{
    printf ("Login (APENAS NUMEROS): ");
    login = valida_inteiros();

    printf ("Senha (APENAS NUMEROS): ");
    senha = valida_inteiros();

        if (login == 123 && senha == 123){
            printf (C_GREEN"Login feito com sucesso!\n"NONE);
            system("pause");
            system("cls");
            permissao = 1;
            i = 0;
        }
        else if(login == 456 && senha == 456){
            printf (C_GREEN"Login feito com sucesso!\n"NONE);
            system("pause");
            system("cls");
            permissao = 2;
            i = 0;
        }
        else{
            system("cls");
            cabecalho();
            printf (BG_RED"Usu�rio nao cadastrado! Tente novamente\n"NONE);
        }
    }while(i!=0);
return(permissao);
}

int menu_perfil_1(){
    int codigo;
    cabecalho();
    printf (REVERSE"Bem-vindo(a)! Escolha uma das op��es abaixo para prosseguir:\n"NONE);
    printf ("1 - Lan�ar Gastos\n");
    printf ("2 - Lan�ar Verbas Recebidas\n");
    printf ("3 - Consultar Limite Disponivel\n");
    printf ("4 - Consultar Lan�amentos\n");
    printf ("5 - Alterar Lan�amentos\n");
    printf ("6 - Tutorial\n");
    printf ("0 - Sair\n");
    printf("Codigo: ");

    codigo = valida_inteiros();

    system("cls");
    cabecalho();

return (codigo);
}

int menu_perfil_2(){
    int codigo;
    cabecalho();
    printf (REVERSE"Bem-vindo(a)! Escolha uma das op��es abaixo para prosseguir:\n"NONE);
    printf ("1 - Consulta de Limite Disponivel\n");
    printf ("0 - Sair\n");
    printf("Codigo: ");

    codigo = valida_inteiros();

    system("cls");

return (codigo);
}

void menu_01(nome_pasta){
    //Funcao para lancar gastos no BD

    char nome_arq[30];
    int categoria, documento, dia;
    float valor;
    char descricao[100], favorecido[50], info[100] = "", data[11];

    cabecalho();

    //CATEGORIA
    do{
        printf ("Insira as informacoes solicitadas abaixo: \n");
        printf ("Categoria:\n");
        printf ("1 � RH\n");
        printf ("2 � Encargos Sociais\n");
        printf ("3 � Fundo Reserva\n");
        printf ("4 - Alimenta��o\n");
        printf ("5 � Material Pedag�gico\n");
        printf ("6 � Concession�ria\n");
        printf ("7 � Oficineiro\n");
        printf ("8 � Outras Despesas\n");

        categoria = valida_inteiros();
        if(categoria <1 || categoria >8){
            printf(BG_RED"Digite um valor valido!\n"NONE);
            system("pause");
            system("cls");
            cabecalho();
        }
    }while(categoria <1 || categoria >8);

    sprintf(nome_arq, "%s\\%i.txt", nome_pasta,categoria);

    escreve_BD(info, nome_arq);

    sprintf(info, "%i", categoria);
    escreve_BD(info, nome_arq);
    system("cls");
    cabecalho();

    //DATA
    printf ("Dia do Documento\n");

    do{
        dia = valida_inteiros();
        if(dia <1 || dia >31){
            printf(BG_RED"Digite um valor valido!\n"NONE);
            printf("Valor: ");
        }
    }while(dia <1 || dia >31);

    sprintf(info, "%d", dia);
    escreve_BD(info, nome_arq);
    system("cls");
    cabecalho();

    //NUMERO DO DOCUMENTO
    printf ("N�mero do Documento \n ");
    documento = valida_inteiros();
    sprintf(info, "%i", documento);
    escreve_BD(info, nome_arq);
    system("cls");
    cabecalho();

    //DESCRICAO
    printf ("Descri��o \n ");
    setbuf(stdin, NULL);
    scanf(" %100[^\n]", descricao);
    strcpy(info, descricao);
    escreve_BD(info, nome_arq);
    system("cls");
    cabecalho();

    //FAVORECIDO
    printf ("Nome do Favorecido \n");
    setbuf(stdin, NULL);
    scanf(" %100[^\n]", favorecido);
    strcpy(info, favorecido);
    escreve_BD(info, nome_arq);
    system("cls");
    cabecalho();

    //VALOR
    printf ("Valor\nR$");

    valor = valida_reais();
    sprintf(info, "%.2f", valor);
    escreve_BD(info, nome_arq);
    system("cls");
    fim_lancamento(nome_arq);

    return;
}

void menu_02(nome_pasta){
    // Funcao para lancar verbas recebidas
    char nome_arq[30];
    int opcao2, dia1, mes1, ano1, categoria;
    float valor2;
    char info[100];

    sprintf(nome_arq, "%s\\verbas.txt", nome_pasta);
    //Apaga o conteudo da pasta
    FILE* fp;
    fp = fopen(nome_arq, "w");

    char descr_categorias[8][30] = {"1 � RH\n", "2 - Encargos Sociais\n", "3 � Fundo Reserva\n", "4 - Alimenta��o\n",
    "5 � Material Pedag�gico\n", "6 � Concession�ria\n", "7 � Oficineiro\n", "8 � Outras Despesas\n"};

    //Lanca as verbas no BD
    for(int i = 0; i<8; i++){

        cabecalho();

        printf("%s", descr_categorias[i]);
        printf("Valor\nR$");
        valor2 = valida_reais();
        sprintf(info, "%.2f", valor2);
        escreve_BD(info, nome_arq);
        system("cls");

        fim_lancamento(nome_arq);
    }
return;
}

void menu_03(nome_pasta){
    // Verifica a verba disponivel por categoria
    float valor_gasto, valor_disponivel, valor, percentual;

    char descr_categorias[8][40] = {REVERSE"1 � RH\n"NONE, REVERSE"2 - Encargos Sociais\n"NONE,
    REVERSE"3 � Fundo Reserva\n"NONE, REVERSE"4 - Alimenta��o\n"NONE, REVERSE"5 � Material Pedag�gico\n"NONE,
    REVERSE"6 � Concession�ria\n"NONE, REVERSE"7 � Oficineiro\n"NONE, REVERSE"8 � Outras Despesas\n"NONE};

    char linha[200];
    char *resultado;
    char *resultado2;
    char *pch;
    int categoria;
    int l = 0;

    char nome_arq[50], nome_arq2[50];

    sprintf(nome_arq2, "%s\\verbas.txt", nome_pasta);
    FILE* fp2;
    fp2 = fopen(nome_arq2, "r");


    if(fp2 == NULL){
        printf(BG_RED"\nLance primeiro os Limites de Verba\n"NONE);
        system("pause");
        return;
    }
    printf("Gastos Mensais por Categoria:\n\n");

    for(int j = 0; j <=7; j++){
        sprintf(nome_arq, "%s\\%i.txt", nome_pasta,j+1);
        FILE* fp;
        fp = fopen(nome_arq, "r");

        if(fp == NULL){
            printf(BG_RED"\nLance primeiro os Gastos da Categoria %s\n"NONE, descr_categorias[j]);
            system("pause");
            return;
        }

        while (!feof(fp)){
            resultado = fgets(linha, 100, fp);
            if (resultado){
                pch = strtok (linha,"|");
                int i = 0;
                while (pch != NULL){
                    if(i%5 == 0 && i!= 0){
                        valor = atof(pch);
                        valor_gasto = valor_gasto+valor;
                    }
                    i++;
                    pch = strtok (NULL, "|");
                }
            }
        }

         while (!feof(fp2)){
            resultado2 = fgets(linha, 100, fp2);
            if(resultado2){
                pch = strtok(linha, "|");
                valor = atof(pch);
                valor_disponivel = valor;
            }
            break;
        }

        percentual = (valor_gasto/valor_disponivel)*100;

        printf("\n%s--------------------------Valor Recebido: R$%.2f\n",
            descr_categorias[j],valor_disponivel);
        printf("--------------------------Valor Gasto: R$%.2f\n", valor_gasto);

        if((valor_disponivel - valor_gasto)<0){
            printf("--------------------------Valor Dispon�vel: " C_RED"R$%.2f\n\n"NONE, (valor_disponivel - valor_gasto));
        }else{
            printf("--------------------------Valor Dispon�vel: R$%.2f\n\n", (valor_disponivel - valor_gasto));
        }

        printf("RECEBIDO\t\t\t\t\t\t");
        printf("DISPON�VEL\n");
        printf("%.2f",valor_disponivel);

        for(int i = 0; (i<percentual && i<100); i=i+2){
            printf("*");
        }
        for(int i = 0; i<(100-percentual); i=i+2){
            printf("_");
        }

        if(percentual>100){
            printf(C_RED"%.2f\n"NONE,(valor_disponivel-valor_gasto));
        }else if(percentual>75 && percentual <= 100){
            printf(C_YELLOW"%.2f\n"NONE,(valor_disponivel-valor_gasto));
        }else{
            printf("%.2f\n",(valor_disponivel-valor_gasto));
        }

        if(percentual>100){
            printf(C_RED"\t\t\t\t%.2f%c\n"NONE, percentual, '%');
        }else if(percentual>75 && percentual <= 100){
            printf(C_YELLOW"\t\t\t\t%.2f%c\n"NONE, percentual, '%');
        }else{
            printf("\t\t\t\t%.2f%c\n", percentual, '%');
        }

        valor_gasto = 0.0;
        l++;
        if(l % 3 == 0 && l != 0){
            system("pause");
            system("cls");
            cabecalho();
        }
    }
        system("pause");
        system("cls");
return;
}

void menu_04(nome_pasta){
    //Apresenta os lan�amentos realizados
    char nome_arq[30];
    char titulo[6][25] = {"Categoria: ", "Dia: ", "Numero: ", "Descri��o: ", "Nome do Favorecido: ", "Valor: R$"};
    char categoria[8][25] = {" � RH", " - Encargos Sociais", " � Fundo Reserva", " - Alimenta��o",
    " � Material Pedag�gico", " � Concession�ria", " � Oficineiro", " � Outras Despesas"};
    char info;
    int i, k = 1, l = 0;

    printf("Lan�amentos realizados:\n");

    for(int j = 1; j <=8; j++){
        sprintf(nome_arq, "%s\\%i.txt", nome_pasta,j);
        FILE* fp;
        fp = fopen(nome_arq, "r");

        i = 0;
        while ((info = getc(fp)) != EOF){
            if(info == '|'){
                if(i == 0){
                    if(l % 4 == 0 && l != 0){
                        system("pause");
                        system("cls");
                        cabecalho();
                    }
                    printf(REVERSE"Lan�amento %i"NONE, k);
                    k++;
                }
                printf("\n");
                printf("%s", titulo[i]);
                if(i<=5){
                    i++;
                }else{
                    i = 0;
                    l++;
                }
            }else{
                putchar(info);
                if(i == 1){
                    printf("%s", categoria[j-1]);
                }
            }
        }
        fclose(fp);
    }
    system("pause");


return;
}

void menu_05(nome_pasta){
    //Altera lan�amentos realizados
    int categoria = 0, lancamento;

    char titulo[6][15] = {"Categoria: ", "Dia: ", "Numero: ", "Descri��o: ", "Nome: ", "Valor: R$"};
    char categorias[8][25] = {" � RH", " - Encargos Sociais", " � Fundo Reserva", " - Alimenta��o",
    " � Material Pedag�gico", " � Concession�ria", " � Oficineiro", " � Outras Despesas"};

    char nome_arq[30],nome_arq2[30], cadeia[30], info[200] = "";
    char info2;
    int i=0, k=1, lanc_max = 1, l = 0;

    int documento, dia;
    float valor;
    char descricao[100], favorecido[50], data[11];

    system("cls");
    cabecalho();

    do{
        printf("Selecione a Categoria do Lan�amento que Deseja Alterar:\n");
        printf ("Categoria:\n");
        printf ("1 � RH\n");
        printf ("2 � Encargos Sociais\n");
        printf ("3 � Fundo Reserva\n");
        printf ("4 - Alimenta��o\n");
        printf ("5 � Material Pedag�gico\n");
        printf ("6 � Concession�ria\n");
        printf ("7 � Oficineiro\n");
        printf ("8 � Outras Despesas\n");

        categoria = valida_inteiros();
        if(categoria <1 || categoria >8){
            printf(BG_RED"Digite um valor valido!\n"NONE);
            system("pause");
            system("cls");
            cabecalho();
        }
    }while(categoria <1 || categoria >8);

    system("cls");
    cabecalho();

    sprintf(nome_arq2, "%s\\%i.txt", nome_pasta,categoria);
    FILE* fp;
    fp = fopen(nome_arq2, "r");

    if(fp == NULL){
        printf(BG_RED"\nErro ao alterar lan�amento!\n"NONE);
        system("pause");
        return;
    }

    while ((info2 = getc(fp)) != EOF){
        if(info2 == '|'){
            if(i == 0){
                if(l % 4 == 0 && l != 0){
                    system("pause");
                    system("cls");
                    cabecalho();
                }
                l++;
                printf(REVERSE"Lan�amento %i"NONE, k);
                lanc_max = k;
                k++;
            }
            printf("\n");
            printf("%s", titulo[i]);
            if(i<=5){
                i++;
            }else{
                i = 0;
            }
        }else{
            putchar(info2);
            if(i == 1){
                printf("%s", categorias[categoria-1]);
            }
        }
    }
    system("pause");

    if(fp == NULL){
        printf(BG_RED"\nN�o h� gastos lan�ados nesta categoria\n"NONE);
        system("pause");
        return;
    }
    system("cls");
    cabecalho();

    printf("Para sair, digite 0!\n\n");
    printf("Selecione o lan�amento que deseja alterar: ");

    do{
        lancamento = valida_inteiros();

        if(lancamento == 0){
            printf("\nVoltando para o menu principal!\n\n");
            system("pause");
        return;
        }
        if(lancamento <1 || lancamento > lanc_max){
            printf(BG_RED"Digite um valor valido!\n"NONE);
        }
    }while(lancamento <1 || lancamento > lanc_max);

    sprintf(nome_arq, "%sNOVO.txt", nome_arq2);

    fclose(fp);
    fp = fopen(nome_arq2, "r");

    if(fp == NULL){
        printf(BG_RED"\nErro ao alterar lan�amento!\n"NONE);
        system("pause");
        return;
    }

    FILE *fp2;
    fp2 = fopen(nome_arq, "w");

    if(fp2 == NULL){
        printf(BG_RED"\nErro ao alterar lan�amento!\n"NONE);
        system("pause");
        return;
    }

    i = 0;
    while (fgets(info, 200, fp)!= NULL){
        if(i < lancamento-1){
            fputs(info, fp2);
        }
        else if(i == lancamento-1){
            sprintf(info, "%i", categoria);
            fprintf(fp2, "|%s", info);
            fprintf(fp2, "|");
            system("cls");
            cabecalho();

            //DATA
            printf ("Dia do Documento\n");
            do{
                dia = valida_inteiros();
                if(dia <1 || dia >31){
                    printf(BG_RED"Digite um valor valido!\n"NONE);
                    printf("Valor: ");
                }
            }while(dia <1 || dia >31);

            sprintf(info, "%d", dia);
            fprintf(fp2, "%s", info);
            fprintf(fp2, "|");
            system("cls");
            cabecalho();

            //NUMERO DO DOCUMENTO
            printf ("N�mero do Documento \n ");
            documento = valida_inteiros();
            sprintf(info, "%d", documento);
            fprintf(fp2, "%s", info);
            fprintf(fp2, "|");
            system("cls");
            cabecalho();

            //DESCRICAO
            printf ("Descri��o \n ");
            setbuf(stdin, NULL);
            scanf(" %99[^\n]", descricao);
            strcpy(info, descricao);
            fprintf(fp2, "%s", info);
            fprintf(fp2, "|");
            system("cls");
            cabecalho();

            //FAVORECIDO
            printf ("Nome do Favorecido \n");
            setbuf(stdin, NULL);
            scanf(" %99[^\n]", favorecido);
            strcpy(info, favorecido);
            fprintf(fp2, "%s", info);
            fprintf(fp2, "|");
            system("cls");
            cabecalho();

            //VALOR
            printf ("Valor\nR$");
            valor = valida_reais();
            sprintf(info, "%.2f", valor);
            fprintf(fp2, "%s", info);
            fprintf(fp2, "|\n");
            system("cls");
        }
        else{
            fputs(info, fp2);
        }
        i++;
    }
    fclose(fp);
    fclose(fp2);

    printf("Altera��o realizada com sucesso!\n\n");
    system("pause");

    remove(nome_arq2);
    rename(nome_arq,nome_arq2);

return;
}

void cabecalho(){
    //Cabecalho do Sistema
    desenhar(200, 170);

    gotoxy(1,1);
    printf("**************************************************************************************************\n");
    gotoxy(28,2);
    printf("SISTEMA DE GESTAO DE VERBAS PUBLICAS\n");
    gotoxy(1,3);
    printf("**************************************************************************************************\n");

    return 0;
return;
}

void escreve_BD(info, nome_arq){
    //Escreve as informacoes digitadas no BD
    FILE* fp;
    fp = fopen(nome_arq, "a");
    fprintf(fp, "%s", info);
    fprintf(fp, "|");
    fclose(fp);
return;
}

void fim_lancamento(nome_arq){
    //Termina uma linha de lancamento
    FILE* fp;
    fp = fopen(nome_arq, "a");
    fprintf(fp, "\n");
    fclose(fp);
return;
}
int valida_inteiros(){
    int inteiro;
    int retorno = -1;
    char letra;

    do{
        retorno = scanf("%d", &inteiro);
        if (retorno == 0){
            printf(BG_RED"Digite um valor v�lido!\n"NONE);
            system("pause");
            printf("Valor: ");
        }
        do{
            letra = getchar();
        }while(letra != '\n');
    }while(retorno == 0);

return inteiro;
}

float valida_reais(){
    float real;
    int retorno = -1;
    char letra;

    do{
        retorno = scanf("%f", &real);
        if (retorno == 0){
            printf(BG_RED"Digite um valor v�lido!\n"NONE);
            system("pause");
            printf("Valor: ");
        }else if(real < 0.0){
            printf(BG_RED"Digite um valor v�lido!\n"NONE);
            system("pause");
            printf("Valor: ");
        }
        do{
            letra = getchar();
        }while(letra != '\n');
    }while(retorno == 0 || real < 0.0);

return real;
}

void tutorial(){
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);

    printf("Nosso programa foi desenvolvido para OSCs que buscam \n");
    printf("gerenciar seus recursos governamentais com maior \n");
    printf("eficiencia e clareza. \n\n");


    system("pause");
    system("cls");
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);


    printf("O programa possui 6 menus:\n");
    printf ("1 - Lan�ar Gastos\n");
    printf ("2 - Lan�ar Verbas Recebidas\n");
    printf ("3 - Consultar Limite Disponivel\n");
    printf ("4 - Consultar Lan�amentos\n");
    printf ("5 - Alterar Lan�amentos\n");
    printf ("6 - Tutorial\n\n");

    printf("Vamos olhar mais de perto os men�s e entender melhor o\n");
    printf("que cada um deles faz!\n\n");


    system("pause");
    system("cls");
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);


    printf (REVERSE"\t\tMenu 1 - Lan�ar Gastos!\n\n"NONE);
    printf("Esse menu tem como objetivo armazenar os gastos que a \n");
    printf("OSC realizou no m�s de trabalho.\n\n");

    printf("O programa armazena as informa��es em arquivos de texto,\n");
    printf("por�m, n�o recomendamos a manipula��o destes arquivos, j�\n");
    printf("que isso pode danificar o comportamento do programa e \n");
    printf("acarretar na perda dos dados j� lan�ados.\n\n");

    printf("Sempre o lan�amento deve preencher todos os campos, visando\n");
    printf("a correta armazenagem das informa��es.\n");
    printf("Caso algum campo n�o precise ser preenchido, preencha-o com\n");
    printf("um 0.\n\n");


    system("pause");
    system("cls");
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);


    printf ("\t   "REVERSE"Menu 2 - Lan�ar Verbas Recebidas!\n\n"NONE);

    printf("Esse menu tem como objetivo armazenar as verbas que \n");
    printf("o governo disponibilizou para o m�s em quest�o.\n\n");

    printf("Caso deseje alterar algum valor, apenas acesse o menu \n");
    printf("2 novamente para realizar as altera��es necess�rias!\n");


    system("pause");
    system("cls");
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);


    printf ("\t   "REVERSE"Menu 3 - Consultar Limite Disponivel!\n\n"NONE);

    printf("Este menu serve para consultar o valor recebido e o\n");
    printf("valor gasto no per�odo.\n\n");

    printf("Al�m dessas informa��es, o programa disponibiliza um \n");
    printf("gr�fico com o valor ainda dispon�vel e qu�o perto a OSC\n");
    printf("est� de estourar o valor disponibilizado\n");
    printf("Os valores ficam "C_YELLOW"Amarelos"NONE" quando passam de 75%c do Recebido\n", '%');
    printf("e ficam "C_RED"Vermelhos"NONE" quando ultrapassam o Valor Recebido!");


    printf("\nExemplo de gr�fico: \n\n\n");
    printf("6 - Concession�ria\n--------------------------Valor Recebido: R$10000,00\n"
           "--------------------------Valor Gasto: R$7733,45\n"
           "--------------------------Valor Dispon�vel: "C_YELLOW"R$2266,55"NONE"\n\n\n"
           "RECEBIDO                                                DISPON�VEL\n"
           "10000,00***************************************____________"C_YELLOW"2266,55\n"NONE
           "                                "C_YELLOW"77,33%c\n\n"NONE, '%');


    system("pause");
    system("cls");
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);


    printf ("\t   "REVERSE"Menu 4 - Consultar Lan�amentos!\n\n"NONE);

    printf("Este menu serve para consultar os lan�amentos realizados\n");
    printf("no per�odo em quest�o.\n\n");

    printf("O Menu 4 - Consultar Lan�amentos n�o serve para alterar \n");
    printf("os lan�amentos realizados. Esta funcionalidade est�\n");
    printf("dispon�vel no pr�ximo menu!\n\n");

    printf("Abaixo est� um exemplo de lan�amento realizado: \n\n");
    printf(REVERSE"Lan�amento 22\n"NONE"Categoria: 5 - Material Pedag�gico\n""Dia: 12\n"
           "Numero: 123123123\n""Descri��o: Compra de Cadernos e livros \n"
           "Nome do Favorecido: Papelaria do Joaquim\n""Valor: R$397,32\n\n\n");


    system("pause");
    system("cls");
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);


    printf ("\t   "REVERSE"Menu 5 - Alterar Lan�amentos!\n\n"NONE);

    printf("Este menu serve para alterar os lan�amentos realizados.\n");
    printf("Ao selecionar o Menu 5 - Alterar Lan�amentos, voc� dever�\n");
    printf("selecionar a categoria do lan�amento que deseja alterar.\n\n");

    printf("O programa ir� exibir os lan�amentos da categoria \n");
    printf("selecionada, e voc� dever� lembrar o �ndice do lan�amento \n");
    printf("que deseja alterar.\n\n");

    printf("Caso esque�a o indice do lan�amento durante a sele��o, \n");
    printf("digite 0 para voltar para o menu principal.\n\n");

    printf("Ao final do lan�amento, caso queira verificar se os dados\n");
    printf("est�o corretos, utilize o Menu 4 - Consultar Lan�amentos!\n\n");


    system("pause");
    system("cls");
    cabecalho();
    printf(REVERSE"Bem Vindo (a) ao Sistema de Gest�o de Verbas P�blicas\n\n"NONE);


    printf ("\t\t "REVERSE"Menu 6 - Tutorial\n\n"NONE);

    printf("Caso queira visualizar o tutorial novamente, basta acessar\n");
    printf("o Menu 6 - Tutorial\n\n");

    printf("Se ainda persistir alguma d�vida na utiliza��o do programa, \n");
    printf("basta entrar em contato com a equipe de suporte no e-mail:\n\n");

    printf("\tgestao_verbas_publicas@gmail.com\n\n");


    system("pause");
    system("cls");

return;
}

void desenhar(int largura, int altura) {

    int i, j;

    altura /= 4;
    largura /= 2;

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if (i == altura - 1) {
                printf("#");
            } else if (j == largura - 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

