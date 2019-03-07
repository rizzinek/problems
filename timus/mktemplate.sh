#!/bin/bash

rm -r $1
mkdir $1
cp "./template/p.cpp" "$1/$1.cpp"
echo "#!/bin/bash
g++ -o p $1.cpp" > "$1/cmpl"
chmod a+x "$1/cmpl"
touch "$1/input.txt"
