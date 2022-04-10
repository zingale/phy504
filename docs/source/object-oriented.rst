**********************
Object-Oriented Design
**********************

.. admonition:: reading

   Cyganek section 4.1

The use of classes to organize concepts into reusable software objects
containing data and functions is the hallmark of `object-oriented
programming
<https://en.wikipedia.org/wiki/Object-oriented_programming>`_.

Core concepts in OO programming are listed below.  It's hard to find
precise definitions of these, and they often seem to overlap a bit
in what they mean.

* *encapsulation* : this means we hide how the data in the class is
  stored.  For example, by making the member data ``private``.

  There may be *setters* and *getters* to access some information, but
  the types of objects that are used are hidden from a user of the
  class.  This allows us to change how we store the data (refactor the
  code) without affecting users of the class.

* *inheritance* : this means that we can use a class as the *base class*
  (or *superclass*) to define new classes.  These new classes *inherit* all
  of the data and functions of the base, but can also change its behavior as
  needed to work in a new way, specific to the new class.

* *abstraction* : this works at the level of the interfaces of the
  member functions of the class.  Similar to encapsulation, it hides
  implementation details from the user.

  For example, operator overloading the ``+`` operator to work with
  our vectors is an example of abstraction.  We used something
  familiar to ourself to work on our vectors without having to know
  how it is implemented in the class.

  Another example comes into play with inheritance, where a base class
  implements the interface that all of the child classes will then
  define for their specific data.

* *polymorphism* : this is another type of abstraction, and means
  "many forms".  This typically means that we have functions that know
  how to operate with different types.  Overloading functions and
  operators with the same name is an example of polymorphism. 


.. note::

   your text discusses the `SOLID software engineering strategy
   <https://en.wikipedia.org/wiki/SOLID>`_ -- we won't discuss that
   here.


Nice discussion about the difference between abstraction and encapsulation is given in this `Difference between abstraction and encapsulation? Stack Overflow question <https://stackoverflow.com/questions/742341/difference-between-abstraction-and-encapsulation>`_.

Concisely, it says:

* encapsulation means *information hiding*

* abstraction means *implementation hiding*

We've already been practicing both of these, even if we didn't
explicitly point it out.
