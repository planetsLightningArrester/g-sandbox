# `g++` sandbox

C++ project with the following features set up.

* A project called `math`
* Unit tests for the package `sum` inside `math`
* `Makefile`s to build and test
* `install_dependencies` to install dependencies

## Usage

Install the dependencies
```Bash
chmod 700 ./install_dependencies.sh
sudo ./install_dependencies.sh
```

Build CMake
```Bash
make build
```

Run all tests
```Bash
make test
```