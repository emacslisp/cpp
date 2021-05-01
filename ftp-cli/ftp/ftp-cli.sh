echo "building c file"
for fname in *.c
do
    if [ "${fname%%.*}" != "main" ]; then
        echo ${fname%%.*}.c
        gcc -gdwarf-2 -g3 -c ${fname%%.*}.c -o ${fname%%.*}.o
    fi
done

ar r ftp-client.a *.o
gcc -gdwarf-2 -g3 -shared *.o -o ftp-client.so