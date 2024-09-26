#!/bin/bash

if $1; then
    echo "succeeded"
    exit 1
else
    echo "Failure. Not as expected"
fi
