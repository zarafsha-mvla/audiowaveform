#!/bin/bash

git clone https://github.com/zarafsha-mvla/audiowaveform.git
cd audiowaveform
mkdir build
cd build
cmake -D ENABLE_TESTS=0 ..
sudo make install


