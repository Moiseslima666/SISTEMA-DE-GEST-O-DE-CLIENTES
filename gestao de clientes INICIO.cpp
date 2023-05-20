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

int menu(Cliente * clientes){
	int opicao;
	printf("\t\t\t\t=================================================\n\n");
	printf("\t\t\t\t\t####### Gestão de Clientes #######\n\n");
    printf("\t\t\t\t=================================================\n\n\n\n");
	printf("\t1 - -= cadastrar cliente =-\n");
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



