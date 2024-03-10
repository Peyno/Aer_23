PLRU ?= 0
all: clean run

run: test_cache

build: clean build_cache

test_cache: build_cache
		clear
		echo "Running cache Testbench"
		./cacheCtrlTb

plru:
	bsc -u -sim -g mkPLRUTb PLRUTb.bsv
	bsc -sim -e mkPLRUTb -o plruTb
	./plruTb

build_cache:
		bsc -u -sim -g mkCacheCtrlTb CacheCtrlTb.bsv
		bsc -sim -e mkCacheCtrlTb -o cacheCtrlTb
		rm -f *.bo *.ba *.h *.cxx

clean:
		rm -f cacheCtrlTb plruTb
		rm -f *.*o *.ba *.cxx *.h *.v