FROM python:3.12-bullseye

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    clang \
    lldb \
    llvm \
    x11-apps \
    libx11-xcb1 \
    && pip3 install --upgrade pip \
    && pip3 --disable-pip-version-check --no-cache-dir install -r requirements.txt \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* \
    |& tee -a /var/logs/build.log

WORKDIR /app

ENV PYTHONPATH=/src
ENV DISPLAY=:0

COPY . /app
