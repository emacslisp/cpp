for fname in *.c
do
    if [ "${fname%%.*}" != "main" ]; then
        echo "build ${fname%%.*}.c"
        gcc ${fname%%.*}.c -o ${fname%%.*}.run
    fi
done