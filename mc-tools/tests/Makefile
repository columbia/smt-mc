all::
	g++ ex2.c -o ex2 -lpthread -I$(XTERN_ROOT)/include \
	-L$(XTERN_ROOT)/dync_hook -Wl,--rpath,$(XTERN_ROOT)/dync_hook -lxtern-annot \
	-I$(SMT_MC_ROOT)/mc-tools/dbug/install/include -L$(SMT_MC_ROOT)/mc-tools/dbug/install/lib -ldbug-stubs -lpthread
	g++ ex3.c -o ex3 -lpthread -I$(XTERN_ROOT)/include \
        -L$(XTERN_ROOT)/dync_hook -Wl,--rpath,$(XTERN_ROOT)/dync_hook -lxtern-annot \
        -I$(SMT_MC_ROOT)/mc-tools/dbug/install/include -L$(SMT_MC_ROOT)/mc-tools/dbug/install/lib -ldbug-stubs -lpthread
	g++ ex4.c -o ex4 -lpthread -I/home/heming/rcs/smt+mc/xtern/include \
	-L$(XTERN_ROOT)/dync_hook -Wl,--rpath,$(XTERN_ROOT)/dync_hook -lxtern-annot \
	-I$(SMT_MC_ROOT)/mc-tools/dbug/install/include -L$(SMT_MC_ROOT)/mc-tools/dbug/install/lib -ldbug-stubs -lpthread
	g++ -I$(SMT_MC_ROOT)/mc-tools/dbug/install/include -L$(SMT_MC_ROOT)/mc-tools/dbug/install/lib \
	-o test-dbug-on-off test-dbug-on-off.c -ldbug-stubs -lpthread
