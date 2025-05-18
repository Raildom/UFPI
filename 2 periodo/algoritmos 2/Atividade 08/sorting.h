typedef struct{
	int chave;
	char nome[30];
	char endereco[50];
	char telefone[14];
}Alunos;

void gerarDados(Alunos v[], int n, int ordemChave);
void bolha(Alunos v[], int n);
void selecao(Alunos v[], int n);
void insercao(Alunos v[], int n);