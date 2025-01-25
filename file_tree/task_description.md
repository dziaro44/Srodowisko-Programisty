# File Tree Task Description

The task requires writing a program that takes input in the following format:

## Input Format
- Number of sets
- For each set:
  - `folder/file`
  - Line of text.

## Task Requirements
For each set, the program should:
1. If the "folder" does not exist in the directory where the program was run, it should be created.
2. If the "file" does not exist in the "folder," it should be created.
3. Append the line "Line of text." to the "file."
4. Create a symbolic link in the directory where the program was run, linking to the file `folder/file` and name the symlink `file.symlink`.

## Example

In the root directory, we have two folders: `tree_test` and `prog_dir`. The first is empty, and the second contains the executable file. Running the following commands from the root directory:

```bash
$ cd tree_test
$ ./../prog_dir/prog
4
folderA/1.txt
First line of text.
folderB/one.txt
123
folderA/1.txt
Second line of text.
folderA/2.txt
Some file.
```

### Expected File Tree

```
├── 1.txt.symlink -> /home/test_tree/folderA/1.txt
├── 2.txt.symlink -> /home/test_tree/folderA/2.txt
├── folderA
│   ├── 1.txt
│   └── 2.txt
├── folderB
│   └── one.txt
└── one.txt.symlink -> /home/test_tree/folderB/one.txt
```

### Content of Files

- `folderA/1.txt` contains:
  ```
  First line of text.
  Second line of text.
  ```

- `folderA/2.txt` contains:
  ```
  Some file.
  ```

- `folderB/one.txt` contains:
  ```
  123
  ```

## Required Functions

The following functions should be used in the program:

- `getenv()` from `stdlib.h` to obtain the current directory from the "PWD" environment variable.
- `stat()` from `sys/stat.h` to check if the folder with the given name exists (with the appropriate flag to check if it is a folder).
- `mkdir()` from `sys/stat.h` to create directories.
- `open()` from `fcntl.h` to create and open files.
- `write()` from `unistd.h` to append text to files.
- `symlink()` from `unistd.h` to create symbolic links.