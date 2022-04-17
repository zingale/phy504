************
Github Pages
************

`Github Pages <https://pages.github.com/>`_ allows us to host a webpage
directly on github.  Often we do this in our project repo itself, so
we keep the code and documentation / webpage all in one place.

Let's learn how to host our webpage on github.  First lets create a
new repository:

.. figure:: github-new-repo.png
   :align: center
   :width: 90%

We'll work on building documentation for our array class, so let's
name this project ``cxx-array`` and check the ``add README`` option.
Keep everything else the same:

.. figure:: github-cxx-array-repo.png
   :align: center
   :width: 90%

Now we can clone the repo on our local machine by finding the location
under the "code" button:

.. figure:: github-clone-button.png
   :align: center
   :width: 90%

We would do:

.. prompt:: bash

   git clone git@github.com:<username>/cxx-array.git

(where you replace ``<username>`` with your github username to get your
repo.

Now go to the *settings* for this repo and go to the *Pages* settings
and enable github pages for ``main`` in the ``/docs`` directory.  And
click *save*.

.. figure:: github-pages.png
   :align: center
   :width: 90%


Now in our cloned repository, we need to create the ``docs/`` directory
and put our initial page there.  In your ``cxx-array/`` create the ``docs/``
directory:

.. prompt:: bash

   mkdir docs/

Now let's add the following ``index.html`` there:

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

   <body>
   </html>

and finally add it and push:

.. prompt:: bash

   git add index.html
   git commit -m "first webpage"
   git push

After a minute or two, we can view our page:

https://zingale.github.io/cxx-array/

