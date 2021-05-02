echo "==== build ftp server"
cd ftp-server
./ftp-server.sh

echo "==== build ftp client"
cd ../ftp
./ftp-cli.sh

cd ..
gcc main.c -o main.run ./ftp/ftp-client.a ./ftp-server/ftp-server.a 