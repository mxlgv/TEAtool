**A program for encrypting files with a 128-bit public key using the Tiny Encryption Algorithm (TEA).**
**This program is intended for Kolibri OS.**
**To compile under another's OS use "make".**

    `make`              
    `make install`
        
**Usage example:**
    *TEAtool in.file out.file -k FFAB1100C176001F1ADDB8E792001EA5 -e    
    *TEAtool in.file out.file -K my.key -e
    *TEAtool -r FFAB1100C176001F1ADDB8E792001EA5 my 
