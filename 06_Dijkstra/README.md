# Weighted graphs: Dijkstra

This folder contains the implementation and testing of the Dijkstra algorithm.


A Makefile can be produced by using [cmake](https://cmake.org/) as follows:

```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```

You have to use the [`binheap` library](04_Binary_heaps) to compile heap sort, and you can do it by using the command:

```bash
cmake -G "Unix Makefiles" -DBINHEAP_PATH=<BINHEAP_INSTALL_DIR> CMakeLists.txt
```

I've chosen the folder `~/Documenti/'Algorithmic Design'/Algorithmic_Design/03_Binary_heaps` or the folder `~/Documenti/'Algorithmic Design/Algorithmic_Design/04_Binary_heaps_noswap'`, depending on what type of binary heap you want to use (see [here](../04_Binary_heaps_noswap/README.md) the difference). See [here](../03_Binary_heaps/README.md) to have more details about `<BINHEAP_INSTALL_DIR>`.

Afterwards you can compile the code by executing `make`. This produces an executable named `test_sorting` which can be executed in POSIX systems by using the command:

```bash
./test_dijkstra
```

Description output.