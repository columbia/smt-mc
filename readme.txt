0. How to play with git submodules.
http://git-scm.com/book/en/Git-Tools-Submodules

1. What to checkout.
$ git clone https://github.com/hemingcui/smt-mc.git smt+mc, OR:
$ git clone git@repair.cs.columbia.edu:smt+mc
$ cd smt+mc
$ git submodule init
$ git submodule update

Importantly, please note that, if you want to checkout a newer version of 
"smt+mc" sometime later (including its submodules "xtern" and "dbug"),
you have to run BOTH "pull" and "submodule update" in the "smt+mc" directory.
And you can ONLY run the two git commands in the root directory "$SMT_MC_ROOT",
otherwise you won't get a correct update. The git submodule mechanism is so painful :)
$ cd $SMT_MC_ROOT
$ git pull
$ git submodule update   (if you don't run this step, submodules won't be updated!!!)


2. Setting env variables, append them to your ~/.bashrc. Run
"echo $SMT_MC_ROOT" to make sure they are correct.
$ export SMT_MC_ROOT=the absolute path of "smt+mc"

If one needs to use a separate env variable in the submodule, she/he could define it like this:
$ export XTERN_ROOT=$SMT_MC_ROOT/xtern/

3. How to build xtern.
Go to $XTERN_ROOT and follow the readme.txt. You may need to (easily) install some 
dependent libraries using "apt-get install ..." while building xtern and its benchmarks.
If you only want to checkout parrot only, not the parrot+dbug eco system, you can
skip the following steps.

4. How to build dbug. Please read the $SMT_MC_ROOT/mc-tools/readme.txt for more details.
You may need to (easily) install some dependent libraries using "apt-get install ..."
while building dbug. Please read this pdf link to install the dependent libraries.
http://www.cs.cmu.edu/~jsimsa/dbug/dbug-manual.pdf

5. How to integrate xtern with dbug (after successfully building both of them):
Build:
$ cd $SMT_MC_ROOT/mc-tools/dbug
$ ./mk-xtern+dbug

6. TBD.

