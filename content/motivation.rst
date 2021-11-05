Motivation and overview
=======================


What is CMake?
--------------

Software is everywhere and so are build systems. Whenever you run a piece of
software,  anything from calendar apps to computationally-intensive programs,
there was a build system involved in transforming the plain-text source code
into binary files that could run on the device you are using. In research code
projects, CMake is often involved in this.

CMake is a **build-system generator**: it provides a family of tools and a
*domain-specific language* (DSL) to **describe** what the build system should
achieve when the appropriate build tools are invoked.
The DSL is platform- *and* compiler-agnostic: you can reuse the same CMake
scripts to obtain *native* build systems on any platform.

CMake is not a build system. It generates files for build systems to use
to build the software.

.. figure:: img/build-systems.svg
   :align: center

   On GNU/Linux, the native build system will be a collection of Makefiles.
   The ``make`` build tool uses these Makefiles to transform sources to
   executables and libraries.
   CMake abstracts the process of generating the Makefiles away into a
   generic DSL.


Having a look at available generators
-------------------------------------

Let us get acquainted with the CMake and especially its command-line interface.

We can get help at any time with:

.. code-block:: console

   $ cmake --help

This will output quite a number of options to your screen.
We can analyze the last few lines first (your output may differ):

.. code-block:: text

  Generators

  The following generators are available on this platform (* marks default):
    Green Hills MULTI            = Generates Green Hills MULTI files
                                   (experimental, work-in-progress).
  * Unix Makefiles               = Generates standard UNIX makefiles.
    Ninja                        = Generates build.ninja files.
    Ninja Multi-Config           = Generates build-<Config>.ninja files.
    Watcom WMake                 = Generates Watcom WMake makefiles.
    CodeBlocks - Ninja           = Generates CodeBlocks project files.
    CodeBlocks - Unix Makefiles  = Generates CodeBlocks project files.
    CodeLite - Ninja             = Generates CodeLite project files.
    CodeLite - Unix Makefiles    = Generates CodeLite project files.
    Eclipse CDT4 - Ninja         = Generates Eclipse CDT 4.0 project files.
    Eclipse CDT4 - Unix Makefiles= Generates Eclipse CDT 4.0 project files.
    Kate - Ninja                 = Generates Kate project files.
    Kate - Unix Makefiles        = Generates Kate project files.
    Sublime Text 2 - Ninja       = Generates Sublime Text 2 project files.
    Sublime Text 2 - Unix Makefiles
                                 = Generates Sublime Text 2 project files.

In CMake terminology, the native build scripts and build tools are called
**generators**. On any particular platform, the list will show which native
build tools can be used through CMake. They can either be "plain", such as
Makefiles or Ninja, or IDE-like projects.

You can also inquire about a specific module, command or variable:

.. code-block:: console

   $ cmake --help-variable CMAKE_GENERATOR

Finally, you can access the full CMake manual with:

.. code-block:: console

   $ cmake --help-full


A complete toolchain
--------------------

The family of tools provided with CMake offers a complete toolchain to manage
the development cycle: from sources to build artifacts, testing, and deployment.
We refer to these stages as *CMake times* and each tool is appropriate at a specific time. In this workshop, we will discuss:

- **CMake time** or **configure time**. This is the stage when ``cmake`` is
  invoked to parse the ``CMakeLists.txt`` in your project, configure and generate the build
  system.
- **Build time**. This is handled by the native build tools, but, as we have
  seen, these can be effectively wrapped by ``cmake`` itself.
- **CTest time** or **test time**. At this stage, you will test your build
  artifacts.


.. figure:: img/cmake-times.jpg
   :align: center

   You can manage all the stages of a software project's lifetime with the tools provided by CMake.
   This figure shows all these stages (*times*) and which tool is appropriate for each.
   The figure is reproduced from `CMake Cookbook
   <https://github.com/dev-cafe/cmake-cookbook>`_ and is licensed under the
   terms of the `CC-BY-SA
   <https://creativecommons.org/licenses/by-sa/4.0/legalcode>`_.
