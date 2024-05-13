# min.h, Yet another C library which contains a bunch of utilities & recreations

`min` is the pinyin of the Chinese character `皿`, which represents a vessel
for holding stuff.

> [!WARNING]
> This project is just for fun & learning, thus it has absolute NO WARRANTY,
> use it as your own risk.

## Build

> [!NOTE]
> Make sure to run `make clean` before you change compile options

### With C standard library (Only tested with GCC)

```sh
make
```

### Without C standard library (Only on amd64 GNU/Linux, perhaps)

```sh
make NOSTDBUILD=1
```

After compilation, static library will be placed at `lib/static`, and
the shared one at `lib/shared`.
