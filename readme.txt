0. How to play with git submodules.
http://git-scm.com/book/en/Git-Tools-Submodules

1. Init submodule (only for those who checkout the repo from git).
If you download the repo in a tar bar from Internet, skip this step.
> git clone git@repair.cs.columbia.edu:smt+mc
> cd smt+mc
> git submodule init
> git submodule update

Importantly, please note that, if you want to checkout a newer version of 
"smt+mc" sometime later (including its submodules "xtern" and "dbug"),
you have to run BOTH "pull" and "submodule update" in the "smt+mc" directory.
And you can ONLY run the two git commands in the root directory "smt+mc",
otherwise you won't get a correct update. The git submodule mechanism is so painful :)
> cd smt+
> git pull
> git submodule update   (if you don't run this step, submodules won't be updated!!!)

2. Export env variable. Add this line to your ~/.bashrc.
Run "echo $SMT_MC_ROOT" to make sure it is correct.
> export SMT_MC_ROOT=the absolute path of "smt+mc"

3. How to build Parrot (a.k.a., xtern). Refer to $SMT_MC_ROOT/xtern/readme.txt.
It also contains information of our performance hints.

4. How to build Parrot with a model checking tool dbug.
Refer to $SMT_MC_ROOT/mc-tools/readme.txt.

