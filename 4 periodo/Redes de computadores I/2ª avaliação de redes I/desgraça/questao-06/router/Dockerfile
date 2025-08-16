FROM ubuntu:latest

# Instalar ferramentas de rede e FRR para RIP
RUN apt-get update && apt-get install -y iproute2 procps net-tools frr && rm -rf /var/lib/apt/lists/*

# Garantir que o usuário e grupo 'frr' sejam criados
RUN useradd -r -s /sbin/nologin -M frr || true
RUN groupadd -r frr || true

# Manter o contêiner ativo (sobrescrito no docker-compose)
CMD ["tail", "-f", "/dev/null"]