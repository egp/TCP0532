# TCP0532

TCP0532 is an Arduino library skeleton for a PN532-based NFC reader project focused on identifying and eventually reading a specific **MIFARE Plus EV1** tag.

At this stage, the repository is intentionally small:

- standard Arduino library layout
- CI that compiles the example sketches
- a thin C++ library skeleton
- a first example that proves the library wiring and compile path

## Current scope

The immediate goal is to have a clean place to build the project before the hardware arrives.

Planned early milestones:

1. reader alive over I2C
2. tag detection
3. UID / version / protocol characterization
4. transport-layer implementation for PN532
5. tag-specific probing and read experiments

## Repository layout

```text
TCP0532/
├── .github/workflows/ci.yml
├── examples/
│   └── ReaderAlive/
├── src/
│   ├── TCP0532.cpp
│   └── TCP0532.h
├── .gitignore
├── keywords.txt
├── library.properties
├── LICENSE
├── Makefile
└── README.md
```

## Local build prerequisites

- Arduino CLI installed
- the relevant cores installed for the boards you want to compile against

Examples:

```bash
arduino-cli core update-index
arduino-cli core install arduino:avr
arduino-cli core install arduino:renesas_uno
```

## Local compile examples

Default board:

```bash
make compile
```

Specific board:

```bash
make compile FQBN=arduino:renesas_uno:minima
make compile FQBN=arduino:renesas_uno:unor4wifi
```

Compile all configured boards:

```bash
make compile-all
```

## Example sketch

`examples/ReaderAlive/ReaderAlive.ino` is only a bootstrap sketch.
It does **not** talk to the PN532 yet.
It simply proves:

- the library structure is valid
- the example compiles
- the starter API shape is in place

## Design intent

The long-term code split should stay clean:

- `TCP0532`: transport / board-facing wrapper
- PN532 protocol helpers
- MIFARE Plus EV1 probing/auth logic
- tag-specific parsing logic

That way, the tag-specific logic does not get welded directly into the transport layer.

## License

MIT
