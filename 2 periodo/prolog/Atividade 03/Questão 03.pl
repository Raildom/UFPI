inverte([], []).
inverte([X|Rest], Invertida) :- 
    inverte(Rest, RestInvertida), append(RestInvertida, [X], Invertida).