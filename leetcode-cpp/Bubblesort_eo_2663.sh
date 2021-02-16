me=`basename "$0"`
fbname=${me%.*}
g++ -g3 -std=c++11 ${fbname}.cpp ./lib/lib.a -DFILEIO -o ${fbname}.run
./${fbname}.run
cat ${fbname}.out