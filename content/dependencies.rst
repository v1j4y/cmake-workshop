.. _dependencies:


Finding and using dependencies
==============================

.. objectives::

   - Learn how to use |find_package|.
   - Learn what other detection alternatives exist.

The vast majority of software projects do not happen in a vacuum: they will have
dependencies on existing frameworks and libraries.  Good documentation will
instruct your users to ensure that these are satisfied in their programming
environment. The build system is the appropriate place to check that these
preconditions are met and that your project can be built correctly.
In this episode, we will show you few examples of how to detect and use
dependencies in your CMake build system.


Finding dependencies
--------------------

CMake offers a family of commands to find artifacts installed on your system:

- |find_file| to retrieve the full path to a file.
- |find_library| to find a library, shared or static.
- |find_package| to find and load settings from an external project.
- |find_path| to find the directory containing a file.
- |find_program| to find an executable.

The workhorse of dependency discovery is |find_package|, which will cover your
needs in almost all use cases.

.. signature:: |find_package|

   .. code-block:: cmake

      find_package(<PackageName> [version] [EXACT] [QUIET] [MODULE]
             [REQUIRED] [[COMPONENTS] [components...]]
             [OPTIONAL_COMPONENTS components...]
             [NO_POLICY_SCOPE])

   This command will attempt finding the package with name ``<PackageName>`` by
   searching in a number of `predefined folders
   <https://cmake.org/cmake/help/latest/command/find_package.html?highlight=find_package#search-procedure>`_.
   It is possible to ask for a minimum or exact version. If ``REQUIRED`` is
   given, a failed search will trigger a fatal error.  The rules for the search
   are obtained from modules named ``Find<PackageName>.cmake``.
   Packages can also have *components* and you can ask to detect just a handful of them.

- For a large selection of common dependencies, the ``Find<PackageName>.cmake``
  modules shipped with CMake work flawlessly and are maintained by the CMake
  developers. This lifts the burden of programming your own dependency
  detection tricks.
- |find_package| will set up **imported targets**: targets defined *outside*
  your project that you can use with your own targets.  The properties on
  imported targets defines *usage requirements* for the dependencies. A command
  such as:

  .. code-block:: cmake

     target_link_libraries(your-target
       PUBLIC
         imported-target
       )

  will set compiler flags, definitions, include directories, and link libraries
  from ``imported-target`` to ``your-target`` *and* to all other targets in
  your project that will use ``your-target``.

These two points above simplify **enormously** the burden of dependency detection and
consistent usage within a multi-folder project.


Using find_package
------------------

When attempting dependency detection with |find_package|, you should make sure that:

- A ``Find<PackageName>.cmake`` module exists,
- Which components, if any, it provides, and
- What imported targets it will set up.

A complete list of ``Find<PackageName>.cmake`` can be found from the command-line interface:

.. code-block:: console

   $ cmake --help-module-list | grep "Find"

Another way is to browse: https://github.com/Kitware/CMake/tree/master/Modules


.. typealong:: Using OpenMP

   We want to compile the following OpenMP sample code: [#omp]_


   .. literalinclude:: code/day-2/22_taskloop/solution/taskloop.cpp
      :language: c++

   Note the usage of the ``taskloop`` construct, which was introduced in OpenMP
   4.5: we need to make sure our C++ compiler is suitably compatible with *at
   least* that version of the standard.

   From the documentation of the ``FindOpenMP.cmake`` module:

   .. code-block:: bash

      $ cmake --help-module FindOpenMP | less

   we find that the module provides the components ``C``, ``CXX``, and
   ``Fortran`` and that ``OpenMP::OpenMP_CXX`` target will be provided, if
   detection is successful.
   Thus, we do the following:

   .. code-block:: cmake

      find_package(OpenMP 4.5 REQUIRED COMPONENTS CXX)

      target_link_libraries(task-loop PRIVATE OpenMP::OpenMP_CXX)

   We can configure and build verbosely. [#verbose]_
   Notice that compiler flags, include directories, and link libraries are properly resolved by CMake.

   You can download the :download:`complete working example <code/tarballs/22_taskloop_solution.tar.bz2>`.

.. challenge:: Using MPI

   In this exercise, you will attempt compiling a "Hello, world" program that
   uses the message passing interface (MPI).

   1. Check whether a ``FindMPI.cmake`` module exists in the built-in module
      library.
   2. Get acquainted with its components and the variables and imported targets
      it defines.

   .. tabs::

      .. tab:: C++

         Download the :download:`scaffold code <code/tarballs/23_mpi-cxx.tar.bz2>`.

         #. Compile the source file to an executable.
         #. Link against the MPI imported target.
         #. Invoke a verbose build and observe how CMake compiles and links.

         You can download the :download:`complete working example <code/tarballs/23_mpi-cxx_solution.tar.bz2>`.

      .. tab:: Fortran

         Download the :download:`scaffold code <code/tarballs/23_mpi-f.tar.bz2>`.

         #. Compile the source file to an executable.
         #. Link against the MPI imported target.
         #. Invoke a verbose build and observe how CMake compiles and links.

         You can download the :download:`complete working example <code/tarballs/23_mpi-f_solution.tar.bz2>`.


.. keypoints::

   - CMake has a rich ecosystem of modules for finding software dependencies. They are called ``Find<package>.cmake``.
   - The ``Find<package>.cmake`` modules are used through ``find_package(<package>)``.


.. rubric:: Footnotes

.. [#omp]

   Example adapted from page 85 in `OpenMP 4.5 examples
   <http://www.openmp.org/wp-content/uploads/openmp-examples-4.5.0.pdf>`_.

.. [#verbose]

   The way in which to trigger a verbose build depends on the native build tool you are using.
   For Unix Makefiles:

   .. code-block:: bash

      $ cmake --build build -- VERBOSE=1

   For Ninja:

   .. code-block:: bash

      $ cmake --build build -- -v
