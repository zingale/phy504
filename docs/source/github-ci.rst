*********************************
Continuous integration and github
*********************************

For a large project, with multiple developers, we often want to ensure
that any changes that they make to the code still pass all of the
tests before we merge it into the ``main`` git branch.  This is part
of the software development process called
`continuous integration <https://en.wikipedia.org/wiki/Continuous_integration>`_.

Github has a feature called `Github actions <https://docs.github.com/en/actions>`_ that allow us to set up simple
scripts that run on all pull requests.

We'll look at how this can work---this is a high level overview of
the process that we will experiment with.  Usually one of the main
developers of a large project will have already implemented the
testing.

We'll use this repository: https://github.com/phy504-sbu-s24/unit_tests

There are a few places to look:

* The github action itself is a `YAML <https://en.wikipedia.org/wiki/YAML>`_ file:
  https://github.com/phy504-sbu-s24/unit_tests/blob/main/.github/workflows/cxx-unit-tests.yml

  This is placed in the repository in the ``.github/workflows/`` directory

* The action runs on all pull requests as well as any direct push to
  the repo.  You can see the status of all actions that have run here:
  https://github.com/phy504-sbu-s24/unit_tests/actions

.. admonition:: try it...

   Let's break the code and issue a pull request to see the action in action...

.. admonition:: try it...

   Let's add a second action that tests for compiler warnings.  We can
   use the compilation flag ``-Werror`` to turn warnings into errors,
   which should cause the action to fail.


Some other types of CI
======================

Some other useful things you can do with Github actions / CI include:

* Spellchecking your source using `codespell <https://github.com/codespell-project/codespell>`_.
  See this example: https://github.com/AMReX-Astro/Castro/blob/main/.github/workflows/codespell.yml

* Enforcing code style.  Here's an example using `uncrustify <https://github.com/uncrustify/uncrustify>`_:
  https://github.com/marketplace/actions/c-style-check


.. tip::

   A Github action is used to build this lecture notes from the ReST source
   in the lecture note repo: https://github.com/zingale/phy504

   This is that action: https://github.com/zingale/phy504/blob/main/.github/workflows/gh-pages.yml

   We'll learn more about documenting code shortly.
