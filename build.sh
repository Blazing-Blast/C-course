#! /bin/bash
export CX='g++'
export CC='gcc'
export RUSTC='cargo build'
COMMONFLAGS="-Wall -g"
export CFLAGS="$COMMONFLAGS"
export CXXFLAGS="$COMMONFLAGS" 
export RUSTARGS=""

echo "$@"

if [ "$1" ]
then
    make out -C src -C "$1" &&
    cp "src/$1/out" bin/$1;
else
    for DIR in `ls src`; do
        make $@ -C src -C "$DIR";
        cp "src/$DIR/out" bin/$DIR &
    done
fi