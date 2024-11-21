# push_swap (42 school project)

The "push_swap" project at 42 School challenges students to implement a sorting algorithm using two stacks. The goal is to sort a list of integers with the fewest possible operations while adhering to strict constraints. This project tests proficiency in algorithm optimization, data structure manipulation, and managing edge cases efficiently.

- **Subject:** [English](./subject/en.subject.pdf) / [French](./subject/fr.subject.pdf) / [Spanish](./subject/es.subject.pdf)
- **Location:** 42 School Barcelona
- **Validation:** December 2024

## How to use

1. Clone repo locally
2. Rename `..gitignore` into `.gitignore`
3. Push to you own repo

This way, only the files requested by the subject will be pushed to your repo.

### Output
```bash
cd test
make test
```

![42 push_swap_line make output](./test/screenshot/output.png)

## Run tests

### Memory leaks
- Install [valgrind](https://valgrind.org/): `sudo apt update && sudo apt install valgrind`
- Run test: `cd test && valgrind --leak-check=full ./gnl`

![42 push_swap leaks test valgrind](./test/screenshot/valgrind.png)

### Moulinette test
- Install [paco](https://github.com/xicodomingues/francinette): `bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"`
- Run test inside the project folder: `paco`

![42_push_swap francinette test](./test/screenshot/paco.png)

## TODO

- Update list of .c files in Makefile
- Update ..gitignore file
- Remove the follwing calls + corresponding files:

## Notes

1. Push 2 first numbers to B

- If lstsize(A) == 4: push(B)
- if lstsize(A) >= 5 nbs: 2 * push(B)

2. While lstsize(A) > 3:

2A. Get target nodes

foreach(A) while cost != 0: calculate cost for pushing:
- A above the "just smaller B to A"
- A below the "highest B" (if there is no smaller B than A)

cost = (nb of ops to bring nb on top of A) + (nb of ops to bring a->target_node on top of B)

Condition "while cost != 0": if cost == 0, we cannot get better, so we stop searching / looping

