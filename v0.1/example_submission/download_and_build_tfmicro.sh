
# Use this variable to set which commit of TensorFlow you would like to test.
# This commit can be from any active branch.
TF_COMMIT_SHA=4e411538304cad267edeea2580ddda1fab77cd4e

cd $(dirname $0)
TFMICRO_BINARY=libtensorflow-microlite.a
if [ ! -f "$TFMICRO_BINARY" ]; then
  if [ ! -d "tensorflow" ]; then
    curl --header "PRIVATE-TOKEN: Hb7KDihnd9UsPy3Vfymk" "https://git.soton.ac.uk/api/v4/projects/3745/repository/archive.zip?sha=$TF_COMMIT_SHA" --output ./tensorflow.zip
    unzip tensorflow.zip
    mv -f tensorflow-*/tensorflow .
    rm -rf tensorflow-*
  fi
  make -f tensorflow/lite/micro/tools/make/Makefile third_party_downloads
  make -f tensorflow/lite/micro/tools/make/Makefile microlite $1 -j18
  mv tensorflow/lite/micro/tools/make/gen/*/lib/libtensorflow-microlite.a .
fi
