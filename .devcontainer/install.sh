pip install --upgrade pip
pip install -r requirements.txt

source_dir="https://cloud.structura-engineering.com/storage/BRXSDK/BRXSDK_Bcad_V24_1_05.zip"
temp_dir="/tmp/BRXSDK/BRXSDK_Bcad_V24_1_05.zip"
dest_dir="/usr/local/lib/BRXSDK"

mkdir -p $(dirname $temp_dir)
curl $source_dir -o $temp_dir

sudo unzip -o $temp_dir -d $dest_dir
rm $temp_dir
