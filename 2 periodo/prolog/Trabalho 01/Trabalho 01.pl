% NOME         LINHA        VISITA     PROFISSAO      SIGNO       COMIDAS
m(beatriz,     amarela,     filha,     arquiteta,     touro,      frango).
m(rosana,      azul,        mae,       economista,    gemeos,     peixe).
m(joice,       branca,      tia,       tradutora,     sargitario, macarrao).
m(alessandra,  verde,       avo,       policial,      leao,       pizza).
m(luiza,       vermelho,    sobrinha,  nutricionista, escorpiao,  sopa).

profissao(Nome, Profissao):-
    m(Nome, _, _, Profissao, _, _).

visitar(Nome, Visita):-
    m(Nome, _, Visita, _, _, _).

linha(Nome, Linha):-
    m(Nome, Linha, _, _, _, _).

signo(Nome, Signo):-
    m(Nome, _, _, _, Signo, _).

comida(Signo, Gosta):-
    m(_, _, _, _, Signo, Gosta).