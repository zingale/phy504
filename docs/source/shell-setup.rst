************************
Dotfiles and the Mathlab
************************

Unix programs often store configuration options in a *dot-file* in
your home directory (e.g., ``.emacs``).

A quirk of the MathLab computers is that our home directory is erased
every 48 hours.  However, the machines are setup to run a script
``~/MySBFiles/mybashrc`` each time you login, so we can use that to
work around the home directory limitation.

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

We'll discuss loops and if-tests in the shell later, but there is one
other new command we will note here: ``ln``.  ``ln -s`` creates a
*symbolic link* to a file -- it makes it appear as if these files are
in our home directory ``~/`` when they actually live elsewhere in our
path.

.. note::

   You can add other shortcuts or ``alias`` -es to you ``mybashrc`` file.
   A good thing to do is to also add:

   .. code:: bash

      alias rm='rm -i'
      alias cp='cp -i'
      alias mv='mv -i'

   This will force those commands to ask before overwriting or deleting a file.

Now save and move it to ``~/MySBFiles/``:

.. prompt:: bash

   mv -i mybashrc ~/MySBFiles/


Now you should be able to put any configuration files into
``~/MySBFiles/dotfiles/`` and then will be linked to your home
directory when you log in.  We'll need this later when we work with
git.


Git configuration
=================

Before we start using git we need to configure it.  This will
create a file ``~/.gitconfig`` with global settings for using git.

First we need to tell git our name and email -- this will be used in
the log files when we make changes so other users know who made the
changes.

.. prompt:: bash

   git config --global user.name "name"
   git config --global user.email "email"

where you replace ``"name"`` with your name and ``"email"`` with your email address.

Next we need to tell git which editor we are going to use.  We'll look at editors more later,
but for now we'll use ``nano``.

.. prompt:: bash

   git config --global core.editor "nano -w"

see https://swcarpentry.github.io/git-novice/02-setup/index.html#line-endings for other options.

Now, we want to ensure that this file is linked to our home directory when we log in:

.. prompt:: bash

   mv .gitconfig MySBFiles/dotfiles/

Note: you might get a warning that it cannot preserve access times -- that is okay.

To test this, open up a new terminal and do

.. prompt:: bash

   ls -al

and make sure you see the ``.gitconfig`` file.  It might look something like:

.. code::

   lrwxrwxrwx  1 mzingale domain users   66 Jan 30 10:19 .gitconfig -> /home/campus.stonybrook.edu/mzingale/MySBFiles/dotfiles/.gitconfig

The ``->`` in the name shows that it is a link to the actual file
stored in our ``MySBFiles/`` directory.


