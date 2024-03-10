all: sim/mkGaussTb.o sim/model_mkGaussTb.o

.PHONY: sim/mkGaussTb.o
sim/mkGaussTb.o:
	@echo exec: 'c++ -O3  -Wall -Wno-unused -D_FILE_OFFSET_BITS=64 "-O3" "-Wall" "-Wno-unused" "-D_FILE_OFFSET_BITS=64" "-fPIC" "-Wno-uninitialized" "-fpermissive" "-std=c++11" "-D_GLIBCXX_USE_CXX11_ABI=0" -I"/usr/local/lib"/Bluesim -Wno-uninitialized -fPIC -c -o "sim/mkGaussTb.o" "sim/mkGaussTb.cxx"'
	@c++ -O3  -Wall -Wno-unused -D_FILE_OFFSET_BITS=64 "-O3" "-Wall" "-Wno-unused" "-D_FILE_OFFSET_BITS=64" "-fPIC" "-Wno-uninitialized" "-fpermissive" "-std=c++11" "-D_GLIBCXX_USE_CXX11_ABI=0" -I"/usr/local/lib"/Bluesim -Wno-uninitialized -fPIC -c -o "sim/mkGaussTb.o" "sim/mkGaussTb.cxx"
	@echo 'Bluesim object created: sim/mkGaussTb.{h,o}'

.PHONY: sim/model_mkGaussTb.o
sim/model_mkGaussTb.o:
	@echo exec: 'c++ -O3  -Wall -Wno-unused -D_FILE_OFFSET_BITS=64 "-O3" "-Wall" "-Wno-unused" "-D_FILE_OFFSET_BITS=64" "-fPIC" "-Wno-uninitialized" "-fpermissive" "-std=c++11" "-D_GLIBCXX_USE_CXX11_ABI=0" -I"/usr/local/lib"/Bluesim -Wno-uninitialized -fPIC -c -o "sim/model_mkGaussTb.o" "sim/model_mkGaussTb.cxx"'
	@c++ -O3  -Wall -Wno-unused -D_FILE_OFFSET_BITS=64 "-O3" "-Wall" "-Wno-unused" "-D_FILE_OFFSET_BITS=64" "-fPIC" "-Wno-uninitialized" "-fpermissive" "-std=c++11" "-D_GLIBCXX_USE_CXX11_ABI=0" -I"/usr/local/lib"/Bluesim -Wno-uninitialized -fPIC -c -o "sim/model_mkGaussTb.o" "sim/model_mkGaussTb.cxx"
	@echo 'Bluesim object created: sim/model_mkGaussTb.{h,o}'

