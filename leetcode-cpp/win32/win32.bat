cl /c /EHsc *.cpp
lib /out:lib.lib *.obj
cl main.cpp lib.lib
