0. Patch applications for dBug.
The following applications need special patches to run with dBug. 
These patches are disabled by default. (By default applications are built to run with xtern) 
To enable these patches, refer to 'mk' script of each application.
=================================
Program         Patch
---------------------------------
npb-lu          lu.patch
---------------------------------
bdb_rep         divergence.patch
---------------------------------
splash2-fmm     fmm-dbug.patch
---------------------------------
redis           redis-time.patch
=================================

1. Install libraries for dBug.
You may need to install these (and maybe some more) libraries.
Read this doc before you start: www.cs.cmu.edu/~jsimsa/dbug/dbug-manual.pdf
> sudo apt-get install libboost-dev libboost-doc ruby-full rubygems php5 python-dev libxml++2.6-dev binutils-dev
> sudo gem install rubytree
> sudo gem install xml-simple


2. Install dBug.
> cd $SMT_MC_ROOT/mc-tools
> ./mk-dbug
> cd $XTERN_ROOT/obj
Rebuild xtern with "XTERN_PLUS_DBUG=1", as below:
> make ENABLE_OPTIMIZED=0/1 clean \
  && make ENABLE_OPTIMIZED=0/1 XTERN_PLUS_DBUG=1 \
  && make ENABLE_OPTIMIZED=0/1 XTERN_PLUS_DBUG=1 install


3. Set environment variables. Run "echo $LD_LIBRARY_PATH" to make sure it is correct.
> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SMT_MC_ROOT/mc-tools/dbug/install/lib


4. How to run the Parrot+dBug ecosystem and run dBug alone.
There are a number of $SMT_MC_ROOT/xtern/eval/*-dbug.cfg files,
and they are the config files for all programs running with Parrot+dBug or dBug alone.

Run Parrot+dBug ecosystem (use the splash2x benchmark suite as an example):
> cd $SMT_MC_ROOT/xtern/eval/
> ./eval.py -mc --smtmc-only splash2x-dbug.cfg

Run dBug alone:
> cd $SMT_MC_ROOT/xtern/eval/
> ./eval.py -mc --dbug-only splash2x-dbug.cfg

In order to further learn how to run each program with Parrot+dBug or dBug:
> cd $SMT_MC_ROOT/xtern/eval/
> ./eval.py -mc --generate-xml-only splash2x-dbug.cfg
> cd current/172_splash2_fft
Run the Parrot+dBug ecosystem with the FFT program (please make sure to run 
this command in the current/172_splash2_fft/ directory, because the option file
current/172_splash2_fft/local.options has effects):
> $SMT_MC_ROOT/mc-tools/dbug/install/bin/dbug-explorer ./run_xtern.xml
Run dBug alone with the FFT program:
> $SMT_MC_ROOT/mc-tools/dbug/install/bin/dbug-explorer ./run.xml

Also, please refer to this "-h" for more evaluation options:
> cd $SMT_MC_ROOT/xtern/eval/
> ./eval.py -h

