Graphical and text conventions
==============================

We adopt a few conventions which help organize the material.

Function signatures
   These are shown in a text block marked with a wrench emoji:

   .. signature:: |cmake_minimum_required|

      .. code-block:: cmake

         cmake_minimum_required(VERSION <min>[...<max>] [FATAL_ERROR])

   The signature can be hidden by clicking the toggle.

Command parameters
   The description of the command parameters will appear in a separate text
   box. It will be marked with a laptop emoji:

   .. parameters::

      ``VERSION``
          Minimum and, optionally, maximum version of CMake to use.
      ``FATAL_ERROR``
          Raise a fatal error if the version constraint is not satisfied. This
          option is ignored by CMake >=2.6

   The description is hidden and will be shown by clicking the toggle.

Type-along
   The text and code for these activities are in a separate text box, marked with
   a keyboard emoji:

   .. typealong:: Let's look at an example

      .. code-block:: cmake

         cmake_minimum_required(VERSION 3.16)

         project(Hello LANGUAGES CXX)

   The content can be hidden by clicking the toggle.
