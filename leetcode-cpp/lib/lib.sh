for fname in *.cpp
do
    if [ "${fname%%.*}" != "main" ]; then
        g++ -gdwarf-2 -g3 -fPIC -c ${fname%%.*}.cpp -o ${fname%%.*}.o
    fi
done

ar r lib.a *.o
g++ -gdwarf-2 -g3 -shared *.o -o lib.so

g++ main.cpp -o main.run lib.a
./main.run