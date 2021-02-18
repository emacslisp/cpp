me=`basename "$0"`
fbname=${me%.*}
g++ -g3 -std=c++17 ${fbname}.cpp ./lib/lib.a -DFILEIO -o ${fbname}.run
./${fbname}.run