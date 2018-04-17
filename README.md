# leetcode-c
leetcode with C

### Usage

- Build/Run the example:

```
./configure
make
```



- Add a new Test:

  For example, when we add a test **removeDuplicate**,open the file **Makefile.am** and edit.

  add the bin file name to **bin_PROGRAMS** and the source code as **removeDuplicate_SOURCES**:

  ```
  bin_PROGRAMS = two_sum removeDuplicate

  two_sum_SOURCES = src/sum.c
  removeDuplicate_SOURCES = src/removeDuplicate.c

  INCLUDES = -I $(top_srcdir)/src
  CFLAGS = -g -O2 -Wall

  EXTRA_DIST = autogen.sh \
               README.md
  ```

  ​