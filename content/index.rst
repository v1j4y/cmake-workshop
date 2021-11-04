CMake hands-on workshop
=======================


CMake is a language-agnostic, cross-platform build tool and is nowadays the *de
facto* standard,  with many large projects using it to reliably build, test, and
deploy their codebases.


Learning outcomes
-----------------

You will learn how to:

- Write a CMake build system for C, C++, and Fortran projects producing
  libraries and/or executables.
- Run tests for your code with CTest.
- Ensure your build system will work on different platforms.
- Detect and use external dependencies in your project.
- Recognize modular patterns and also recognize and know how to avoid
  problematic "spaghetti" patterns.


.. prereq::

   **Software requirements**

   Before attending this workshop, please make sure that you have access
   to a computer with a compiler for your favorite language and a recent version of CMake.
   Instructions on how to set up these dependencies can be found
   on the :doc:`setup` page.

   **Who is the course for?**

   This course is for students, researchers, engineers, and programmers that have
   heard of `CMake`_ and want to learn how to use it effectively with projects they
   are working on.
   This course assumes no previous experience with `CMake`_. You will have to be
   familiar with the tools commonly used to build software in your compiled
   language of choice: C++, C, Fortran.
   Specifically, this lesson assumes that participants have some prior experience
   with or knowledge of the following topics (but no expertise is required):

   - Compiling and linking executables and libraries.
   - Differences between shared and static libraries.
   - Automated testing.


.. toctree::
   :hidden:
   :maxdepth: 1

   setup


This schedule below is shifting. I am reworking it towards the draft
:ref:`schedule-draft` in the instructor guide, from a 2-day schedule towards a
3-hours schedule. This restructuring will take 2-3 more days.

.. toctree::
   :hidden:
   :maxdepth: 1
   :caption: The lesson

   hello-cmake
   cmake-syntax
   hello-ctest
   environment
   probing
   targets
   dependencies
   cxx-fortran
   fetch-content


.. see also the schedule in guide.rst

.. csv-table::
   :widths: auto
   :delim: ;

   30 min ; :doc:`hello-cmake`
   30 min ; :doc:`cmake-syntax`
   30 min ; :doc:`hello-ctest`
   30 min ; :doc:`environment`
   30 min ; :doc:`probing`
   40 min ; :doc:`targets`
   40 min ; :doc:`dependencies`
   40 min ; :doc:`cxx-fortran`
   30 min ; :doc:`fetch-content`


.. toctree::
   :maxdepth: 1
   :caption: Reference

   conventions
   resources
   guide
   credits
