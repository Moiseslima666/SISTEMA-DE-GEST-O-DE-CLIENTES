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
    int CEP[10];
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
    char cor[20];
    char sexo[2];
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
void pesquisarclienteCPF();
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
    printf("\n\t\t\t\t\t\t\t-----------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t                  GESTÃO DE CLIENTES                  ");
    printf("\n\t\t\t\t\t\t\t-----------------------------------------------------\n\n\n");
    printf("\n\t\t\t\t->>>>>>>>>>>>>>>>>> SEJA BEM-VINDO A NOSSA CENTRAL DE CADASTRO DE CLIENTES! <<<<<<<<<<<<<<<<<<<<<-\n\n");
    
    printf("\n\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t---    ESCOLHA UMA OPÇÃO    ---");
    printf("\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t 1 - CADASTRAR CLIENTE");
    printf("\n\t\t\t\t\t 2 - LISTA DE CLIENTES CADASTRADOS");
    printf("\n\t\t\t\t\t 3 - PESQUISAR CLIENTE POR CPF");
    printf("\n\t\t\t\t\t 4 - CRIAR AGENDA DE VISITAS");
    printf("\n\t\t\t\t\t 5 - LISTAR AGENDA DE VISITAS");
    printf("\n\t\t\t\t\t 6 - AVALIAÇÃO DO CLIENTE");
    printf("\n\t\t\t\t\t 0 - SAIR");
    printf("\n\t\t\t\t\t-----------------------------");
    printf("\n\t\t\t\t\tESCOLHA A OPÇÃO DESEJADA: ");
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
            printf("\n\n\n\t\t\t\t\t\033[1;33m========== O SEU SISTEMA FOI ENCERRADO COM SUCESSO!!!! ==========\033[0m\n\n\n");
            break;
        default:
            printf("\033[1;31m*** DESCULPE, A OPÇÃO ESCOLHIDA ESTÁ INVÁLIDA!! ***\033[0m\n");
            printf("\033[1;31m*** TENTE NOVAMENTE OUTRA OPÇÃO ***\033[0m\n");
    }
}

void cadastro() {
    if (totalclientes < MAX_CLIENTES) {
        struct Cliente cliente;
        printf("\033[1;36m\t\t\t CPF DO CLIENTE (NÚMEROS): \033[0m");
        scanf("%s", cliente.CPF);
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
        printf("\033[1;36m\t\t\tCOR: \033[0m");
        scanf("%s", cliente.cor);
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
        printf("\033[1;36m\t\t\tNÚMERO TELEFONICO : \033[0m");
        scanf("%d", &cliente.telefone);
        fflush(stdin);
        
		sleep(1);
		printf("\t\tAguarde...\n\n");
		sleep(3);
		
		system("cls");
		
		printf("\n\033[1;33m\t\t\t=====================================================\033[0m\n");
        printf("\033[1;33m\t\t\t=====             CADASTRAR ENDEREÇO            =====\033[0m\n");
        printf("\033[1;33m\t\t\t=====================================================\033[0m\n\n");
        
		fflush(stdin);
		printf("\033[1;36m\t\t\tLOGRADOURO: \033[0m");
        scanf("%s", cliente.endereco.logradouro);
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
        printf("\033[1;36m\t\t\tENDEREÇO:\033[0m\n");
        printf("\033[1;36m\t\t\t\tLOGRADOURO: \033[0m%s", clientes[i].endereco.logradouro);
        printf("\033[1;36m\t\t\t\tNÚMERO DA CASA: \033[0m%d\n", clientes[i].endereco.numero);
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
    }

}




void pesquisarclienteCPF(){
    char cpf[12];
    printf("\033[1;36m\t\t\tDIGITE O CPF DO CLIENTE: \033[0m\n\n\n");
    scanf("%s", cpf);
    fflush(stdin);
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
    printf("\t\t\t\033[1;33m===================- INFORMAÇÕES DO CLIENTE -===================!\033[0m\n");
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");


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
            printf("\033[1;36m\t\t\tENDEREÇO:\033[0m\n");
            printf("\033[1;36m\t\t\t\tLOGRADOURO: \033[0m%s", clientes[i].endereco.logradouro);
            printf("\033[1;36m\t\t\t\tNÚMERO DA CASA: \033[0m%d\n", clientes[i].endereco.numero);
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
    printf("\t\t\t\033[1;33m===================- CLIENTE NÃO ENCONTRADO -===================!\033[0m\n");
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
    }
}
       


void salvarDados() {
    FILE *arquivo = fopen("cadastro.txt", "w");
    if (arquivo == NULL) {
        printf("===- ERRO AO ABRIR O ARQUIVO. \n");
        return;
    }

    for (int i = 0; i < totalclientes; i++) {
        fprintf(arquivo, "%c\n", clientes[i].CPF);
        fprintf(arquivo, "%s\n", clientes[i].nome);
        fprintf(arquivo, "%d\n", clientes[i].idade);
        fprintf(arquivo, "%s\n", clientes[i].datadenascimento);
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
        fscanf(arquivo, "%s", clientes[i].datadenascimento);
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

            printf("\033[1;36m\t\tHORÁRIO DA VISITA (hh:mm): \033[0m");
            scanf("%s", agenda.horario);
            fflush(stdin);

            AgendaVisitas[totalagendas] = agenda;
            totalagendas++;

            printf("\n\033[1;32m\t\t\tAGENDA DE VISITA CRIADA COM SUCESSO!!!\033[0m\n\n\n");
        } else {
            printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
            printf("\t\t\t\033[1;33m=====================- CPF NÃO ENCONTRADO -===================!\033[0m\n");
            printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
        }
    } else {
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
        printf("\t\t\t\033[1;33m===================- CLIENTE NÃO ENCONTRADO -===================!\033[0m\n");
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
    }
}

void listarAgendaVisitas() {
    if (totalagendas > 0) {
        for (int i = 0; i < totalagendas; i++) {         
            printf("\033[1;36m\tAGENDA DE VISITA %d:\033[0m\n\n", i + 1);
            printf("\033[1;36m\t\tCPF DO CLIENTE: \033[0m%s\n", AgendaVisitas[i].CPF);
            printf("\033[1;36m\t\tDATA DA VISITA: \033[0m%s\n", AgendaVisitas[i].data);
            printf("\033[1;36m\t\tHORÁRIO DA VISITA: \033[0m%s\n", AgendaVisitas[i].horario);
            printf("\n");
        }
    } else {
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
        printf("\t\t\t\033[1;33m===============- AGENDA DE VISITA NÃO CRIADA -================!\033[0m\n");
        printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n");
    }
}

void avaliacaocliente(){
	int nota;
	salvarDados();
	printf("\t\t\t\033[1;33m==============================================================\033[0m\n");
    printf("\t\t\t\033[1;33m==================- AVALIAÇÃO DO CLIENTE -====================!\033[0m\n");
    printf("\t\t\t\033[1;33m==============================================================\033[0m\n\n\n\n");
    
    printf("\t\t\t\t=====- OLÁ QUERIDO CLIENTE, EM PESQUISA DE AVALIAÇÃO VOCÊ PODERIA INSERIR UMA NOTA DE 1 A 10 DE AVALIAÇÃO -=======\n");
    sleep(3);
    printf("\n\t\t\tCARREGANDO...\n\n\n\n");
    
    printf("\t\t\t====- INSIRA SUA NOTA AQUI -=====: ");
    scanf("%d", &nota);
    
    if(nota >= 7)
    	printf("\t\t\t\t\t\n\n\n============- AGRADECEMOS A PREFERENCIA, MUITO OBRIGADO PRO CONTAR COM O NOSSO SERVIÇO -===============\n\n\n");
    else
	   printf("\t\t\t\t\t\n\n\n==============- DESCULPA, IREMOS FAZER O MAXIMO PARA QUE NO PROXIMO CADASTRO SEJA MELHOR!! -====================\n\n\n\n");	
	   
	return;
}




