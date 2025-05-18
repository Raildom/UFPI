situacao :-
    write('Digite a primeira nota: '),
    read(NOTA1),
    write('Digite a segunda nota: '),
    read(NOTA2),
    write('Digite a terceira nota: '),
    read(NOTA3),
    MEDIA is (NOTA1 + NOTA2 + NOTA3) / 3,
    (
        (MEDIA >= 7, write('Aprovado'));
        (MEDIA < 7, MEDIA >= 4, write('Exame final'));
    (MEDIA < 4, write('Reprovado'))
    ).