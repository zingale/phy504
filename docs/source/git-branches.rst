************
Git Branches
************

When we develop as a team, we often use *branches* to organize our
changes.  Here we walk through an example of branches.

To get more practice, we'll start a new project and initialize it.

Let's repeat the setup we did before...

.. prompt:: bash

   mkdir project2
   cd project2
   echo "a second git project" > README
   git init

Now let's look at the command we did last time to name our branch
``main`` instead of ``master``:

.. prompt:: bash

   git checkout -b main

This is a new (sub-)command, ``checkout``.


.. note::

   You can get help on git commands via manpages using a hyphen
   between ``git`` and the command name, e.g.:

   .. prompt:: bash

      man git-checkout

The ``checkout`` command is used to switch branches or to restore
files.  The command we did above, ``git checkout -b main`` created a
new branch called ``main`` and switched us to it.

Now let's add our ``README`` to git and commit:

.. prompt:: bash

   git add README
   git commit

(Remember to enter a log and save...)

A Feature Branch
================

Now let's imagine that our project is mature and we don't want to break it as
we test out some new ideas.  This is where *branches* come into play.

Let's create a new branch called ``feature`` that we can work on without
disturbing our code in ``main``.

.. prompt:: bash

   git checkout -b feature

This creates a new branch called ``feature`` that is initially identical to ``main``.

You can tell what branch you are on by doing:

.. prompt:: bash

   git branch

and we see:

.. code::

   * feature
     main

The ``*`` indicates which branch we are currently on.

What about the log?

.. prompt:: bash

   git log

we see:

.. code::

   commit ad95254da553cd2eb163205604c08e868165b1e3 (HEAD -> feature, main)
   Author: Michael Zingale <michael.zingale@stonybrook.edu>
   Date:   Mon Jan 31 13:32:43 2022 -0500

       start of my new project

Notice that the commit line shows that both ``feature`` and ``main``
are at the same hash, and it also calls that commit ``HEAD``.
``HEAD`` is the most recent change on the branch.


Now let's make a change.

Let's put our "Hello, World" code in our repo!  Create a file called
``hello.cpp`` and add the following:

.. code:: c++

   #include <iostream>

   int main() {

       std::cout << "Hello, World!" << std::endl;

   }

Let's add it to git control:

.. prompt:: bash

   git add hello.cpp
   git commit

Now look at the log:

.. code::

   commit 2b35469b403d25d601703a3e8c986c62f7822e3e (HEAD -> feature)
   Author: Michael Zingale <michael.zingale@stonybrook.edu>
   Date:   Mon Jan 31 13:54:34 2022 -0500

       our first program

   commit ad95254da553cd2eb163205604c08e868165b1e3 (main)
   Author: Michael Zingale <michael.zingale@stonybrook.edu>
   Date:   Mon Jan 31 13:32:43 2022 -0500

       start of my new project

Now it is clear that ``main`` is still on the last commit but
``feature`` is on the latest (``HEAD``) commit.




We can visualize the *graph* of changes:

.. prompt:: bash

   git log --graph --all --oneline

