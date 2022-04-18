*******
Doxygen
*******

`Doxygen <https://www.doxygen.nl/index.html>`_ is a standard tool for
documenting C++ code.  It works off of comments added to the code to
build documentation (including web pages) describing the structure of
a code and its classes and functions.


We'll continue to work on our ``cxx-array`` repo that we just created.
But to help automate things, we need to make a change to how the
webpage is stored.

Using ``gh-pages``
==================

Our goal is to have GitHub automatically generate our website.  When
we do this, it is best to have the actual web page on a separate branch
so we don't have to keep merging with the regenerating web page
every time we make changes.  This is the purpose of the ``gh-pages``
branch.  It is an *orphaned branch*, so it doesn't have any connection
to ``main``.

Creating the ``gh-pages`` branch
--------------------------------

We'll follow `these instructions
<https://jiafulow.github.io/blog/2020/07/09/create-gh-pages-branch-in-existing-repo/>`_
for creating the ``gh-pages`` branch.

Here's the procedure.  In ``cxx-array/``, make sure you don't have any
uncommitted work, and then do:

.. prompt:: bash

   git checkout --orphan gh-pages
   git reset --hard
   git commit --allow-empty -m "Initializing gh-pages branch"

Now add an ``index.html`` in the empty directory:

.. code:: html

   <!DOCTYPE html>
   <html lang="en">

   <head>
       <title>Hello</title>
       <meta charset="utf-8" />
   </head>

   <body>

   <h1>C++ Array Class</h1>

   <p><tt>Array.H</tt> provides a simple C++ multi-dimensional array class.</p>

   </body>
   </html>

and do:

.. prompt:: bash

   git add index.html
   git commit

Finally, let's push our branch to our repo:

.. prompt:: bash

   git push origin gh-pages

Updating the web location on GitHub
-----------------------------------

Now we need to go back to the GitHub page for our repo and go to
settings and "Pages" and change the "Source" to be "Branch: gh-pages"
and "/ (root)" and save.

After a minute or so, the page should be regenerated and appear at the
same URL as before.

.. note:: 

   From now on, when we want to manually make changes to our web page, we need
   to be on the ``gh-pages`` branch.

We can now switch back to ``main``:

.. prompt:: bash

   git checkout main


Doxygen configuration
=====================

Setting up: https://www.doxygen.nl/manual/starting.html

.. prompt:: bash

   doxygen -g

This creates a file called ``Doxyfile``.  We need to make a few edits to it:

* We want to change ``PROJECT_NAME`` to ``C++ Array``

* We want to change ``OUTPUT_DIRECTORY`` to ``docs``, since that's where we expect our
  source to live

* We'll have Doxygen use the same ``README.md`` that github displays as
  the main page for the Doxygen start page.  This is done by changing:

  .. code::

     USE_MDFILE_AS_MAINPAGE = README.md

* We'll turn off Latex output by changing ``GENERATE_LATEX`` from ``YES`` to ``NO``

* We've been using ``*.H`` for our header files, so we need to add
  this to the list ``FILE_PATTERNS`` in the ``Doxyfile``.

  Doxygen already associates ``.H`` with C++, but just doesn't search
  for it by default.

Annotating our code
===================

Doxygen uses ``///`` as the `documentation comment style
<https://www.doxygen.nl/manual/docblocks.html#specialblock>`_ for C++.
So we would do:

.. code:: c++

   ///
   /// a function to add two numbers
   ///
   double add(double x, double y);

Note that we have an empty ``///`` before and after the documentation.

Now we can annotate our C++ ``Array`` class code.  Here's a version of ``array.H`` that we developed in class with
some documentation comments.

.. literalinclude:: ../../examples/doxygen/array.H
   :language: c++
   :caption: ``array.H``

Add this file to your git repo and commit it.


Trying it out locally
---------------------

We can test out Doxygen locally by doing:

.. prompt:: bash

   doxygen Doxyfile

The HTML will then be in the ``html/`` directory, and we can view the page as:

.. prompt:: bash

   google-chrome html/index.html


Setting up a GitHub action
==========================

Now create a file: ``.github/workflows/gh-pages.yml`` with the following content:

.. code:: yaml

   name: github pages

   on:
     push:
       branches:
         - main

   jobs:
     deploy:
       runs-on: ubuntu-latest
       steps:
         - uses: actions/checkout@v3

         - name: Install pandoc and doxygen
           run: |
             sudo apt install pandoc doxygen

         - name: Setup python
           uses: actions/setup-python@v3
           with:
             python-version: '3.9'

         - name: Install dependencies
           run: python3 -m pip install -r ./requirements.txt

         - name: Build Doxygen
           run: |
                mkdir docs
                doxygen Doxyfile

         - name: Deploy
           uses: peaceiris/actions-gh-pages@v3
           with:
             github_token: ${{ secrets.GITHUB_TOKEN }}
             publish_dir: ./docs
             keep_files: true

This does a little more than we need for now, as it gets us prepped
for Sphinx coming next.

Since we're adding stuff, let's add a ``cxx-array/requirements.txt`` now as well,
with the following content:

.. code::

   sphinx
   sphinx_rtd_theme

And finally add, commit, and push these files to the GitHub repo.

One last thing...
=================

We need to go back to ``gh-pages`` and now link to the Doxygen docs from our ``index.html``.


.. admonition:: voila!

   If everything worked correctly, then the GitHub action should run
   Doxygen and copy the HTML it generated to our web page.


