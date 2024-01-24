***************
Getting Started
***************

We will use the Linux computer lab / Math SINC site for the class.

In-class work presentations will mostly be live-coding, where we all
work on the ideas together.  Notes will be presented on the class
website before class to guide the discussion and then updated after
class to reflect what we covered.

(Thanks to Doug Swesty for his advice on using the MathLab computers)

In class
========

The computers in class are running Ubuntu 20.04 and have all of the
software needed for this course installed.  There are a few quicks
compared to how a normal Linux system will behave.

.. tip::

   If the computer is asleep when you arrive, you can wake it by doing:

   | ctrl + alt + F2
   | ctrl + alt + F1

.. warning::

   Your home directory is wiped clean every 48 hours.  This means
   that we cannot rely on storing configuration files on our system.

You will log in with your NetID and password and then you will be
presented a terminal prompt for your password a second time to mount
your Stony Brook `MySBfiles
<https://it.stonybrook.edu/services/mysbfiles>`_ directory.  This is where
you will want to store your data.

.. tip::

   After you enter your username, a small "settings" icon will appear
   in the bottom right of the screen.  You can use this to select your
   default desktop.  Choose "MATE" to have your display appear like the
   instructor's desktop / what's displayed on the projector.

.. tip::

   If for some reason the MySBfiles doesn't mount, then you can rerun
   it by typing:

   .. prompt:: bash

      myfile

.. warning::

   Do not try to get superuser privileges on these machines.  Any
   attempts to ``su`` or ``sudo`` are logged and repeated attempts may
   be reported to campus IT.

.. note::

   You should familarized yourself with the campus IT policy:
   https://it.stonybrook.edu/policies/p109


Using your own machine
======================

You are encouraged to also work on your own personal laptop.  The
easiest way to do so would be to install a Linux virtual machine (for
example, `using Ubuntu
<https://ubuntu.com/tutorials/how-to-run-ubuntu-desktop-on-a-virtual-machine-using-virtualbox#1-overview>`_).
Other options include the `Windows Subsystem for Linux
<https://docs.microsoft.com/en-us/windows/wsl/install>`_.

You will want to make sure you install the ``g++`` compiler (something
later than version 7), ``git``, and ``bash``.

These instructions on `Using C++ and WSL in VS Code <https://code.visualstudio.com/docs/cpp/config-wsl>`_ offer a nice solution.

.. note::

   I only use Linux, so I cannot help you debug any Windows issues.  If you find something
   that works for you, please feel free to share it with the code.

Using the MathLab remotely
==========================

There are 2 special machines that you can log onto remotely via ssh.
If you are using Windows, then I would recommend the `PuTTY SSH client
<https://www.putty.org/>`_.  

.. note::

   These machines appear to be unreliable this semester.

With ssh you can connect to:

* ``portal.mathlab.stonybrook.edu``

* ``portal2.mathlab.stonybrook.edu``

.. important::

   These are shared resources, so you should not run anything compute
   intensive or non-class work on these machines.

If you are connecting to one of these via ssh on the command line, then you would do::

  ssh <netid>@portal.mathlab.stonybrook.edu

where you replace ``<netid>`` with your NetID.

You can connect similarly with PuTTY.


MySBFiles
=========

The ``~/MySBFiles/`` directory is mounted from a windows machine and
is (1) slow, (2) unreliable, and (3) times out after 120 minutes.  It
is therefore suggested that you do your work in your home directory
and then move anything you wish to keep to your ``~/MySBFiles/`` drive
before logging off.

