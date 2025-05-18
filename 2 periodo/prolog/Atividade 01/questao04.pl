progenitor(paulo, maria).
progenitor(paulo, gabriel).
progenitor(pedro, joao).
progenitor(maria, jose).
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, julia).
progenitor(jose, iris).
progenitor(iris, jorge).


sexo(jose, masculino).
sexo(joao, masculino).
sexo(jorge, masculino).
sexo(pedro, masculino).
sexo(paulo, masculino).
sexo(gabriel, masculino).
sexo(ana, feminino).
sexo(maria, feminino).
sexo(julia, feminino).
sexo(iris, feminino).

casado(joao, maria).
casado(maria, joao).

pai(X, Y) :-
    progenitor(X, Y), sexo(X, masculino).

mae(X, Y) :-
    progenitor(X, Y), sexo(X, feminino).

filho(X, Y) :-
    progenitor(Y, X), sexo(X, masculino).

filha(X, Y) :-
    progenitor(Y, X), sexo(X, feminino).

irmao(X, Y) :-
    sexo(X, masculino), progenitor(Z, X), progenitor(Z, Y), X \= Y.

irma(X, Y) :-
    sexo(X, feminino), progenitor(Z, X), progenitor(Z, Y), X \= Y.

avom(Z, Y) :-
    sexo(Z, masculino), progenitor(Z, X), progenitor(X, Y).

avof(Z, Y) :-
    sexo(Z, feminino), progenitor(Z, X), progenitor(X, Y).

tio(X, Y) :-
    irmao(X, Z), progenitor(Z, Y).

tia(X, Y) :-
    irma(X, Z), progenitor(Z, Y).

bisavom(X, Y) :-
    sexo(X, masculino), progenitor(X, Z), progenitor(Z, A), progenitor(A, Y).

bisavof(X, Y) :-
    sexo(X, feminino), progenitor(X, Z), progenitor(Z, A), progenitor(A, Y).

cunhado(X, Y):-
    sexo(X, masculino), casado(X, Z), (irma(Z, Y); irmao(Z, Y)).

cunhada(X, Y):-
    sexo(X, feminino), casado(X, Z), (irma(Z, Y); irmao(Z, Y)).




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% questão 04 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
sogra(X, Y):-
    mae(X, Z), casado(Z, Y).

sogro(X, Y):-
    pai(X, Z), casado(Z, Y).
    
