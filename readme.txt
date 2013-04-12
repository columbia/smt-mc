0. Parrot system evaluation raw data. Please refer to this google doc:
 
https://docs.google.com/spreadsheet/ccc?key=0Arky53jIFG9hdE03ZmZrYlU3dXM4Um5xLU85OGxCMGc#gid=0

There are multiple tabs in this doc. The "performance overhead" tab
shows the performance overhead of Parrot over nondeterministic executions.
The "A" column in this tab shows what kinds of performance hints are added.
"@" means soft barriers, "N" means performance critical sections, and "x" or blank
means no hints are added. The "performance comparisons" tab shows the performance
comparisons of three systems, Parrot, dthreads and CoreDet.
The "model checking results" tab shows the model checking results
of the Parror+dBug ecosystem.


1. Get the repository (only for those who checkout the repo from git).
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
> cd smt+mc
> git pull
> git submodule update   (if you don't run this step, submodules won't be updated!!!)


2. Export env variable $SMT_MC_ROOT. It will be used
in the repository to compile and run programs.
Add this line to your ~/.bashrc, and run "echo $SMT_MC_ROOT" to make sure it is correct.
> export SMT_MC_ROOT=the absolute path of "smt+mc"


3. How to build Parrot (a.k.a., xtern). Refer to $SMT_MC_ROOT/xtern/readme.txt.
It also contains information of our performance hints.


4. How to build Parrot with a model checking tool dBug.
Refer to $SMT_MC_ROOT/mc-tools/readme.txt.

