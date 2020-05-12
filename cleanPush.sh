#!/bin/bash
cd GUI/build-GUI-Desktop-Debug
make clean -j8
cd ../.. 
git add . && git commit -m "$1" && git push origin Jerome 
