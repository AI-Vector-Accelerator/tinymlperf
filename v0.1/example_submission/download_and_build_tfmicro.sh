
# Use this variable to set which commit of TensorFlow you would like to test.
# This commit can be from any active branch.
# If it is left blank then the most recent commit in the master branch will be pulled
TF_COMMIT_SHA=

cd $(dirname $0)
TFMICRO_BINARY=libtensorflow-microlite.a
if [ ! -f "$TFMICRO_BINARY" ]; then
  if [ ! -d "tensorflow" ]; then
    if [ ! -z "$TF_COMMIT_SHA" ]; then
      curl --header "PRIVATE-TOKEN: Hb7KDihnd9UsPy3Vfymk" "https://git.soton.ac.uk/api/v4/projects/3745/repository/archive.zip?sha=$TF_COMMIT_SHA" --output ./tensorflow.zip
    else
      curl --header "PRIVATE-TOKEN: Hb7KDihnd9UsPy3Vfymk" "https://git.soton.ac.uk/api/v4/projects/3745/repository/archive.zip" --output ./tensorflow.zip
    fi
    unzip tensorflow.zip
    mv -f tensorflow-*/tensorflow .
    rm -rf tensorflow-*
  fi
  make -f tensorflow/lite/micro/tools/make/Makefile third_party_downloads
  make -f tensorflow/lite/micro/tools/make/Makefile microlite $1 -j18
  mv tensorflow/lite/micro/tools/make/gen/*/lib/libtensorflow-microlite.a .
fi