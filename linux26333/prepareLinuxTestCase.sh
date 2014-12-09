#!/bin/sh -v
version=linux-2.6.33.3

#tarball=$version.tar.bz2
#if [ ! -f $tarball ]; then
#  wget http://www.kernel.org/pub/linux/kernel/v2.6/$tarball
#fi
#tar xjf $tarball

git clone https://kernel.googlesource.com/pub/scm/linux/kernel/git/stable/linux-stable
mv linux-stable/ linux
cd linux/
git checkout af352dbf0b0a8d9d4c17018d63fae48b654fd03b

# ln -s $version linux
cd linux
make allnoconfig ARCH=x86
make prepare ARCH=x86
# Creates include/generated/compile.h needed for init/version.o; the command
# will give an error which we want to ignore.
make SUBDIRS=init ARCH=x86 &> /dev/null
cd ..

dir=`pwd`
cd ..
java -jar sbt-launch.jar compile  mkrun

cd $dir
sh applyPCs.sh
