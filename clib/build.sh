for fname in *.c
do
    if [ "${fname%%.*}" != "main" ]; then
        gcc ${fname%%.*}.c -o ${fname%%.*}.run
    fi
done