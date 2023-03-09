# cpp-brainfuck-interpreter
A [Brainfuck](https://esolangs.org/wiki/Brainfuck) interpreter I wrote in C++.

## Why?
I had nothing better to do, so I had a go at creating my own interpreter of this fabulous language.


## What can I use it for?
You can easily run Brainfuck code on your system, instead of using an online interpreter.


## How do I use it?

Compile the interpreter yourself or download the latest [pre-compiled binary](https://github.com/stumburs/cpp-brainfuck-interpreter/releases/latest)

### Running from the command-line
1. Write a Brainfuck program and save the file, preferably with the **.bf** file extension
2. Open your favorite command line interface
3. Run `bf.exe <path_to_code_file>`
    - This will run your Brainfuck program in the CLI

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

## Known issues
- Adding line breaks, breaks the interpreter, how ironic


## Want to fix bugs or improve this interpreter?
If you would like to add a feature yourself, perform a pull request and add your changes. I will review them

If you found a bug, or have an idea for a feature, open an issue

**Keep in mind!** I prefer to keep this interpreter as simple and minimalistic as possible. If you wish to make drastic changes I might not agree with, feel free to just *steal* my code. I give anyone permission to use this *very complex* code for their needs :)
