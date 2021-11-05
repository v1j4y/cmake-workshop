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
- Recognize modular patterns but also recognize and know how to avoid
  problematic and later unmaintainable "spaghetti" patterns.


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


Schedule
--------

.. csv-table::
   :widths: auto
   :align: center
   :delim: ;

    15 min ; :ref:`motivation`
    15 min ; :ref:`quick-tour`

           ; Lunch break

    15 min ; :ref:`hello-world-executable` and setup help
    15 min ; :ref:`hello-world-library`
    10 min ; Compile flags and compile definitions
    10 min ; Discussion

    10 min ; Break

    10 min ; :ref:`targets`
    15 min ; Exercise: building a larger project
    10 min ; Environment, and dependencies
    15 min ; Exercise: discovering and linking dependencies
    10 min ; Discussion: typical pitfalls

    10 min ; Break

    10 min ; Testing and nesting
    15 min ; Exercise: testing with CTest
    15 min ; Exercise: composing modules
    10 min ; Discussion


.. toctree::
   :hidden:
   :maxdepth: 1
   :caption: Introduction

   motivation
   cmake-syntax
   quick-tour


.. toctree::
   :hidden:
   :maxdepth: 1
   :caption: Hands-on workshop

   hello-cmake
   targets
   probing
   environment
   dependencies
   hello-ctest
   fetch-content


.. toctree::
   :maxdepth: 1
   :caption: Reference

   resources
   credits
