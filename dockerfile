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
    llvm \
    libegl1 \
    libxkbcommon0 \
    libdbus-1-3 \
    libxcb-cursor0 \
    libsm6 \
    libxext6 \
    libxrender1 \
    libfontconfig1 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-randr0 \
    libxcb-render-util0 \
    libxcb-xinerama0 \
    libxcb-xfixes0 \
    libxcb-shape0 \
    libxcb-sync1 \
    libxcb-xkb1 \
    libx11-xcb1 \
    libxi6 \
    libxrender1 \
    libxkbcommon-x11-0 \
    libxcb1 \
    libx11-6 \
    libxext6 \
    libxfixes3 \
    libxrender1 \
    libx11-dev \
    libxext-dev \
    libxfixes-dev \
    libxi-dev \
    libxrender-dev \
    libxcb1-dev \
    libx11-xcb-dev \
    libxcb-glx0-dev \
    libxkbcommon-dev \
    libxkbcommon-x11-dev \
    libfontconfig1-dev