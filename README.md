# min.h, Yet another zero dependency C library

> [!WARNING]
> This toy project is just for fun & learning, thus it has absolute NO WARRANTY,
> use it as your own risk.

## WTF is this

TLDR; This is a library that provide some low level utilities that depends
on nothing but an OS (well, specifically, amd64, aarch64, loongarch64
GNU/Linux for now).

## Build

> [!NOTE]
> Make sure to run `make clean` before you change compile options

### Build (Only work on amd64, aarch64, loongarch64 GNU/Linux)

```sh
make
```

After compilation, static library will be placed at `lib/static`, and
the shared one at `lib/shared`.

## What's the meaning of `min`?

`min` is the pinyin of the Chinese character `皿`, which represents a vessel
for holding stuff.
