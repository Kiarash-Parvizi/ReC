#  ReC

Orient your code in sections

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Compilation Using GCC

* Compile the project using following command:
```
gcc -o ReC ReC.c
```

### Usage
* Add ReC executable directory to your system PATH
* If you are using windows place the provided ls.exe file in the same location as the ReC.exe
* Open a new directory and write some ReC Code && save them with .c or .h extension
* To convert your code to a version that c compilers can understand run:
```
ReC
```
* You're done, A new dir named 'ReC' is now created, which contains all your new code
* Compile the new generated code and see the results

---

### ReC example code
```
#include<stdio.h>

section Server {
  
  //Vars
  int this.userCount = 0;
  
  void Start() {
    this.User::init();
  }
  
  section User {
    void Add() {
      printf("A new user was added | userCount : %d\n", parent.userCount);
      // or: printf("A new user was added | userCount : %d\n", root.userCount);
      parent.userCount++;
    }
    
    void init() {
      printf("Running...\n");
    }
  }
  //
}

int main() {
  Server::Start();
  Server::User::Add();
  Server::User::Add();
  Server::User::Add();
  printf("From Main: { Server::userCount = %d }\n", Server::userCount);
}
```
---

## Author
[Kiarash Parvizi](https://github.com/Kiarash-Parvizi)

## License

This project is licensed under the GNU General Public License - see the [LICENSE](https://github.com/Kiarash-Parvizi/ReC/blob/master/LICENSE) file for details
