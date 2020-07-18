pkgname=TEAtool
pkgver=1.7
pkgrel=1
pkgdesc="Tiny algorithm encryption utility"
url="https://github.com/turbocat2001/TEAtool"
license=('GPLv3')
arch=(x86_64)



build(){
    cd $startdir
    make
}

package() {
    cd $startdir
    mkdir -p $pkgdir/usr/bin
    make install DIR=$pkgdir/usr/bin
}


