echo "building c file"
for fname in *.c
do
    if [ "${fname%%.*}" != "main" ]; then
        echo ${fname%%.*}.c
        gcc -gdwarf-2 -g3 -fPIC -c ${fname%%.*}.c -o ${fname%%.*}.o
    fi
done

ar r ftp-server.a *.o
gcc -gdwarf-2 -g3 -shared *.o -o ftp-server.so