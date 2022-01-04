************************
BASH and the Command Line
************************

The "shell" is your interface to the operator system.  To access the
shell, we need to open a terminal on the computer.

Which shell?
============

There are a wide variety of shells that are used today.  The default
on many systems is [BASH](https://www.gnu.org/software/bash/).  Others
that you might commonly encounter are [zsh](https://www.zsh.org/) and
[fish](https://fishshell.com/).

We'll focus on BASH, and most of what we learn here will apply
directly to the other shells.

Some online shell documentation:

* The [Software Carpentry Unix Shell](https://swcarpentry.github.io/shell-novice/) lesson

* The official [Bash Reference Manual](https://www.gnu.org/software/bash/manual/html_node/index.html)

Setting up
==========

To help us understand some basic shell operations, we will all work
with a collection of files and directories.  Type the following
commands (we'll explain their meaning later) to get the files we
need

.. code:: bash

   curl https://swcarpentry.github.io/shell-novice/data/shell-lesson-data.zip
   unzip shell-lesson-data.zip

This data set comes from the Software Carpentry project.


