# cpp-brainfuck-interpreter

A [brainfuck](https://esolangs.org/wiki/Brainfuck) interpreter I wrote in C++20.

-   [cpp-brainfuck-interpreter](#cpp-brainfuck-interpreter)
    -   [Why?](#why)
    -   [What can I use it for?](#what-can-i-use-it-for)
    -   [Installation and usage](#installation-and-usage)
        -   [Running from the command-line](#running-from-the-command-line)
        -   [Running from Visual Studio Code with the Code Runner extension installed.](#running-from-visual-studio-code-with-the-code-runner-extension-installed)
        -   [Parameters](#parameters)
        -   [Tips](#tips)
        -   [Updating](#updating)
    -   [Known issues](#known-issues)
    -   [Want to fix bugs or improve this interpreter?](#want-to-fix-bugs-or-improve-this-interpreter)

## Why?

I had nothing better to do, so I had a go at creating my own interpreter of this fabulous language.

## What can I use it for?

You can easily run brainfuck code on your system, instead of using an online interpreter.

## Installation and usage

Compile the interpreter yourself or download the latest [pre-compiled binary](https://github.com/stumburs/cpp-brainfuck-interpreter/releases/latest)

### Running from the command-line

1. Write a brainfuck program and save the file, preferably with the **.bf** file extension
2. Open your favorite command line interface
3. Run `bf.exe <path_to_code_file>`
    - This will run your brainfuck program in the CLI

### Running from Visual Studio Code with the [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) extension installed.

1. Save the **bf.exe** interpreter in a folder
2. Add the folder to your Windows PATH variables
    - Verify this step by closing any existing command line interfaces
    - Open a new command line interface
    - Type `bf`
    - If you did everything correctly, you should see `No input file supplied.` in the CLI
3. Open Visual Studio Code
4. Add this interpreter to your Code Runner settings by going to **File > Preferences > Settings** or pressing `CTRL + ,` on your keyboard
5. Go to **Extensions > Run Code configuration**
6. Click **Edit in settings.json** under **Code-runner: Executor Map**
7. Inside of `"code-runner.executorMap"`, add the following line of code

```
"brainfuck": "bf"
```

8. Verify by creating a **hello_world.bf** file and running this code.

```
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

### Parameters

`--help` displays all parameters/information (~1.6)

`--version` displays currently installed version (~1.4)

### Tips

For developing brainfuck programs in Visual Studio Code, I recommend this [extension](https://marketplace.visualstudio.com/items?itemName=attilabuti.brainfuck-syntax) for syntax highlighting.

The [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) extension is useful for quickly running your programs, however, you will have to follow the steps mentioned previously to set it up with this interpreter.

### Updating

To update the brainfuck interpreter, simply download a newer version and replace your existing executable.

## Known issues

-   None, at the moment

## Want to fix bugs or improve this interpreter?

If you would like to add a feature yourself, perform a pull request and add your changes. I will review them

If you found a bug, or have an idea for a feature, open an issue

**Keep in mind!** I prefer to keep this interpreter as simple and minimalistic as possible. If you wish to make drastic changes I might not agree with, feel free to just _steal_ my code. I give anyone permission to use this _very complex_ code for their needs :)
