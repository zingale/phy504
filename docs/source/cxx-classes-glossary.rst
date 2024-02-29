==============
Class glossary
==============


* Instance / object: A ``class`` provides the definitions of the
  member data and function that work together to describe a concept.
  We create an *instance* of a class, resulting in an ``object``.
  This is something that is defined in our system's memory.  We can
  have multiple objects of the same class, each with their own memory.

* Constructor / destructor: a constructor is a function that is called
  when we create an instance of a class.  Its job is to allocate any
  memory and initialize values of the member data.

  A destructor is a function that is called when we destroy our
  object---usually by letting it go out of scope.  Its job is to free
  any memory we allocated and do any other needed clean-up.


* `Encapsulation
  <https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)>`_:
  An object has its own member data and member functions.  As a user
  of the class, we don't need to know how the data is stored within
  the object---we just need to know that the class provides functions
  that allow us to interact with the data.  This is the concept of
  encapsulation.

  Sometimes we will make the data explicitly hidden and only allow it
  to be manipulated via functions.

* `Inheritance
  <https://en.wikipedia.org/wiki/Inheritance_(object-oriented_programming)>`_:
  Inheritance is the idea that we can build a new class from an
  existing class---inheriting its data and functions, potentially
  overriding some.




