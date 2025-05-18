:- dynamic paciente/2.
% paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico).
paciente([maria, feminino, 37, nao, nao, passado, 30.5, 5.7, 100], nao).
paciente([gorete, feminino, 53, nao, nao, passado, 26.37, 4.5, 112], nao).
paciente([pedro, masculino, 54, nao, nao, nunca, 31.86, 6.6, 145], nao).
paciente([juliana, feminino, 37, nao, nao, passado, 21.25, 6.1, 200], nao).
paciente([catisvalda, feminino, 56, nao, nao, nunca, 30.95, 6.5, 145], nao).
paciente([ursulino, masculino, 79, nao, nao, passado, 31.19, 5.8, 155], nao).
paciente([jose, masculino, 67, nao, nao, sim, 27.32, 6.8, 220], sim).
paciente([marta, feminino, 74, nao, nao, sim, 29.51, 8.2, 240], sim).
paciente([jussara, feminino, 37, nao, nao, passado, 36.87, 8.8, 160], sim).
paciente([katia, feminino, 65, sim, sim, nunca, 33.55, 8.9, 202], sim).
paciente([marcelo, masculino, 55, nao, sim, passado, 30.42, 6.2, 300], sim).
paciente([ayla, feminino, 61, nao, nao, passado, 34.45, 6.5, 280], sim).
paciente([rafaela, feminino, 58, sim, nao, nunca, 38.31, 7.0, 200], sim).
paciente([cassia, feminino, 61, nao, nao, sim, 30.11, 6.2, 240], sim).
paciente([elisa, feminino, 26, nao, nao, passado, 27.32, 4.0, 200], nao).
paciente([alice, feminino, 74, nao, nao, passado, 28.12, 5.0, 100], nao).
paciente([jade, feminino, 45, sim, nao, nunca, 23.05, 4.8, 130], nao).
paciente([heloise, masculino, 56, nao, nao, nunca, 26.78, 4.8, 200], nao).
paciente([benicio, masculino, 20, nao, nao, passado, 23.04, 5.7, 160], nao).
paciente([paulo, masculino, 70, nao, nao, passado, 15.94, 5.8, 158], nao).
paciente([otavio, masculino, 30, nao, nao, passado, 15.8, 6.2, 90], nao).
paciente([isis, feminino, 80, nao, nao, nunca, 22.04, 9.0, 209], sim).
paciente([francivaldo, masculino, 63, nao, sim, passado, 27.32, 6.6, 300], sim).
paciente([juvelino, masculino, 58, nao, nao, passado, 32.38, 6.6, 159], sim).
paciente([maya, feminino, 43, sim, nao, nunca, 34.21, 9.0, 160], sim).
paciente([genetildes, masculino, 56, nao, nao, nunca, 37.59, 4.0, 159], nao).
paciente([waldisney, masculino, 60, nao, nao, passado, 25.4, 4.0, 200], nao).
paciente([reinaldo, masculino, 27, nao, nao, passado, 27.32, 3.5, 100], nao).
paciente([frederico, masculino, 54, nao, nao, passado, 30.41, 5.0, 158], nao).

diagnosticar_diabetes([_, _, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico) :-
    
    (var(Idade); var(Hipertensao); var(Cardiaco); var(Fumante); var(IMC); var(Hemoglobina); var(Glicose)),
    Diagnostico = 'Falta fazer exames', !.
diagnosticar_diabetes([Nome, _, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico) :-
    calcular_pontuacao(IMC, Hemoglobina, Idade, Fumante, Hipertensao, Cardiaco, Glicose, Pontuacao),
    diagnosticar_com_base_na_pontuacao(Pontuacao, Diagnostico),
    (   paciente([Nome|_], _)
    ->  true
    ;   format('Paciente ~w nao esta cadastrado. Deseja adiciona-lo? (sim/nao): ', [Nome]),
        read(Resposta),
        (   Resposta == sim
        ->  assertz(paciente([Nome, _, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico)),
            write('Paciente adicionado com sucesso.'), nl
        ;   write('Paciente nao adicionado.'), nl
        )
    ).

diagnosticar_diabetes2([_, _, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico) :-
    (var(Idade); var(Hipertensao); var(Cardiaco); var(Fumante); var(IMC); var(Hemoglobina); var(Glicose)),
    Diagnostico = 'Falta fazer exames', !.
diagnosticar_diabetes2([_, _, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico) :-
    calcular_pontuacao(IMC, Hemoglobina, Idade, Fumante, Hipertensao, Cardiaco, Glicose, Pontuacao),
    diagnosticar_com_base_na_pontuacao(Pontuacao, Diagnostico).

calcular_pontuacao(IMC, Hemoglobina, Idade, Fumante, Hipertensao, Cardiaco, Glicose, Pontuacao) :-
    pontuacao_imc(IMC, PontuacaoIMC),
    pontuacao_hemoglobina(Hemoglobina, PontuacaoHemoglobina),
    pontuacao_idade(Idade, PontuacaoIdade),
    pontuacao_fumante(Fumante, PontuacaoFumante),
    pontuacao_hipertensao(Hipertensao, PontuacaoHipertensao),
    pontuacao_cardiaco(Cardiaco, PontuacaoCardiaco),
    pontuacao_glicose(Glicose, PontuacaoGlicose),
    Pontuacao is (PontuacaoIMC + PontuacaoHemoglobina + PontuacaoIdade + PontuacaoFumante + PontuacaoHipertensao + PontuacaoCardiaco + PontuacaoGlicose) / 7.

pontuacao_imc(IMC, 1) :- IMC > 30, !.
pontuacao_imc(_, 0).

pontuacao_hemoglobina(Hemoglobina, 1) :- Hemoglobina > 7.0, !.
pontuacao_hemoglobina(_, 0).

pontuacao_idade(Idade, 1) :- Idade > 50, !.
pontuacao_idade(_, 0).

pontuacao_fumante(sim, 1) :- !.
pontuacao_fumante(_, 0).

pontuacao_hipertensao(sim, 1) :- !.
pontuacao_hipertensao(_, 0).

pontuacao_cardiaco(sim, 1) :- !.
pontuacao_cardiaco(_, 0).

pontuacao_glicose(Glicose, 1) :- Glicose > 200, !.
pontuacao_glicose(_, 0).

diagnosticar_com_base_na_pontuacao(Pontuacao, sim) :-
    Pontuacao >= 0.4, !.
diagnosticar_com_base_na_pontuacao(_, nao).

adicionar_paciente([Nome|Resto], Diagnostico) :-
    \+ paciente([Nome|_], _),
    diagnosticar_diabetes2([Nome|Resto], Diagnostico),
    assertz(paciente([Nome|Resto], Diagnostico)),
    write('Paciente adicionado com sucesso.'), nl, !.
adicionar_paciente([Nome|_], _) :-
    paciente([Nome|_], _),
    write('Paciente com este nome ja existe.'), nl, !.
adicionar_paciente(_, _) :-
    write('Falta fazer exames.'), nl, !.

editar_paciente([Nome|AntigasCaracteristicas], [Nome|NovasCaracteristicas], NovoDiagnostico) :-
    
    findall(
        paciente([Nome|AntigasCaracteristicas], _),
        paciente([Nome|AntigasCaracteristicas], _),
        PacientesAntigos
    ),
    
    maplist(retract, PacientesAntigos),

    assertz(paciente([Nome|NovasCaracteristicas], NovoDiagnostico)),
    write('Paciente editado com sucesso.'), nl.

remover_paciente([Nome|Caracteristicas]) :-

    ( paciente([Nome|Caracteristicas], _)
    ->  retract(paciente([Nome|Caracteristicas], _)),
        write('Paciente removido com sucesso.'), nl
    ;   write('Paciente nao encontrado.')
    ).
calcular_imc(Peso, Altura) :-
    Altura > 0,
    Peso > 0,
    IMC is Peso / (Altura * Altura), write('IMC = '), write(IMC), nl.


% Exemplo de uso "OBS: não foi o GPT, deu um trabalho do cão", agora com todo respeito segue os exemplos de uso:

% ?- diagnosticar_diabetes([pedro, masculino, 54, nao, nao, nunca, 31.86, 6.6, 145], Diagnostico).
% Diagnostico = nao.

% ?- adicionar_paciente([ana, feminino, 45, sim, nao, passado, 28.0, 6.0, 150], Diagnostico).
% Paciente adicionado com sucesso.
% Diagnostico = nao.

% ?- editar_paciente([pedro, masculino, 54, nao, nao, nunca, 31.86, 6.6, 145], [pedro, masculino, 55, nao, nao, nunca, 32.0, 6.7, 150]).
% Paciente editado com sucesso.

%?- remover_paciente([frederico, masculino, 54, nao, nao, passado, 30.41, 5.0, 158]).
% Paciente removido com sucesso.
% true.

% ?- calcular_imc(70, 1.75).
% IMC = 22.86.