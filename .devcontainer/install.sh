#!/bin/bash

# Pip installations
pip3 install --upgrade pip
pip3 install -r requirements.txt

# Apt-get installations
sudo apt-get update
sudo apt-get install -y curl libxcursor1 libxi6 libgl1-mesa-glx libasound2 libjpeg62-turbo
# Add any other apt-get installations if needed

# Additional commands
curl https://s3.amazonaws.com/parsec-build/package/parsec-linux.deb -o parsec-linux.deb
sudo dpkg -i parsec-linux.deb
rm parsec-linux.deb
