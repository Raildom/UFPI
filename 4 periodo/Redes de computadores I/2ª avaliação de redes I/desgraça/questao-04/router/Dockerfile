FROM ubuntu:latest

# Install necessary network tools
RUN apt-get update && apt-get install -y iproute2 procps net-tools && rm -rf /var/lib/apt/lists/*

# Keep container running
CMD ["tail", "-f", "/dev/null"]