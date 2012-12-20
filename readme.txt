1. What to checkout.
git clone git@repair.cs.columbia.edu:apps
git clone git@repair.cs.columbia.edu:smt+mc

2. Setting env variables, append them to your ~/.bashrc.
export APPS_DIR=(the absolute directory path that you run the git clone commands)/apps
export SMT_MC_ROOT=(the absolute directory path that you run the git clone commands)/smt+mc

If one needs to use a separate env variable in the submodule, she/he could define it like this:
export XTERN_ROOT=$SMT_MC_ROOT/xtern/

3. How to build the tool.
tbd.

XXX. How to play with git submodules.
http://git-scm.com/book/en/Git-Tools-Submodules
