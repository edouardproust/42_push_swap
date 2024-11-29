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

### Test with random number:

For a single test on a list containing 500 ints (replace `500` by your desired number of ints):
```
cd test
make ARGS="$(./generate 500)" // Replace 500 by the desired number of ints
```
To test it 50 times for example (replace `50` by your desired number of tests):
```
cd test
for i in {1..50}; do make check count ARGS="$(./generate 500)"; done
```

### Memory leaks
- Install [valgrind](https://valgrind.org/): `sudo apt update && sudo apt install valgrind`
- Run test: `cd test && valgrind --leak-check=full ./gnl`

![42 push_swap leaks test valgrind](./test/screenshot/valgrind.png)

### Moulinette test
- Install [paco](https://github.com/xicodomingues/francinette): `bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"`
- Run test inside the project folder: `paco`

![42_push_swap francinette test](./test/screenshot/paco.png)
