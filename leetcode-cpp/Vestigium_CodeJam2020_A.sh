me=`basename "$0"`
fbname=${me%.*}
g++ -g3 -std=c++11 -DFILEIO ${fbname}.cpp ./lib/lib.a -o ${fbname}.run
./${fbname}.run