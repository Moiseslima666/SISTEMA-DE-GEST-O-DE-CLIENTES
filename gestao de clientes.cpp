#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

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
	Endereco endereco;
};


