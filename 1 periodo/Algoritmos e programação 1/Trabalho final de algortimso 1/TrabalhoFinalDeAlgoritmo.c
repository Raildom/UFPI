//Bibliotecas utilizadas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Comando que permite ao programador dar um nome a um valor constante antes de o programa ser compilado.
#define tamanho 50

//Variáveis globais.
//As variáveis "nome" e "FormaDePagamento" são matrizes usadas para guardar valores do tipo string.
char nome[tamanho][tamanho], FormaDePagamento[tamanho][tamanho];
//As variáveis "valor" e "NumeroDoQuarto" são vetores utilizados para guardar valores do tipo inteiro.
//As variáveis "opcao" e "opcao2" são usadas para fazer escolhas no código.
//A variável "i" é usada como contador.
//A variável "auxiliar" é a raiz do código, sendo usada para contar a quantidade de cadastros entre outras coisas.
int NumeroDoQuarto[tamanho], opcao, auxiliar = 0, i = 0, opcao2;
float valor[tamanho];
//Função utilizada para realizar cadastros.
void cadastro() { //Inicio da função cadastro.
    printf("==================== CADASTRO ====================\n");
    //Solicita o nome a ser cadastrado.
    printf("|Digite o nome: ");
    //Salva o nome informado pelo usuário na matriz "nome".
    scanf(" %[^\n]s", nome[auxiliar]);
    fflush(stdin); //Comando usado para limpar o Buffer.

    //Solicita a forma de pagamento a ser cadastrada.
    printf("|Digite a forma de pagamento: ");
    //Salva a forma de pagamento informada pelo usuário na matriz "FormaDePagamento".
    scanf(" %[^\n]s", FormaDePagamento[auxiliar]);
    fflush(stdin); //Comando usado para limpar o Buffer.

    //Solicita o valor a ser cadastrada.
    printf("|Digite o valor: R$");
    //Salva o valor informado pelo usuário no vetor "valor".
    scanf("%f", &valor[auxiliar]);

    //Solicita o número do quarto a ser cadastrado.
    printf("|Digite o numero do quarto: ");
    //Salva o número do quarto no vetor "NumeroDoQuarto".
    scanf("%d", &NumeroDoQuarto[auxiliar]);

    system("cls"); //Função "System("cls")" utilizada para limpar o terminal.

    printf("==================== CADASTRO ====================");
    //Printf utilizado para mostrar as informaões cadastradas.
    printf("\n|Nome: %s\n|Forma de pagamento: %s\n|Numero do quarto: %d\n|Valor: R$%.2f\n|\n", nome[auxiliar], FormaDePagamento[auxiliar], NumeroDoQuarto[auxiliar], valor[auxiliar]);
    //Printf uilizado para avisar que o cadastro foi finalizado com sucesso.
    printf("|Cadastro realizado com sucesso!\n\n");
    //Função utilizado para dar uma pausa até que o usuário confirme.
    system("pause");

    i++; //Incremento da variável "i".
    auxiliar++; //Incremento da variável "auxiliar".

    system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
} //Fim da Função cadastro.

//Função utilizada para exibir todos os dados salvos.
void ListarTodos() { //Inicio da função ListarTodos.
    //For utilizado para percorrer as posições dos vetores e matrizes.
    for (int j = 0; j < auxiliar; j++) { //Inicio do for.
        printf("\n==================== INFORMACOES ====================");
        //printf utilizado para imprimir todos os dados.
        printf("\n|Nome: %s\n|Forma de pagamento: %s\n|Numero do quarto: %d\n|Valor: R$%.2f\n\n", nome[j], FormaDePagamento[j], NumeroDoQuarto[j], valor[j]);
    } //fim do for.
    system("pause"); //Função utilizado para dar uma pausa até que o usuário confirme.
} //fim da função ListarTodos.

//função utilizada para buscar um único objeto.
void busca() { //inicio da função busca.
    //a variável "BuscaQuarto" é utilizada para confirmar se existe um cliente no quarto informado.
    int BuscaQuarto;

    printf("\n==================== BUSCA UNICA ====================");
    //solicita o número do quarto.
    printf("\n|Digite o numero do quarto: ");
    //salva o número do quarto na variável "BuscaQuarto".
    scanf("%d", &BuscaQuarto);
    fflush(stdin); //Comando usado para limpar o Buffer.

    //for utilizado para percorrer as posições dos vetores e matrizes.
    for (i = 0; i < auxiliar; i++) { //inicio do for.
        //se existir um cliente no quarto informado, o programa entrará no if.
        if (NumeroDoQuarto[i] == BuscaQuarto) { //inicio do if.
            //printf utilizado para imprimir todos os dados do quarto informado.
            printf("|\n|Nome: %s\n|Forma de pagamento: %s\n|Numero do quarto: %d\n|Valor: R$%.2f\n\n", nome[i], FormaDePagamento[i], NumeroDoQuarto[i], valor[i]);
            //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
            break; 
        } //fim do if.
    } //fim do for.
    //se a variável "i" for igual a variável "auxilixar", ou seja, se o for percorrer todas as posições e não encontrar uma igual ao solicitado, o programa entrará no if.
    if (i == auxiliar) { // inicio do if.
        //caso o programa entre no if, será imprimido a mensagem "objeto nao encontrado".
        printf("|\n|Objeto nao encontrado!\n\n");
    } //fim do if.
    system("pause"); //Função utilizado para dar uma pausa até que o usuário confirme.
    system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
} // fim da função Busca.

//função utilizada para alterar atributos, EX: nome e forma de pagamento.
void AlterarAtributos() { //inicio da função AlterarAtributos.
    //a variável "BuscaQuarto" é utilizada para confirmar se existe um cliente no quarto informado.
    int BuscaQuarto;

    printf("\n==================== ALTERAR ====================");
    //solicita o número do quarto.
    printf("\n|Digite o numero do quarto: ");
    //salva o número do quarto na variável "BuscaQuarto".
    scanf("%d", &BuscaQuarto);
    fflush(stdin); //Comando usado para limpar o Buffer.
    system("cls"); //Função "System("cls")" utilizada para limpar o terminal.

    //for utilizado para percorrer as posições dos vetores e matrizes.
    for (i = 0; i < auxiliar; i++) { //inicio do for.
        //se existir um cliente no quarto informado, o programa entrará no if.
        if (NumeroDoQuarto[i] == BuscaQuarto) { //inicio do if.
            //imprime um menu com as opções que podem ser alteradas e a opção de sair do menu.
            printf("========================================\n");
            printf("| [1] - Nome \n");
            printf("| [2] - Forma de pagamento   \n");
            printf("| [3] - Valor    \n");
            printf("| [0] - Sair              \n");
            //pergunta qual atributo que irá ser alterado.
            printf("\n|Qual atributo deseja alterar? ");
            //salva os dados recebido na variável "opcao2".
            scanf("%d", &opcao2);
            fflush(stdin); //Comando usado para limpar o Buffer.
            system("cls"); //Função "System("cls")" utilizada para limpar o terminal.

            //função switch case utilizada para alterar o atributo informado.
            switch (opcao2) { //inicio do switch case.
                case 1: //caso o usuário digite 1 o atributo "nome" será alterado.
                    //mostra o nome atual.
                    printf("\n|Nome atual: %s", nome[i]);
                    //solicita o novo nome.
                    printf("\n|Digite o novo nome: ");
                    //salva o novo nome na matriz nome.
                    scanf(" %[^\n]", nome[i]);
                    fflush(stdin); //Comando usado para limpar o Buffer.
                    break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
                case 2: //caso o usuário digite 2 o atributo "FormaDePagamento" será alterado.
                    //mostra a forma de pagamento atual.
                    printf("\n|Forma de Pagamento atual: %s", FormaDePagamento[i]);
                    //solicita a nova forma de pagamento.
                    printf("\n|Digite a nova forma de pagamento: ");
                    //salva a nova forma de pagamento na matriz FormaDePagamento.
                    scanf(" %[^\n]", FormaDePagamento[i]);
                    fflush(stdin); //Comando usado para limpar o Buffer.
                    break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
                case 3: //caso o usuário digite 3 o atributo "Valor" será alterado.
                    //mostra o valor atual.
                    printf("\n|Valor atual: R$%.2f", valor[i]);
                    //solicita o novo valor.
                    printf("\n|Digite o novo valor: R$");
                    //salva o novo valor no vetor valor.
                    scanf("%f", &valor[i]);
                    fflush(stdin); //Comando usado para limpar o Buffer.
                    break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
                case 0: //caso o usuário digite 0 o programa sairá do menu de alterar atributos.
                    break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
                default: //caso o usuário digite uma opção não listada acima será imprimido uma mensagem de erro.
                    printf("|Objeto nao encontrado!\n\n");
            } //fim do switch case.
            break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
        } //fim do if.
    } // fim do for.
    //se a variável "i" for igual a variável "auxilixar", ou seja, se o for percorrer todas as posições e não encontrar uma igual ao solicitado, o programa entrará no if.
    if (i == auxiliar) {
        //caso o programa entre no if, será imprimido a mensagem "objeto nao encontrado".
        printf("|Objeto nao encontrado!\n\n");
    } //fim do if.
    printf("\n"); //comando utilizado para pular uma linha.
    system("pause"); //Função utilizado para dar uma pausa até que o usuário confirme.
    system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
} //fim da função AlterarAtributos.

//função utilizada para remover objetos cadastrados.
void remover(){ //inicio da função remover.
    //a variável "BuscaQuarto" será utilizada para confirmar se existe um cliente no quarto infromado.
    //A variável "i" e "j" serão utilizadas como contador.
    int BuscaQuarto, i, j;

    //a variável "BuscaQuarto" recebe um valor digitado pelo usuário para verificar se há clientes no quarto informado.
    printf("\n==================== REMOVER ====================");
    //solicita o número do quarto.
    printf("\n|Digite o numero do quarto: ");
    //salva o número do quarto na variável "BuscaQuarto".
    scanf("%d", &BuscaQuarto);
    fflush(stdin); //Comando usado para limpar o Buffer.

    //inicio do for utilizado para encontrar a posição no qual o quarto informado está.
    for(i = 0; i < auxiliar; i++){ //inicio do primeiro for.
        //se existir um cliente no quarto informado, o programa entrará no if.
        if(NumeroDoQuarto[i] == BuscaQuarto){
            //for utilizado para percorrer as posições dos vetores e matrizes.
            for(j = i; j < auxiliar - 1; j++){ //inicio do segundo for.
                //função utilizada para colocar valores das posições seguintes nas antecessoras. EX um valor na posição 2 vai para a posição 1.
                strcpy(nome[j], nome[j+1]); 
                strcpy(FormaDePagamento[j],FormaDePagamento[j+1]);
                valor[j] = valor[j + 1];
                NumeroDoQuarto[j] = NumeroDoQuarto[j+1];
            } //fim do segundo for.
        } //fim do if.
    } //fim do primeiro for.

    printf("\n"); //comando utilizado para pular uma linha.
    system("pause"); //Função utilizado para dar uma pausa até que o usuário confirme.
    system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
    auxiliar--;
} //fim da função remover.

//função principal.
int main() { //inicio da função principal.
    //do while utilizado para repetir as linhas de código até que seja digitado 0.
    do { //inicio do "do while".
        system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
        //printf utilizado para imprimir o menu principal.
        printf("===================== Hotel R.R.S ======================");
        printf("\n==================== Menu principal ====================\n| [1] - Cadastrar cliente \n| [2] - Listar clientes   \n| [3] - Buscar cliente    \n| [4] - Alterar atributo  \n| [5] - Remover cliente   \n| [0] - Sair  \n");
        //pergunta qual opção será utilizada.
        printf("\n|Selecione a opcao desejada: ");
        //salva a opção digitada pelo usuário na variável opcao.
        scanf("%d", &opcao);
        //função switch case utilizada para escolher entre as opções demostradas.
        switch (opcao) { //inicio do switch case.
            case 1: //caso o usuário digite 1, será puxado a função cadastro.
                system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
                cadastro();
                break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
            case 2: //caso o usuário digite 2, será puxado a função ListarTodos.
                system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
                ListarTodos();
                break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
            case 3: //caso o usuário digite 3, será puxado a função busca.
                system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
                busca();
                break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
            case 4: //caso o usuário digite 4, será puxado a função AlterarAtributos.
                system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
                AlterarAtributos();
                break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
            case 5: //caso o usuário digite 1, será puxado a função remover.
                system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
                remover();
                break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
            case 0: //caso o usuário digite 0, o programa será encerrado.
                system("cls"); //Função "System("cls")" utilizada para limpar o terminal.
                printf("|Saindo...\n\n");
                system("pause"); //Função utilizado para dar uma pausa até que o usuário confirme.
                break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
            default:
                printf("|\n|Opcao invalida!\n\n");
                system("pause"); //Função utilizado para dar uma pausa até que o usuário confirme.
                break; //comando utilizado para encerrar a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
        } //fim do switch case.
    } while (opcao != 0); //fim do "do while".

    return 0; //a função principal irá retornar 0.
} //fim da função principal.