#!/bin/bash

hppPath="./"
cppPath="./"

mkdir -p $hppPath $cppPath

for class in "$@"
do
	capClass="$(tr '[:lower:]' '[:upper:]' <<< ${class:0:1})${class:1}"
	fcapClass="$(tr '[:lower:]' '[:upper:]' <<< ${class})"
	hpp="$hppPath$capClass".hpp
	cpp="$cppPath$capClass".cpp
	# HPP
	rm -f $hpp && touch $hpp
	cat > $hpp << EOL
#pragma once

#include <iostream>

class $capClass {
	public:
		$capClass(void);
		$capClass(const $capClass& in);
		$capClass& operator=(const $capClass& in);
		~$capClass();
};


EOL

	# CPP
	rm -f $cpp && touch $cpp
	cat > $cpp << EOL
#include "../header/$capClass.hpp"

$capClass::$capClass(void) {}

$capClass::$capClass(const $capClass& in) {(void)in;}

$capClass &$capClass::operator=(const $capClass& in) {
	(void)in;
	return (*this);
}

$capClass::~$capClass(void) {}
EOL
done

printf "\n$# classes created:\n\n"
for class in "$@"
do
	echo "$capClass.hpp/.cpp"
done