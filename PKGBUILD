pkgname=TEAtool
pkgver=1.5
pkgrel=1
pkgdesc="Tiny algorithm encryption utility"
url="https://github.com/turbocat2001/TEAtool"
license=('GPLv3')
arch=(x86_64)


package() {
    cd ..
    make
    mkdir -p $srcdir/usr/bin
    cp TEAtool $srcdir/usr/bin
    cp -r $srcdir/* $pkgdir/
    rm TEAtool
    rm -rf src
  
}
