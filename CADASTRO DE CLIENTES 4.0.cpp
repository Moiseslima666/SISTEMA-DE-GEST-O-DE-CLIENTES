#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_CLIENTES 200


struct Endereco {
    int numero;
    int CEP;
    char logradouro[50];
    char bairro[30];
    char cidade[40];
    char UF[3];
    char pais[20];
};

struct Cliente {
    char nome[50];
    char CPF[15];
    int idade;
    int telefone;
    int idDoCliente;
    char datadenascimento[11]; 
    char email[50];
    char cor[20];
    char sexo[30];
    int id;
    struct Endereco endereco;
};

void escolha(int opcao); 
void desenho();
void cadastro();
void listadeclientes();
void pesquisarclienteid();
void salvarDados();

struct Cliente clientes[MAX_CLIENTES];
int totalclientes = 0;

int menu();

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao;
    do {
        opcao = menu();
        system("cls");
    } while (opcao);
    return 0;
}

int menu() {
    int opcao;
    printf("\n\t\t\t\t-----------------------------------------------------");
    printf("\n\t\t\t\t                  GESTÃO DE CLIENTES                  ");
    printf("\n\t\t\t\t-----------------------------------------------------\n\n\n");
    printf("\n\t\t\t\t- SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES! -\n\n");
    
    printf("\n\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t---    ESCOLHA UMA OPÇÃO    ---");
    printf("\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t 1 - CADASTRAR CLIENTE       ");
    printf("\n\t\t\t\t\t 2 - LISTA DE CLIENTES CADASTRADOS");
    printf("\n\t\t\t\t\t 3 - PESQUISAR CLIENTE POR ID");
	printf("\n\t\t\t\t\t 0 - SAIR                    ");
    printf("\n\t\t\t\t\t-----------------------------");
    printf("\n\t\t\t\t\tESCOLHA A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);
    
    system("cls");
    
    escolha(opcao); 
    
    system("pause");
    
    return opcao;
}

void escolha(int opcao) {
    switch (opcao) {
        case 1:
            printf("========================================================================================================================================================================\n\n");
			printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======= CADASTRO DE CLIENTES =========\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n\n\n");
            printf("========================================================================================================================================================================\n\n");
			cadastro();
            break;
        case 2:
            printf("========================================================================================================================================================================\n\n");
		    printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n");
			printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m==== LISTA DE CLIENTES CADASTRADOS ====\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n\n\n");
			printf("========================================================================================================================================================================\n\n");
			listadeclientes();
            break;
        case 3:
            printf("========================================================================================================================================================================\n\n");
		    printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n");
			printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m==== PESSQUISAR CLIENTE POR ID ====\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n\n\n");
			printf("========================================================================================================================================================================\n\n");
            pesquisarclienteid();
            break;
        
        case 0:
            printf("\033[1;33m========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========\033[0m\n\n\n");
            break;
        default:
            printf("\033[1;31m*** DESCULPE, A OPÇÃO ESCOLHIDA ESTÁ INVÁLIDA!! ***\033[0m\n");
            printf("\033[1;31m*** TENTE NOVAMENTE OUTRA OPÇÃO ***\033[0m\n");
    }
}

void cadastro() {
    if (totalclientes < MAX_CLIENTES) {
        struct Cliente cliente;
        printf("\033[1;36m\t ID DO CLIENTE (NÚMEROS): \033[0m");
        scanf("%d", &cliente.id);
		fflush(stdin);
		
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\tNOME: \033[0m");
        fgets(cliente.nome, sizeof(cliente.nome), stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\tCPF DO CLIENTE: \033[0m");
        fgets(cliente.CPF, sizeof(cliente.CPF), stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\tIDADE: \033[0m");
        scanf("%d", &cliente.idade);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
        
		fflush(stdin);
        printf("\033[1;36m\tDATA DE NASCIMENTO (dd/mm/aaaa): \033[0m");
        scanf("%d", &cliente.datadenascimento);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\tEMAIL: \033[0m");
        fgets(cliente.email, sizeof(cliente.email), stdin);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
        
		fflush(stdin);
        printf("\033[1;36m\tCOR \033[0m");
        scanf("%c", &cliente.cor);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\tSEXO (M/F) \033[0m");
        scanf("%c", &cliente.sexo);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\tNÚMERO TELEFONICO EX:(DDD) 91234-5678 ): \033[0m");
        scanf("%d", &cliente.telefone);
        fflush(stdin);
        
		sleep(4);
		printf("\t\tAguarde...\n\n");
		system("cls");
		
		printf("\n\033[1;33m\t\t\t=====================================================\033[0m\n");
        printf("\033[1;33m\t\t\t=====             CADASTRAR ENDEREÇO            =====\033[0m\n");
        printf("\033[1;33m\t\t\t=====================================================\033[0m\n\n");
        
		fflush(stdin);
		printf("\033[1;36m\t\t\tLOGRADOURO: \033[0m");
        fgets(cliente.endereco.logradouro, sizeof(cliente.endereco.logradouro), stdin);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
        
		printf("\033[1;36m\t\t\tNÚMERO DA CASA: \033[0m");
        scanf("%d", &cliente.endereco.numero);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
		
		printf("\033[1;36m\t\t\tCEP: \033[0m");
        scanf("%d", &cliente.endereco.CEP);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
		
		printf("\033[1;36m\t\t\tBAIRRO: \033[0m");
        fgets(cliente.endereco.bairro, sizeof(cliente.endereco.bairro), stdin);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
		
		printf("\033[1;36m\t\t\tCIDADE: \033[0m");
        fgets(cliente.endereco.cidade, sizeof(cliente.endereco.cidade), stdin);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
		
		printf("\033[1;36m\t\t\tUF: \033[0m");
        fgets(cliente.endereco.UF, sizeof(cliente.endereco.UF), stdin);
        fflush(stdin);
        printf("\n\n");
        
		clientes[totalclientes] = cliente;
        totalclientes++;
        salvarDados();
        
		printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
        printf("\033[1;33m\t\t\t=====   OBRIGADO O CLIENTE FOI CADASTRADO COM SUCESSO    =====\033[0m\n");
        printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
    } else {
        printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
        printf("\033[1;33m\t\t\t====    INFELIZMENTE O NUMERO DE CLIENTES FOI ATINGIDO    ====\033[0m\n");
        printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
    }
}

void listadeclientes() {
    char op;
    int cod;
    if (totalclientes == 0) {
        printf("\t\t\t\t\t\t\t\n\n\n\n\033[1;33m\t\t\t\t\t\t\t==========- INFELIZMENTE NENHUM CLIENTE FOI CADASTRADO -=========\n\n\n\n\n\n\033[0m\n");
        return;
    }
    printf("\033[1;33m==============================================================\033[0m\n");
    printf("\033[1;33m===================- LISTA DE TODOS OS CLIENTES -=============!\033[0m\n");
    printf("\033[1;33m==============================================================\033[0m\n");
    for (int i = 0; i < totalclientes; i++) {
        printf("\n");
        printf("%d - %s\n", i, clientes[i].nome);
    }
    fflush(stdin);
    printf("\033[1;36m\t\t\t=======- MAIS INFORMAÇÕES? -========= (S/N): \033[0m");
    scanf(" %c", &op);
    system("cls");
     sleep(5);
		printf("\t\t\t\t====- CARREGANDO -===...\n\n");
	if (toupper(op) == 'S') {
        printf("\033[1;36mINFORME O ID DO CLIENTE: \033[0m");
        scanf("%d", &cod);
        printf("%d - %s\n", cod, clientes[cod].nome);
        printf("\n\033[1;32m\t===- CPF -===: %s\033[0m", clientes[cod].CPF);
        printf("\n\033[1;32m\t===- IDADE -===: %d\033[0m\n", clientes[cod].idade);
        printf("\n\033[1;32m\t===- DATA DE NASCIMENTO -===: %d\033[0m\n", clientes[cod].datadenascimento);
        printf("\n\033[1;32m\t===- EMAIL -===: %s\033[0m\n", clientes[cod].email);
        printf("\n\033[1;32m\t===- COR -===: %s\033[0m\n", clientes[cod].cor);
        printf("\n\033[1;32m\t===- SEXO -===: %s\033[0m\n", clientes[cod].sexo);
        printf("\n\033[1;32m\t===- NÚMERO TELEFONICO -===: %d\033[0m\n", clientes[cod].telefone);
        printf("\n\033[1;32m\t===- CEP -===: %d\033[0m\n", clientes[cod].endereco.CEP);
        printf("\n\033[1;32m\t===- LOGRADOURO -===: %s\033[0m\n", clientes[cod].endereco.logradouro);
        printf("\n\033[1;32m\t===- NÚMERO: -=== %d\033[0m\n", clientes[cod].endereco.numero);
        printf("\n\033[1;32m\t===- BAIRRO -===: %s\033[0m\n", clientes[cod].endereco.bairro);
        printf("\n\033[1;32m\t===- CIDADE -===: %s\033[0m\n", clientes[cod].endereco.cidade);
        printf("\n\033[1;32m\t===- UF -===: %s\033[0m\n", clientes[cod].endereco.UF);
    }
    fflush(stdin);
    printf("\033[1;33m==============================================================\033[0m\n");
}

void pesquisarclienteid() {
    int id;
    printf("\033[1;36m\t\t\t\t===== INFORME O ID DO CLIENTE ====: \033[0m\n\n");
    scanf("%d", &id);
    printf("\t\t\t\t\t\033[1;33m==============================================================\033[0m\n");
    printf("\t\t\t\t\t\033[1;33m===================- INFORMAÇÕES DO CLIENTE -===================!\033[0m\n");
    printf("\t\t\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");

	printf("\n%d - %s\n", id, clientes[id].nome);
    printf("\n\033[1;32m\t===- NOME -===: %s\033[0m\n", clientes[id].nome);
	printf("\n\033[1;32m\t===- CPF -===: %s\033[0m", clientes[id].CPF);
    printf("\n\033[1;32m\t===- IDADE -===: %d\033[0m\n", clientes[id].idade);
    printf("\n\033[1;32m\t===- DATA DE NASCIMENTO -===: %d\033[0m\n", clientes[id].datadenascimento);
    printf("\n\033[1;32m\t===- EMAIL -===: %s\033[0m\n", clientes[id].email);
    printf("\n\033[1;32m\t===- COR -===: %s\033[0m\n", clientes[id].cor);
    printf("\n\033[1;32m\t===- SEXO -===: %s\033[0m\n", clientes[id].sexo);
    printf("\n\033[1;32m\t===- NÚMERO TELEFONICO -===: %d\033[0m\n", clientes[id].telefone);
    printf("\n\033[1;32m\t===- CEP -===: %d\033[0m\n", clientes[id].endereco.CEP);
    printf("\n\033[1;32m\t===- LOGRADOURO -===: %s\033[0m\n", clientes[id].endereco.logradouro);
    printf("\n\033[1;32m\t===- NÚMERO: -=== %d\033[0m\n", clientes[id].endereco.numero);
    printf("\n\033[1;32m\t===- BAIRRO -===: %s\033[0m\n", clientes[id].endereco.bairro);
    printf("\n\033[1;32m\t===- CIDADE -===: %s\033[0m\n", clientes[id].endereco.cidade);
    printf("\n\033[1;32m\t===- UF -===: %s\033[0m\n", clientes[id].endereco.UF);
    printf("\n\033[1;33m==============================================================\033[0m\n");
    return;
    
	}

 void salvarDados() {
    FILE *arquivo;
    int i;

    arquivo = fopen("clientes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
 
    for (i = 0; i < totalclientes; i++) {
        fprintf(arquivo, "Nome: %s\n", clientes[i].nome);
        fprintf(arquivo, "CPF: %s\n", clientes[i].CPF);
        fprintf(arquivo, "Idade: %d\n", clientes[i].idade);
        fprintf(arquivo, "Data de Nascimento: %s\n", clientes[i].datadenascimento);
        fprintf(arquivo, "Email: %s\n", clientes[i].email);
        fprintf(arquivo, "Cor: %s\n", clientes[i].cor);
        fprintf(arquivo, "Sexo: %s\n", clientes[i].sexo);
        fprintf(arquivo, "Telefone: %d\n", clientes[i].telefone);
        fprintf(arquivo, "CEP: %d\n", clientes[i].endereco.CEP);
        fprintf(arquivo, "Logradouro: %s\n", clientes[i].endereco.logradouro);
        fprintf(arquivo, "Número: %d\n", clientes[i].endereco.numero);
        fprintf(arquivo, "Bairro: %s\n", clientes[i].endereco.bairro);
        fprintf(arquivo, "Cidade: %s\n", clientes[i].endereco.cidade);
        fprintf(arquivo, "UF: %s\n", clientes[i].endereco.UF);
        fprintf(arquivo, "=========================================================================\n");
    }

    fclose(arquivo);
}
   


