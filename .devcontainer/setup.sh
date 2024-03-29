#!/bin/bash

function installLibrary() {
    repo=$1
    api=$2
    git clone $repo temp_repo
    cd temp_repo/workspaces/Bricsys-API/$api
    latest_zip=$(ls -Art | grep .zip | tail -n 1)
    unzip $latest_zip -d /usr/local/bin
    echo 'export PATH=$PATH:/usr/local/lib/' >> ~/.bashrc
    source ~/.bashrc
    cd ../../..
    rm -rf temp_repo
}

function onCreateCommand() {
    pip install --upgrade pip && pip install -r requirements.txt
    sudo apt-get update && sudo apt-get install -y gdb
    installLibrary "https://github.com/Structura-Engineering/Bricsys-API.git" "BRX" # or "TX"
}

onCreateCommand
