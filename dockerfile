FROM python:3.12-bullseye

RUN pip3 install --upgrade pip

COPY requirements.txt /tmp/pip-tmp/
RUN pip3 --disable-pip-version-check --no-cache-dir install -r /tmp/pip-tmp/requirements.txt \
    && rm -rf /tmp/pip-tmp

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    clang \
    lldb \
    llvm 