function download_and_extract() {
    local source_url=$1
    local file_name=$(basename $source_url)
    local folder_name=$(basename $(dirname $source_url))
    local temp_dir="/tmp/$folder_name/$file_name"
    local dest_dir="/usr/local/lib/$folder_name"

    trap 'rm -f $temp_dir' EXIT

    if [ ! -d $(dirname $temp_dir) ]; then
        sudo mkdir -p $(dirname $temp_dir)
    fi

    sudo wget -P $(dirname $temp_dir) $source_url &&
        sudo unzip -q -o $temp_dir -d $dest_dir
}

pip install --upgrade pip && pip install -r requirements.txt

sudo apt-get update && sudo apt-get install -y gdb

download_and_extract "https://cloud.structura-engineering.com/cloud-storage/BRXSDK/BRXSDK_Bcad_V24_1_05.zip"
