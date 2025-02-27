.. _dsp_get_started:

Using NMSIS-DSP
===============

Here we will describe how to run the nmsis dsp examples in Nuclei Spike.

Preparation
-----------

* Nuclei Modified Spike - ``xl_spike``
* Nuclei SDK modified for ``xl_spike`` branch ``dev_xlspike``
* Nuclei RISCV GNU Toolchain
* CMake >= 3.5

Tool Setup
----------

1. Export **PATH** correctly for `xl_spike` and `riscv-nuclei-elf-gcc`

.. code-block:: shell

    export PATH=/path/to/xl_spike/bin:/path/to/riscv-nuclei-elf-gcc/bin/:$PATH

Build NMSIS DSP Library
-----------------------

1. Download or clone NMSIS source code into **NMSIS** directory.
2. cd to `NMSIS/NMSIS/` directory
3. Build NMSIS DSP library using ``make gen_dsp_lib``
4. Strip debug informations using ``make strip_dsp_lib`` to make the generated
   library smaller
5. The dsp library will be generated into ``./Library/DSP/GCC`` folder
6. The dsp libraries will be look like this:

.. code-block::

    $ ll Library/DSP/GCC/
    total 28604
    -rw-r--r-- 1 hqfang nucleisys 1847080 Jul 14 14:51 libnmsis_dsp_rv32imac.a
    -rw-r--r-- 1 hqfang nucleisys 2515912 Jul 14 14:51 libnmsis_dsp_rv32imacp.a
    -rw-r--r-- 1 hqfang nucleisys 1786008 Jul 14 14:51 libnmsis_dsp_rv32imafc.a
    -rw-r--r-- 1 hqfang nucleisys 2377420 Jul 14 14:51 libnmsis_dsp_rv32imafcp.a
    -rw-r--r-- 1 hqfang nucleisys 1785500 Jul 14 14:51 libnmsis_dsp_rv32imafdc.a
    -rw-r--r-- 1 hqfang nucleisys 2367840 Jul 14 14:51 libnmsis_dsp_rv32imafdcp.a
    -rw-r--r-- 1 hqfang nucleisys 2374468 Jul 14 14:51 libnmsis_dsp_rv64imac.a
    -rw-r--r-- 1 hqfang nucleisys 3369340 Jul 14 14:51 libnmsis_dsp_rv64imacp.a
    -rw-r--r-- 1 hqfang nucleisys 2276836 Jul 14 14:51 libnmsis_dsp_rv64imafc.a
    -rw-r--r-- 1 hqfang nucleisys 3151172 Jul 14 14:51 libnmsis_dsp_rv64imafcp.a
    -rw-r--r-- 1 hqfang nucleisys 2275828 Jul 14 14:51 libnmsis_dsp_rv64imafdc.a
    -rw-r--r-- 1 hqfang nucleisys 3140188 Jul 14 14:51 libnmsis_dsp_rv64imafdcp.a

7. library name with extra ``p`` is build with RISCV DSP enabled.

   * ``libnmsis_dsp_rv32imac.a``: Build for **RISCV_ARCH=rv32imac** without DSP enabled.
   * ``libnmsis_dsp_rv32imacp.a``: Build for **RISCV_ARCH=rv32imac** with DSP enabled.

.. note::

    * You can also directly build both DSP and NN library using ``make gen``
    * You can strip the generated DSP and NN library using ``make strip``

How to run
----------

1. Set environment variables ``NUCLEI_SDK_ROOT`` and ``NUCLEI_SDK_NMSIS``,
   and set Nuclei SDK SoC to `xlspike`

.. code-block:: shell

    export NUCLEI_SDK_ROOT=/path/to/nuclei_sdk
    export NUCLEI_SDK_NMSIS=/path/to/NMSIS/NMSIS
    export SOC=xlspike

2. Let us take ``./riscv_class_marks_example/`` for example

3. ``cd ./riscv_class_marks_example/``

4. Run with RISCV DSP enabled NMSIS-DSP library for CORE ``n307``

.. code-block:: shell

    # Clean project
    make DSP_ENABLE=ON CORE=n307 clean
    # Build project
    make DSP_ENABLE=ON CORE=n307 all
    # Run application using xl_spike
    make DSP_ENABLE=ON CORE=n307 run

5. Run with RISCV DSP disabled NMSIS-DSP library for CORE ``n307``

.. code-block:: shell

    make DSP_ENABLE=OFF CORE=n307 clean
    make DSP_ENABLE=OFF CORE=n307 all
    make DSP_ENABLE=OFF CORE=n307 run

.. note::

    * You can easily run this example in your hardware,
      if you have enough memory to run it, just modify the
      ``SOC`` to the one your are using in step 1.
