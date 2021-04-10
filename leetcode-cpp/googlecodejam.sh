cp ./template/template_codejam.cpp $1.cpp
cp ./template/poj_run.sh $1.sh
replace "/ParentingPartneringReturns_2020_C/$1/i" $1.cpp
chmod 755 $1.sh
touch $1.in $1.out