#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define MAX_CLIENTES 200

void desenho();

struct Endereco {
	int numero;
	int CEP;
	char logradouro[50];
	char bairro[30];
	char cidade[40];
	char UF[2];
	char pais[20];

};

struct Cliente {
	char nome[50];
	char CPF[14];
	int idade;
	int telefone;
	int idDoCliente;
	int datadenascimento[10];
	char email[50];
	int id;
	Endereco endereco;
};

int menu(Cliente * clientes);

Cliente clientes[MAX_CLIENTES];
int totalclientes = 0;

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
	printf("\t\t\t\t\t####### GESTÃO DE CLIENTES  #######\n\n");
    printf("\t\t\t\t=================================================\n\n\n\n");
	printf("\n\n\n===== SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES =====");
	
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

void escolha(int opicao1, Cliente *clientes){
	
	switch (opicao1)
	    case 1:
	    	printf("=======================================/n")
			printf("========## CADASTRO DE CLIENTES ##=======");
	    	printf("=========================================/n")
			
			cadastro(Cliente *clientes,  int *numclientes)
	    	
	    	break;
	    case 2:
		    printf("=========** LISTA DE CLIENTES CADASTRADOS **=========");
			
			
			break;
		case 3:
		   printf("=========$$ PESQUISAR CLIENTES POR ID $$========");
		   
		   
		   break;
		case 0:
		   printf("========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========");
		   
		   break;
		   default;
		       printf("*** DESCULPE, A OPIÇÃO ESCOLHIDA ESTA INVALIDA!! ***");
			   printf("*** TENTE NOVAMENTE OUTRA OPÇÃO ***")		
    };
}

void cabecario(){
	printf("\t\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t=======#### SISTEMA DE CADASTRO DE CLIENTES ####=======\n");
	printf("\t\t\t\t\t==============================================\n"
	printf("\n\n")
	printf("\t\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t SEJA BEM VINDO AO NOSSO SISTEMA DE CADASTRO.\n PREENÇA CORRETAMENTA AS FICHAS A SEGUIR PARA EVITAR QUALQUER TIPO DE TRANSTORNO\n OBRIGADO PELA ATENÇÃO\n");
	printf("\t\t\t\t\t==============================================\n"

}

void cadastro(Cliente *clientes,  int *numclientes){
	char opicao
	if (*numClientes < MAX_CLIENTES){
	Cliente clientes;
	
	fflush(stdin);
	printf("\t=====- ID DO CLIENTE (NÚMEROS) -=====: ");
	gets(clientes[code].id);
	
	fflush(stdin);
	printf("\t=====- NOME -=====: ");
	gets(clientes[code].nome);
	
	fflush(stdin);
	printf("\t=====- CPF DO CLIENTE -=====: ");
	gets(clientes[code].cpf);
	
	fflush(stdin);
	printf("\t=====- IDADE -=====: ");
	gets(clientes[code].idade);
	
	fflash(stdin);
	printf("\t=====- DATA DE NASCIMENTO (dd/mm/aaaa) -=====: ");
	gets(clientes[code].datadenascimento);
	
	fflush(stdin);
	printf("\t=====- EMAIL -=====: ");
	gets(clientes[code].email);
	
	fflush(stdin);
	printf("\t=====- NÚMERO TELEFONICO ( (75) 91234-5678 ) -=====: ");
	gets(clientes[code].telefone);
	
	desenho();
	
	printf("\n\t\t\t=====================================================\n");
	printf("\t\t\t======= CADASTRAR ENDEREÇO =======\n");
	printf("\t\t\t=====================================================\n\n"
	
	printf("====- LOGRADOURO -====: ");
	scanf("%s", &clientes[code].endereco.logradouro);
	
	fflush(stdin);
	printf("====- NÚMERO DA CASA -====: ");
	scanf("%d", &clentes[code].endereco.numero);
	
	fflush(stdin);
	printf("====- CEP -====: ");
	scanf("%d", &clentes[code].endereco.CEP);
		
	fflush(stdin);
	printf("====- BAIRRO -====: ");
	scanf("%s", &clentes[code].endereco.bairro);
		
	fflush(stdin);
	printf("====- CIDADE -====: ");
	scanf("%s", &clentes[code].endereco.cidade);
		
	fflush(stdin);
	printf("====- UF -====: ");
	scanf("%s", &clentes[code].endereco.UF);
	
	Cliente[*numClientes] = clientes;
        (*numClientes)++;
        
        printf("==============================================================/n");
        printf("=====- OBRIGADO O CLIENTE FOI CADASTRADO COM SUCESSO -=====!\n");
        printf("==============================================================/n");
    } else {
        printf("==============================================================/n");
		printf("====- INFELIZMENTE O NUMERO DE CLIENTES FOI OBTIDO -====.\n");
		printf("==============================================================/n");

    }
	
}
	
void listadeclientes(Cliente *clientes){
	char op;


	if (totalclientes == 0) {
        printf("\t\t\t==========- INFELIZMENTE NENHUM CLIENTE FOI CADASTRADO -=========.\n");
        return;
    }
    
    printf("==============================================================/n");
    printf("===================- LISTA DE TODOS OS CLIENTES -=============!\n");
    printf("==============================================================/n");

    for(int i = 0; i < code; i++) {
		printf("\n");
		printf("%d - %s\n", i, clientes[i].nome);
	}
	
	fflush(stdin);
	printf("\t\t\t=======- MAIS INFORMAÇOES? -========= (S/N): ");
	scanf("%c", &op);
	
	system("cls");
     

}
	


