#!/bin/env/env bash

build_dir="build"

function clean_build() {
    rm -rf "$build_dir"
    mkdir "$build_dir"
}

function make_build() {
    
    if [ -d "$build_dir" ]; then
        cd "$build_dir" || exit
        cmake ..
        echo "built"
    else    
        echo "failed"   
    fi
}

clean_build
make_build
