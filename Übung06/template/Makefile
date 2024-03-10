.ONESHELL: 

all: clean run

run: test_axi

build: clean build_axi

test_axi: build_axi
		echo "Running axilitelite Testbench"
		./axiliteliteTb

build_axi:
		bsc -u -sim -g mkCacheWrapperTb CacheWrapperTb.bsv
		bsc -sim -e mkCacheWrapperTb -o axiliteliteTb
		rm -f *.bo *.ba *.h *.cxx

clean:
		rm -f axiliteliteTb
		rm -f *.*o *.ba *.cxx *.h *.v