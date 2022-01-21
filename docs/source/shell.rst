*************************
BASH and the Command Line
*************************

.. admonition:: reading

   We will loosely follow the Software Carpentry lesson on `The Unix Shell <https://swcarpentry.github.io/shell-novice/>`_


The "shell" is your interface to the operator system.  It implements a *REPL* interface:
Read, Execute, Print, Loop.  This means it:

* Reads the input (commands) you type
* Executes the command
* Prints the result of the command
* Loops back to the start, waiting to read a new command


To access the
shell, we need to open a terminal on the computer.

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

Filesystem terminology
======================

We'll use the following terms throughout here:

* directory

* file

* home directory : your default directory.  When you first open a shell on your computer,
  this is where you are.

* filesystem




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


Navigating
==========

It's always good to know where you are.  ``pwd`` is the "print working
directory" command -- it simply tells you your location:

.. prompt:: bash

   pwd

If we want to see the contents of the current directory, we use the ``ls`` command:

.. prompt:: bash

   ls

you should see something like::

   creatures  molecules           notes.txt    pizza.cfg  writing
   data       north-pacific-gyre  numbers.txt  solar.pdf

We want to learn the set of commands to move throughout the directory
hierarchy.  ``cd``, as learned above is the "change directory"
command.  There are a few special directories that always exist the help us navigate:

* ``.`` : the current directory

* ``..`` : one directory above us

* ``~`` : our home directory


.. admonition:: try it...

   From your home directory, create a directory / file structure that looks like::

      project
      ├── code
      ├── data
      │   ├── experiment-01.txt
      │   ├── experiment-02.txt
      │   └── experiment-03.txt
      └── results

