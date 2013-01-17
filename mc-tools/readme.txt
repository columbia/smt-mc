1. Add patch.
$ cd $SMT_MC_ROOT/mc-tools/dbug
$ patch -p1 < ../fix-dbug-warning.txt
$ patch -p1 < ../fix-rename.txt

2. Run the script to install dbug with thrift.
You may need to "apt-get install" some libraries depending on thrift.
Read this before you run "mk-dbug": www.cs.cmu.edu/~jsimsa/dbug/dbug-manual.pdf
$ cd $SMT_MC_ROOT/mc-tools
$ ./mk-dbug

3. How to run dbug with one application.
$ cd $SMT_MC_ROOT/xtern/apps/pbzip2
$ ./dbug-run
