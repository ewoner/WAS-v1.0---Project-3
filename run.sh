clear
if [ -e ./Build/server.exe ]
then
	./Build/server.exe
else
	make run
fi
