# ps-playground

## Compiling

- Compiling

  `make <filename>.cpp`

  ex) make 1000.cpp

- Running with stdin

  `make run`

- Running through pipeline

  `make run <filename>.in`

  ex) make run 1.in

- Automatic judge

  `make judge`

## Finishing (Archiving solved problem)

- Finishing (move solution & testcases)

  `./finished <problem_number> <folder>`

  ex) ./finished 12186 BOJ

- What it does
  1. Checks current directory has exactly **one** `.cpp` file (your solution).
     - If none or multiple exist, it prints an error and exits (no changes).
  2. Creates target directory if missing: `<folder>/<problem_number>/`
  3. Moves (and renames) the solution into:

     `<folder>/<problem_number>/main.cpp`

  4. Moves all `*.in` and `*.out` files into the same directory.
  5. Generates `<folder>/<problem_number>/README.md` including the problem link.
  6. Copies `template/main.cpp` into the root as `main.cpp` for the next problem.

- Notes
  - Root `README.md` is not touched.
  - If `<folder>/<problem_number>/README.md` already exists, it will be overwritten by default.
  - `template/main.cpp` must exist.
