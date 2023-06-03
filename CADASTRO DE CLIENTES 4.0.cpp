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
    int id;
    struct Endereco endereco;
};

void escolha(int opcao); 
void desenho();
void cadastro();
void listadeclientes();
void pesquisarclienteid();

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
    fflush(stdin);
	printf("\033[1;33m\t\t\t\t=================================================\033[0m\n\n");
    printf("\033[1;33m\t\t\t\t\t####### GEST�O DE CLIENTES  #######\033[0m\n\n");
    printf("\033[1;33m\t\t\t\t=================================================\033[0m\n\n\n\n");
    printf("\n\n\n\033[1;36m===== SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES =====\033[0m");
    printf("\n\033[1;34m\t1 - -= cadastrar cliente =-\033[0m\n");
    printf("\033[1;34m\t2 - -= lista de todos os clientes cadastrados =-\033[0m\n");
    printf("\033[1;34m\t3 - -= Pesquisar cliente por ID =-\033[0m\n");
    printf("\033[1;31m\t0 - -= Sair =-\033[0m\n\n");
    printf("\033[1;33mEscolha uma op��o: \033[0m");
    scanf("%d", &opcao);
    system("cls");
    escolha(opcao); 
    system("pause");
    return opcao;
}

void escolha(int opcao) {
    switch (opcao) {
        case 1:
            printf("\033[1;33m=======================================\033[0m\n");
            printf("\033[1;33m========## CADASTRO DE CLIENTES ##=======\033[0m\n");
            printf("\033[1;33m=======================================\033[0m\n");
            cadastro();
            break;
        case 2:
            printf("\033[1;33m=========** LISTA DE CLIENTES CADASTRADOS **=========\033[0m\n");
            listadeclientes();
            break;
        case 3:
            printf("\033[1;33m=========$$ PESQUISAR CLIENTES POR ID $$========\033[0m\n");
            pesquisarclienteid();
            break;
        
        case 0:
            printf("\033[1;33m========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========\033[0m\n");
            break;
        default:
            printf("\033[1;31m*** DESCULPE, A OP��O ESCOLHIDA EST� INV�LIDA!! ***\033[0m\n");
            printf("\033[1;31m*** TENTE NOVAMENTE OUTRA OP��O ***\033[0m\n");
    }
}

void cadastro() {
    if (totalclientes < MAX_CLIENTES) {
        struct Cliente cliente;
        printf("\033[1;36m\t=====- ID DO CLIENTE (N�MEROS) -=====: \033[0m");
        scanf("%d", &cliente.id);
		
		sleep(2);
		printf("\t\t\t\tAguarde...\n");
		
		fflush(stdin);
        printf("\033[1;36m\t=====- NOME -=====: \033[0m");
        fgets(cliente.nome, sizeof(cliente.nome), stdin);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		fflush(stdin);
        printf("\033[1;36m\t=====- CPF DO CLIENTE -=====: \033[0m");
        fgets(cliente.CPF, sizeof(cliente.CPF), stdin);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		fflush(stdin);
        printf("\033[1;36m\t=====- IDADE -=====: \033[0m");
        scanf("%d", &cliente.idade);
        fflush(stdin);
        printf("\033[1;36m\t=====- DATA DE NASCIMENTO (dd/mm/aaaa) -=====: \033[0m");
        scanf("%d", &cliente.datadenascimento);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		fflush(stdin);
        printf("\033[1;36m\t=====- EMAIL -=====: \033[0m");
        fgets(cliente.email, sizeof(cliente.email), stdin);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		fflush(stdin);
        printf("\033[1;36m\t=====- N�MERO TELEFONICO ( (75) 91234-5678 ) -=====: \033[0m");
        scanf("%d", &cliente.telefone);
        sleep(4);
		printf("\t\t\t\tAguarde...\n\n");
		printf("\n\033[1;33m\t\t\t=====================================================\033[0m\n");
        printf("\033[1;33m\t\t\t======= CADASTRAR ENDERE�O =======\033[0m\n");
        printf("\033[1;33m\t\t\t=====================================================\033[0m\n\n");
        printf("\033[1;36m\t====- LOGRADOURO -====: \033[0m");
        fgets(cliente.endereco.logradouro, sizeof(cliente.endereco.logradouro), stdin);
        fflush(stdin);
        printf("\033[1;36m\t====- N�MERO DA CASA -====: \033[0m");
        scanf("%d", &cliente.endereco.numero);
        fflush(stdin);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		printf("\033[1;36m\t====- CEP -====: \033[0m");
        scanf("%d", &cliente.endereco.CEP);
        fflush(stdin);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		printf("\033[1;36m\t====- BAIRRO -====: \033[0m");
        fgets(cliente.endereco.bairro, sizeof(cliente.endereco.bairro), stdin);
        fflush(stdin);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		printf("\033[1;36m\t====- CIDADE -====: \033[0m");
        fgets(cliente.endereco.cidade, sizeof(cliente.endereco.cidade), stdin);
        fflush(stdin);
        sleep(2);
		printf("\t\t\t\tAguarde...\n\n");
		printf("\033[1;36m\t====- UF -====: \033[0m");
        fgets(cliente.endereco.UF, sizeof(cliente.endereco.UF), stdin);
        clientes[totalclientes] = cliente;
        totalclientes++;
        printf("\033[1;33m==============================================================\033[0m\n");
        printf("\033[1;33m=====- OBRIGADO O CLIENTE FOI CADASTRADO COM SUCESSO -=====\033[0m\n");
        printf("\033[1;33m==============================================================\033[0m\n");
    } else {
        printf("\033[1;33m==============================================================\033[0m\n");
        printf("\033[1;33m====- INFELIZMENTE O NUMERO DE CLIENTES FOI ATINGIDO -====.\033[0m\n");
        printf("\033[1;33m==============================================================\033[0m\n");
    }
}

void listadeclientes() {
    char op;
    int cod;
    if (totalclientes == 0) {
        printf("\033[1;33m\t\t\t==========- INFELIZMENTE NENHUM CLIENTE FOI CADASTRADO -=========.\033[0m\n");
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
    printf("\033[1;36m\t\t\t=======- MAIS INFORMA��ES? -========= (S/N): \033[0m");
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
        printf("\n\033[1;32m\t===- N�MERO TELEFONICO -===: %d\033[0m\n", clientes[cod].telefone);
        printf("\n\033[1;32m\t===- CEP -===: %d\033[0m\n", clientes[cod].endereco.CEP);
        printf("\n\033[1;32m\t===- LOGRADOURO -===: %s\033[0m\n", clientes[cod].endereco.logradouro);
        printf("\n\033[1;32m\t===- N�MERO: -=== %d\033[0m\n", clientes[cod].endereco.numero);
        printf("\n\033[1;32m\t===- BAIRRO -===: %s\033[0m\n", clientes[cod].endereco.bairro);
        printf("\n\033[1;32m\t===- CIDADE -===: %s\033[0m\n", clientes[cod].endereco.cidade);
        printf("\n\033[1;32m\t===- UF -===: %s\033[0m\n", clientes[cod].endereco.UF);
    }
    fflush(stdin);
    printf("\033[1;33m==============================================================\033[0m\n");
}

void pesquisarclienteid() {
    int id;
    printf("\033[1;36m\t===== INFORME O ID DO CLIENTE ====: \033[0m");
    scanf("%d", &id);
    printf("\033[1;33m==============================================================\033[0m\n");
    printf("\033[1;33m===================- INFORMA��ES DO CLIENTE -===================!\033[0m\n");
    printf("\033[1;33m==============================================================\033[0m\n");
    printf("\n%d - %s\n", id, clientes[id].nome);
    printf("\n\033[1;32m\t===- CPF -===: %s\033[0m", clientes[id].CPF);
    printf("\n\033[1;32m\t===- IDADE -===: %d\033[0m\n", clientes[id].idade);
    printf("\n\033[1;32m\t===- DATA DE NASCIMENTO -===: %d\033[0m\n", clientes[id].datadenascimento);
    printf("\n\033[1;32m\t===- EMAIL -===: %s\033[0m\n", clientes[id].email);
    printf("\n\033[1;32m\t===- N�MERO TELEFONICO -===: %d\033[0m\n", clientes[id].telefone);
    printf("\n\033[1;32m\t===- CEP -===: %d\033[0m\n", clientes[id].endereco.CEP);
    printf("\n\033[1;32m\t===- LOGRADOURO -===: %s\033[0m\n", clientes[id].endereco.logradouro);
    printf("\n\033[1;32m\t===- N�MERO: -=== %d\033[0m\n", clientes[id].endereco.numero);
    printf("\n\033[1;32m\t===- BAIRRO -===: %s\033[0m\n", clientes[id].endereco.bairro);
    printf("\n\033[1;32m\t===- CIDADE -===: %s\033[0m\n", clientes[id].endereco.cidade);
    printf("\n\033[1;32m\t===- UF -===: %s\033[0m\n", clientes[id].endereco.UF);
    printf("\n\033[1;33m==============================================================\033[0m\n");
    return;
}
  

