.. _sources-to-executables:


From sources to executables
===========================

.. questions::

   - How do we use CMake to compile source files to executables?

.. objectives::

   - Learn what tools available in the CMake suite.
   - Learn how to write a simple ``CMakeLists.txt``.
   - Learn the difference between *build systems*, *build tools*, and *build system generator*.
   - Learn to distinguish between *configuration*, *generation*, and *build* time.


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


.. _hello-world-executable:

Type-along: building an executable
----------------------------------

.. exercise:: Compiling "Hello, world" with CMake

   We will now proceed to compile a single source file to an executable. Choose
   your favorite language and start typing along!

   1. Create a new folder and in the folder create a source file:

     .. tabs::

        .. tab:: C++

           .. literalinclude:: exercises/hello-executable/cxx/hello.cpp
              :language: c++

        .. tab:: Fortran

           .. literalinclude:: exercises/hello-executable/fortran/hello.f90
              :language: fortran

   2. The folder contains only the source code. We need to add a file called
      ``CMakeLists.txt`` to it.  CMake reads the contents of these special files
      when generating the build system:

     .. tabs::

        .. tab:: C++

           .. literalinclude:: exercises/hello-executable/cxx/CMakeLists.txt
              :language: cmake

        .. tab:: Fortran

           .. literalinclude:: exercises/hello-executable/fortran/CMakeLists.txt
              :language: cmake

   3. We are ready to call CMake and get our build system:

      .. code-block:: console

         $ cmake -S. -Bbuild

   4. And finally build our executable:

      .. code-block:: console

         $ cmake --build build

   5. Try to also run the executable.


.. discussion:: Discussion: We prefer out-of-source builds

   The ``-S`` switch specifies which source directory CMake should scan: this is
   the folder containing the *root* ``CMakeLists.txt``, *i.e.* the one containing
   the |project| command.
   By default, CMake will allow *in-source* builds, *i.e.* storing build
   artifacts alongside source files. This is **not** good practice: you should
   always keep build artifacts from sources separate. Fortunately, the ``-B``
   switch helps with that, as it is used to give where to store build artifacts,
   including the generated build system. This is the minimal invocation of ``cmake``:

   .. code-block:: console

      $ cmake -S. -Bbuild

   To switch to another generator, we will use the ``-G`` switch:

   .. code-block:: console

      $ cmake -S. -Bbuild -GNinja

   Options to be used at build-system generation are passed with the ``-D``
   switch. For example, to change compilers:

   .. code-block:: console

      $ cmake -S. -Bbuild -GNinja -DCMAKE_CXX_COMPILER=clang++

   Why prefer out-of-source builds?

   - You can build several builds with the same source without having to copy the entire project
     and merging changes later (sequential and parallel, debug and release).

We have learned met three CMake directives (you can click on these to jump to
the official documentation help text):

- |cmake_minimum_required|
- |project|
- |add_executable|

The case of CMake commands and variables does not matter: the DSL is
case-insensitive. However, the plain-text files that CMake parses **must be
called** ``CMakeLists.txt`` and the case matters!


.. _hello-world-library:

Exercise: building and linking a library
----------------------------------------

.. exercise:: A more modular "Hello, world"

   Only rarely we have one-source-file projects and more realistically, as
   projects grow, we split them up into separate files. This simplifies
   (re)compilation but also helps humans maintaining and understanding the
   project.

   We stay with the toy project but also here things got more real and more
   modular and we decided to split the project up into several files:

   .. tabs::

      .. tab:: C++

         hello.cpp:

         .. literalinclude:: exercises/hello-library/cxx/hello.cpp
            :language: c++

         greeting.cpp:

         .. literalinclude:: exercises/hello-library/cxx/greeting.cpp
            :language: c++

         greeting.hpp:

         .. literalinclude:: exercises/hello-library/cxx/greeting.hpp
            :language: c++

      .. tab:: Fortran

         hello.f90:

         .. literalinclude:: exercises/hello-library/fortran/hello.f90
            :language: fortran

         greeting.f90:

         .. literalinclude:: exercises/hello-library/fortran/greeting.f90
            :language: fortran

   **Your first goal**: try to build this by adapting the `CMakeLists.txt` from
   earlier by first adding all the source files into the same |add_executable|.

CMake can of course be used to produce libraries as well as executables.  The
relevant command is |add_library|.  You can link libraries can be linked into
other targets (executables or other libraries) with |target_link_libraries|.

.. callout:: Executables and libraries are targets

   We will encounter the term **target** repeatedly. In CMake, a target is any
   object given as first argument to |add_executable| or |add_library|.  Targets
   are the basic atom in CMake.  Whenever you will need to organize complex
   projects, think in terms of its targets and their mutual dependencies.  The
   whole family of CMake commands ``target_*`` can be used to express chains of
   dependencies and is much more effective than keeping track of state with
   variables.  We will clarify these concepts in :ref:`targets`.


.. exercise:: Collecting files into libraries

   **Your second goal**: now try to build a greeting library and link against this library
   instead of collecting all sources into the executable target:

   .. tabs::

      .. tab:: C++

         .. literalinclude:: exercises/hello-library/cxx/CMakeLists.txt
            :language: cmake

      .. tab:: Fortran

         .. literalinclude:: exercises/hello-library/fortran/CMakeLists.txt
            :language: cmake

   Which solution did you like better? Discuss the pros and cons.

   What kind of library did you get? Static or shared? Try configuring the project as follows:

   .. code-block:: bash

      $ cmake -S. -Bbuild -DBUILD_SHARED_LIBS=ON

   The ``BUILD_SHARED_LIBS`` variable influences the default behavior of |add_library|.


.. discussion:: Discussion: Granulatity of libraries

   Write me ...


.. keypoints::

   - CMake is a **build system generator**, not a build system.
   - You write ``CMakeLists.txt`` to describe how the build tools will create artifacts from sources.
   - You can use the CMake suite of tools to manage the whole lifetime: from source files to tests to deployment.
   - The structure of the project is mirrored in the build folder.
