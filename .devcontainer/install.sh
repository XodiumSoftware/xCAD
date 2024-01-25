function installFromCloud() {
    url=$1
    filename=$(basename $url)
    foldername=${filename%.*}
    sudo wget $url
    sudo mkdir -p /usr/local/lib/$foldername
    sudo unzip -d /usr/local/lib/$foldername $filename
    sudo rm $filename
    echo 'export PATH=$PATH:/usr/local/lib/' >> ~/.bashrc
    source ~/.bashrc
}

function onCreateCommand() {
    pip install --upgrade pip && pip install -r requirements.txt
    sudo apt-get update && sudo apt-get install -y gdb
    installFromCloud "https://cloud.structura-engineering.com/storage/BRXSDK/BRXSDK_Bcad_V24_2_01.zip"
}

onCreateCommand
