echo "building cpp file"
for fname in *.cpp
do
    if [ "${fname%%.*}" != "main" ]; then
        echo ${fname%%.*}.cpp
        g++ -gdwarf-2 -g3 -fPIC -std=c++11 -c ${fname%%.*}.cpp -o ${fname%%.*}.o
    fi
done

ar r lib.a *.o
g++ -gdwarf-2 -g3 -shared *.o -o lib.so

g++ main.cpp -o main.run lib.a
./main.run