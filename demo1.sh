#!/bin/sh

delay=${1-0.5}
while true
do 
  python stoplight r 255; python stoplight b 0
  sleep $delay; 
  python stoplight y 255; python stoplight r 0
  sleep $delay; 
  python stoplight g 255; python stoplight y 0
  sleep $delay; 
  python stoplight b 255; python stoplight g 0
  sleep $delay
done
