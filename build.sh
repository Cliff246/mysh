#!/bin/env/env bash

build_dir="build"

function clean_build() {
    rm -rf "$build_dir"
    mkdir "$build_dir"
}

function cmake_build() {
    
    if [ -d "$build_dir" ]; then
        cd "$build_dir" || exit
        cmake ..
        echo "built"
    else    
        echo "failed"   
    fi
    cd ..
}

function compile_build() {
    
    if [ -d "$build_dir" ]; then
        cd "$build_dir" || exit
        make
        echo "built"
    else    
        echo "failed"   
    fi
    cd ..
}

clean_build
cmake_build
compile_build
