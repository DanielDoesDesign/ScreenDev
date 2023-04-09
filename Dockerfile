# For more information, please refer to https://aka.ms/vscode-docker-python
FROM mcr.microsoft.com/devcontainers/base:jammy

#EXPOSE 8000

# Keeps Python from generating .pyc files in the container
#ENV PYTHONDONTWRITEBYTECODE=1

# Turns off buffering for easier container logging
#ENV PYTHONUNBUFFERED=1

WORKDIR /app
COPY . /app

# Install pip requirements
RUN  apt-get update &&\
    apt-get install ffmpeg libsm6 libxext6 -y &&\
    apt install libgl1-mesa-glx &&\
    apt install build-essential -y --no-install-recommends &&\
    apt-get install make &&\
    apt-get install libsdl2-dev -y &&\
    apt-get install gdb -y

# Creates a non-root user with an explicit UID and adds permission to access the /app folder
# For more info, please refer to https://aka.ms/vscode-docker-python-configure-containers
RUN adduser -u 5678 --disabled-password --gecos "" appuser && chown -R appuser /app
USER appuser