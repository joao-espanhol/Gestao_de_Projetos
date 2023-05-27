#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu_inicial();
void menu_01();
void menu_02();
void menu_03();
void menu_04();

void main() {

    setlocale(LC_ALL, "Portuguese");

    int codigo;
    codigo = menu_inicial();

    switch(codigo){
        case 1:
            menu_01();
            break;
        case 2:
             menu_02();
             break;
        case 3:
            menu_03();
            break;
        case 4:
            menu_04();
            break;
        default:
            printf("Escreva uma op��o v�lida");
    }

    return;
}

int menu_inicial(){
    int codigo;
    printf ("Bem-vindo(a)! Escolha uma das op��es abaixo para prosseguir:\n");
    printf ("1 - Lan�ar gastos\n");
    printf ("2 - Lan�ar Verba Recebida\n");
    printf ("3 - Consulta de Gastos Mensais\n");
    printf ("4 � Exportar Relat�rio de Presta��o de Contas\n");
    printf("Codigo: ");
    scanf ("%i", &codigo);

    system("cls");

    return (codigo);
}

void menu_01(){
    //Funcao para lancar gastos no BD

    int categoria, documento, valor;
    char data[10], descricao[100], favorecido[50];

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
    scanf("%i", &categoria);
    system("cls");
    //Funcao de escrever no BD aqui

    printf ("Data do Documento (DD/MM/AAAA)\n");
    scanf("%s", data);
    system("cls");
    //Funcao de escrever no BD aqui
    printf ("N�mero do Documento \n ");
    scanf("%i", &documento);
    system("cls");
    //Funcao de escrever no BD aqui
    printf ("Descri��o \n ");
    scanf("%s", descricao);
    system("cls");
    //Funcao de escrever no BD aqui
    printf ("Nome do Favorecido \n");
    scanf("%s", favorecido);
    system("cls");
    //Funcao de escrever no BD aqui
    printf ("Valor\nR$");
    scanf("%i", &valor);
    system("cls");
    //Funcao de escrever no BD aqui

    return;
}

void menu_02(){
    // Funcao para lancar verbas recebidas ou consultar verbas
    int opcao2, valor2, verba, verba_gasta, proxima_verba;
    char data2[15], descricao2[100];

    printf("Escolha uma das opcoes: \n");
    printf("1 - Lan�ar Verba Recebida\n");
    printf("2 � Consultar Limite de Verba\n");
    scanf("%i", &opcao2);
    system("cls");

    switch(opcao2){
        case 1:
            //Lanca a verba no BD
            printf("Data do Recebimento (DD/MM/AAAA)\n");
            scanf("%s", data2);
            system("cls");
            //Funcao de escrever no BD aqui
            printf("Descri��o\n");
            scanf("%s", descricao2);
            system("cls");
            //Funcao de escrever no BD aqui
            printf("Valor\nR$");
            scanf("%i", &valor2);
            system("cls");
            //Funcao de escrever no BD aqui
            break;
        case 2:
            //Funcao para verificar o saldo disponivel
            printf("Verba Dispon�vel %i \n", verba);
            printf("Porcentagem de Verba Gasta %i \n", verba_gasta);
            printf("Tempo at� a pr�xima verba %i \n", proxima_verba);
            break;
        default:
            printf("Digite um codigo valido");
    }
return;
}

void menu_03(){
    // Verifica a verba disponivel por categoria
    int gasto_rh, disponivel_rh, gasto_esociais, disponivel_esociais, gasto_fundo, disponivel_fundo,
    gasto_alimentacao, disponivel_alimentacao, gasto_pedagogico, disponivel_pedagogico, gasto_concessionaria,
    disponivel_concessionaria, gasto_oficineiro, disponivel_oficineiro, gasto_outros, disponivel_outros;

    printf("Gastos Mensais por Categoria:") ;
    printf("\n1 � RH ------------------------------------------ Valor Gasto:", gasto_rh,
           "Valor Dispon�vel: \n",disponivel_rh);
    printf("\n2 � Encargos Sociais ------------------------ Valor Gasto:", gasto_esociais,
           "Valor Dispon�vel: \n", disponivel_esociais);
    printf("\n3 � Fundo Reserva -------------------------- Valor Gasto:", gasto_fundo,
           "Valor Dispon�vel:\n", disponivel_fundo);
    printf("\n4 - Alimenta��o ----------------------------- Valor Gasto:", gasto_alimentacao,
           "Valor Dispon�vel:\n", disponivel_alimentacao);
    printf("\n5 � Material Pedag�gico ------------------ Valor Gasto:", gasto_pedagogico,
           "Valor Dispon�vel:\n", disponivel_pedagogico);
    printf("\n6 � Concession�ria ------------------------- Valor Gasto:",gasto_concessionaria,
           "Valor Dispon�vel:\n", disponivel_concessionaria);
    printf("\n7 � Oficineiro -------------------------------- Valor Gasto:", gasto_oficineiro,
           "Valor Dispon�vel:\n", disponivel_oficineiro);
    printf("\n8 � Outras Despesas ----------------------- Valor Gasto:", gasto_outros,
           "Valor Dispon�vel:\n", disponivel_outros);

return;
}

void menu_04(){
    //Exporta relatorio do periodo
    char data_de, data_ate;

    printf("Exportar relat�rio para presta��o de contas, selecione o per�odo de tempo que deseja consultar:\n");

    printf("De: DD/MM/AAAA\n");
    scanf("%s", &data_de);
    printf("At�: DD/MM/AAAA\n");
    scanf("%s", &data_ate);

return;
}
