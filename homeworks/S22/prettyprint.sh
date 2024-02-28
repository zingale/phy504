#!/bin/bash

for i in $(seq 0 ${2})
do
  echo "${1:$i:${#1}}"
done
