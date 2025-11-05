from fastapi import FastAPI
from uvicorn import run

app = FastAPI()

@app.get("/")
def hello_world():
    return {"message": "teste 29 liso"}

@app.get("/calculo/{numero}")
def calculo(numero : int):
    resultado = numero * 5
    return {"resultado": resultado}