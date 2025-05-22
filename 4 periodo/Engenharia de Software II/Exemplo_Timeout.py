import requests

try:
    # Faz uma chamada HTTP com timeout de 2 segundos
    resposta = requests.get("https://httpbin.org/delay/5", timeout=2)
    print("Resposta recebida:", resposta.status_code)
except requests.exceptions.Timeout:
    print("Erro: o serviço demorou demais para responder (timeout).")
