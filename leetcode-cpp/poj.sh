cp Palindrome_poj1159.cpp $1.cpp
cp ./template/poj_run.sh $1.sh
replace "/Palindrome_poj1159/$1/i" $1.cpp
chmod 755 $1.sh
touch $1.in $1.out