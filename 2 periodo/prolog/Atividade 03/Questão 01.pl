% Letra A
adiciona(X, L1, L2) :- 
    append(L1, [X], L2).

%Letra B
apaga(_, [], []).
apaga(X, [X | T], T).
apaga(X, [H | T], [H | R]) :- 
    apaga(X, T, R).

%Letra C
membro(X, [X | _]).
membro(X, [_ | T]) :- 
    membro(X, T).

%Letra D
concatena([], L, L).
concatena([H | T], L, [H | R]) :- 
    concatena(T, L, R).


%Letra E
tamanho([], 0).
tamanho([_ | T], N) :- 
    tamanho(T, N1), N is N1 + 1.
