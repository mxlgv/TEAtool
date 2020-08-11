# TEAtool 

### Description:

*A program for encrypting files with a 128-bit public key using the Tiny Encryption Algorithm (TEA). This program is intended for Kolibri OS.*

### Compilation and installation:

**To compile under Kolibri OS, use TCC.**

    tcc teatool.c -o teatool -lck

**Compiling for Windows using "Tiny C Compiler":**
    
    tcc teatool.c -o teatool

**To compile under Linux, use "make".**

*English version:*

    make
    
*Russian version:*

    make rus
                
**Installation / Uninstallation for Linux**

    make install
    make uninstall
        
**Installation package for ArchLinux(AUR):**
    
    yay -S teatool-git
    
### Usage example:

*Encrypting the "in.file" file with the "FFAB1100C176001F1ADDB8E792001EA5" key in normal mode:*

    teatool in.file out.file -k FFAB1100C176001F1ADDB8E792001EA5 -e normal 
    
*Encrypting the "in.file" file with the key-file "my.key" in speed mode:*

    teatool in.file out.file -K my.key -e speed


*Writing the "FFAB1100C176001F1ADDB8E792001EA5" key to the key-file "my.key"*
    
    teatool -r FFAB1100C176001F1ADDB8E792001EA5 my

 
