FROM nginx:latest

# Install iproute2 for network configuration
RUN apt-get update && apt-get install -y iproute2 && rm -rf /var/lib/apt/lists/*

# Copy custom Nginx config and website content
COPY nginx.conf /etc/nginx/nginx.conf
COPY index.html /usr/share/nginx/html/index.html

# Expose port 80
EXPOSE 80

# Start Nginx and keep container running
# The gateway configuration will be added via command in docker-compose
CMD ["nginx", "-g", "daemon off;"]
