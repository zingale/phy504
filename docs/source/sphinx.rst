******
Sphinx
******

`Sphinx <https://www.sphinx-doc.org/en/master/>`_ is a documentation
tool that is commonly used for writing code documentation (especially
for python projects).  It uses `restructured text
<https://www.sphinx-doc.org/en/master/usage/restructuredtext/index.html>`_
as the format for writing the documentation and compiles it into HTML,
LaTeX/PDF, ...  It can also highlight code syntax.

.. tip::

   These course notes are all written using Sphinx

Despite its python origins, `sphinx can be used with Doxygen via Breathe
<https://leimao.github.io/blog/CPP-Documentation-Using-Sphinx/>`_ to
allow for nice looking sphinx documentation to provide the C++ documentation
Doxygen generates.

Installing
==========

We can install Sphinx locally via:

.. prompt:: bash

   pip install sphinx sphinx_rtd_theme --user





Using Doxygen with Sphinx
=========================

The Sphinx breathe extension allows us to incorporate Doxygen documentation
into Sphinx sites.
