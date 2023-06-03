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
	    	printf("========## CADASTRO DE CLIENTES ##=======");
	    	printf("========## CADASTRO DE CLIENTES ##=======\n");


	    	break;
	    case 2:
		    printf("=========** LISTA DE CLIENTES CADASTRADOS **=========");
		    printf("=========** LISTA DE CLIENTES CADASTRADOS **=========\n");


			break;
		case 3:
		   printf("=========$$ PESQUISAR CLIENTES POR ID $$========");
		   printf("=========$$ PESQUISAR CLIENTES POR ID $$========\n");


		   break;
		case 0:
		   printf("========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========");
		   printf("========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========\n");
		   exit(0);

		   break;
		default:
		    printf("*** DESCULPE, A OPIÇÃO ESCOLHIDA ESTA INVALIDA!! ***");
		    printf("*** DESCULPE, A OPÇÃO ESCOLHIDA É INVALIDA!! ***");
			printf("*** TENTE NOVAMENTE OUTRA OPÇÃO ***");
			break;

	}
    }

 int menu(Cliente * clientes){
    printf("\t\t\t\t=================================================\n\n\n\n");
	printf("\n\n\n===== SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES =====");

	printf("\t1 - -= cadastrar cliente =-\n");
	printf("\n\n\t1 - -= cadastrar cliente =-\n");
    printf("\t2 - -= lista de todos os clientes cadastrados =-\n");
    printf("\t3 - -= Pesquisar cliente por ID =-\n");
    printf("\t0 - -= Sair =-\n\n");
 void cadastro(Cliente *clientes){


}

