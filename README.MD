**A program for encrypting files with a 128-bit public key using the Tiny Encryption Algorithm (TEA).**
**This program is intended for Kolibri OS.**

**To compile under Kolibri OS, use TCC.**

    `tcc TEAtool.c -o TEAtool -lck`

**To compile under Linux, use "make".**

*English version:*

    `make`
    
*Russian version:*

    `make rus`  
                
**Installation / Uninstallation for Linux**

    `make install`
    `make uninstall`
        
**Installation package for ArchLinux(AUR):**
    
    `yay -S teatool`
    
**Usage example:**

    `TEAtool in.file out.file -k FFAB1100C176001F1ADDB8E792001EA5 -e normal`  
    `TEAtool in.file out.file -K my.key -e speed`
    `TEAtool -r FFAB1100C176001F1ADDB8E792001EA5 my` 

 
