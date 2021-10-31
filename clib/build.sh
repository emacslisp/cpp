for fname in *.c
do
    if [ "${fname%%.*}" != "main" ]; then
        echo "build ${fname%%.*}.c"
        gcc -w ${fname%%.*}.c -o ${fname%%.*}.run
    fi
done