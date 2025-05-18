intersec([], _, []).
intersec([X|Rest1], L2, [X|Rest2]) :- 
    membro(X, L2), intersec(Rest1, L2, Rest2).

intersec([_|Rest1], L2, Rest2) :- 
    intersec(Rest1, L2, Rest2).