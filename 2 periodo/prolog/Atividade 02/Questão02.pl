lado(retangulo, sim).
lado(quadrado, sim).
lado(circulo, nao).

todos_os_lados_iguais(retangulo, nao).
todos_os_lados_iguais(quadrado, sim).
todos_os_lados_iguais(circulo, nao).

vertice(retangulo, sim).
vertice(quadrado, sim).
vertice(circulo, nao).


forma_geometrica(Forma) :-
    write('A forma possui lados? '),
    read(LADO),
    write('A forma possui quatro lados iguais? '),
    read(LADOS),
    write('A forma possui vertices? '),
    read(VERTICE),
    lado(Forma, LADO),
    todos_os_lados_iguais(Forma, LADOS),
    vertice(Forma, VERTICE).