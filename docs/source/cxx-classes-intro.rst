Introduction to Classes
=======================

.. admonition:: reading

   Cyganek section 3.15



Classes are objects that hold both data and functions that know how to operate on the data.

.. note::

   In C++, both ``struct`` and ``class`` create a class, with the difference being
   whether the data is publicly accessible by default.

We'll start by doing a ``struct`` with a *constructor*---this will
behave like a class, except by default all of the data will be
publicly available.

Here's the basic format of a struct / class:

.. code:: c++

   struct ClassName {

       // data members are declared here

       ClassName(int param1, int param2) {
           // do any initialization for when we create a ClassName object
       }

       // other member functions here

   };

The most important function is the *constructor*.  When we create an
instance of our class, the constructor function is called and does any
initialization / setup that the class requires.

.. note::

   The constructor always has the same name as the class/struct.

Here's a concrete example---we'll build on our vector of planets, but making a class/struct
that holds the data and member functions that know how to operate on that data.

First well define the ``struct`` called ``SolarSystem`` and write the constructor:

.. literalinclude:: ../../examples/classes/solar_system.H
   :language: c++
   :caption: ``solar_system.H``

Keeping with our strategy to reuse code, this uses our ``planet.H`` header from before (and
will rely on the ``planet.cpp`` source file that implemented some functions).

Some notes:

* After the constructor name and arguments there is a ``:`` and an initialization:

  .. code:: c++

     SolarSystem(const double mass)
       : star_mass{mass}
     {
        ...

  this is called the *initialization list*.  Any member data specified in that (comma-separated)
  list is initialized when an object is created as an instance of the class.

* In the constructor body we have an ``assert()`` statement---this
  will abort the code if it is false.  This is a way to add runtime
  checking to the code to ensure that it is being used properly /
  matching your assumptions.

* We end with some forward declarations of *member functions* of the class.  These functions
  will have access to the class data directly.

To *instantiate* the class, i.e., create a ``SolarSystem`` object, we would do:

.. code:: c++

   SolarSystem ss(1.0);

where we pass the constructor arguments at the time we create our object.

.. note::

   A class can have multiple constructors.  A constructor that takes no arguments
   is called the *default constructor*.

We provide implementations of the member functions in a separate file:

.. literalinclude:: ../../examples/classes/solar_system.cpp
   :language: c++
   :caption: ``solar_system.cpp``


Notes:

* For each of the member functions, since we are defining them outside
  of the ``struct SolarSystem {};``, we need to include the namespace
  and scope operator, ``::``, to reference the class that they belong
  to.

* Our ``add_planet()`` member function checks to see if a planet already exists.

Finally, we can use our ``SolarSystem`` class.  Here's a ``main()`` function:

.. literalinclude:: ../../examples/classes/test_solar_system.cpp
   :language: c++
   :caption: ``test_solar_system.cpp``

We can compile this using the same general ``GNUmakefile`` we developed previously.  We'll
add two features to it:

.. literalinclude:: ../../examples/classes/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

The first is a new target: ``clean``.  By doing

.. prompt:: bash

   make clean

We will remove all of the object files (``*.o``) and the executable.

The second new feature is the addition of some compilation flags:

.. code:: make

   CFLAGS := -Wall -Wextra -Wpedantic -Wshadow

These are specific to the GNU compilers, and turn on some warnings
that help spot code mistakes.  See `GCC warning options
<https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>`_ for more
details.

The main advantage to using a class here is that we don't need to know
how the planet data is actually stored (in this case in a ``std::vector<Planet>``).
By creating member functions that are part of the class, we hide the implementation
details from the user.  Instead they are given a simple set of functions
to interact with the data.


.. admonition:: try it...

   Let's make our class more useful.  Lets implement the following functions:

   .. code:: c++

      int get_planet(const std::string& name, Planet& p_return);

      double get_period(const std::string& name);

   The first will take a ``Planet`` in the argument list (by
   reference) and if ``name`` exists, it will return its properties
   through the reference.  The return value here is ``int`` and is
   meant to return a status that we can check to see if the ``name``
   was a valid planet.

   The second will take a planet ``name`` and compute and return its
   period.

   .. dropdown:: solution

      The updated header is:

      .. literalinclude:: ../../examples/classes_better/solar_system.H
         :language: c++
         :caption: new ``solar_system.H``

      and corresponding functions:

      .. literalinclude:: ../../examples/classes_better/solar_system.cpp
         :language: c++
         :caption: new ``solar_system.cpp``

      and test driver:

      .. literalinclude:: ../../examples/classes_better/test_solar_system.cpp
         :language: c++
         :caption: new ``test_solar_system.cpp``


.. admonition:: try it...

   To understand the difference between a ``struct``, where everything is public, and
   a ``class`` where everything is private by default, let's edit ``solar_system.H``
   and change ``struct`` to ``class``.

   What happens when we compile?

   Now try adding a ``public:`` statement to the code.


.. tip::

   Instead of doing a ``get_planet()`` to return a copy of a planet from our
   solar system object, we can return an iterator using ``std::find_if()`` as:

   .. code:: c++

      std::vector<Planet>::iterator SolarSystem::find_planet(const std::string& name) {

          auto it = std::find_if(planets.begin(), planets.end(),
                                 [&] (const Planet& p) {return p.name == name;});

          return it;
      }


In this simple example, we really did not need to use an initialization list, but there
are situations when it is desired or even required:

* if any of our member data is ``const`` or a reference.

* if we have other classes as our member data (including things like ``std::vector``)
  and initializing them involves some overhead.  It can be faster to do the initialization
  via the initialization list.

See the stack overflow `Why should I prefer to use member
initialization lists?
<https://stackoverflow.com/questions/926752/why-should-i-prefer-to-use-member-initialization-lists>`_
discussion.
