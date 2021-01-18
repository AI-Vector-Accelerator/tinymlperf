
# Use this variable to set which commit of TensorFlow you would like to test.
# This commit can be from any active branch.
# If it is left blank then the most recent commit in the master branch will be pulled
TF_COMMIT_SHA=

cd $(dirname $0)
TFMICRO_BINARY=libtensorflow-microlite.a
if [ ! -f "$TFMICRO_BINARY" ]; then
  if [ ! -d "tensorflow" ]; then
    if [ ! -z "$TF_COMMIT_SHA" ]; then
      wget https://github.com/AI-Vector-Accelerator/tensorflow/archive/${TF_COMMIT_SHA}.zip -O ./tensorflow.zip
    else
      wget https://github.com/AI-Vector-Accelerator/tensorflow/archive/master.zip -O ./tensorflow.zip
    fi
    unzip tensorflow.zip
    mv -f tensorflow-*/tensorflow .
    rm -rf tensorflow-*
  fi
  make -f tensorflow/lite/micro/tools/make/Makefile third_party_downloads
  make -f tensorflow/lite/micro/tools/make/Makefile microlite $1 -j18
  mv tensorflow/lite/micro/tools/make/gen/*/lib/libtensorflow-microlite.a .
fi