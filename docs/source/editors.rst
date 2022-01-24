*******
Editors
*******

We already looked at ``nano`` to edit files.  An editor not only allows us to write our source
code, but it can also help us by:

* Doing syntax highlighting of the language

* Handle indentation for us

* Show mismatched ``)`` and ``}`` in our code

* Autocompleting variable and function names

and more.

Let's look at some common editors

.. figure:: https://imgs.xkcd.com/comics/real_programmers.png
   :width: 90%
   :align: center
   :alt: xkcd comic on editors

   from XKCD

Dotfiles and the Mathlab
========================

Unix programs often store configuration options in a *dot-file* in
your home directory (e.g., ``.emacs``).

A quirk of the MathLab computers is that our home directory is erased
every 48 hours.  To work around this, we need to do the following:

Create a directory called ``dotfiles/`` in your shared ``MySBFiles/`` directory:

.. prompt:: bash

   mkdir ~/MySBFiles/dotfiles

Create a file called ``mybashrc`` in your ``MySBFiles/`` directory
that will link the dotfiles into your home directory each time you log
in.  We'll create this file in our home directory and then move it there,
to be safe:

.. prompt:: bash

   nano ~/mybashrc

Copy and paste the following into that file:

.. code:: bash

   for dotfile in ~/MySBFiles/dotfiles/.*
   do
      if [ ! -f ~/`basename $dotfile` ]; then
         ln -s $dotfile ~/;
      fi;
   done

Now save and move it to ``~/MySBFiles/``:

.. prompt:: bash

   mv -i mybashrc ~/MySBFiles/


Now you should be able to put any configuration files into
``~/MySBFiles/dotfiles/`` and then will be linked to your home
directory when you log in.  We'll need this later when we work with
git.





nano
====

``nano`` is a pretty basic editor and very easy to use.  We already saw that when we saved our
``hello.cpp`` it recognized it as C++ code and highlighted it in different colors.

There are some basic customizations you can make by creating a ``~/.nanorc`` file,
some of which are listed here: `customizing nano <https://timnash.co.uk/customising-nano-productivity-friday/>`_


emacs
=====

Emacs


You can run emacs in a terminal (instead of a separate window), by doing:

.. prompt:: bash

   emacs -nw

This is useful for remote connections.

Here's my `emacs config file <https://github.com/zingale/mysystem/blob/master/.emacs>`_ file.


vi
==


VS Code
=======

