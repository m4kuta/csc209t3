#!/bin/bash

program=$1

for item in *
do
    if [ $item  == "test"* ]
    then
        if "./$program" $item
        then
            echo "$program" terminated successfully
        else
            echo "$program" $item failed
        fi
    # else
    #     echo invalid program
    fi
done