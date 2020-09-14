#!/bin/bash
echo "123abc abc123" | sed -r 's/.* ([a-z]+[0-9]+)/\1/'
echo "123abc abc123" | sed -r 's/(.*) ([a-z]+[0-9]+) (.*)/\2/'
cat testText | sed -rn 's/line1/this/gp'
cat testText | grep 'line1' | sed -r 's/.+ .+ abc([0-9]+) .+/\1/'
