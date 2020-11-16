cd $(dirname $0)
TFMICRO_BINARY=libtensorflow-microlite.a
if [ ! -f "$TFMICRO_BINARY" ]; then
  if [ ! -d "tensorflow" ]; then
    curl --header "PRIVATE-TOKEN: Hb7KDihnd9UsPy3Vfymk" "https://git.soton.ac.uk/api/v4/projects/3745/repository/archive.zip" --output ./tensorflow-master.zip
    unzip tensorflow-master.zip
    mv -f tensorflow-master-*/tensorflow .
    rm -rf tensorflow-master*
  fi
  make -f tensorflow/lite/micro/tools/make/Makefile third_party_downloads
  make -f tensorflow/lite/micro/tools/make/Makefile microlite $1 -j18
  mv tensorflow/lite/micro/tools/make/gen/*/lib/libtensorflow-microlite.a .
fi
