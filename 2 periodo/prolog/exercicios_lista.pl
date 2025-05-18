% aluno(joao, calculo).
% aluno(maria, calculo).
% aluno(joel, programacao).
% aluno(joel, estrutura).

% frequenta(joao, puc).
% frequenta(maria, puc).
% frequenta(joel, ufrj).

% professor(carlos, calculo).
% professor(ana_paula, estrutura).
% professor(pedro, programacao).

% funcionario(pedro, ufrj).
% funcionario(ana_paula, puc).
% funcionario(carlos, puc).

% alunos(Y, X) :-
%     aluno(Y, Disciplina), frequenta(Y, Instituicao), funcionario(X, Instituicao), professor(X, Disciplina).

% associado(X, Y) :-
%     frequenta(X, Y); funcionario(X, Y).





% tipo_sanguineo(a).
% tipo_sanguineo(b).
% tipo_sanguineo(ab).
% tipo_sanguineo(o).

% doa(a, a).
% doa(a, ab).
% doa(b, b).
% doa(b, ab).
% doa(ab, ab).
% doa(o, a).
% doa(o, b).
% doa(o, ab).
% doa(o, o).

% recebe(a, a).
% recebe(a, o).
% recebe(b, b).
% recebe(b, o).
% recebe(ab, a).
% recebe(ab, b).
% recebe(ab, ab).
% recebe(ab, o).
% recebe(o, o).



% maiorquecem(Numero) :-
%     write('Digite um numero: '),
%     read(Numero),
%     (
%         (Numero > 100, write('E maior que 100!'));
%         (Numero =< 100, write('Menor ou igual a 100!'))
%     ).

% nota(joao, 5.0).
% nota(mariana, 9.0).
% nota(joaquim, 4.5).
% nota(maria, 6.0).
% nota(cleuza, 8.5).
% nota(mara, 4.0).
% nota(joana, 8.0).
% nota(jose, 6.5).
% nota(mary, 10.0).

% situacao(X) :-
%     nota(X, Nota),
%     (
%         (Nota >= 7.0, Nota =< 10.0, write('Aprovado.'));
%         (Nota >= 5.0, Nota =< 6.9, write('Recuperacao.'));
%         (Nota >= 0.0, Nota =< 4.9, write('Reprovado.'))
%     ).















% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Atividade de monitoria %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% impar_par(X) :-
%     (
%         (X mod 2 =:= 0, X =\= 0, write(X), write(' e par.'));
%         (X mod 2 =\= 0, X =\= 0, write(X), write(' e impar.'));
%         (X = 0, write('E nulo'))
%     ).

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% intervalo(X, X) :- !. 
% intervalo(X, Y) :-
%     X < Y - 1,
%     X2 is X + 1,
%     writeln(X2), 
%     intervalo(X2, Y).

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% intervalo_divisor(X, X) :- !. 
% intervalo_divisor(X, Y) :-
%     X2 is X + 1,
%     (
%         (0 is Y mod X) -> 
%         writeln(X), 
%         intervalo_divisor(X2, Y)
%         ; 
%         intervalo_divisor(X2, Y)
%     ).

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% fatorial(0, 1) :- !.
% fatorial(X, Y) :-
%     X2 is X - 1,
%     fatorial(X2, Y2),
%     Y is X * Y2.

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

nota(joao, 5.0).
nota(maria, 6.0).
nota(junior, 2.0).
nota(joana, 8.0).
nota(mariana, 9.0).
nota(joaquim, 4.5).
nota(cleuza, 8.5).
nota(mara, 4.0).
nota(jose, 6.5).
nota(mary, 10.0).
nota(lima, 3.5).

situacao() :-
    nota(X, NOTA),
    (
        (NOTA >= 7, write(X), write(' esta aprovado(a)'));
        (NOTA >= 4, NOTA < 7, write(X), write(' esta de recuperacao'));
        (NOTA < 4, write(X), write(' esta reprovado(a)'))
    ).
reprovados :-
    nota(X, NOTA),
    NOTA < 4, write(X).
recuperacao :-
    nota(X, NOTA),
    NOTA >= 4, NOTA < 7, write(X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ligacao(1, 2).
ligacao(1, 3).
ligacao(2, 4).
ligacao(3, 4).
ligacao(3,6).
ligacao(4, 6).
ligacao(5,6).

caminhos(X, Y) :- ligacao(X, Y), write(Y), ! ; ligacao(Y, X), write(Y), !.
caminhos(X, Y) :-
    ligacao(X,Z),
    write(Z), write(' -> '),
    caminhos(Z, Y), !.
caminho(X, Y) :- write(X), write(' -> '), caminhos(X, Y).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%