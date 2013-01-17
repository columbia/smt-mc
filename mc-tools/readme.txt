1. Add patch.
$ cd $SMT_MC_ROOT/mc-tools/dbug
$ patch -p1 < ../fix-dbug-warning.txt
$ patch -p1 < ../fix-rename.txt

2. Run the script to install dbug with thrift.
$ cd $SMT_MC_ROOT/mc-tools
$ ./mk-dbug

3. How to run dbug with application.
$ cd $SMT_MC_ROOT/xtern/apps/pbzip2
$ ./dbug-run
