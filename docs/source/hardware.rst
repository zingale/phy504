*****************
Computer Hardware
*****************

.. admonition:: reading

   Cyganek section 2.1


Modern computers implement a `von Neumann architecture <https://en.wikipedia.org/wiki/Von_Neumann_architecture>`_ which consists of
(copied from Wikipedia):

* A processing unit that contains an arithmetic logic unit and processor registers

* A control unit that contains an instruction register and program counter

* Memory that stores data and instructions

* External mass storage

* Input and output mechanisms

An example architecture is shown here:

.. figure:: ABasicComputer.gif
   :align: center
   :width: 70%

   (`Lambtron / Wikipedia <https://en.wikipedia.org/wiki/Central_processing_unit#/media/File:ABasicComputer.gif>`_)

Our program and the data it operates on is stored in the main memory of the system.  We need to move that from the main memory into the processor.

The *arithmetic logic unit* (ALU) performs the basic instructions on
the data.  The commands that it executes are processor-specific, and
if we wanted to code them directly, we'd write our code in *assembly
language*.  Luckily we don't need to do that -- instead we'll code in
C++ and use a *complier* to translate our code into the
machine-specific instructions.

Data moves through a memory hierarchy, typically something like

   main memory → L3 cache → L2 cache → L1 cache → processor registers

The further away the data is from the processor, the longer it takes
to move it to the processor, but the larger the pool of memory.

There are some instances (that's we'll see later), where knowledge of
this memory hierarchy can allow us to write faster programs.

On our machines, you can see the details of the processor, including the cache size, by doing:

.. prompt:: bash

   less /proc/cpuinfo

