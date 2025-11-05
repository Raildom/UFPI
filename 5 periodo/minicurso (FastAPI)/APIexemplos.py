from fastapi import FastAPI, HTTPException, status
from typing import Optional
from pydantic import BaseModel

app = FastAPI(title="API Maneira")

class ItemParcial(BaseModel):
    nome: Optional[str] = None
    preco: Optional[float] = None
    em_oferta: Optional[bool] = None


class ItemUpdate(BaseModel):
    nome: str
    preco: float
    em_oferta: bool


# --- Modelo Pydantic ---
class Item(BaseModel):
    id: int          # ID do item (inteiro)
    nome: str        # Nome do item
    preco: float     # Preço do item
    em_oferta: bool = False  # Flag se está em oferta (padrão False)

# --- "Banco de Dados" em Dicionário ---
db_itens_dict: dict[int, Item] = {}  # Simula um DB em memória

# --- GET básico ---
@app.get("/")
def ler_raiz():
    """
    GET básico - Retorna uma mensagem de boas-vindas.
    Navegador: http://127.0.0.1:8000/
    HTTPie:   http GET http://127.0.0.1:8000/
    cURL:     curl -X GET http://127.0.0.1:8000/
    """
    return {"mensagem": "Olá, FastAPI !"}

# --- GET com query parameters (listagem de itens) ---
@app.get("/itens/")
def listar_itens(skip: int = 0, limit: int = 10):
    """
    GET com query parameters - Lista itens com paginação.
    Query Parameters:
        - skip: quantos itens pular
        - limit: quantos itens retornar
    Navegador: http://127.0.0.1:8000/itens/?skip=0&limit=10
    HTTPie:   http GET http://127.0.0.1:8000/itens/ skip==0 limit==10
    cURL:     curl -X GET "http://127.0.0.1:8000/itens/?skip=0&limit=10"
    """
    itens = list(db_itens_dict.values())
    return itens[skip : skip + limit]

# --- GET por ID (path parameter) ---
@app.get("/itens/{item_id}")
def ler_item(item_id: int):
    """
    GET por ID - Retorna um item específico pelo ID.
    Path Parameter:
        - item_id: ID do item
    Navegador: http://127.0.0.1:8000/itens/1
    HTTPie:   http GET http://127.0.0.1:8000/itens/1
    cURL:     curl -X GET http://127.0.0.1:8000/itens/1
    """
    if item_id in db_itens_dict:
        return db_itens_dict[item_id]
    raise HTTPException(status_code=404, detail="Item não encontrado")

# --- POST ---
@app.post("/itens/", status_code=status.HTTP_201_CREATED)
def criar_item(item: Item):
    """
    POST - Cria um novo item.
    Body (JSON):
        {
            "id": 1,
            "nome": "Item A",
            "preco": 50.0,
            "em_oferta": false
        }
    HTTPie: http POST http://127.0.0.1:8000/itens/ id=1 nome="Item A" preco=50.0 em_oferta:=false
    cURL:   curl -X POST http://127.0.0.1:8000/itens/ -H "Content-Type: application/json" -d '{"id":1,"nome":"Banana","preco":5.0,"em_oferta":false}'
    """
    if item.id in db_itens_dict:
        raise HTTPException(status_code=400, detail="ID já cadastrado")
    db_itens_dict[item.id] = item
    return item

# --- PUT ---
@app.put("/itens/{item_id}")
def atualizar_item(item_id: int, item: ItemUpdate):
    """
    PUT - Atualiza um item inteiro (substitui todos os campos).
    Body (JSON):
        {
            "nome": "Item Atualizado",
            "preco": 60.0,
            "em_oferta": true
        }
    HTTPie: http PUT http://127.0.0.1:8000/itens/1 nome="Item Atualizado" preco=60.0 em_oferta:=true
    cURL:   curl -X PUT http://127.0.0.1:8000/itens/1 -H "Content-Type: application/json" -d '{"nome":"Item Atualizado","preco":60.0,"em_oferta":true}'
    """
    if item_id not in db_itens_dict:
        raise HTTPException(status_code=404, detail="Item não encontrado")

    existente = db_itens_dict[item_id]
    existente.nome = item.nome
    existente.preco = item.preco
    existente.em_oferta = item.em_oferta
    return existente

# --- DELETE ---
@app.delete("/itens/{item_id}")
def deletar_item(item_id: int):
    """
    DELETE - Remove um item pelo ID.
    Path Parameter:
        - item_id: ID do item
    HTTPie: http DELETE http://127.0.0.1:8000/itens/1
    cURL:   curl -X DELETE http://127.0.0.1:8000/itens/1
    """
    if item_id not in db_itens_dict:
        raise HTTPException(status_code=404, detail="Item não encontrado")
    return db_itens_dict.pop(item_id)


@app.patch("/itens/{item_id}")
def atualizar_parcial(item_id: int, item: ItemParcial):
    """
    PATCH - Atualiza parcialmente os campos de um item.
    Body (JSON) pode conter apenas os campos a atualizar:
        {
            "nome": "Novo Nome",
            "preco": 55.0
        }
    HTTPie: http PATCH http://127.0.0.1:8000/itens/1 nome="Novo Nome" preco:=55.0
    cURL:   curl -X PATCH http://127.0.0.1:8000/itens/1 -H "Content-Type: application/json" -d '{"nome":"Novo Nome","preco":55.0}'
    """
    if item_id not in db_itens_dict:
        raise HTTPException(status_code=404, detail="Item não encontrado")
    existente = db_itens_dict[item_id]
    if item.nome is not None:
        existente.nome = item.nome
    if item.preco is not None:
        existente.preco = item.preco
    if item.em_oferta is not None:
        existente.em_oferta = item.em_oferta
    return existente



