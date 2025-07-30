# Lexical Analyzer in C

This is a simple *Lexical Analyzer* written in the C programming language. It performs *lexical analysis* on input source code, breaking it into tokens such as keywords, identifiers, numbers, operators, and symbols.

---

## 🚀 Features

This lexical analyzer can identify:
- ✅ *Keywords*: int, float, if, else, while, return, etc.
- ✅ *Identifiers*: Variable names like score, total
- ✅ *Integers and Floats*: e.g., 100, 12.5
- ✅ *Operators*: +, -, *, /, =, ==, !=, >=, <=, <, >
- ✅ *Symbols*: ;, (, ), {, }
- ✅ *Single-line Comments*: // comment here

---

## 🛠 How It Works

- Enter your code input and end with a $ symbol
- The analyzer scans input *character by character*
- It classifies each lexeme into its correct *token type*

---

## 💻 Sample Input

```c
int score = 12.5;
if (score >= 10) {
    // Check score
    return score;
}$
