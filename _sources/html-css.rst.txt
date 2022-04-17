**********
HTML + CSS
**********

.. admonition:: reading

   * The official HTML spec: https://html.spec.whatwg.org/

   * Reference on the different tags: https://www.w3schools.com/tags/default.asp

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

.. tip::

   A good reference on the different tags is provided by
   https://www.w3schools.com/tags/default.asp

Separating content
==================

HTML using `headings <https://www.w3schools.com/html/html_headings.asp>`_
to break the content of a page into sections.  The headings are
indicated by ``<h1> ... </h1>`` down through ``<h6> ... </h6>``.

We can also denote paragraphs by wrapping them in ``<p> ... </p>``.

Here's an example:

.. literalinclude:: ../../examples/html/basic_headings/index.html
   :language: html
   :caption: ``index.html``




Adding CSS
==========

CSS means `cascading style sheets <https://en.wikipedia.org/wiki/CSS>`_.
CSS files provide a set of styling rules for different HTML elements.
"Cascading" here means that the rules on a element have a hierarchy
that is followed if more than one rule tries to modify an element.

Typically we provide the styles in a separate file with the ``.css``
extension.

For example, we can style the body of our page with a *stylesheet*:

.. literalinclude:: ../../examples/html/basic_with_css/style.css
   :language: css
   :caption: ``style.css``

and then add the line:

.. code:: html

   <link rel="stylesheet" href="style.css" />

to the ``<head> .. </head>`` block in our HTML file to load this sheet.


divs
====

A useful HTML element for grouping styles is the `div tag
<https://www.w3schools.com/tags/tag_div.asp>`_, ``<div>``.  We can put
any content in a ``<div> ... </div>`` region and specify the styling
for that region using.



HTML elements (including divs) can have either a *class* name or and
*id selector*:

* ``<div id="name">`` is used to indicate that there is a *single instance*
  of ``name`` in the HTML page.  This is called an *id-selector*   Elements
  in this div can be styled as:

  .. code:: css

     #name {}

* ``<div class="name">`` is used when we might want to have multiple 
  divs on the page with the same styling.  This is called a *class selector*
  and we style as:

  .. code:: css

     .name {}


.. admonition:: try it...

   Let's wrap our "Hello World" in a div and try to style it:

   .. literalinclude:: ../../examples/html/nicer_css/index.html
      :language: html
      :caption: ``index.html``

   In particular, create a rule:

   .. code:: css

      #container {}

   and let's try to do the following:

   * make the width only 80% of the page

   * add some padding (this applies inside the div between the div and
     the content)

   * use margins (these apply outside the div, between the div and the outer
     element) to give the content a ``max-width``

   * change the background color of the div region

   * add a border

   .. dropdown:: solution

      .. literalinclude:: ../../examples/html/nicer_css/style.css
         :language: css
         :caption: ``style.css``

Inspector
=========

Most web browsers have an *inspector* that let's you look at the styling
on a page.  In Chrome, you open the inspector by doing "F12".

We can see what styling is taking effect on the different elements and
also adjust the styling right in the browser to see how it takes effect.



Images
======

Images in HTML are included via the ``<img>`` tag.  Here's an example
image:

  .. figure:: ../../examples/html/nicer_css/luna_bw.png
     :align: center
     :width: 40%

     ``luna_bw.png``

We would include this as:

.. code:: html

   <p class="center"><img src="luna_bw.png" alt="picture of luna"></p>

Here, ``<p> ... </p>`` denotes a paragraph

and we could style it via:

.. code:: css

   .center {text-align: center;}

.. tip::

   Accessibility is an important design consideration when making web pages,
   and you should use the ``alt`` tag to provide a text alternative to the
   image for screen readers.


Responsive pages
================

A *responsive* page changes the styling based on the device / screen
size.  Usually this is triggered by the ``@media`` rule:
https://www.w3schools.com/cssref/css3_pr_mediaquery.asp

A very simply responsive page using only HTML and CSS is shown here:
https://www.w3schools.com/cssref/css3_pr_mediaquery.asp

Let's start with this and try to style it a bit.


.. tip::

   Instead of writing your own page from scratch, start with a template
   from a site like: https://html5up.net/ 

