class Televisao:
    def __init__(self):
        self._volume = 0
        self._canal = 1
        self._ligada = False

    @property
    def volume(self):
        return self._volume
    @volume.setter
    def volume(self, volume):
        self._volume = volume

    @property
    def canal(self):
        return self._canal
    @canal.setter
    def canal(self, canal):
        self._canal = canal

    @property
    def ligada(self):
        return self._ligada
    @ligada.setter
    def ligada(self, ligada):
        self._ligada = ligada

class ControleRemoto:
    def __init__(self, televisao):
        self._televisao = televisao
        
    @property
    def televisao(self):
        return self._televisao
    @televisao.setter
    def televisao(self, televisao):
        self._televisao = televisao

    def aumentar_volume(self):
        if self.televisao.ligada:
            if self.televisao.volume < 100:
                self.televisao.volume += 1
                return True, f"\nVolume aumentado com sucesso\nVolume atual: {self.televisao.volume}\n"
            else:
                return False, "\nVolume no máximo possível\n"
        else:
            return False, "\nTelevisão desligada!\n"

    def diminuir_volume(self):
        if self.televisao.ligada:
            if self.televisao.volume > 0:
                self.televisao.volume -= 1
                return True, f"\nVolume reduzido com sucesso\nVolume atual: {self.televisao.volume}\n"
            else:
                return False, "\nVolume no mínimo possível\n"
        else:
            return False, "\nTelevisão desligada!\n"

    def aumentar_canal(self):
        if self.televisao.ligada: 
            if self.televisao.canal < 100:
                self.televisao.canal += 1
                return True, f"\nCanal aumentado com sucesso\nCanal atual: {self.televisao.canal}\n"
            else:
                return False, "\nCanal máximo!\n"
        else:
            return False, "\nTelevisão desligada!\n"

    def diminuir_canal(self):
        if self.televisao.ligada:
            if self.televisao.canal > 0:
                self.televisao.canal -= 1
                return True, f"\nCanal reduzido com sucesso\nCanal atual: {self.televisao.canal}\n"
            else:
                return False, "\nCanal mínimo!\n"
        else:
            return False, "\nTelevisão desligada!\n"
            
    def trocar_canal(self, canal):
        if self.televisao.ligada:
            if 0 < canal <= 100:
                self.televisao.canal = canal
                return True, f"\nCanal alterado com sucesso\nCanal atual: {self.televisao.canal}\n"
            else:
                return False, "\nCanal inválido!\n"
        else:
            return False, "\nTelevisão desligada!\n"
            
    def consulta_volume(self):
        return self.televisao.volume

    def ligar_desligar(self):
        self.televisao.ligada = not self.televisao.ligada

def menu():
    televisao = Televisao()
    controle = ControleRemoto(televisao)

    while True:
        print("[1] - Ligar/Desligar")
        print("[2] - Aumentar volume")
        print("[3] - Diminuir volume")
        print("[4] - Aumentar canal")
        print("[5] - Diminuir canal")
        print("[6] - Escolher canal")
        print("[7] - Consultar volume")
        print("[0] - Sair")
        
        op = int(input("Digite a opção desejada: "))

        if op == 1:
            controle.ligar_desligar()
            if controle.televisao.ligada:
                print("\nTelevisão ligada\n")
            else:
                print("\nTelevisão desligada\n")
        elif op == 2:
            res = controle.aumentar_volume()
            print(res[1])
        elif op == 3:
            res = controle.diminuir_volume()
            print(res[1])
        elif op == 4:
            res = controle.aumentar_canal()
            print(res[1])
        elif op == 5:
            res = controle.diminuir_canal()
            print(res[1])
        elif op == 6:
            canal = int(input("Digite o canal desejado: "))
            res = controle.trocar_canal(canal)
            print(res[1])
        elif op == 7:
            print("\nVolume: {}\n".format(controle.consulta_volume()))
        elif op == 0:
            break
        else:
            print("\nOpção inválida!\n")
menu()