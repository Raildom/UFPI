ordena(Lista, Ordenada, Menor, Maior) :-
    sort(Lista, Ordenada),
    [Menor|_] = Ordenada, reverso(Ordenada, [Maior|_]).