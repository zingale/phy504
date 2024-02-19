#!/bin/sh

for i in *.jpg
do
    convert -resize 10% $i `basename $i .jpg`.png
done
