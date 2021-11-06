.. _flags-definitions-debugging:


Compile flags, definitions, and debugging
=========================================

The way in which to trigger a verbose build depends on the native build tool you are using.
For Unix Makefiles:

.. code-block:: bash

   $ cmake --build build -- VERBOSE=1

For Ninja:

.. code-block:: bash

   $ cmake --build build -- -v



Printing messages
-----------------

You will most likely have to engage in debugging your CMake scripts at one point
or another.  We believe that print-based debugging is the most effective way to
do so and the main workhorse will be the |message| command:

.. signature:: |message|

   .. code-block:: cmake

      message([<mode>] "message to display")

.. parameters::

   ``<mode>``
       What type of message to display, for example:

         - ``STATUS``, for incidental information.
         - ``FATAL_ERROR``, to report an error that prevents further processing and generation.


|message| can be a bit awkward to work with, especially when you want to print
the name *and* value of a variable.  Including the built-in module
``CMakePrintHelpers`` will make your life easier when debugging, since it
provides the |cmake_print_variables| function:

.. signature:: |cmake_print_variables|

   .. code-block:: cmake

      cmake_print_variables(var1 var2 ... varN)

   This command accepts an arbitrary number of variables and prints their name and value to standard output.
   For example:

   .. code-block:: cmake

      include(CMakePrintHelpers)

      cmake_print_variables(CMAKE_C_COMPILER CMAKE_MAJOR_VERSION DOES_NOT_EXIST)

   gives:

   .. code-block:: text

      -- CMAKE_C_COMPILER="/usr/bin/gcc" ; CMAKE_MAJOR_VERSION="2" ; DOES_NOT_EXIST=""


.. code-block:: cmake

   cmake_print_variables(CMAKE_CXX_COMPILER_ID CMAKE_CXX_COMPILER_VERSION)



Variables
+++++++++

These are either CMake- or user-defined. You can obtain the list of CMake-defined variables with:

.. code-block:: bash

   $ cmake --help-variable-list

You can create a new variable with the |set| command:

.. signature:: |set|

   .. code-block:: cmake

      set(<variable> <value>... [PARENT_SCOPE])

Variables in CMake are always of string type, but certain commands can interpret
them as other types.  If you want to declare a *list* variable, you will have to
provide it as a ;-separated string. Lists can be manipulated with the ``list``
family of commands.
You can inspect the value of a variable by *dereferencing* it with the ``${}``
operator, as in bash shell.

One of the most confusing aspects in CMake is the scoping of variables. There are three variable scopes in the DSL:

- Function. In effect when a variable is |set| within a function: the variable
  will be visible within the function, but not outside.
- Directory. In effect when processing a ``CMakeLists.txt`` in a directory:
  variables in the parent folder will be available, but any that is |set| in the
  current folder will not be propagated to the parent.
- Cache. These variables are **persistent** across calls to ``cmake`` and
  available to all scopes in the project.
  Modifying a cache variable requires using a special form of the |set| function:

  .. signature:: |set|

     .. code-block:: cmake

        set(<variable> <value>... CACHE <type> <docstring> [FORCE])


Here is a list of few CMake-defined variables:

- |PROJECT_BINARY_DIR|. This is the build folder for the project.
- |PROJECT_SOURCE_DIR|. This is the location of the root ``CMakeLists.txt`` in the project.
- |CMAKE_CURRENT_LIST_DIR|. This is the folder for the ``CMakeLists.txt`` currently being processed.


Help on a specific built-in variable can be obtained with:

.. code-block:: bash

   $ cmake --help-variable PROJECT_BINARY_DIR
