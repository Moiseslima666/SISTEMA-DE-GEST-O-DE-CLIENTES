#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>



#define MAX_CLIENTES 200

struct Agenda{
	char CPF[15]; 
	int data[20];
	int horario[10];
}Agenda[100];

struct AgendaVisitas{
	char CPF[15]; 
	int data[20];
	int horario[10];
}AgendaVisitas[100];

struct Endereco {
    int numero;
    int CEP;
    char logradouro[50];
    char bairro[30];
    char cidade[40];
    char UF[3];
};

struct Cliente {
    char nome[50];
    char CPF[15];
    int idade;
    char telefone[15];
    int datadenascimento[20]; 
    char email[50];
<<<<<<< HEAD
    char cor[20];
    char sexo[2];
=======
    char raca[20];
    char sexo[30];
    int id;
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
    struct Endereco endereco;
};


struct Visita {
    struct Cliente cliente;
    char data[20];
    char hora[10];
};

void escolha(int opcao); 
void desenho();
void cadastro();
void listadeclientes();
<<<<<<< HEAD
void pesquisarclienteCPF();
=======
void pesquisarclienteid();
void deletarCliente();
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
void salvarDados();
void criarAgendaVisitas();
void listarAgendaVisitas();
void avaliacaocliente();
void lerCadastro();

struct Visita visitas[MAX_CLIENTES];
struct Cliente clientes[MAX_CLIENTES];
int totalclientes = 0;
int totalvisitas = 0;
int totalagendas = 0;

int menu();

int main(){
    
	setlocale(LC_ALL, "portuguese");
    lerCadastro();
    
	int opcao;
    do {
        opcao = menu();
        system("cls");
    } while (opcao);
    return 0;
}

int menu(){
    int opcao;
<<<<<<< HEAD
    printf("\n\t\t\t\t\t\t\t-----------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t                  GEST�O DE CLIENTES                  ");
    printf("\n\t\t\t\t\t\t\t-----------------------------------------------------\n\n\n");
    printf("\n\t\t\t\t->>>>>>>>>>>>>>>>>> SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES! <<<<<<<<<<<<<<<<<<<<<-\n\n");
=======
    printf("\n\t\t\t\t-----------------------------------------------------");
    printf("\n\t\t\t\t                  GEST?O DE CLIENTES                  ");
    printf("\n\t\t\t\t-----------------------------------------------------\n\n\n");
    printf("\n\t\t\t\t- SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES! -\n\n");
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
    
    printf("\n\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t---    ESCOLHA UMA OP??O    ---");
    printf("\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t 1 - CADASTRAR CLIENTE");
    printf("\n\t\t\t\t\t 2 - LISTA DE CLIENTES CADASTRADOS");
<<<<<<< HEAD
    printf("\n\t\t\t\t\t 3 - PESQUISAR CLIENTE POR CPF");
    printf("\n\t\t\t\t\t 4 - CRIAR AGENDA DE VISITAS");
    printf("\n\t\t\t\t\t 5 - LISTAR AGENDA DE VISITAS");
    printf("\n\t\t\t\t\t 6 - AVALIA��O DO CLIENTE");
    printf("\n\t\t\t\t\t 0 - SAIR");
=======
    printf("\n\t\t\t\t\t 3 - PESQUISAR CLIENTE POR ID");
    printf("\n\t\t\t\t\t 4 - DELETAR CLIENTE");
	printf("\n\t\t\t\t\t 0 - SAIR                    ");
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
    printf("\n\t\t\t\t\t-----------------------------");
    printf("\n\t\t\t\t\tESCOLHA A OP??O DESEJADA: ");
    scanf("%d", &opcao);
    fflush(stdin);
    
    system("cls");
    
    escolha(opcao); 
    
    system("pause");
    
    return opcao;
}

void escolha(int opcao){
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
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m==== PESSQUISAR CLIENTE POR CPF ====\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n\n\n");
            printf("========================================================================================================================================================================\n\n");
            pesquisarclienteCPF();
            break;
        case 4:
<<<<<<< HEAD
            printf("========================================================================================================================================================================\n\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m========= CRIAR AGENDA DE VISITAS =========\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n\n\n");
            printf("========================================================================================================================================================================\n\n");
            criarAgendaVisitas();
            break;
        case 5:
            printf("========================================================================================================================================================================\n\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m========= LISTAR AGENDA DE VISITAS =========\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n\n\n");
            printf("========================================================================================================================================================================\n\n");
            listarAgendaVisitas();
            break;
        case 6:
		    printf("========================================================================================================================================================================\n\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m========= LISTAR AGENDA DE VISITAS =========\033[0m\n");
            printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n\n\n");
            printf("========================================================================================================================================================================\n\n");
            avaliacaocliente();
            break;
		case 0:
=======
        	printf("========================================================================================================================================================================\n\n");
        	printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m======================================\033[0m\n");
        	printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m===== DELETAR CLIENTE =================\033[0m\n");
        	printf("\n\t\t\t\t\t\t\t\t\t\033[1;33m=======================================\033[0m\n\n\n");
        	printf("========================================================================================================================================================================\n\n");
        	deletarCliente();
        	break;
        case 0:
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
            printf("\033[1;33m========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========\033[0m\n\n\n");
            break;
        default:
            printf("\033[1;31m*** DESCULPE, A OP??O ESCOLHIDA EST? INV?LIDA!! ***\033[0m\n");
            printf("\033[1;31m*** TENTE NOVAMENTE OUTRA OP??O ***\033[0m\n");
    }
}

void cadastro() {
    if (totalclientes < MAX_CLIENTES) {
        struct Cliente cliente;
<<<<<<< HEAD
        printf("\033[1;36m\t\t\t CPF DO CLIENTE (N�MEROS): \033[0m");
        scanf("%s", cliente.CPF);
=======
        printf("\033[1;36m\t ID DO CLIENTE (N?MEROS): \033[0m");
        scanf("%d", &cliente.id);
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
		fflush(stdin);
		
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\t\t\tNOME: \033[0m");
        fgets(cliente.nome, sizeof(cliente.nome), stdin);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		
		fflush(stdin);
        printf("\033[1;36m\t\t\tIDADE: \033[0m");
        scanf("%d", &cliente.idade);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
        
		fflush(stdin);
        printf("\033[1;36m\t\t\tDATA DE NASCIMENTO (dd/mm/aaaa): \033[0m");
        scanf("%s", cliente.datadenascimento);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\t\t\tEMAIL: \033[0m");
        scanf("%s", cliente.email);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
        
		fflush(stdin);
<<<<<<< HEAD
        printf("\033[1;36m\t\t\tCOR: \033[0m");
        scanf("%s", cliente.cor);
=======
        printf("\033[1;36m\tCOR: \033[0m");
        scanf("%c", &cliente.raca);
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
        printf("\033[1;36m\t\t\tSEXO (M/F): \033[0m");
        scanf("%s", cliente.sexo);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		
		fflush(stdin);
<<<<<<< HEAD
        printf("\033[1;36m\t\t\tN�MERO TELEFONICO : \033[0m");
=======
        printf("\033[1;36m\tN?MERO TELEFONICO EX:(DDD) 91234-5678 ): \033[0m");
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
        scanf("%d", &cliente.telefone);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		sleep(3);
		
		system("cls");
		
		printf("\n\033[1;33m\t\t\t=====================================================\033[0m\n");
        printf("\033[1;33m\t\t\t=====             CADASTRAR ENDERE?O            =====\033[0m\n");
        printf("\033[1;33m\t\t\t=====================================================\033[0m\n\n");
        
		fflush(stdin);
		printf("\033[1;36m\t\t\tLOGRADOURO: \033[0m");
        scanf("%s", cliente.endereco.logradouro);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
        
		printf("\033[1;36m\t\t\tN?MERO DA CASA: \033[0m");
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
        scanf("%s", cliente.endereco.bairro);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
		
		printf("\033[1;36m\t\t\tCIDADE: \033[0m");
        scanf("%s", cliente.endereco.cidade);
        fflush(stdin);
        
		sleep(1);
		printf("\t\t\tAguarde...\n\n");
		
		printf("\033[1;36m\t\t\tUF: \033[0m");
        scanf("%s", cliente.endereco.UF);
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

<<<<<<< HEAD
void listadeclientes(){
    if (totalclientes > 0) {
        for (int i = 0; i < totalclientes; i++) {
        sleep(1);
	    printf("\n\t\t\tCARREGANDO...\n\n");
        sleep(3);
    
        system("cls");
		printf("\033[1;36m\t\t\tCLIENTE %d:\033[0m\n\n", i + 1);
        printf("\033[1;36m\t\t\tCPF: \033[0m%s", clientes[i].CPF);
        printf("\033[1;36m\t\t\tNOME: \033[0m%s", clientes[i].nome);
        printf("\033[1;36m\t\t\tIDADE: \033[0m%d\n", clientes[i].idade);
        printf("\033[1;36m\t\t\tDATA DE NASCIMENTO: \033[0m%s\n", clientes[i].datadenascimento);
        printf("\033[1;36m\t\t\tEMAIL: \033[0m%s", clientes[i].email);
        printf("\033[1;36m\t\t\tCOR: \033[0m%s", clientes[i].cor);
        printf("\033[1;36m\t\t\tSEXO: \033[0m%s", clientes[i].sexo);
        printf("\033[1;36m\t\t\tTELEFONE: \033[0m%d\n", clientes[i].telefone);
        printf("\033[1;36m\t\t\tENDERE�O:\033[0m\n");
        printf("\033[1;36m\t\t\t\tLOGRADOURO: \033[0m%s", clientes[i].endereco.logradouro);
        printf("\033[1;36m\t\t\t\tN�MERO DA CASA: \033[0m%d\n", clientes[i].endereco.numero);
        printf("\033[1;36m\t\t\t\tCEP: \033[0m%d\n", clientes[i].endereco.CEP);
        printf("\033[1;36m\t\t\t\tBAIRRO: \033[0m%s", clientes[i].endereco.bairro);
        printf("\033[1;36m\t\t\t\tCIDADE: \033[0m%s", clientes[i].endereco.cidade);
        printf("\033[1;36m\t\t\t\tESTADO (UF): \033[0m%s", clientes[i].endereco.UF);
        printf("\n\n");
        }
    } else{
        sleep(1);
	    printf("\n\t\t\tCARREGANDO...\n\n");
		sleep(3);
    
    system("cls");
		printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
        printf("\033[1;33m\t\t\t=============    NENHUM CLIENTE CADASTRADO    ===============\033[0m\n");
        printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
=======
void listadeclientes() {
    char op;
    int cod;
    if (totalclientes == 0) {
        printf("\n\n\n\n\033[1;33m\t\t\t==========- INFELIZMENTE NENHUM CLIENTE FOI CADASTRADO -=========\n\n\n\n\n\n\033[0m\n");
        return;
    }
    printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
    printf("\033[1;33m\t\t\t===================- LISTA DE TODOS OS CLIENTES -=============\033[0m\n");
    printf("\033[1;33m\t\t\t==============================================================\033[0m\n");
    for (int i = 0; i < totalclientes; i++) {
        printf("\n");
        printf("%d - %s\n", i, clientes[i].nome);
    }
    fflush(stdin);
    printf("\033[1;36m\n\t\t\t======= MAIS INFORMA??ES? ========= (S/N): \033[0m");
    scanf(" %c", &op);
    fflush(stdin);
    
    system("cls");
    
    sleep(1);
	printf("\n\t\t\tCARREGANDO...\n\n");
    sleep(3);
    
    system("cls");
		
	if (toupper(op) == 'S') {
        printf("\033[1;36m\t\t\tINFORME O ID DO CLIENTE: \033[0m");
        scanf("%d", &cod);
        fflush(stdin);
        
        printf("%d - %s\n", cod, clientes[cod].nome);
        printf("\n\033[1;32m\t\t\tCPF: %s\033[0m\n", clientes[cod].CPF);
        printf("\n\033[1;32m\t\t\tIDADE: %d\033[0m\n", clientes[cod].idade);
        printf("\n\033[1;32m\t\t\tDATA DE NASCIMENTO: %d\033[0m\n", clientes[cod].datadenascimento);
        printf("\n\033[1;32m\t\t\tEMAIL: %s\033[0m\n", clientes[cod].email);
        printf("\n\033[1;32m\t\t\tRAÇA: %s\033[0m\n", clientes[cod].raca);
        printf("\n\033[1;32m\t\t\tSEXO: %s\033[0m\n", clientes[cod].sexo);
        printf("\n\033[1;32m\t\t\tN?MERO TELEFONICO: %d\033[0m\n", clientes[cod].telefone);
        printf("\n\033[1;32m\t\t\tCEP: %d\033[0m\n", clientes[cod].endereco.CEP);
        printf("\n\033[1;32m\t\t\tLOGRADOURO: %s\033[0m\n", clientes[cod].endereco.logradouro);
        printf("\n\033[1;32m\t\t\tN?MERO: %d\033[0m\n", clientes[cod].endereco.numero);
        printf("\n\033[1;32m\t\t\tBAIRRO: %s\033[0m\n", clientes[cod].endereco.bairro);
        printf("\n\033[1;32m\t\t\tCIDADE: %s\033[0m\n", clientes[cod].endereco.cidade);
        printf("\n\033[1;32m\t\t\tUF: %s\033[0m\n", clientes[cod].endereco.UF);
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
    }

}




void pesquisarclienteCPF(){
    char cpf[12];
    printf("\033[1;36m\t\t\tDIGITE O CPF DO CLIENTE: \033[0m\n\n\n");
    scanf("%s", cpf);
    fflush(stdin);
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
    printf("\t\t\t\033[1;33m===================- INFORMA??ES DO CLIENTE -===================!\033[0m\n");
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");

<<<<<<< HEAD

    int encontrado = 0;
    for (int i = 0; i < totalclientes; i++) {
        if (strcmp(clientes[i].CPF, cpf) == 0) {
            printf("\033[1;36m\t\t\tCPF: \033[0m%s", clientes[i].CPF);
            printf("\033[1;36m\t\t\tNOME: \033[0m%s", clientes[i].nome);
            printf("\033[1;36m\t\t\tIDADE: \033[0m%d\n", clientes[i].idade);
            printf("\033[1;36m\t\t\tDATA DE NASCIMENTO: \033[0m%s%s/%s", clientes[i].datadenascimento);
            printf("\033[1;36m\t\t\tEMAIL: \033[0m%s", clientes[i].email);
            printf("\033[1;36m\t\t\tCOR: \033[0m%s", clientes[i].cor);
            printf("\033[1;36m\t\t\tSEXO: \033[0m%s", clientes[i].sexo);
            printf("\033[1;36m\t\t\tTELEFONE: \033[0m%d\n", clientes[i].telefone);
            printf("\033[1;36m\t\t\tENDERE�O:\033[0m\n");
            printf("\033[1;36m\t\t\t\tLOGRADOURO: \033[0m%s", clientes[i].endereco.logradouro);
            printf("\033[1;36m\t\t\t\tN�MERO DA CASA: \033[0m%d\n", clientes[i].endereco.numero);
            printf("\033[1;36m\t\t\t\tCEP: \033[0m%d\n", clientes[i].endereco.CEP);
            printf("\033[1;36m\t\t\t\tBAIRRO: \033[0m%s", clientes[i].endereco.bairro);
            printf("\033[1;36m\t\t\t\tCIDADE: \033[0m%s", clientes[i].endereco.cidade);
            printf("\033[1;36m\t\t\t\tESTADO (UF): \033[0m%s", clientes[i].endereco.UF);
            printf("\n\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
    printf("\t\t\t\033[1;33m===================- CLIENTE N�O ENCONTRADO -===================!\033[0m\n");
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
    }
}
       

=======
	printf("\n%d - %s\n", id, clientes[id].nome);
    printf("\n\033[1;32m\t\t\tNOME: %s\033[0m\n", clientes[id].nome);
	printf("\n\033[1;32m\t\t\tCPF: %s\033[0m\n", clientes[id].CPF);
    printf("\n\033[1;32m\t\t\tIDADE: %d\033[0m\n", clientes[id].idade);
    printf("\n\033[1;32m\t\t\tDATA DE NASCIMENTO: %d\033[0m\n", clientes[id].datadenascimento);
    printf("\n\033[1;32m\t\t\tEMAIL: %s\033[0m\n", clientes[id].email);
    printf("\n\033[1;32m\t\t\tCOR: %s\033[0m\n", clientes[id].raca);
    printf("\n\033[1;32m\t\t\tSEXO: %s\033[0m\n", clientes[id].sexo);
    printf("\n\033[1;32m\t\t\tN?MERO TELEFONICO: %d\033[0m\n", clientes[id].telefone);
    printf("\n\033[1;32m\t\t\tCEP: %d\033[0m\n", clientes[id].endereco.CEP);
    printf("\n\033[1;32m\t\t\tLOGRADOURO: %s\033[0m\n", clientes[id].endereco.logradouro);
    printf("\n\033[1;32m\t\t\tN?MERO: %d\033[0m\n", clientes[id].endereco.numero);
    printf("\n\033[1;32m\t\t\tBAIRRO: %s\033[0m\n", clientes[id].endereco.bairro);
    printf("\n\033[1;32m\t\t\tCIDADE: %s\033[0m\n", clientes[id].endereco.cidade);
    printf("\n\033[1;32m\t\t\tUF: %s\033[0m\n", clientes[id].endereco.UF);
    printf("\n\033[1;33m\t\t\t==============================================================\033[0m\n");
    return;
    
	}
	
	void deletarCliente(){
		int num;
		char meca[50];
		
		FILE *arquivo;
    	int i;

    	arquivo = fopen("clientes.txt", "w");

    	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    	}
		
		printf("\033[1;36m\t\t\t QUAL CLIENTE VOCÊ DESEJA DELETAR? \033[0m\n\n");
		
		printf("numero: ");
		scanf("%d", &num);
		
		strcpy(clientes[num].nome, "  ");
		strcpy(clientes[num].CPF, "     ");
		clientes[num].idade = NULL;
		strcpy(clientes[num].datadenascimento, "   ");
		strcpy(clientes[num].email, "   ");
		strcpy(clientes[num].raca, "    ");
		strcpy(clientes[num].sexo, "     ");
		clientes[num].telefone = NULL;
		clientes[num].endereco.CEP = NULL;
		strcpy(clientes[num].endereco.logradouro, "     ");
		clientes[num].endereco.numero = NULL;
		strcpy(clientes[num].endereco.bairro, "      ");
		strcpy(clientes[num].endereco.cidade, "   ");
		strcpy(clientes[num].endereco.UF, "   ");
		
		
		fprintf(arquivo, "Nome: %s\n", clientes[num].nome);
        fprintf(arquivo, "CPF: %s\n", clientes[num].CPF);
        fprintf(arquivo, "Idade: %d\n", clientes[num].idade);
        fprintf(arquivo, "Data de Nascimento: %s\n", clientes[num].datadenascimento);
        fprintf(arquivo, "Email: %s\n", clientes[num].email);
        fprintf(arquivo, "Raça: %s\n", clientes[num].raca);
        fprintf(arquivo, "Sexo: %s\n", clientes[num].sexo);
        fprintf(arquivo, "Telefone: %d\n", clientes[num].telefone);
        fprintf(arquivo, "CEP: %d\n", clientes[num].endereco.CEP);
        fprintf(arquivo, "Logradouro: %s\n", clientes[num].endereco.logradouro);
        fprintf(arquivo, "N?mero: %d\n", clientes[num].endereco.numero);
        fprintf(arquivo, "Bairro: %s\n", clientes[num].endereco.bairro);
        fprintf(arquivo, "Cidade: %s\n", clientes[num].endereco.cidade);
        fprintf(arquivo, "UF: %s\n", clientes[num].endereco.UF);
        fprintf(arquivo, "=========================================================================\n");
		
		
		
		
		
		
		
		totalclientes--;
		printf("\n\n\n\n\033[1;33m\t\t\t==========- CLIENTE DELETADO COM SUCESSO -=========\n\n\n\n\n\n\033[0m\n");
		
		

		system("pause");
		system("cls");
		menu();
	}
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d

 void salvarDados() {
    FILE *arquivo = fopen("cadastro.txt", "w");
    if (arquivo == NULL) {
        printf("===- ERRO AO ABRIR O ARQUIVO. \n");
        return;
    }
<<<<<<< HEAD

    for (int i = 0; i < totalclientes; i++) {
        fprintf(arquivo, "%c\n", clientes[i].CPF);
        fprintf(arquivo, "%s\n", clientes[i].nome);
        fprintf(arquivo, "%d\n", clientes[i].idade);
        fprintf(arquivo, "%s/%s/%s\n", clientes[i].datadenascimento);
        fprintf(arquivo, "%s\n", clientes[i].email);
        fprintf(arquivo, "%s\n", clientes[i].cor);
        fprintf(arquivo, "%s\n", clientes[i].sexo);
        fprintf(arquivo, "%d\n", clientes[i].telefone);
        fprintf(arquivo, "%s\n", clientes[i].endereco.logradouro);
        fprintf(arquivo, "%d\n", clientes[i].endereco.numero);
        fprintf(arquivo, "%d\n", clientes[i].endereco.CEP);
        fprintf(arquivo, "%s\n", clientes[i].endereco.bairro);
        fprintf(arquivo, "%s\n", clientes[i].endereco.cidade);
        fprintf(arquivo, "%s\n", clientes[i].endereco.UF);
        fprintf(arquivo, "\n");
=======
 
    for (i = 0; i < totalclientes; i++) {
        fprintf(arquivo, "Nome: %s\n", clientes[i].nome);
        fprintf(arquivo, "CPF: %s\n", clientes[i].CPF);
        fprintf(arquivo, "Idade: %d\n", clientes[i].idade);
        fprintf(arquivo, "Data de Nascimento: %s\n", clientes[i].datadenascimento);
        fprintf(arquivo, "Email: %s\n", clientes[i].email);
        fprintf(arquivo, "Raça: %s\n", clientes[i].raca);
        fprintf(arquivo, "Sexo: %s\n", clientes[i].sexo);
        fprintf(arquivo, "Telefone: %d\n", clientes[i].telefone);
        fprintf(arquivo, "CEP: %d\n", clientes[i].endereco.CEP);
        fprintf(arquivo, "Logradouro: %s\n", clientes[i].endereco.logradouro);
        fprintf(arquivo, "N?mero: %d\n", clientes[i].endereco.numero);
        fprintf(arquivo, "Bairro: %s\n", clientes[i].endereco.bairro);
        fprintf(arquivo, "Cidade: %s\n", clientes[i].endereco.cidade);
        fprintf(arquivo, "UF: %s\n", clientes[i].endereco.UF);
        fprintf(arquivo, "=========================================================================\n");
>>>>>>> 64b8423ce5c1b1ad9cc84977fa23f73a5afd472d
    }

    fclose(arquivo);
}

void lerCadastro() {
    FILE *arquivo = fopen("cadastro.txt", "r");
    if (arquivo == NULL) {
        return;
    }

    for (int i = 0; i < totalclientes; i++) {
        fscanf(arquivo, "%c", &clientes[i].CPF);
        fscanf(arquivo, "%s", clientes[i].nome);
        fscanf(arquivo, "%d", &clientes[i].idade);
        fscanf(arquivo, "%s/%s/%s", clientes[i].datadenascimento);
        fscanf(arquivo, "%s", clientes[i].email);
        fscanf(arquivo, "%c", &clientes[i].cor);
        fscanf(arquivo, "%c", &clientes[i].sexo);
        fscanf(arquivo, "%d", &clientes[i].telefone);
        fscanf(arquivo, "%s", clientes[i].endereco.logradouro);
        fscanf(arquivo, "%d", &clientes[i].endereco.numero);
        fscanf(arquivo, "%d", &clientes[i].endereco.CEP);
        fscanf(arquivo, "%s", clientes[i].endereco.bairro);
        fscanf(arquivo, "%s", clientes[i].endereco.cidade);
        fscanf(arquivo, "%s", clientes[i].endereco.UF);
    }

    fclose(arquivo);
}

void criarAgendaVisitas() {
    if (totalclientes > 0) {
        struct AgendaVisitas agenda;
        printf("\033[1;36m\t\t\tCPF DO CLIENTE A SER AGENDADO : \033[0m");
        scanf("%s", agenda.CPF);
        fflush(stdin);

        int encontrado = 0;
        for (int i = 0; i < totalclientes; i++) {
            if (strcmp(clientes[i].CPF, agenda.CPF) == 0) {
                encontrado = 1;
                break;
            }
        }

        if (encontrado) {
            printf("\033[1;36m\t\tDATA DA VISITA (dd/mm/aaaa): \033[0m");
            scanf("%s", agenda.data);
            fflush(stdin);

            printf("\033[1;36m\t\tHOR�RIO DA VISITA (hh:mm): \033[0m");
            scanf("%s", agenda.horario);
            fflush(stdin);

            AgendaVisitas[totalagendas] = agenda;
            totalagendas++;

            printf("\n\033[1;32m\t\t\tAGENDA DE VISITA CRIADA COM SUCESSO!!!\033[0m\n\n\n");
        } else {
            printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
            printf("\t\t\t\033[1;33m=====================- CPF N�O ENCONTRADO -===================!\033[0m\n");
            printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
        }
    } else {
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
        printf("\t\t\t\033[1;33m===================- CLIENTE N�O ENCONTRADO -===================!\033[0m\n");
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
    }
}

void listarAgendaVisitas() {
    if (totalagendas > 0) {
        for (int i = 0; i < totalagendas; i++) {         
            printf("\033[1;36m\tAGENDA DE VISITA %d:\033[0m\n\n", i + 1);
            printf("\033[1;36m\t\tCPF DO CLIENTE: \033[0m%s\n", AgendaVisitas[i].CPF);
            printf("\033[1;36m\t\tDATA DA VISITA: \033[0m%s\n", AgendaVisitas[i].data);
            printf("\033[1;36m\t\tHOR�RIO DA VISITA: \033[0m%s\n", AgendaVisitas[i].horario);
            printf("\n");
        }
    } else {
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
        printf("\t\t\t\033[1;33m===============- AGENDA DE VISITA N�O CRIADA -================!\033[0m\n");
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
    }
}

void avaliacaocliente(){
	int nota;
	salvarDados();
	printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
    printf("\t\t\t\033[1;33m==================- AVALIA��O DO CLIENTE -====================!\033[0m\n");
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n\n");
    
    printf("\t\t\t\t=====- OL� QUERIDO CLIENTE, EM PESQUISA DE AVALIA��O VOC� PODERIA INSERIR UMA NOTA DE 1 A 10 DE AVALIA��O -=======\n");
    sleep(3);
    printf("\n\t\t\tCARREGANDO...\n\n\n\n");
    
    printf("\t\t\t====- INSIRA SUA NOTA AQUI -=====: ");
    scanf("%d", &nota);
    
    if(nota >= 7)
    	printf("\t\t\t\t\t\n\n\n============- AGRADECEMOS A PREFERENCIA, MUITO OBRIGADO PRO CONTAR COM O NOSSO SERVI�O -===============\n\n\n");
    else
	   printf("\t\t\t\t\t\n\n\n==============- DESCULPA, IREMOS FAZER O MAXIMO PARA QUE NO PROXIMO CADASTRO SEJA MELHOR!! -====================\n\n\n\n");	
	   
	return;
}



