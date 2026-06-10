#include <stdio.h>
#include <string.h>


#define MAX 10

struct Produto{

int estoque;
char produto[50];
float preço;


};

// ==========================
// FUNÇÃO PARA VALIDAR PREÇO
// ==========================
float lerPreco()
{

struct Produto pr1[MAX];

    do
    {
        printf("Digite o preco do produto: R$ ");
        scanf("%f", &pr1->preço);


        if (pr1->preço < 0)
        {
            printf("Preco invalido!\n");
        }


    } while (pr1->preço < 0);


    return pr1->preço;
}


// =============================
// FUNÇÃO PARA VALIDAR ESTOQUE
// =============================
int lerEstoque()
{
struct Produto pr1[MAX];


    do
    {
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &pr1->estoque);


        if (pr1->estoque < 0)
        {
            printf("Quantidade invalida!\n");
        }


    } while (pr1->estoque < 0);


    return pr1->estoque;
}


// ==========================
// FUNÇÃO PARA CADASTRAR
// ==========================
int cadastrarProduto(struct Produto pr1[MAX],
                     int total)
{
    int i = total;


    // Verifica limite máximo
    if (total >= MAX)
    {
        printf("\nLimite maximo de produtos atingido!\n");
        return total;
    }


    getchar();


    printf("\n===== CADASTRO DE PRODUTO =====\n");


    // Cadastro do nome
    do
    {
        printf("Nome do produto: ");
        fgets(pr1[i].produto, 50, stdin);


        pr1[i].produto[strcspn(pr1[i].produto, "\n")] = '\0';


        if (strlen(pr1[i].produto) == 0)
        {
            printf("Nome nao pode ser vazio!\n");
        }


    } while (strlen(pr1[i].produto) == 0);


    // Cadastro do preço
    pr1[i].preço = lerPreco();


    // Cadastro do estoque
    pr1[i].estoque = lerEstoque();


    // Incrementa quantidade de produtos
    total++;


    printf("\nProduto cadastrado com sucesso!\n");


    return total;
}


// ==========================
// MENU
// ==========================
void menu()
{
    printf("\n=============================\n");
    printf(" SISTEMA DE PRODUTOS\n");
    printf("=============================\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Produto mais caro\n");
    printf("5 - Valor total em estoque\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}


void listarproduto(struct Produto pr1[MAX],int total){




if(total==0){


printf("Nenhum produto foi cadastrado ainda!!");


}
int i;
for(i=0;i<total;i++){


printf("\nProduto %d:",i+1);
printf("\nNomes: %s",pr1[i].produto);
printf("\nEstoques: %d",pr1[i].estoque);
printf("\nPrecos: %.2f",pr1[i].preço);
printf("\n======================\n");


}
}
int BuscarProduto(struct Produto pr1[MAX],int total){
 
if(total==0){


printf("\nNenhum produto foi cadastrado!");


}


char BuscarNome[50];
int i;


getchar();
printf("Digite o nome do produto:");
fgets(BuscarNome, 50, stdin);


BuscarNome[strcspn(BuscarNome, "\n")] = '\0';


for(i=0; i<total; i++){


if(strcmp(BuscarNome, pr1[i].produto) == 0){


printf("\nNome encontrado: %s",pr1[i].produto);
printf("\nPreco encontrado: %.2f",pr1[i].preço);
printf("\nEstoque do produto encontrado: %d",pr1[i].estoque);


}
}
return 0;
}
void ProdutoMaisCaro(struct Produto pr1[MAX],int total){


int i,indiceMaisCaro = 0;


for(i=0; i<total; i++){


if(pr1[i].preço>pr1[indiceMaisCaro].preço){


indiceMaisCaro = i;


    }


}


printf("\n ====== PRODUTO MAIS CARO======");
printf("\n Nome: %s",pr1[indiceMaisCaro].produto);
printf("\n Preço: R$%f",pr1[indiceMaisCaro].preço);
printf("\n estoque: %d",pr1 [indiceMaisCaro].estoque);


}


void ValorTotalEstoque(struct Produto pr1[MAX], int total) {
    if (total == 0) {
    printf("\nNenhum produto cadastrado para calcular o total!\n");
    return;
    }


    float valorTotalAcumulado = 0;
    int i;


    for (i = 0; i < total; i++) {


    valorTotalAcumulado += (pr1[i].preço * pr1[i].estoque);
    }


    printf("\n====== VALOR TOTAL EM ESTOQUE ======");
    printf("\nO valor total de todos os produtos no estoque é: R$ %.2f\n", valorTotalAcumulado);
}
// ==========================
// FUNÇÃO PRINCIPAL
// ==========================
int main()
{
    struct Produto pr1[MAX];

    int total = 0;
    int opcao;


    do
    {
        menu();


        scanf("%d", &opcao);


        switch (opcao)
        {
        case 1:
            total = cadastrarProduto(pr1,total);
            break;


        case 2:
            listarproduto(pr1,total);
            break;


        case 3:
            BuscarProduto(pr1,total);
            break;


        case 4:
            ProdutoMaisCaro(pr1,total);
            break;


        case 5:
        ValorTotalEstoque(pr1,total);
        break;


        case 0:
            printf("\nPrograma encerrado.\n");
            break;


        default:
            printf("\nOpcao invalida!\n");
        }


    } while (opcao != 0);


    return 0;
}



//O Github é muito daora! Obrigado Professor Guilherme por essa aula!!

//nota 8/10 muito bem feito porem falata adicionar algumas coisas 