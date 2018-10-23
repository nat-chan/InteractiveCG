#!/bin/bash

[ $# -ne 2 ]&& cat <<EOF && exit 255
Usage: $0 [1文字のショートカット] [小文字のブラシ名]
Example: $0 t triangle
EOF

cp pointBrush.h ${2}Brush.h
cp pointBrush.cpp ${2}Brush.cpp

sed -i ${2}Brush.h                  \
    -e "s/pointBrush/${2}Brush/g"   \
    -e "s/PointBrush/${2^}Brush/g"  \
    -e "s/POINTBRUSH/${2^^}BRUSH/g" \

sed -i ${2}Brush.cpp                \
    -e "s/pointBrush/${2}Brush/g"   \
    -e "s/PointBrush/${2^}Brush/g"  \
    -e "s/POINTBRUSH/${2^^}BRUSH/g" \

vim impBrush.h                                                                 \
    -c 'normal! /};
    -c 'wq'

vim impressionistDoc.cpp                                                       \
    -c 'normal! /^#include
    -c 'normal! /Points
    -c 'wq'

vim impressionistUI.cpp                                                        \
    -c 'normal! /Points
		-c 'wq'