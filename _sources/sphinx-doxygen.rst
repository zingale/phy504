****************
Sphinx + Doxygen
****************

Despite its python origins, `sphinx can be used with Doxygen via Breathe
<https://leimao.github.io/blog/CPP-Documentation-Using-Sphinx/>`_ to
allow for nice looking sphinx documentation to provide the C++ documentation
Doxygen generates.

.. tip::

   The Sphinx *breathe* extension allows us to incorporate Doxygen
   documentation into Sphinx sites.

We'll start with our existing repo set up for Sphinx and make the following
changes:

1. Move ``Doxyfile`` into ``docs/`` and change the following:

   * change ``OUTPUT_DIRECTORY`` to ``doxy_files``

   * change ``INPUT`` to ``../``

   * Turn off HTML and turn on XML---Breathe works off of the XML output.

     * set ``GENERATE_HTML`` to ``NO``

     * set ``GENERATE_XML`` to ``YES``

2. Update our ``conf.py`` to include Breathe and also run Doxygen for us.  Here's
   the updated ``conf.py``:

   .. code:: python

      # Configuration file for the Sphinx documentation builder.
      #
      # For the full list of built-in configuration values, see the documentation:
      # https://www.sphinx-doc.org/en/master/usage/configuration.html

      # -- Project information -----------------------------------------------------
      # https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

      import subprocess

      subprocess.call("cd ..; doxygen", shell=True)

      project = 'C++ Array'
      copyright = '2024, PHY 504'
      author = 'PHY 504'

      # -- General configuration ---------------------------------------------------
      # https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

      extensions = ["sphinx.ext.autodoc", "breathe"]

      templates_path = ['_templates']
      exclude_patterns = []

      # -- Options for HTML output -------------------------------------------------
      # https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

      html_theme = 'sphinx_rtd_theme'
      html_static_path = ['_static']

      breathe_projects = { "cxx_array": "../doxy_files/xml/" }
      breathe_default_project = "cxx_array"

3. Create a  ``doxygen_files.rst`` in ``source/`` with the following:

   .. code:: ReST

      Doxygen Files
      =============

      .. doxygenindex::
         :project: cxx_array

4. Update ``index.rst`` by adding the following:

   .. code:: ReST

      .. toctree::
         :maxdepth: 1
         :caption: API

         doxygen_files

We don't need to do any changes to our GitHub workflow.  We should be able to just add these new
files / changes, commit, and push, and the website will be updated.

