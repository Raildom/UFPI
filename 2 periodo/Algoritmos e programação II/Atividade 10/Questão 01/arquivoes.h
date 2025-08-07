typedef struct{
	int chave;
	char nome[30];
	char endereco[50];
	char telefone[14];
}Alunos;

int salvarDados(Alunos *turma, char *nomeArquivo);
int restaurarDados(char *nomeArquivo, Alunos *turma);