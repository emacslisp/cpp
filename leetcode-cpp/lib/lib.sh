for fname in *.cpp
do
    if [[ "${fname%%.*}" != "main" ]]; then
        g++ -c ${fname%%.*}.cpp -o ${fname%%.*}.o
    fi
done

ar r lib.a *.o

g++ main.cpp -o main.run lib.a
./main.run