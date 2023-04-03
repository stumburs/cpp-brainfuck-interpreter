#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <array>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "No input file supplied.\nUse \"bf --help\" for more information\n";
        return 1;
    }

    if (std::string(argv[1]) == "--help")
    {
        std::cout << "Available commands:\n\n\t--help\t\tDisplays this screen\n\t--version\tDisplays installed version\n";
        return 1;
    }

    if (std::string(argv[1]) == "--version")
    {
        std::cout << "cpp-brainfuck-interpreter 1.6-static\nhttps://github.com/stumburs\n";
        return 1;
    }

    // Create input file
    std::string file_path = argv[1];
    std::ifstream input_file(file_path);

    // Check if file successfully opened
    if (!input_file.is_open())
    {
        std::cout << "Failed to open file.\n";
        return 1;
    }

    // Preprocess file to remove non-Brainfuck characters
    std::string program((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    std::erase_if(program, [](char c)
                  { return !strchr("><+-.,[]", c); });
    input_file.close();

    // Init memory
    constexpr std::size_t mem_size = 30000;
    std::array<uint8_t, mem_size> mem = {0};
    uint8_t *ptr = mem.data();

    // Run program
    std::stack<std::streampos> loop_stack; // stack to keep track of loop positions
    std::size_t loop_counter = 0;          // counter for nested loops
    std::size_t i = 0;
    while (i < program.length())
    {
        switch (program[i])
        {
        case '>':
            ++ptr;
            break;
        case '<':
            --ptr;
            break;
        case '+':
            ++*ptr;
            break;
        case '-':
            --*ptr;
            break;
        case '.':
            std::cout << *ptr;
            break;
        case ',':
            std::cin >> *ptr;
            break;
        case '[':
            if (*ptr == 0)
            {
                // Skip loop body
                int nested_loops = 1;
                while (nested_loops > 0)
                {
                    ++i;
                    if (program[i] == '[')
                        ++nested_loops;
                    else if (program[i] == ']')
                        --nested_loops;
                }
            }
            else
            {
                loop_stack.push(i);
                ++loop_counter;
            }
            break;
        case ']':
            if (*ptr != 0)
                i = loop_stack.top();
            else
            {
                loop_stack.pop();
                --loop_counter;
            }
            break;
        default:
            break;
        }
        ++i;
        if (loop_counter == 0 && i >= program.length())
            break; // exit loop if all loops have been exited
    }
    return 0;
}
