*************************
Navigating the Filesystem
*************************

.. admonition:: reading

   We will loosely follow the Software Carpentry lesson on `The Unix Shell <https://swcarpentry.github.io/shell-novice/>`_


The shell
=========

The *shell* is your interface to the operator system.  It implements a *REPL* interface:
Read, Execute, Print, Loop.  This means it:

* Reads the input (commands) you type
* Executes the command
* Prints the result of the command
* Loops back to the start, waiting to read a new command

The power of the shell is that we can easily combine different tools
together to create powerful commands to manipulate files on the
computer.

To access the shell, we need to open a terminal on the computer.

Here's a quick demonstration: the ``echo`` command simply prints anything following
it to the terminal:

.. prompt:: bash

   echo Hello, World



Which shell?
============

There are a wide variety of shells that are used today.  The default
on many systems is `BASH <https://www.gnu.org/software/bash/>`_.  Others
that you might commonly encounter are `zsh <https://www.zsh.org/>`_ and
`fish <https://fishshell.com/>`_.

We'll focus on BASH, and most of what we learn here will apply
directly to the other shells.

Some online shell documentation:

* The `Software Carpentry Unix Shell <https://swcarpentry.github.io/shell-novice/>`_ lesson

* The official `Bash Reference Manual <https://www.gnu.org/software/bash/manual/html_node/index.html>`_

A basic "cheat sheet" is available here: `Unix/Linux Command Reference <https://upload.wikimedia.org/wikipedia/commons/7/79/Unix_command_cheatsheet.pdf>`_.


Setting up
==========

To help us understand some basic shell operations, we will all work
with a collection of files and directories.  Type the following
commands (we'll explain their meaning later) to get the files we
need

.. prompt:: bash

   curl https://swcarpentry.github.io/shell-novice/data/shell-lesson-data.zip --output shell-lesson-data.zip
   unzip shell-lesson-data.zip

This data set comes from the Software Carpentry project.

This creates a directory on the filesystem named ``shell-lesson-data/``.  To begin, we want to
"change directory" into that directory, using the ``cd`` command:

.. prompt:: bash

  cd shell-lesson-data


First walkthrough
=================

Let's walkthrough the `Navigating Files and Directories
<https://swcarpentry.github.io/shell-novice/02-filedir/index.html>`_
lesson together.  You are also encouraged to work through it on your
own outside of class.


Filesystem terminology
======================

We'll use the following terms throughout here:

* ``file system`` : the collection (and organization) of all of the files stored on your computer

* ``file`` : a single unit containing a collection of data

* ``directory`` :  (also known as a folder) a collection of files and directories

* ``home directory`` : your default directory.  When you first open a shell on your computer,
  this is where you are.





Summary
=======

We learned the following commands:

* ``pwd`` : print working directory (where you currently are in the file system)

* ``ls`` : list the contents of a directory

* ``cd`` : change directory


There are a few special directories that always exist the help us navigate:

* ``.`` : the current directory

* ``..`` : one directory above us

* ``~`` : our home directory

The ``/`` character has 2 roles:

* The ``/`` directory is the *root* of the filesystem

* A path uses ``/`` to separate directory names

.. tip::

   The Unix shell uses tab-completion to make it easier to type.
   Start typing a path (or command) and then press the *Tab* key and
   it will either complete it (if there is a unique file / command) or
   display the possible completions.

.. tip::

   You can navigate through your history of commands using the up and down arrows.

