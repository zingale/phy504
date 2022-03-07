********
File I/O
********

Reading from / writing to a file uses the same stream operators as we
used to take input from a user or write to the screen.

To open a file, we use:

.. code:: c++

   std::ofstream of;
   of.open("file.txt");

alternately, we can pass the name of the file to the *constructor* of the class,

.. code:: c++

   std::ofstream of("file.txt");

Once the file is open, we can send output to it using the stream operator ``<<``:

.. code:: c++

   double x{0.0};
   of << x << std::endl;


When we are done with the file, we can close it:

.. code:: c++

   of.close();

.. note::

   C++ will manage closing the file when it goes out of scope (e.g. at
   the end of a function).  However, you can still free it earlier if
   desired.

The alternate to open a file for reading is ``std::ifstream``.  Note
that both of these are defined by the ``fstream`` header.

Here's an example of writing our planet information out to a file:

.. literalinclude:: ../../examples/io/output_example.cpp
   :language: c++

Let's now look at how to read that file back in.

There are 2 approaches we can take:

* Just read in each piece of information as needed, e.g.:

  .. code:: c++

     std::ifstream infile{"file.txt");

     infile >> x >> y >> x;

* Read the file line-by-line into a string and then treat that string
  as a stream and read from it.

  The ``getline()`` function will do this for us:

  .. code:: c++

     std::string line{};
     std::getline(of, line);

  To interpret the string as a stream, we can use ``std::stringstream``:

  .. code:: c++

     std::stringstream ss(line);
     ss >> x >> y >> z;

Here's an example of reading our file line by line.  We rely on the
fact when it reaches the end of the file, ``getline()`` will evaluate
as ``false`` in a conditional.

.. literalinclude:: ../../examples/io/input_example2.cpp
   :language: c++


.. admonition:: try it...

   A file stream object was an ``.eof()`` method that is ``true`` when
   we reach the end of a file.  However, it is only set after a failed
   read from the file.

   If we try using this in our ``while`` loop, it is possible that we
   will test as ``true`` and then fail to read in the loop body.



.. tip::

   When you open a file for output using ``ofstream`` as shown above it overwrites
   an existing file of that name.

   If we wish instead to append to an existing file, we would do:

   .. code:: c++

      std::ofstream of("file.txt", std::ios::app);


.. admonition:: try it...

   Let's write our own version of ``wc``.  Here's a text file:
   :download:`lorem-ipsum.txt <./lorem-ipsum.txt>`.

   Let's write a C++ code the counts the number of lines, words, and
   characters from the input file.

   We don't know how to take a command line argument yet, so let's
   just hardcode the file name into the program for now.

   .. dropdown:: solution

      .. literalinclude:: ../../examples/io/wc_example.cpp
         :language: c++


.. You text has an example of writing to a file in table 3.5
