echo "building cpp file"
for fname in *.c
do
    if [ "${fname%%.*}" != "main" ]; then
        echo ${fname%%.*}.cpp
        g++ -gdwarf-2 -g3 -fPIC -std=c++11 -c ${fname%%.*}.c -o ${fname%%.*}.o
    fi
done

ar r lib.a *.o
g++ -gdwarf-2 -g3 -shared *.o -o lib.so

g++ emacs.c -o main.run lib.a
./main.run