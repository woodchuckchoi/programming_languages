#!/bin/bash

# to send both stderr and stdout to the same file
ps -ef | head > f 2 > &1

# to send a file to stdin
head < $HOME/.bashrc

