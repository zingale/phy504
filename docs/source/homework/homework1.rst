**********
Homework 1
**********

.. admonition:: due: 2022-02-09

   While you are free to talk with your classmates and ask me / others
   questions on slack, you are expected to do your own work for these
   assignments.

#. In class we showed how to clone the repo
   https://github.com/phy504-sbu-s24/test-repo, make a fork, and push to
   our fork, and then do a pull-request to ask for your changes to be
   made to the original repo.

   Add a file of the form ``username.txt`` containing your name
   (replacing ``username`` with your Github username) to your fork and
   issue a pull request for it to be merged into the main repo.

   Note: you might have done this during class time -- if so, you are done.

   You don't need to turn anything in for this -- I'll see the
   pull-request if you were successful and you will get credit.

#. Create a git repo called ``hello_C`` in your github profile and add a
   hello.cpp with the following content:

   .. code:: c++

      #include <iostream>

      int main() {

          std::cout << "Hello, World!" << std::endl;

      }

   and commit this to your repo.

   Now add a second commit, with a ``.gitignore`` telling git to ignore an executable named ``hello``.

   Push this all back to your github repo.  Your repo should show 2
   commits with descriptive git log messages.

   For your solution, simply e-mail me the URL of your repo.

