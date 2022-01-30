*****************
A Git Walkthrough
*****************

We'll do a walkthrough on git.

.. note::

   An alternate walkthrough is provided by the `Software Carpentry
   <https://software-carpentry.org/>`_ lesson `Version Control with
   Git <https://swcarpentry.github.io/git-novice/index.html>`_ and it
   is highly suggested that you work through that on your own.

There are a few ways in which we can use git.  We'll start by assuming
that we are the only developer on a project and learn the basics and
then we'll see how to share what we've done locally and remotely using
GitHub.

.. note::

   You should create a `GitHub account <https://github.com>`_.  Pick a
   username that is professional and meaningful.

Our goal here is to create a project (we'll call the directory
``project/``) and have git keep track of the files and changes to our
project.

#. First create a project directory with some basic content:

   .. prompt:: bash

      mkdir project
      cd project
      echo "this is the start of my awesome new project" > README

#. Now let's tell git that we want to track this directory.

   .. prompt:: bash

      git init

   If you do ``ls`` it will look like nothing has changed, but this
   command created a ``.git/`` sub-directory in our project, which you
   can see by doing:

   .. prompt:: bash

      ls -a

#. The version of git on the MathLab computers is old, and it will
   create a default *branch* named ``master``.  This has been
   deprecated and the community is moving to the name ``main`` for the
   default, so we'll change this now:

   .. prompt:: bash

      git checkout -b main

   We'll talk about branches in a bit.  Just note that with a recent
   version of git, this command would be unnecessary.

#. At this point, we haven't told git about any of our files.  To tell git
   to track the file ``README`` we do:

   .. prompt:: bash

      git add README
      git commit README

   .. note::

      When you ``commit``, and editor window will pop up asking you to
      make a commit message.  This is where you describe the change so
      "future you" or someone else can understand why the change was
      made.

   We set our default editor to nano, so type in your message, save
   the change with ``^O``, and then exit with ``^X``.

   We can now ask git the state of our project with

   .. prompt:: bash

      git status

   You should see something like:

   .. code::

      On branch main
      nothing to commit, working tree clean

   We can also see our log message:

   .. prompt:: bash

      git log

   The output will look like:

   .. code::

      commit 2001a0e996110926a576dcb5fc13fc8022864d0b (HEAD -> main)
      Author: Michael Zingale <michael.zingake@stonybrook.edu>
      Date:   Sun Jan 30 13:11:24 2022 -0500

          my first change

   But should show your name, and the long string of numbers of
   letters are ``commit`` on the first line will be different.  We'll call
   the string the ``hash``.  More on that later...

#. Now let's modify the file

   Open the file with nano and add a second line of text:

   .. prompt:: bash

      nano README

   Here's my file:

   .. prompt:: bash

      cat README

   .. code::

     this is the start of my awesome new project
     this is now under version control!

   What does git think about our changes?

   .. prompt:: bash

      git status

   you should see something like:

   .. code::

      On branch main
      Changes not staged for commit:
        (use "git add <file>..." to update what will be committed)
        (use "git checkout -- <file>..." to discard changes in working directory)

              modified:   README

      no changes added to commit (use "git add" and/or "git commit -a")

   This is telling you that you have local changes but you haven't yet told git to care about them.

   Let's ``add`` the changes:

   .. prompt:: bash

      git add README


   and now ``git status`` will show something like:

   .. code::

      On branch main
      Changes to be committed:
        (use "git reset HEAD <file>..." to unstage)

              modified:   README


   .. note::

      **What is add really doing?**

      Git has a concept call the *staging area*.  When we ``add`` a
      file, git puts the changes into the staging area.  We can add
      multiple changes via separate ``git add`` invocations, and git
      will accumulate these in the staging area.

      Once we do ``git commit``, git will record the all of the
      changes that are staged into a "commit".

   To have git track these changes, we can now just do:

   .. prompt:: bash

      git commit

   Notice that we didn't specify the file here -- all the changes that
   were staged were part of that commit.

   If we now do ``git log``, we'll see that there is a second commit
   in our project, and it has a different unique hash:

   .. code::

      commit 78b6925752e8388dddb3d65b6355bfeeb87b87a7 (HEAD -> main)
      Author: Michael Zingale <michael.zingake@stonybrook.edu>
      Date:   Sun Jan 30 14:23:09 2022 -0500

          make some modifications

      commit 2001a0e996110926a576dcb5fc13fc8022864d0b
      Author: Michael Zingale <michael.zingake@stonybrook.edu>
      Date:   Sun Jan 30 13:11:24 2022 -0500

          my first change


#. Let's create and add another file.

   We'll write our first shell script.  Open a new file in nano:

   .. prompt:: bash

      nano myscript

   and copy-paste the following content into it:

   .. code:: bash

      ls -l > script.out

   be sure to end with a new line.

   Now, this script is not that fancy and it needs to be run as:

   .. prompt:: bash

      bash ./myscript

   when you do this, you should see the output ``script.out`` created.

   Now let's tell git that we want it to track this:

   .. prompt:: bash

      git add myscript
      git commit

   Be sure to add a useful message.

#. Ignoring things.

   Let's look at the status of our project:

   .. prompt:: bash

      git status

   You'll see something like:

   .. code::

      On branch main
      Untracked files:
        (use "git add <file>..." to include in what will be committed)

              script.out

      nothing added to commit but untracked files present (use "git add" to track)

   It is telling us that it is not keeping track of ``script.out``.
   But we don't want it to -- that is the output from running out
   script, and generally we don't keep the output of our codes in
   version control.

   So we'd like to tell git to ignore that file.  The way to do this is to
   create a ``.gitignore`` file:

   .. prompt:: bash

      nano .gitignore

   and add the following:

   .. code::

      *.out

   now if you do ``git status``, that file will not appear, but ``.gitignore`` does!  So
   add ``.gitignore`` to git by doing ``git add`` followed by ``git commit``.


#. Going back in time...

   Let's look at our project history so far:

   .. prompt:: bash

      git log

   We see something like this (again, your hashes will be different)

   .. code::

      commit 834db7fafeff3d95a314a3f3772c9443a59e2e41 (HEAD -> main)
      Author: Michael Zingale <michael.zingake@stonybrook.edu>
      Date:   Sun Jan 30 16:00:24 2022 -0500

          add a .gitignore

      commit 974e7cee6045d1cd95d4d11f4af28d19cb37cb4c
      Author: Michael Zingale <michael.zingake@stonybrook.edu>
      Date:   Sun Jan 30 15:55:35 2022 -0500

          my first shell script

      commit 78b6925752e8388dddb3d65b6355bfeeb87b87a7
      Author: Michael Zingale <michael.zingake@stonybrook.edu>
      Date:   Sun Jan 30 14:23:09 2022 -0500

          make some modifications

      commit 2001a0e996110926a576dcb5fc13fc8022864d0b
      Author: Michael Zingale <michael.zingake@stonybrook.edu>
      Date:   Sun Jan 30 13:11:24 2022 -0500

          my first change

   Let's go back to the start of the project -- we want to go to just after the first
   commit

   .. prompt:: bash

      git checkout 2001a0e996110926a576dcb5fc13fc8022864d0b

   Now if you do ``ls``, you'll see just the ``README`` file, and it will appear
   with just the first edit.


Summary
=======

We learned:

* ``git init``

* ``git add``

* ``git commit``

* ``git status``

* ``git log``
