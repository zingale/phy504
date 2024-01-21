***************************
Looping on the Command Line
***************************

.. admonition:: reading

   We will loosely follow the Software Carpentry `Loops
   <https://swcarpentry.github.io/shell-novice/05-loop.html>`_
   lesson from `The Unix Shell
   <https://swcarpentry.github.io/shell-novice/>`_


If-Tests
========

That lesson does not cover *if-tests*, so we will supplement that
here.  Some information can be found on the Linux Documentation Project
`Conditional Statements
<https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_07_01.html>`_
section.


And if-test has the form:

.. code:: bash

   if [ condition ]
   then
      # do something
   fi

where *condition* is evaluated, and if true, we take the action
specified in the block.  ``fi`` is the *end-if* statement, ending the
block of code that is conditionally executed.

Let's go back to looping over the files in ``creatures/`` that the
Software Carpentry lesson did.  But let's add some that don't exist
and have our loop test for that

.. code:: bash

   for creature in basilisk.dat pegasus.dat minotaur.dat centaur.dat unicorn.dat
   do
      if [ ! -e ${creature} ]
      then
         echo creature ${creature} does not exist
      fi
   done
 


Now, let's look back at the loop we put into our ``mybashrc`` and now
we can understand what it is doing:

.. code:: bash

   for dotfile in ~/MySBFiles/dotfiles/.*
   do
      if [ ! -f ~/`basename $dotfile` ]; then
         ln -s $dotfile ~/;
      fi;
   done

Notice that you can put the ``then`` on the same line as ``if`` if you separate with a ``;``.
There is still one new command here, ``basename`` and one new piece of syntax -- using the backticks, \`.

We can see what basename does by looking at the man page:

.. prompt:: bash

   man basename

The backtick is a special syntax in a shell command.  Essentially it means:

* first execute any commands inside the openning \` and closing \`

* substitute the output of the command in place and then use do the rest of the script

Note that an equivalent way of doing this in Bash is to use ``$( ... )``.

So for example, we could do:

.. code:: bash

   for creature in `ls *.dat`
   do
      echo ${creature}
   done

(but for this simple example, we also know that a wildcard would work here).


Here's an example where we change the name of the extension of the file from `.dat` to `.out`

.. code:: bash

   for creature in *.dat
   do
      echo `basename $creature .dat`.out
   done

.. tip::

   When we do ``${creature}`` above, we are treating asking Bash to
   substitute the value of the variable ``creature``.  There are actually
   a lot of handy operations we can do on shell variables, as you can
   see here: http://www.gnu.org/software/bash/manual/html_node/Shell-Parameter-Expansion.html


Summary
=======

We learned the following commands:

* ``for``, ``do``, and ``done`` : the syntax for a loop

* ``if`` and ``fi`` : the syntax for an if-test

* ``history`` : see the list of commands we used in this session

