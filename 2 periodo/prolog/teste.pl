% % progenitor(paulo, maria).
% % progenitor(paulo, gabriel).
% % progenitor(pedro, joao).
% % progenitor(maria, jose).
% % progenitor(joao, jose).
% % progenitor(joao, ana).
% % progenitor(jose, julia).
% % progenitor(jose, iris).
% % progenitor(iris, jorge).


% % sexo(jose, masculino).
% % sexo(joao, masculino).
% % sexo(jorge, masculino).
% % sexo(pedro, masculino).
% % sexo(paulo, masculino).
% % sexo(gabriel, masculino).
% % sexo(ana, feminino).
% % sexo(maria, feminino).
% % sexo(julia, feminino).
% % sexo(iris, feminino).

% % casado(joao, maria).
% % casado(maria, joao).

% % pai(X, Y) :-
% %     progenitor(X, Y), sexo(X, masculino).

% % mae(X, Y) :-
% %     progenitor(X, Y), sexo(X, feminino).

% % filho(X, Y) :-
% %     progenitor(Y, X), sexo(X, masculino).

% % filha(X, Y) :-
% %     progenitor(Y, X), sexo(X, feminino).

% % irmao(X, Y) :-
% %     sexo(X, masculino), progenitor(Z, X), progenitor(Z, Y), X \= Y.

% % irma(X, Y) :-
% %     sexo(X, feminino), progenitor(Z, X), progenitor(Z, Y), X \= Y.

% % avom(Z, Y) :-
% %     sexo(Z, masculino), progenitor(Z, X), progenitor(X, Y).

% % avof(Z, Y) :-
% %     sexo(Z, feminino), progenitor(Z, X), progenitor(X, Y).

% % tio(X, Y) :-
% %     irmao(X, Z), progenitor(Z, Y).

% % tia(X, Y) :-
% %     irma(X, Z), progenitor(Z, Y).

% % bisavom(X, Y) :-
% %     sexo(X, masculino), progenitor(X, Z), progenitor(Z, A), progenitor(A, Y).

% % bisavof(X, Y) :-
% %     sexo(X, feminino), progenitor(X, Z), progenitor(Z, A), progenitor(A, Y).

% % cunhado(X, Y):-
% %     sexo(X, masculino), casado(X, Z), (irma(Z, Y); irmao(Z, Y)).

% % cunhada(X, Y):-
% %     sexo(X, feminino), casado(X, Z), (irma(Z, Y); irmao(Z, Y)).


% % sogra(X, Y):-
% %     mae(X, Z), casado(Z, Y).

% % sogro(X, Y):-
% %     pai(X, Z), casado(Z, Y).
    




% % fatorial(0, 1) :- !.
% %     fatorial(X, Y) :- 
% %     X2 is X - 1, 
% %     fatorial(X2, Y2), 
% %     Y is X * Y2.


% % imparPar(N) :-
% %     N mod 2 =:= 0,
% %     write(N), write(' e par').

% % imparPar(N) :-
% %     N mod 2 =\= 0,
% %     write(N), write(' e impar').


% % verificaIdade:-
% %     write('digite sua idade '),
% %     read(Idade),
% %     Idade >= 18, write('maior de idade!').

% % lerNome:-
% %     write('digite seu nome: '),
% %     read(Nome),
% %     write(Nome), write("ABC").

% % f(1, um).
% % f(s(1), dois).
% % f((s(s(1))), tres).
% % f(s(s(s(X))), N):-
% %     f(X, N).


% % primo(X, Y) :-
% %     progenitor(Z, X), progenitor(W, Y), irmao(Z, W), Z \= W.












% % :- op(500, xfy, ++).
% % A ++ B :-
% %     atom_concat(A, B, Resultado), 
% %     write(Resultado).

% % :- op(500, xfx, igual).
% % A igual B :-
% %     A = B.


% % Definindo as equipes
% equipe(vermelha).
% equipe(verde).
% equipe(azul).
% equipe(branco).
% equipe(fenix).
% equipe(tratores).
% equipe(peraltas).
% equipe('14Biz').

% % Definindo os capitães e suas respectivas equipes
% capitao_equipe(oscar, fenix).
% capitao_equipe(juliano, tratores).
% capitao_equipe(marcio, '14Biz').
% capitao_equipe(carlos, verde).

% % Definindo as pontuações
% pontuacao(vermelha, 390).
% pontuacao(verde, 410).
% pontuacao(azul, 380).
% pontuacao(branco, 400).
% pontuacao(fenix, 370).
% pontuacao(tratores, 360).
% pontuacao(peraltas, 350).
% pontuacao('14Biz', 340).

% % Definindo as idades dos capitães
% idade(oscar, 25).
% idade(juliano, 28).
% idade(marcio, 26).
% idade(carlos, 24).

% % Definindo strikes feitos por cada equipe
% strikes(vermelha, 15).
% strikes(verde, 18).
% strikes(azul, 12).
% strikes(branco, 14).
% strikes(fenix, 10).
% strikes(tratores, 9).
% strikes(peraltas, 11).
% strikes('14Biz', 8).

% % Definindo cores dos uniformes
% uniforme(vermelha, vermelho).
% uniforme(verde, verde).
% uniforme(azul, azul).
% uniforme(branco, branco).
% uniforme(fenix, amarelo).
% uniforme(tratores, laranja).
% uniforme(peraltas, roxo).
% uniforme('14Biz', preto).

% % Consulta a: Qual a equipe que fez mais strikes?
% mais_strikes(Equipe) :-
%     strikes(Equipe, Strikes),
%     \+ (strikes(_, S), S > Strikes).

% % Consulta b: Artur é capitão de que equipe?
% capitao_artur(Equipe) :-
%     capitao_equipe(artur, Equipe).

% % Consulta c: Qual a pontuação da equipe de uniforme amarelo?
% pontuacao_uniforme_amarelo(Pontuacao) :-
%     uniforme(Equipe, amarelo),
%     pontuacao(Equipe, Pontuacao).

% % Consulta d: Qual a equipe com maior idade do capitão?
% maior_idade_capitao(Equipe) :-
%     capitao_equipe(Capitao, Equipe),
%     idade(Capitao, Idade),
%     \+ (capitao_equipe(C, _), idade(C, I), I > Idade).

% % Consulta e: Qual o nome do capitão da equipe que tem 24 anos?
% capitao_idade_24(Capitao) :-
%     capitao_equipe(Capitao, _),
%     idade(Capitao, 24).

% % Exemplo de consultas
% % ?- mais_strikes(Equipe).
% % ?- capitao_artur(Equipe).
% % ?- pontuacao_uniforme_amarelo(Pontuacao).
% % ?- maior_idade_capitao(Equipe).
% % ?- capitao_idade_24(Capitao).

