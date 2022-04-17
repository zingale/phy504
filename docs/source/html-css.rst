**********
HTML + CSS
**********

.. admonition:: reading

   * The official HTML spec: https://html.spec.whatwg.org/


Web pages are written in a combination of HTML as CSS.  The basic division
is that:

* HTML provides the content and structure

* CSS provides the style

We don't have time to dive deep into how to write a modern webpage, but we can look at some of the concepts.

.. note::

   Our goal here is to learn how to write a basic webpage describing
   our codes.  We are not going to be able to cover web design deeply,
   but hopefully we'll learn enough so that we can use templates that
   others have written to write our own pages.


Basic HTML structure
====================

A basic HTML page has the following format:

.. literalinclude:: ../../examples/html/basic/index.html
   :language: html
   :caption: ``index.html``

Some comments:

* HTML *tags* need to be opened and closed to denote a block in
  which they apply.  For instance: ``<body>`` opens the main
  body of the page and ``</body>`` closes the main body of the
  page.

* Some tags are self-closing, and we end with ``/>``, for instance
  in above: ``<meta charset="utf-8" />``

* The name ``index.html`` is commonly used to indicate the first
  page of a website.  Many web-servers will automatically display
  this page when we go to a web site.

* We can open this page in our browser as:

  .. prompt:: bash

     google-chrome index.html

  or

  .. prompt:: bash

     firefox index.html


divs
====


responsive pages typically use a ``@media`` property to override
properties of other elements.


Very simple layout:

https://www.w3schools.com/css/tryit.asp?filename=trycss_website_layout_grid





The latest version of CSS supports a grid layout:

https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Grid_Layout
