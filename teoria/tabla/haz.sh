#!/bin/bash
make clean
rm *.pro
qmake -project
fichero=$( ls *.pro )
echo "QT += widgets" >> $fichero
qmake
make
echo "pon el && ejecutable para acelerar"
