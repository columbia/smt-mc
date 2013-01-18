0. Add patch.
$ cd $SMT_MC_ROOT/mc-tools/dbug
$ patch -p1 < ../fix-dbug-warning.txt
$ patch -p1 < ../fix-rename.txt

1. Libraries.
You may need to install these (and maybe some more) libraries.
Read this before you start: www.cs.cmu.edu/~jsimsa/dbug/dbug-manual.pdf
$ sudo apt-get install libboost-dev libboost-doc ruby-full rubygems php5 python-dev
$ sudo gem install rubytree
$ sudo gem install xml-simple

2. Run the script to install dbug with thrift.
$ cd $SMT_MC_ROOT/mc-tools
$ ./mk-dbug

3. Update the $PATH in  your ~/.bashrc, run "echo $PATH" to make sure it is correct.
$ export PATH=$PATH:$SMT_MC_ROOT/mc-tools/dbug/install/bin

4. How to use dbug.
$ cd $SMT_MC_ROOT/mc-tools
$ gcc $SMT_MC_ROOT/mc-tools/dbug/tutorial/example-2.c -lpthread -o dbug-ex2
$ explorer.rb --prefix $SMT_MC_ROOT/mc-tools/dbug/install/ ./dbug-ex2

Then you will see a "dbug-logs" directory in your local working directory, and
a few "dbug-history-x". E.g., "dbug-history-1" is one of the exploration dbug explored.
Also, there will be trace files located in /tmp/dbug/.

One of the dbug-history-x (a sync operation scheduling plan) could look like this:

1 1 1 1 0
1:pthread_mutex_init:RESOURCE_CREATE:1 0 0 0 0 0 0 0 0:4077692927:
2 2 2 2 1
1:pthread_mutex_lock:RESOURCE_ACCESS:2 0 0 0 0 0 0 0 0:4077692927:2:
2:pthread_mutex_lock:RESOURCE_ACCESS:1 1 0 0 0 0 0 0 0:4077692927:2:
2 1 2 2 2
2:pthread_mutex_unlock:RESOURCE_RELEASE:1 2 0 0 0 0 0 0 0:4077692927:
1:pthread_mutex_lock:RESOURCE_ACCESS:2 0 0 0 0 0 0 0 0:4077692927:2:
1 1 1 1 0 3
1:pthread_mutex_lock:RESOURCE_ACCESS:2 0 0 0 0 0 0 0 0:4077692927:2:
1 1 1 1 0 4
1:pthread_mutex_unlock:RESOURCE_RELEASE:3 0 0 0 0 0 0 0 0:4077692927:
1 1 1 1 0 5
1:pthread_join:THREAD_JOIN:4 0 0 0 0 0 0 0 0:2:
1 1 1 1 0 6
1:pthread_mutex_destroy:RESOURCE_DELETE:5 2 0 0 0 0 0 0 0:4077692927:


Please refer to the user manual for more details of this scheduling plan.
http://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/15213-f10/www/manual.pdf


5. If you want to run a program with multiple arguments, you need a quote.
And make sure you use absolute path, avoid "~" within your quote, since seems
that ruby does something weird to this character.

E.g., use this "chk-run" script for pbzip2:
$ cd $SMT_MC_ROOT/xtern/apps/pbzip2
$ ./mk
$ ./chk-run

