pip install --upgrade pip
pip install -r requirements.txt

zip_file=".temp/BRXSDK_Bcad_V24_1_05.zip"
dest_dir="/usr/local/lib/BRXSDK"

sudo unzip $zip_file -d $dest_dir
