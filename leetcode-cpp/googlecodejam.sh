cp Vestigium_CodeJam2020_A.cpp $1.cpp
cp Vestigium_CodeJam2020_A.sh $1.sh
replace "/Vestigium_CodeJam2020_A/$1/i" $1.cpp
chmod 755 $1.sh
touch $1.in $1.out