#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define MAX_CLIENTES 150

struct Endereco {
	int numero;
	int CEP;
	char logradouro[50];
	char bairro[30];
	char cidade[40];
	char UF[2];
};

struct Cliente {
	char nome[50];
	char CPF[14];
	int idade;
	int telefone;
	int idDoCliente;
	Endereco endereco;
};

int menu(Cliente * clientes);

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

int main() {
	setlocale(LC_ALL, "portuguese");
	int opicao;
	
	Cliente *clientes = (Cliente *) malloc(5*sizeof(Cliente));
	
	do {
		
		
		opicao = menu(clientes);
		
		system("cls");
	} while(opicao);
	
	
}

void escolha(int opicao1, Cliente *clientes){
	
	switch(opicao1){
	    case 1:
	    	printf("========## CADASTRO DE CLIENTES ##=======\n");
	    	
	    	
	    	break;
	    case 2:
		    printf("=========** LISTA DE CLIENTES CADASTRADOS **=========\n");
			
			
			break;
		case 3:
		   printf("=========$$ PESQUISAR CLIENTES POR ID $$========\n");
		   
		   
		   break;
		case 0:
		   printf("========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========\n");
		   exit(0);
		   
		   break;
		default:
		    printf("*** DESCULPE, A OPÇÃO ESCOLHIDA É INVALIDA!! ***");
			printf("*** TENTE NOVAMENTE OUTRA OPÇÃO ***");
			break;
			
	}
    }

void cabecario(){
	printf("\t\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t=======#### SISTEMA DE CADASTRO DE CLIENTES ####=======\n");
	printf("\t\t\t\t\t==============================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t SEJA BEM VINDO AO NOSSO SISTEMA DE CADASTRO.\n PREENÇA CORRETAMENTA AS FICHAS A SEGUIR PARA EVITAR QUALQUER TIPO DE TRANSTORNO\n OBRIGADO PELA ATENÇÃO\n");
	printf("\t\t\t\t\t==============================================\n");

}
int menu(Cliente * clientes){
	int opicao;
	printf("\t\t\t\t=================================================\n\n");
	printf("\t\t\t\t\t####### GESTÃO DE CLIENTES  #######\n\n");
    printf("\t\t\t\t=================================================\n\n\n\n");
	printf("\n\n\n===== SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES =====");
	
	printf("\n\n\t1 - -= cadastrar cliente =-\n");
    printf("\t2 - -= lista de todos os clientes cadastrados =-\n");
    printf("\t3 - -= Pesquisar cliente por ID =-\n");
    printf("\t0 - -= Sair =-\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opicao);
    
	system("cls");
	
	escolha(opicao, clientes);
	
	system("pause");
	
	return opicao;
}


void cadastro(Cliente *clientes){
	char opicao;
	
	fflush(stdin);
	printf("\t=====- NOME -=====: ");
	gets(clientes[code].nome);
	
	fflush(stdin);
	printf("\t=====- CPF DO CLIENTE -=====: ");
	gets(clientes[code].cpf);
	
	fflush(stdin);
	printf("\t=====- IDADE -=====: ");
	gets(clientes[code].idade);
	
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t======= CADASTRAR ENDEREÇLO =======\n");
	printf("\t\t\t=====================================================\n");
	
	
	
}
