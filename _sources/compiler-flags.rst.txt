*******************************
Making the Compiler Do the Work
*******************************

Compilers have lots of options that affect the compilation.  So far,
with ``g++`` we've just been using ``-o`` to name the executable.  But
we can also have the compiler warn us about problematic C++ code we may
have written.  A useful set of options is:

.. prompt:: bash

   g++ -Wall -Wextra -Wpedantic

Here's a brief summary:

* ``-Wall`` : this turns on options that warn about things most users deem problematic.  For my version, it enables:

  * ``-Waddress``
  * ``-Warray-bounds=1`` (only with -O2)
  * ``-Warray-compare``
  * ``-Wbool-compare``
  * ``-Wbool-operation``
  * ``-Wc++11-compat``
  * ``-Wc++14-compat``
  * ``-Wcatch-value``
  * ``-Wchar-subscripts``
  * ``-Wcomment``
  * ``-Wdangling-pointer=2``
  * ``-Wformat``
  * ``-Wformat-overflow``
  * ``-Wformat-truncation``
  * ``-Wint-in-bool-context``
  * ``-Winit-self``
  * ``-Wlogical-not-parentheses``
  * ``-Wmaybe-uninitialized``
  * ``-Wmemset-elt-size``
  * ``-Wmemset-transposed-args``
  * ``-Wmisleading-indentation``
  * ``-Wmismatched-dealloc``
  * ``-Wmismatched-new-delete``
  * ``-Wmissing-attributes``
  * ``-Wmultistatement-macros``
  * ``-Wnarrowing``
  * ``-Wnonnull``
  * ``-Wnonnull-compare``
  * ``-Wopenmp-simd``
  * ``-Wparentheses``
  * ``-Wpessimizing-move``
  * ``-Wpointer-sign``
  * ``-Wrange-loop-construct``
  * ``-Wreorder``
  * ``-Wrestrict``
  * ``-Wreturn-type``
  * ``-Wself-move``
  * ``-Wsequence-point``
  * ``-Wsign-compare``
  * ``-Wsizeof-array-div``
  * ``-Wsizeof-pointer-div``
  * ``-Wsizeof-pointer-memaccess``
  * ``-Wstrict-aliasing``
  * ``-Wstrict-overflow=1``
  * ``-Wswitch``
  * ``-Wtautological-compare``
  * ``-Wtrigraphs``
  * ``-Wuninitialized``
  * ``-Wunknown-pragmas``
  * ``-Wunused-function``
  * ``-Wunused-label``
  * ``-Wunused-value``
  * ``-Wunused-variable``
  * ``-Wuse-after-free=2``
  * ``-Wvolatile-register-var``
  * ``-Wzero-length-bounds``

* ``-Wextra``:

  * ``-Wclobbered``
  * ``-Wcast-function-type``
  * ``-Wdangling-reference``
  * ``-Wdeprecated-copy``
  * ``-Wempty-body``
  * ``-Wignored-qualifiers``
  * ``-Wimplicit-fallthrough=3``
  * ``-Wmissing-field-initializers``
  * ``-Woverride-init``
  * ``-Wstring-compare``
  * ``-Wredundant-move``
  * ``-Wtype-limits``
  * ``-Wuninitialized``
  * ``-Wshift-negative-value``
  * ``-Wunused-parameter``
  * ``-Wunused-but-set-parameter``
