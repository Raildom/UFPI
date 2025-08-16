FROM ubuntu:latest

# Install necessary tools (links for browsing, iproute2 for routing, net-tools, dnsutils)
RUN apt-get update && apt-get install -y iproute2 links net-tools dnsutils iputils-ping && rm -rf /var/lib/apt/lists/*

# Keep container running
CMD ["tail", "-f", "/dev/null"]

