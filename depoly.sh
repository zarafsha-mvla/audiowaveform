#!/bin/bash


mkdir build
cd build
cmake -D ENABLE_TESTS=0 ..
sudo make install


