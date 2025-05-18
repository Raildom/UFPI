aluno(joao, calculo). 
aluno(maria, calculo). 
aluno(joel, programacao). 
aluno(joel, estrutura). 
frequenta(joao, ufpi). 
frequenta(maria, ufpi). 
frequenta(joel, ufma). 
professor(carlos, calculo). 
professor(ana_paula, estrutura). 
professor(pedro, programacao). 
funcionario(pedro, ufma). 
funcionario(ana_paula, ufpi). 
funcionario(carlos, ufpi).


professorde(X, Y):-
    aluno(Y, Z), frequenta(Y, A), funcionario(X, A), professor(X, Z).

associado(X, Y):-
    funcionario(X, Y); frequenta(X, Y).
