cd Object

gcc -c -I../Include -I.. *.c

ar r ../Object.a *.o
cd ..

cd Parser
gcc -c -I../Include -I.. *.c
ar r ../Parser.a *.o
cd ..

cd Python
gcc -c -I../Include -I.. *.c
ar r ../Python.a *.o
cd ..

cd Programs
gcc -I../Include -I.. python.c -o python.run ../Object.a ../Parser.a ../Python.a
./python.run
cd ..