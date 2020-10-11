#!/bin/bash
read -e -p "filename/location: " file 
for id in {00000..99999};
do
echo $id | ./$file; 
done | grep flag

