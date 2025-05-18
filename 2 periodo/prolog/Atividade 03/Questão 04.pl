elementosIguais([], _, []).
elementosIguais([X|Rest1], L2, [X|Rest2]) :- 
    member(X, L2), elementosIguais(Rest1, L2, Rest2).

elementosIguais([_|Rest1], L2, Rest2) :- 
    elementosIguais(Rest1, L2, Rest2).