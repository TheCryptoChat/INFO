#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/infocoin.ico

convert ../../src/qt/res/icons/infocoin-16.png ../../src/qt/res/icons/infocoin-32.png ../../src/qt/res/icons/infocoin-48.png ${ICON_DST}
