#!/bin/bash
sudo mv build/mstd /usr/lib/libmstd.so
sudo rm -rf /usr/include/mstd/
sudo cp -r include/ /usr/include/mstd