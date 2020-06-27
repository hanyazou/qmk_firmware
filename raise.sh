#!/bin/bash
make -r -R -C $(dirname $0) -f build_keyboard.mk  KEYBOARD=dygma/raise KEYMAP=applause SILENT=false $*
#make -r -R -C $(dirname $0) -f build_keyboard.mk  KEYBOARD=dygma/raise KEYMAP=default SILENT=false $*
# /cygdrive/c/Program\ Files/BOSSA/bossac.exe -p COM10 -e -R -o 0x2000 -w dygma_raise_applause.bin
