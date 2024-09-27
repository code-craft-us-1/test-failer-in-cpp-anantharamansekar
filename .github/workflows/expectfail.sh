#!/bin/bash

if $1; then
    echo "succeeded"
    exit 0
else
    echo "Failure. Not as expected"
fi
