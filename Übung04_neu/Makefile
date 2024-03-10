CXXFLAGS=-O3 -Wall -Wno-unused -D_FILE_OFFSET_BITS=64 -fPIC -Wno-uninitialized -fpermissive -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0
BSC_CXXFLAGS=$(patsubst %,-Xc++ %,$(CXXFLAGS))
SIMDIR=sim
BDIR=build
FDIR=fdir
INFODIR=info

sim_all: bluesim_TestSlidingWindow bluesim_AcceleratorChecker bluesim_AcceleratorTb bluesim_GaussTb bluesim_GaussChecker bluesim_BufferTb

bluesim_%: bsv_compile_% imageReader.o imageWriter.o oracle.o $(INFODIR) $(BDIR) $(SIMDIR) $(FDIR)
	bsc -info-dir $(INFODIR) -fdir $(FDIR) -bdir $(BDIR) -simdir $(SIMDIR) $(BSC_CXXFLAGS) -parallel-sim-link 2 -sim -e mk$* -Xl "imageReader.o" -Xl "imageWriter.o" -Xl "oracle.o" -Xl -lpng -Xl -lz -Xl -lX11 -Xl -lpthread -o $*_bluesim

bsv_compile_%: $(INFODIR) $(BDIR) $(SIMDIR) $(FDIR)
	bsc -info-dir $(INFODIR) -fdir $(FDIR) -bdir $(BDIR) -simdir $(SIMDIR) -u -show-range-conflict -keep-fires -show-schedule -keep-inlined-boundaries -sim -g mk$* $*.bsv

oracle.o: oracle.cpp
	c++ $(CXXFLAGS) -c -o "oracle.o" "oracle.cpp"

imageReader.o: imageReader.cpp
	c++ $(CXXFLAGS) -c -o "imageReader.o" "imageReader.cpp"

imageWriter.o: imageWriter.cpp
	c++ $(CXXFLAGS) -c -o "imageWriter.o" "imageWriter.cpp"

$(BDIR):
	mkdir $(BDIR)

$(SIMDIR):
	mkdir $(SIMDIR)

$(FDIR):
	mkdir $(FDIR)

$(INFODIR):
	mkdir $(INFODIR)

clean:
	rm -rf $(INFODIR) $(BDIR) $(SIMDIR) $(FDIR) *.*o *.*a *.cxx *mk*.h imported_BDPI_functions.h *.v *_bluesim *.log *Out*.png *.vcd