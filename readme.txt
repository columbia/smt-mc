0. How to play with git submodules.
http://git-scm.com/book/en/Git-Tools-Submodules

1. What to checkout.
You need <username, password> in order to checkout the dbug submodule. Ask Heming Cui.
$ git clone git@repair.cs.columbia.edu:apps
$ git clone git@repair.cs.columbia.edu:smt+mc
$ cd smt+mc
$ git submodule init
$ git submodule update

2. Setting env variables, append them to your ~/.bashrc. Run "echo $APPS_DIR" and
"echo $SMT_MC_ROOT" to make sure they are correct.
$ export APPS_DIR=the absolute path of "apps"
$ export SMT_MC_ROOT=the absolute path of "smt+mc"

If one needs to use a separate env variable in the submodule, she/he could define it like this:
$ export XTERN_ROOT=$SMT_MC_ROOT/xtern/

3. How to build xtern.
Go to $XTERN_ROOT and follow the readme.txt. You may need to (easily) install some 
dependent libraries using "apt-get install ..." while building xtern and its benchmarks.

4. How to build dbug. Please read the $SMT_MC_ROOT/mc-tools/readme.txt for more details.
You may need to (easily) install some dependent libraries using "apt-get install ..."
while building dbug. Please read this pdf link to install the dependent libraries.
http://www.cs.cmu.edu/~jsimsa/dbug/dbug-manual.pdf

5. How to integrate xtern with dbug (after successfully building both of them):
Build:
$ cd $SMT_MC_ROOT/mc-tools/dbug
$ patch -p1 < ../disable-dbug-intra-process.patch
$ patch -p1 < ../add-ld-preload-xtern.patch
$ cd $SMT_MC_ROOT/mc-tools
$ ./mk-xtern+dbug

Run:
$ gcc $SMT_MC_ROOT/mc-tools/dbug/tutorial/example-2.c -lpthread -o dbug-ex2
$ $SMT_MC_ROOT/mc-tools/dbug/install-xtern+dbug/bin/explorer.rb --prefix $SMT_MC_ROOT/mc-tools/dbug/install-xtern+dbug/ ./dbug-ex2

