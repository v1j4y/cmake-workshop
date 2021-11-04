Instructor's guide
==================

Learning outcomes
-----------------

- Write a CMake build system for C, C++, and Fortran projects producing
  libraries and/or executables.
- Run tests for your code with CTest.
- Ensure your build system will work on different platforms.
- Detect and use external dependencies in your project.
- Safely and effectively build mixed-language projects (Python+C/C++,
  Python+Fortran, Fortran+C/C++)


Schedule
--------

This is not in place yet but I am reworking/condensing the schedule towards:

.. csv-table::
   :widths: auto
   :align: center
   :delim: ;

    30 min ; Motivation, overview, and basics (morning)

           ; Lunch break

    10 min ; From sources to executables
    15 min ; Exercise: hello world
    15 min ; Exercise: building a larger project
    10 min ; Discussion: typical pitfalls

    10 min ; Break

    10 min ; Configuring and dependencies
    15 min ; Exercise: autogenerating a configuration
    15 min ; Exercise: discovering and linking dependencies
    10 min ; Discussion

    10 min ; Break

    10 min ; Testing and nesting
    15 min ; Exercise: testing with CMake
    15 min ; Exercise: composing modules
    10 min ; Discussion

    10 min ; Wrap-up
